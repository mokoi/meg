/****************************
Copyright © 2007-2013 Luke Salisbury
This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
****************************/

/* Standard Headers */
#include "loader_global.h"
#include "entity_functions.h"
#include "runtime_parser.h"
#include "runtime_options.h"
#include "maps.h"
#include "loader_functions.h"

/* Required Headers */
#include <zlib.h>
#include <sys/stat.h>
#include <glib/gstdio.h>

enum MapParserModes {
	MPM_NEW,
	MPM_ROOT,
	MPM_SETTING,
	MPM_OBJECT,
	MPM_PATH,
	MPM_POINTS
};

/* Global Functions  */


/* Local Functions  */
void map_parse_handler_start( GMarkupParseContext *context, const gchar *element_name, const gchar **attribute_names, const gchar **attribute_values, gpointer user_data, GError **error);
void map_parse_handler_end( GMarkupParseContext *context, const gchar *element_name, gpointer user_data, GError **error);
void map_dimension_parse_start( GMarkupParseContext *context, const gchar *element_name, const gchar **attribute_names, const gchar **attribute_values, gpointer user_data, GError **error);
DisplayObjectTypes VirtualObject_Type( const gchar * type_name );

/* Global Variables */


/* Local Variables */
gint map_parse_mode = MPM_NEW;

static GMarkupParser map_parser_xml = { map_parse_handler_start, map_parse_handler_end, NULL, NULL, NULL};
static GMarkupParser map_dimension_parser = { map_dimension_parse_start, NULL, NULL, NULL, NULL};


/********************************
* map_parser_colour
*
*/
void map_parser_colour( rgbaColour * colour, gboolean use_alpha, const gchar **attribute_names, const gchar **attribute_values)
{
	colour->red = colour->blue = colour->green = colour->alpha = 255;
	for (; *attribute_names && *attribute_values; attribute_names++, attribute_values++)
	{
		if ( !g_ascii_strcasecmp (*attribute_names, "red") )
			colour->red = (guint8)g_ascii_strtoull(*attribute_values, NULL, 10);
		else if ( !g_ascii_strcasecmp (*attribute_names, "blue") )
			colour->blue = (guint8)g_ascii_strtoull(*attribute_values, NULL, 10);
		else if ( !g_ascii_strcasecmp (*attribute_names, "green") )
			colour->green = (guint8)g_ascii_strtoull(*attribute_values, NULL, 10);
		else if ( !g_ascii_strcasecmp (*attribute_names, "alpha") )
		{
			if ( use_alpha )
			{
				colour->alpha = (guint8)g_ascii_strtoull(*attribute_values, NULL, 10);
			}
		}
	}
}

/********************************
* map_dimension_parse_start
*
*/
void map_dimension_parse_start( GMarkupParseContext *context, const gchar *element_name, const gchar **attribute_names, const gchar **attribute_values, gpointer user_data, GError **error )
{
	if ( g_ascii_strcasecmp(element_name, "dimensions") == 0 )
	{
		for (; *attribute_names && *attribute_values; attribute_names++, attribute_values++)
		{
			if ( g_ascii_strcasecmp (*attribute_names, "width") == 0 )
				((GdkRectangle*)user_data)->width = atoi(*attribute_values);
			else if ( g_ascii_strcasecmp (*attribute_names, "height") == 0 )
				((GdkRectangle*)user_data)->height = atoi(*attribute_values);
		}
	}
}


/********************************
* map_parse_handler_start
*
*/
void map_parse_handler_start( GMarkupParseContext *context, const gchar *element_name, const gchar **attribute_names, const gchar **attribute_values, gpointer user_data, GError **error )
{
	MokoiMap * mokoi_map_info = NULL;
	VirtualObjectList * virtual_object_list = NULL;


	MapInfo * map_info = (MapInfo *)user_data;


	if ( map_info->file_type == 0 )
	{
		mokoi_map_info = (MokoiMap *)map_info->data;
	}
	else if ( map_info->file_type == 1 )
	{
		virtual_object_list = (VirtualObjectList *)map_info->data;
	}

	if ( map_info->parse_mode == MPM_SETTING && map_info->file_type == 0)
	{
		/* Settings */
		if ( g_ascii_strcasecmp (element_name, "color") == 0 )
		{
			map_parser_colour(&mokoi_map_info->colour8, FALSE, attribute_names, attribute_values);
		}
		else if ( g_ascii_strcasecmp (element_name, "option") == 0 )
		{
			gchar * key = NULL, *value = NULL, *type = NULL;
			for (; *attribute_names && *attribute_values; attribute_names++, attribute_values++)
			{
				if ( g_ascii_strcasecmp(*attribute_names, "key") == 0 )
					key = g_strdup(*attribute_values);
				else if ( g_ascii_strcasecmp(*attribute_names, "value") == 0 )
					value = g_strdup(*attribute_values);
				else if ( g_ascii_strcasecmp(*attribute_names, "type") == 0 )
					type = g_strdup(*attribute_values);
			}

			if ( key && value )
			{
				if ( g_ascii_strcasecmp( value, "(null)" ) )
					g_hash_table_insert( map_info->settings, (gpointer)key, RuntimeSetting_New(value, type) );
				else
					g_hash_table_insert( map_info->settings, (gpointer)key, RuntimeSetting_New("", type) );
			}

		}
		else if ( g_ascii_strcasecmp (element_name, "dimensions") == 0 )
		{
			for (; *attribute_names && *attribute_values; attribute_names++, attribute_values++)
			{
				if ( g_ascii_strcasecmp (*attribute_names, "width") == 0 )
					mokoi_map_info->position.width = atoi(*attribute_values);
				else if ( g_ascii_strcasecmp (*attribute_names, "height") == 0 )
					mokoi_map_info->position.height = atoi(*attribute_values);
				if ( g_ascii_strcasecmp (*attribute_names, "x") == 0 )
					mokoi_map_info->position.x = atoi(*attribute_values);
				else if ( g_ascii_strcasecmp (*attribute_names, "y") == 0 )
					mokoi_map_info->position.y = atoi(*attribute_values);
			}
		}
	}
	else if ( map_info->parse_mode == MPM_PATH )
	{
		/* Create Path Object Object */
		DisplayObject * object_display = g_new0(DisplayObject, 1);
		object_display->layer = 42;
		object_display->w = object_display->h = 16;
		object_display->type = DT_PATHITEM;
		object_display->resizable = FALSE;
		for (; *attribute_names && *attribute_values; attribute_names++, attribute_values++)
		{
			if ( g_ascii_strcasecmp (*attribute_names, "x") == 0 )
				object_display->x = atoi(*attribute_values);
			else if ( g_ascii_strcasecmp (*attribute_names, "y") == 0 )
				object_display->y = atoi(*attribute_values);
		}


		/* Append Object */
		GList * last_object = NULL;
		if ( map_info->file_type == 0 )
		{
			MokoiMapObject * object = NULL;

			last_object = g_list_last(mokoi_map_info->objects);
			object = (MokoiMapObject *)last_object->data;
			object->object->path = g_slist_append( object->object->path, object_display );

		}
		else if ( map_info->file_type == 1 )
		{
			VirtualObject * object = NULL;

			last_object = g_list_last(virtual_object_list->objects);
			object = (VirtualObject *)last_object->data;
			object->object->path = g_slist_append( object->object->path, object_display );

		}


	}
	else if ( map_info->parse_mode == MPM_OBJECT )
	{
		MokoiMapObject * map_object = NULL;
		VirtualObject * virtual_object = NULL;
		DisplayObject * object_display = NULL;

		/* Get Last Object */
		GList * last_object = NULL;
		if ( map_info->file_type == 0 )
		{
			last_object = g_list_last(mokoi_map_info->objects);
			map_object = (MokoiMapObject *)last_object->data;
			object_display = (DisplayObject*)map_object->object;
		}
		else if ( map_info->file_type == 1 )
		{
			last_object = g_list_last(virtual_object_list->objects);
			virtual_object = (VirtualObject *)last_object->data;
			object_display = (DisplayObject *)virtual_object->object;
		}

		/* Update Object */
		object_display->resizable = TRUE;
		if ( g_ascii_strcasecmp (element_name, "position") == 0 )
		{
			for (; *attribute_names && *attribute_values; attribute_names++, attribute_values++)
			{
				if ( *attribute_names[0] =='x' )
					object_display->x = g_ascii_strtod(*attribute_values, NULL);
				else if ( *attribute_names[0] =='y' )
					object_display->y = g_ascii_strtod(*attribute_values, NULL);
				else if ( *attribute_names[0] =='l' )
					object_display->layer = (gint)g_ascii_strtod(*attribute_values, NULL);
				else if ( *attribute_names[0] =='w' )
					object_display->w = g_ascii_strtod(*attribute_values, NULL);
				else if ( *attribute_names[0] =='h' )
					object_display->h = g_ascii_strtod(*attribute_values, NULL);
				else if ( *attribute_names[0] =='r' )
					object_display->rotate = atoi(*attribute_values)/90;
				else if ( *attribute_names[0] =='f' )
					object_display->flip = (gboolean)g_ascii_strtod(*attribute_values, NULL);
			}

			if ( object_display->type == DT_LINE )
			{
				object_display->w -= object_display->x;
				object_display->h -= object_display->y;
			}
		}
		else if ( g_ascii_strcasecmp(element_name, "entity") == 0 )
		{
			if ( map_object )
			{
				for (; *attribute_names && *attribute_values; attribute_names++, attribute_values++)
				{
					if ( !g_ascii_strcasecmp( *attribute_names, "value" ) )
					{
						map_object->entity_file = g_strdup(*attribute_values);
					}
					else if ( !g_ascii_strcasecmp( *attribute_names, "global" ) )
					{
						map_object->entity_global = !g_ascii_strcasecmp(*attribute_values, "true");
					}
					else if ( !g_ascii_strcasecmp( *attribute_names, "language" ) )
					{
						map_object->entity_language = g_strdup(*attribute_values);
					}
				}
			}
		}
		else if ( g_ascii_strcasecmp(element_name, "color") == 0 )
		{
			if ( map_object )
			{
				map_parser_colour(&map_object->colour8, TRUE, attribute_names, attribute_values);
				object_display->colour.red = (gdouble)map_object->colour8.red / 255.0;
				object_display->colour.blue = (gdouble)map_object->colour8.blue / 255.0;
				object_display->colour.green = (gdouble)map_object->colour8.green / 255.0;
				object_display->colour.alpha = (gdouble)map_object->colour8.alpha / 255.0;
			}
		}
		else if ( g_ascii_strcasecmp(element_name, "setting") == 0 )
		{
			if ( map_info->file_type == 0 )
			{
				const gchar * key = NULL, *value = NULL, *type = NULL;
				for (; *attribute_names && *attribute_values; attribute_names++, attribute_values++)
				{
					if ( g_ascii_strcasecmp(*attribute_names, "key") == 0 )
						key = *attribute_values;
					else if ( g_ascii_strcasecmp(*attribute_names, "value") == 0 )
						value = *attribute_values;
					else if ( g_ascii_strcasecmp(*attribute_names, "type") == 0 )
						type = *attribute_values;
				}

				if ( key && value )
				{
					if ( !g_ascii_strcasecmp( key, "id" ) )
					{
						if ( value[0] != '*')
							map_object->object_id = "";
						else
							map_object->object_id = g_strdup(value);
					}
					else if ( !g_ascii_strcasecmp( key, "entity" ) )
					{
						gchar ** file = g_strsplit( value, ".", 2);
						if ( g_strv_length(file) == 2 )
						{
							map_object->entity_file = g_strdup(file[0]);
							map_object->entity_language = g_strdup(file[1]);
						}
						g_strfreev( file );
					}
					else if ( !g_ascii_strcasecmp( key, "global" ) )
					{
						map_object->entity_global = !g_ascii_strcasecmp(value, "true");
					}
					else
					{
						if ( g_ascii_strcasecmp( value, "(null)" ) )
							g_hash_table_replace( map_object->settings, (gpointer)g_strdup(key), RuntimeSetting_New(value, type) );
						else
							g_hash_table_replace( map_object->settings, (gpointer)g_strdup(key), RuntimeSetting_New("", type) );
					}
				}
			}
		}
		else if ( g_ascii_strcasecmp(element_name, "path") == 0 )
		{
			map_info->parse_mode = MPM_PATH;
		}
		else if ( g_ascii_strcasecmp(element_name, "point") == 0 )
		{

			DisplayObject * object_point = g_new0(DisplayObject, 1);

			object_point->type = DT_POINT;
			object_point->layer = 43;
			object_point->w = object_point->h = 16;
			object_point->resizable = FALSE;
			for (; *attribute_names && *attribute_values; attribute_names++, attribute_values++)
			{
				if ( g_ascii_strcasecmp (*attribute_names, "x") == 0 )
					object_point->x = atoi(*attribute_values);
				else if ( g_ascii_strcasecmp (*attribute_names, "y") == 0 )
					object_point->y = atoi(*attribute_values);
			}

			if ( object_point->x > object_display->w )
			{
				object_display->w  = object_point->x;
			}
			if ( object_point->y > object_display->h )
			{
				object_display->h  = object_point->y;
			}

			object_display->shape = g_slist_append( object_display->shape, object_point );
		}
	}
	else
	{
		/* Root Element */
		if ( g_ascii_strcasecmp( element_name, "settings" ) == 0 )
		{
			map_info->parse_mode = MPM_SETTING;
		}
		else if ( g_ascii_strcasecmp( element_name, "object" ) == 0 )
		{
			map_info->parse_mode = MPM_OBJECT;

			/* Created Display Object */
			DisplayObject * object_display = g_new0(DisplayObject, 1);

			object_display->supports_path = TRUE;
			object_display->type = DT_NONE;
			object_display->layer = 1;
			object_display->rotate = 0;
			object_display->flip = 0;

			object_display->colour.red = 1.0;
			object_display->colour.green = 1.0;
			object_display->colour.blue = 1.0;
			object_display->colour.alpha = 1.0;


			object_display->id = map_info->id_counter++;

			/*  */
			if ( map_info->file_type == 0 )
			{
				MokoiMapObject * map_object = g_new0(MokoiMapObject, 1);

				map_object->parent = map_info;
				map_object->settings = g_hash_table_new(g_str_hash, g_str_equal);

				for (; *attribute_names && *attribute_values; attribute_names++, attribute_values++)
				{
					if ( g_ascii_strcasecmp(*attribute_names, "type") == 0 )
						map_object->type = MapObject_Type(*attribute_values);
					else if ( g_ascii_strcasecmp (*attribute_names, "value") == 0 )
						map_object->name = g_strdup(*attribute_values);
					else if ( g_ascii_strcasecmp(*attribute_names, "id") == 0 )
						map_object->object_id = g_strdup(*attribute_values);
					else if ( g_ascii_strcasecmp(*attribute_names, "parent") == 0 )
						g_hash_table_insert( map_object->settings, (gpointer)g_strdup(*attribute_names), RuntimeSetting_New(g_strdup(*attribute_values), "hidden") );
					else if ( g_ascii_strcasecmp(*attribute_names, "global") == 0 )
						g_hash_table_insert( map_object->settings, (gpointer)g_strdup(*attribute_names), RuntimeSetting_New(g_strdup(*attribute_values), "hidden") );
				}

				if ( map_object->type == 't' )
				{
					g_hash_table_insert( map_object->settings, "number", RuntimeSetting_New("-1", "hidden") );
				}

				map_object->object = object_display;
				mokoi_map_info->objects = g_list_append(mokoi_map_info->objects, (gpointer*)map_object);

			}
			else if ( map_info->file_type == 1 )
			{
				VirtualObject * virtual_object = g_new0(VirtualObject, 1);


				for (; *attribute_names && *attribute_values; attribute_names++, attribute_values++)
				{
					if ( g_ascii_strcasecmp(*attribute_names, "type") == 0 )
						virtual_object->type = MapObject_Type(*attribute_values);
					else if ( g_ascii_strcasecmp (*attribute_names, "value") == 0 )
						virtual_object->name = g_strdup(*attribute_values);
					else if ( g_ascii_strcasecmp(*attribute_names, "id") == 0 )
						virtual_object->ident = g_strdup(*attribute_values);

				}

				virtual_object->object = object_display;
				virtual_object_list->objects = g_list_append(virtual_object_list->objects, (gpointer*)virtual_object);
				//map_info->displayList = g_list_append(map_info->displayList, (gpointer*)object_display);

				object_display->id = virtual_object_list->id_count++;
			}
		}
		else
		{

		}
	}
}

/********************************
* map_parse_handler_end
*
*/
void map_parse_handler_end( GMarkupParseContext * context, const gchar *element_name, gpointer user_data, GError **error )
{
	MapInfo * map_info = (MapInfo *)user_data;
	if ( g_ascii_strcasecmp( element_name, "settings" ) == 0 )
	{
		map_info->parse_mode = MPM_ROOT;
	}
	else if ( g_ascii_strcasecmp (element_name, "object") == 0 )
	{
		map_info->parse_mode = MPM_ROOT;
	}
	else if ( g_ascii_strcasecmp (element_name, "path") == 0 )
	{
		map_info->parse_mode = MPM_OBJECT;
	}
}

/********************************
* Map_ParseXML
*
@ map:
*/
gboolean Map_ParseXML( MapInfo * map_info, gchar * content )
{
	GError * error  = NULL;
	GMarkupParseContext * ctx;

	ctx = g_markup_parse_context_new( &map_parser_xml, (GMarkupParseFlags)0, map_info, NULL );
	if ( g_markup_parse_context_parse( ctx, content, -1, &error ) )
	{
		g_markup_parse_context_end_parse( ctx, NULL );
	}
	else
	{
		Meg_Error_Print( __func__, __LINE__, "Parsing setting error. Reason: %s", error->message );
		g_clear_error(&error);
	}
	g_markup_parse_context_free( ctx );

	return TRUE;
}


/********************************
* Map_GetDimensions
*
@ file:
@ width:
@ height:
*/
gboolean Map_GetDimensions( gchar * file, gint  * width, gint * height )
{
	GdkRectangle rect = { 0, 0, 1, 1 };
	GMarkupParseContext * ctx;
	gchar * content = NULL;
	gchar * dest = g_strdup_printf( "/maps/%s.xml", file );

	if ( Meg_file_get_contents( dest, &content, NULL, NULL ) )
	{
		ctx = g_markup_parse_context_new( &map_dimension_parser, (GMarkupParseFlags)0, &rect, NULL );
		g_markup_parse_context_parse( ctx, content, -1, NULL );
		g_markup_parse_context_end_parse( ctx, NULL );
		g_markup_parse_context_free( ctx );
	}

	*width = rect.width;
	*height = rect.height;

	g_free( dest );

	return TRUE;

}
