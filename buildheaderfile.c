/****************************
Copyright © 2013-2014 Luke Salisbury
This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
****************************/


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

#ifndef nullptr
	#define nullptr NULL
#endif

#define LOG_MESSAGE(M, ...) printf("%18s:%04d | " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define FH(q) q

#ifndef ELIX_FILE_PATH_LENGTH
	#define ELIX_FILE_PATH_LENGTH 768
#endif

#ifndef ELIX_FILE_NAME_LENGTH
	#define ELIX_FILE_NAME_LENGTH 256
#endif

#ifndef ftello64
	#define ftello64 ftello
#endif
#ifndef fseeko64
	#define fseeko64 fseeko
#endif

typedef void* data_pointer;
typedef FILE * file_pointer;

typedef uint64_t file_size;
typedef int64_t file_offset;

typedef enum {
	EFF_STATUS_UNKNOWN = 1 << 0,
	EFF_FILE_OPEN = 1 << 1, EFF_FILE_READ_ONLY = 1 << 2, EFF_FILE_READ_ERROR = 1 << 3 ,
	EFF_FILE_WRITE = 1 << 4, EFF_FILE_WRITE_ERROR = 1 << 5, EFF_WRITABLE = 1 << 6
} ElixFileFlag;

struct ElixFile {
	FILE * handle;
	file_size length;
	file_size pos;
	uint32_t flag;
};
typedef struct ElixFile elix_file;

uint32_t elix_hash( const char * str, size_t len ) {
	//Jenkins One-at-a-time hash
	uint32_t hash = 0;
	size_t i;

	for (i = 0; i < len; i++) {
		hash += str[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}


file_offset elix_file_offset(elix_file * file) {
	// Note: due to pointless warnings, using ftello64 instead of ftello
	file_offset q = ftello64( FH(file->handle) );
	if ( q < 0 ) {
		return 0;
	}
	return q;
}

uint32_t elix_file_at_end(elix_file * file) {
	if ( file->handle ) {
		if ( file->pos == file->length )
			return true;
		return !(feof( FH(file->handle) ) == 0);
	}
	return true;
}

uint32_t elix_file_seek(elix_file * file, file_offset pos ) {
	if ( fseeko64( FH(file->handle), pos, SEEK_SET ) == 0) {
		file->pos = pos;
		return true;
	}
	return false;
}

size_t elix_file_read(elix_file * file, data_pointer buffer, size_t data_size, size_t amount) {
	if ( !file || !file->handle || file->length < data_size || !buffer ) {
		return 0;
	}

	size_t q = fread(buffer, data_size, amount, FH(file->handle));
	if ( q != 0 ) {
		file_offset p = elix_file_offset( file );
		if ( p >= 0 ) {
			file->pos = p;
		}
	}
	return q;
}


size_t elix_file_write( elix_file * file, data_pointer data, size_t size ) {
	if ( !file || !file->handle ) {
		return 0;
	}
	return fwrite(data, size, 1, FH(file->handle));

}

static inline file_size elix_file_tell(elix_file * file) {
	return (file_size)(elix_file_offset(file));
}

file_size elix_file__update_length(elix_file * file) {
	file_offset pos = elix_file_offset(file);
	fseeko64( FH(file->handle), 0, SEEK_END );
	file->length = elix_file_tell(file);
	fseeko64( FH(file->handle), pos, SEEK_SET );
	return file->length;
}

uint32_t elix_file_open(elix_file * file, const char * filename, ElixFileFlag mode) {
	file->handle = fopen(filename, (mode & EFF_FILE_WRITE ? "wb" : "rb") );
	//fopen_s( &file->handle, filename, (mode & EFF_FILE_WRITE ? "wb" : "rb") );
	if ( file->handle ) {
		file->flag = mode;
		elix_file__update_length(file);
		return true;
	} else {
		LOG_MESSAGE("File not found %s", filename);
	}
	file->flag = (mode | EFF_FILE_WRITE ? EFF_FILE_WRITE_ERROR : EFF_FILE_READ_ERROR);
	return false;

}

uint32_t elix_file_close(elix_file * file) {
	if ( file->handle ) {
		return fclose( FH(file->handle) ) == 0;
	}
	return false;
}


static inline size_t elix_cstring_length(const char * string, uint8_t include_terminator ) {
	if (string) {
		size_t c = 0;
		while(*string++) {
			++c;
		}
		return c + include_terminator;
	}
	return 0;
}

bool elix_cstring_has_suffix( const char * str, const char * suffix) {
	size_t str_length = elix_cstring_length(str, 0);
	size_t suffix_length = elix_cstring_length(suffix, 0);
	size_t offset = 0;

	if ( str_length < suffix_length )
		return false;

	offset = str_length - suffix_length;
	for (size_t c = 0; c < suffix_length;  c++ ) {
		if ( str[offset + c] != suffix[c] )
			return false;
	}
	return true;
}

size_t elix_cstring_append( char * str, const size_t len, const char * text, const size_t text_len) {
	size_t length = elix_cstring_length(str, 0);
	// TODO: Switch to memcpy
	for (size_t c = 0;length < len && c < text_len; length++, c++) {
		str[length] = text[c];
	}
	str[length+1] = 0;
	return length;
}

char * elix_cstring_from( const char * source, const char * default_str, size_t max_length ) {
	//ASSERT( default_str != nullptr )
	const char * ptr = source != nullptr ? source : default_str;
	size_t length = (max_length == SIZE_MAX) ? elix_cstring_length(ptr, 1) : max_length;

	if ( length <= 1 ) {
		//LOG_ERROR("elix_cstring_from failed, source was empty");
		return nullptr;
	}

	char * dest = malloc(length); //new char[length]();
	memcpy(dest, ptr, length);
	dest[length] = 0;
	return dest;
}


void elix_cstring_copy( const char * source_init, char * dest_init) {
	char * source = (char *)source_init;
	char * dest = dest_init;
	do {
		*dest++ = *source++;
	} while(*source != 0);
	*dest = '\0';
}


struct ElixPath {
	char * uri;
	char * path;
	char * filename;
	char * filetype;
};
typedef struct ElixPath elix_path;


struct ElixDirectory {
	uint16_t count;
	elix_path * files;
};
typedef struct ElixDirectory elix_directory;


elix_path elix_path_create(const char * string) {
	elix_path uri = {0,0,0,0};
	size_t length = elix_cstring_length(string, 0);
	size_t split = SIZE_MAX;
	size_t extension_split = SIZE_MAX;
	for (split = length-1; split > 0; split--) {
		if ( string[split] == '\\' || string[split] == '/') {
			split++;
			break;
		}
		if ( extension_split == SIZE_MAX && string[split] == '.') {
			extension_split = split;
		}
	}

	//ASSERT(split < length);
	uri.uri = malloc(length+1);
	memset(uri.uri,0, length+1);
	elix_cstring_copy(string, uri.uri);
	uri.path = elix_cstring_from( string, "/", split );

#ifdef PLATFORM_WINDOWS
	elix_cstring_char_replace(uri.path, '\\', '/');
#endif
	if ( extension_split != SIZE_MAX ) {
		uri.filename = elix_cstring_from(string + split, "/", extension_split - split);
		uri.filetype = elix_cstring_from(string + extension_split, "/",SIZE_MAX);
	} else {
		uri.filename = elix_cstring_from(string + split, "/", length - split);
		uri.filetype = nullptr;
	}

	return uri;
}


void elix_os_directory_list_destroy(elix_directory ** directory) {
	for (int f = 0; f < (*directory)->count; ++f) {
		//free((*directory)->files[f]);
	}
	free((*directory)->files);
	//free(*directory);
	*directory = nullptr;
}

elix_directory * elix_os_directory_list_files(const char * path, const char * suffix) {
	elix_directory * directory = nullptr;
	DIR * current_directory;
	struct dirent * entity;
	current_directory = opendir(path);
	if ( !current_directory ) {
		return directory;
	}
	directory = calloc(1, sizeof(directory));
	while ((entity = readdir(current_directory)) ) {
		if ( entity->d_name[0] == '.' && (entity->d_name[1] == '.'|| entity->d_name[1]== 0)){

		} else if (suffix) {
			if ( elix_cstring_has_suffix(entity->d_name, suffix ) )
				directory->count++;
		} else {
			directory->count++;
		}
	}
	size_t path_len = elix_cstring_length(path, 0);
	directory->files = malloc(directory->count * sizeof(elix_path));
	rewinddir(current_directory);
	uint16_t index = 0;
	char buffer[ELIX_FILE_PATH_LENGTH] = {0};
	elix_cstring_copy(path, buffer);
	while ( (entity = readdir(current_directory)) ) {
		if ( entity->d_name[0] == '.' && (entity->d_name[1] == '.'|| entity->d_name[1]== 0)){

		} else if (suffix) {
			if ( elix_cstring_has_suffix(entity->d_name, suffix ) ) {
				memset(buffer+path_len, 0, ELIX_FILE_PATH_LENGTH-path_len);
				elix_cstring_append(buffer, ELIX_FILE_PATH_LENGTH, entity->d_name, elix_cstring_length(entity->d_name, 0));
				directory->files[index] = elix_path_create(buffer);
				index++;
			}
		} else {
			memset(buffer+path_len, 0, ELIX_FILE_PATH_LENGTH-path_len);
			elix_cstring_append(buffer, ELIX_FILE_PATH_LENGTH, entity->d_name, elix_cstring_length(entity->d_name, 0));
			directory->files[index] = elix_path_create(buffer);
			index++;
		}
	}
	closedir(current_directory);
	return directory;
}


size_t elix_file_read_buffer(elix_file * file, data_pointer data, size_t data_size, const char * skipable) {
	if ( !file || !file->handle || !data ) {
		return 0;
	}

	uint8_t char_buffer;
	uint8_t * data_buffer = data;
	size_t index = 0;
	size_t q = 0;// = elix_file_read(file, &char_buffer, 1,1);
	size_t skip_index = 0;
	do {
		q = elix_file_read(file, &char_buffer, 1,1);

		while (skipable[skip_index]) {
			if ( skipable[skip_index] == char_buffer ) {
				goto next_character;
			}
			skip_index++;
		}
		data_buffer[index++] = char_buffer;

		next_character:
		skip_index = 0;

	} while ( index+1 < data_size && !elix_file_at_end(file));
	data_buffer[index] = 0;
	return index;
}

bool elix_cstring_has_prefix( const char * str, const char * prefix) {
	size_t str_length = elix_cstring_length(str, 0);
	size_t prefix_length = elix_cstring_length(prefix, 0);

	if ( str_length < prefix_length )
		return false;

	for (size_t c = 0; c < prefix_length;  c++ ) {
		if ( str[c] != prefix[c] )
			return false;
	}
	return true;
}

size_t elix_cstring_trim( char * string ) {
	size_t length = elix_cstring_length(string, 0);

	while( length && string[0] == ' ' ) {
		memmove(string, string + 1, length);
		length--;
	}
	size_t pos = length ? length-1 : 0;
	while( pos && string[pos] == ' ' ) {
		string[pos] = 0;
		length--;
		pos--;
	}
	return length;
}

#define ELIX_CHAR_LOWER 1
#define ELIX_CHAR_UPPER 2
#define ELIX_CHAR_CAPITALISE 3
void elix_cstring_transform( char * string, uint8_t mode ) {
	size_t length = elix_cstring_length(string, 0);
	for (size_t var = 0; var < length; ++var) {
		switch (mode) {
			case ELIX_CHAR_LOWER:
				if (string[var] >= 'A' && string[var] <= 'Z') {
					string[var] += 32;
				}
				break;
			case ELIX_CHAR_UPPER:
				if (string[var] >= 'a' && string[var] <= 'z') {
					string[var] -= 32;
				}
				break;
			case ELIX_CHAR_CAPITALISE:
				if (string[var] >= 'a' && string[var] <= 'z') {
					string[var] -= 32;
				}
				mode = 0;
				break;
			default:
				break;
		}
	}
}

//TODO: Check UTF8 strings
size_t elix_file_write_escaped( elix_file * file, data_pointer data, size_t size ) {
	if ( !file || !file->handle ) {
		return 0;
	}
	static uint8_t escapable_char[3] = {'\n', '\\', '"'};
	size_t escape_counter = 0;
	uint8_t * data_index = data;
	for (size_t ind = 0 ; ind < size; ind++) {
		for (size_t sc = 0; sc <= 3; sc++) {
			if ( data_index[ind] == escapable_char[sc]) {
				escape_counter++;
			}
		}
	}
	if ( escape_counter ) {
		size_t written = 0;
		size_t new_size = size + escape_counter;
		uint8_t * new_data = malloc(size + new_size);
		memcpy(new_data, data, size);
		for (size_t ind = 0 ; ind < new_size; ind++) {
			for (size_t sc = 0; sc <= 3; sc++) {
				if ( new_data[ind] == escapable_char[sc]) {

					memmove(new_data+ind+1,new_data+ind,new_size - ind);
					new_data[ind]= '\\';
					if ( escapable_char[sc] == '\n') {
						new_data[ind+1]= 'n';
					}

					sc = 9;
					ind++;
				}
			}
		}

		written = fwrite(new_data, size + escape_counter, 1, FH(file->handle));
		free(new_data);
		return written;
	}
	else {
		return fwrite(data, size, 1, FH(file->handle));
	}

}
size_t elix_cstring_spaces_to_tabs(char * string, size_t space_amount) {
	size_t length = elix_cstring_length(string, 0);
	size_t space_start = SIZE_MAX;
	size_t space_counter = 0;
	for (size_t var = 0; var < length; ++var) {
		if ( string[var] == ' ') {
			if ( space_start == SIZE_MAX ) {
				space_start = var;
			}
			space_counter++;
			if ( space_counter == space_amount) {
				memmove(string+space_start+1,string+space_start+space_amount,length - space_start - space_amount);
				string[space_start] = '\t';
				length -= space_amount-1;
				var -= space_amount-1;

				space_counter = 0;
			space_start = SIZE_MAX;
			}
		} else {
			space_counter = 0;
			space_start = SIZE_MAX;
		}
	}
	string[length] = 0;
	return length;
}

//void read_file( elix_path * file, elix_file * output_file  )
//{
//	elix_file input_file;
//	elix_file_open(&input_file, file->uri, EFF_FILE_READ_ONLY);

//	char * define = elix_cstring_from(file->filename, nullptr,SIZE_MAX);
//	elix_cstring_transform(define, ELIX_CHAR_UPPER);

//	elix_file_write(output_file,"#define GUI_", 12);
//	elix_file_write(output_file, define, elix_cstring_length(define,0));
//	elix_file_write(output_file," \"", 2);

//	while (!elix_file_at_end(&input_file)) {
//		char data[256];
//		size_t read = elix_file_read_line(&input_file, data, 256);
//		elix_file_write_escaped(output_file, data, read);
//	}

//	elix_file_write(output_file,"\" \n", 3);

//	free(define);

//}

void read_file( elix_path * file, elix_file * output_file  )
{
	elix_file input_file;
	elix_file_open(&input_file, file->uri, EFF_FILE_READ_ONLY);

	char * define = elix_cstring_from(file->filename, nullptr,SIZE_MAX);
	elix_cstring_transform(define, ELIX_CHAR_LOWER);

	elix_file_write(output_file,"\t\"", 2);
	elix_file_write(output_file, define, elix_cstring_length(define,0));
	elix_file_write(output_file,"\", \"", 4);

	while (!elix_file_at_end(&input_file)) {
		char data[256];
		size_t read = elix_file_read_buffer(&input_file, data, 256, "\r");
		read = elix_cstring_spaces_to_tabs(data,2);
		elix_file_write_escaped(output_file, data, read);
	}

	elix_file_write(output_file,"\",\n", 3);

	free(define);

}



void scan_directory_write_to( char * dir, elix_file * output_file )
{
	elix_directory * defaults_dir = elix_os_directory_list_files(dir, ".gui");
	if ( defaults_dir ) {
		for (size_t a = 0; a < defaults_dir->count; ++a) {
			read_file(&defaults_dir->files[a], output_file);
			printf("%s %s \n", defaults_dir->files[a].filename, defaults_dir->files[a].uri);
		}
		elix_os_directory_list_destroy(&defaults_dir);
	} else {
		printf("Directory not found");
	}

}




int main(int argc, char *argv[])
{
	if ( argc < 2 )
	{
		printf("buildheaderfile.exe - missing argument");
		return 0;
	}

	elix_file output_file;
	//TODO check argv[2]
	elix_file_open(&output_file,"include/ui_resources.h", EFF_FILE_WRITE);

	elix_file_write(&output_file,"static const char * ui_resources[] = {\n", 39);
	scan_directory_write_to( argv[1], &output_file );
	elix_file_write(&output_file,"};", 2);
	elix_file_close(&output_file);


	return 0;
}
