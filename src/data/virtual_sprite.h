/****************************
Copyright © 2007-2014 Luke Salisbury
This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
****************************/
#ifndef _VIRTUAL_SPRITE_H_
	#define _VIRTUAL_SPRITE_H_

	#include "loader_global.h"

	Spritesheet * VirtualSpriteSheet_Get( gboolean update_sprite_image );
	gboolean VirtualSpriteSheet_Insert(gchar * file_name , gboolean visible);

	void VirtualSprite_UpdateName( GtkLabel * label, MapInfo * map_info );
	void VirtualSprite_Save( GtkButton * button, MapInfo * map_info );
	MapInfo * VirtualSprite_GetInfo( gchar * id );
	GdkPixbuf *  VirtualSprite_BuildPixbuf( gchar * id );
#endif
