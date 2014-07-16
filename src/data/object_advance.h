/****************************
Copyright © 2007-2014 Luke Salisbury
This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
****************************/

#ifndef OBJECT_ADVANCE_H
	#define OBJECT_ADVANCE_H

	gboolean ObjectAdvance_Sprite( DisplayObject * object, GtkWindow * window );
	gboolean ObjectAdvance_Text( DisplayObject * object, GtkWindow * window );
	gboolean ObjectAdvance_Shape( DisplayObject * object, GtkWindow * window );
	gboolean ObjectAdvance_Line(DisplayObject * object, GtkWindow * window );
	gboolean ObjectAdvance_File( DisplayObject * object, GtkWindow * window );
	gboolean ObjectAdvance_Polygon( DisplayObject * object, GtkWindow * window );

#endif
