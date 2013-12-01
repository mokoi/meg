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

/* Required Headers */
#include "animation.h"
#include "animation_functions.h"
#include "sheets_functions.h"

/* External Functions */
gboolean Sheet_SaveFile( MokoiSheet * sheet );
/* Local Type */

/* Global Variables */
extern GSList * mokoiSpritesheets;

/* Local Variables */


/* UI */
#include "ui/animation_advance.gui.h"
const gchar * mokoiUI_AnimationAdvance = GUIANIMATION_ADVANCE


/********************************
* Animation_AdvanceDialog
*
*/
gboolean Animation_AdvanceDialog( MokoiSheet * sheet, MokoiSprite * sprite )
{
	/* Check if the the Sprite contains a animation. */
	if ( sprite->animation == NULL )
	{
		return FALSE;
	}

	if ( !sprite->animation->image_loaded )
	{
		SpriteAnimation_Build(sprite);
	}

	GtkTreeIter iter;
	GtkListStore * store_frames;
	GtkWidget * dialog, * entry_name, * check_visible, * tree_frames, * spin_mask, * file_mask, * image_preview, * image_group, * file_entity, *area_framepreview, * button_entitysettings, * button_play;
	GObject * spin_frame_x, * spin_frame_y, * spin_frame_time;

	/* UI */
	GtkBuilder * ui = Meg_Builder_Create(mokoiUI_AnimationAdvance, __func__, __LINE__);
	g_return_val_if_fail( ui, FALSE );

	/* Widget */
	dialog = GET_WIDGET( ui, "dialog");

	/* Detail Tab */
	entry_name = GET_WIDGET( ui, "entry_name" );
	check_visible = GET_WIDGET( ui, "check_visible" );
	spin_mask = GET_WIDGET( ui, "spin_mask");
	file_mask = GET_WIDGET( ui, "combo_maskfile");
	image_preview = GET_WIDGET( ui, "image_preview");

	/* Frame Tab */
	area_framepreview = GET_WIDGET( ui, "area_framepreview");
	tree_frames = GET_WIDGET( ui, "tree_frames");
	store_frames = GET_LISTSTORE( ui, "store_frames" );
	spin_frame_x = gtk_builder_get_object( ui, "spin_frame_x");
	spin_frame_y = gtk_builder_get_object( ui, "spin_frame_y");
	spin_frame_time = gtk_builder_get_object( ui, "spin_frame_time");
	button_play = GET_WIDGET( ui, "button_play");

	/* Entity Tab */
	file_entity = GET_WIDGET( ui, "combo_entities");
	button_entitysettings = GET_WIDGET( ui, "button_entitysettings");


	/* Grouping Tab */
	image_group = GET_WIDGET( ui, "image_group");
/*
	area_grouptopleft = SpriteGrouping_GetWidget(  ui, "area_grouptopleft", sheet, sprite, 0 );
	area_grouptop = SpriteGrouping_GetWidget(  ui, "area_grouptop", sheet, sprite, 1 );
	area_grouptopright = SpriteGrouping_GetWidget(  ui, "area_grouptopright", sheet, sprite, 2 );
	area_groupright = SpriteGrouping_GetWidget(  ui, "area_groupright", sheet, sprite, 3 );
	area_groupbottomright = SpriteGrouping_GetWidget(  ui, "area_groupbottomright", sheet, sprite, 4 );
	area_groupbottom = SpriteGrouping_GetWidget(  ui, "area_groupbottom", sheet, sprite, 5 );
	area_groupbottomleft = SpriteGrouping_GetWidget(  ui, "area_groupbottomleft", sheet, sprite, 6 );
	area_groupleft = SpriteGrouping_GetWidget(  ui, "area_groupleft", sheet, sprite, 7 );
*/
	SpriteGrouping_GetWidget(  ui, "area_grouptopleft", sheet, sprite, 0 );
	SpriteGrouping_GetWidget(  ui, "area_grouptop", sheet, sprite, 1 );
	SpriteGrouping_GetWidget(  ui, "area_grouptopright", sheet, sprite, 2 );
	SpriteGrouping_GetWidget(  ui, "area_groupright", sheet, sprite, 3 );
	SpriteGrouping_GetWidget(  ui, "area_groupbottomright", sheet, sprite, 4 );
	SpriteGrouping_GetWidget(  ui, "area_groupbottom", sheet, sprite, 5 );
	SpriteGrouping_GetWidget(  ui, "area_groupbottomleft", sheet, sprite, 6 );
	SpriteGrouping_GetWidget(  ui, "area_groupleft", sheet, sprite, 7 );


	/* Settings */
	sprite->animation->model = GTK_TREE_MODEL(store_frames);

	AnimationPreview * anim_data = g_new0(AnimationPreview, 1);
	anim_data->widget = area_framepreview;
	anim_data->parent = g_strdup(sprite->parent);

	g_object_set_data( G_OBJECT(tree_frames), "mokoisheet", (gpointer)sprite->parent );
	g_object_set_data( spin_frame_x, "my_column_num", GUINT_TO_POINTER(2) );
	g_object_set_data( spin_frame_y, "my_column_num", GUINT_TO_POINTER(3) );
	g_object_set_data( spin_frame_time, "my_column_num", GUINT_TO_POINTER(4) );
	g_object_set_data( G_OBJECT(button_play), "AnimationPreview", (gpointer)anim_data );


	/* Signal */
	g_signal_connect( tree_frames, "button-press-event", G_CALLBACK(Animation_MouseMenu), store_frames);
	g_signal_connect( tree_frames, "popup-menu", G_CALLBACK(Animation_PopupMenu), store_frames);
	g_signal_connect( tree_frames, "query-tooltip", G_CALLBACK(Animation_Tooltip), NULL);

#if GTK_MAJOR_VERSION == 2
	g_signal_connect( area_framepreview, "expose-event", G_CALLBACK(Animation_Preview_Update), anim_data );
#else
	g_signal_connect( area_framepreview, "draw", G_CALLBACK(Animation_Preview_Draw), anim_data );
#endif

	g_signal_connect( button_entitysettings, "button-press-event", G_CALLBACK(EntityCombo_Properties_Open), file_entity );
	g_signal_connect( button_play, "button-press-event", G_CALLBACK(Animation_Preview_Pressed), sprite );
	g_signal_connect( spin_frame_x, "edited", G_CALLBACK(Animation_ChangePosition), store_frames);
	g_signal_connect( spin_frame_y, "edited", G_CALLBACK(Animation_ChangePosition), store_frames);
	g_signal_connect( spin_frame_time, "edited", G_CALLBACK(Animation_ChangePosition), store_frames);


	/* Set Default Values */
	gtk_entry_set_text( GTK_ENTRY(entry_name), sprite->detail->name );

	Meg_ComboFile_Scan( file_mask, "masks",  ".pgm", TRUE, 0 );
	Meg_ComboFile_Scan( file_entity, "scripts",  ".mps", TRUE, 0 );

	if ( sprite->mask )
	{
		if ( sprite->mask->name != NULL )
		{
			Meg_ComboText_SetIndex( GTK_COMBO_BOX(file_mask), sprite->mask->name);
		}
		else
		{
			gtk_spin_button_set_value( GTK_SPIN_BUTTON(spin_mask), (gdouble) sprite->mask->value );
		}
	}
	else
	{
		sprite->mask = g_new0(MokoiMask, 1);
	}

	if ( sprite->entity )
	{
		Meg_ComboText_SetIndex( GTK_COMBO_BOX(file_entity), sprite->entity );
	}

	gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON(check_visible), sprite->visible );

	if (sprite->image)
	{
		gtk_image_set_from_pixbuf( GTK_IMAGE(image_group), sprite->image );
	}

	/*
	if ( sprite->animation->image )
	{
	   gtk_image_set_from_animation( GTK_IMAGE(image_preview), (GdkPixbufAnimation*)sprite->animation->image );
	}
	*/
	/* Set Frames to treeview */
	GSList * frames = sprite->animation->frames;
	if ( store_frames )
	{
		while( frames )
		{
			MokoiAnimationFrame * current_frame = (MokoiAnimationFrame *)frames->data;
			if ( current_frame )
			{
				GdkPixbuf * pixbuf = Sprite_GetPixbuf( current_frame->sprite, sprite->parent );
				/* frame, image, x, y, ms */

				gtk_list_store_append( store_frames, &iter );
				gtk_list_store_set( store_frames, &iter, 0, g_strdup(current_frame->sprite), 1, pixbuf, 2, current_frame->offset.x, 3, current_frame->offset.y, 4, current_frame->length_ms, -1 );
			}
			frames = g_slist_next( frames );
		}
	}
	else
	{
		Meg_Error_Print( __func__, __LINE__, "Missing ListStore" );
	}

	gtk_widget_show_all( gtk_dialog_get_content_area( GTK_DIALOG(dialog) ) );
	gtk_window_set_transient_for( GTK_WINDOW(dialog), Meg_Main_GetWindow() );

	if ( gtk_dialog_run( GTK_DIALOG (dialog) ) == GTK_RESPONSE_APPLY)
	{
		const gchar * sprite_name;
		gchar * mask_filename, * entity_filename;

		sprite_name = gtk_entry_get_text( GTK_ENTRY(entry_name) );
		mask_filename = Meg_ComboText_GetText( GTK_COMBO_BOX(file_mask) );
		entity_filename = Meg_ComboText_GetText( GTK_COMBO_BOX(file_entity) );

		if ( !sprite_name )
			Meg_Error_Print( __func__, __LINE__, "Mokoi_Sprite_AdvanceSprite: No name given");
		else if ( !g_utf8_strlen(sprite_name,-1) )
			Meg_Error_Print( __func__, __LINE__, "Mokoi_Sprite_AdvanceSprite: No name given");
		else
		{
			Sprite_Clear( sprite );

			sprite->detail->name = g_strdup( sprite_name );
			sprite->ident = g_strdup_printf( "%s:%s", sprite->parent, sprite->detail->name );

			if ( mask_filename )
				sprite->mask->name = g_strdup( mask_filename );
			else
				sprite->mask->value = gtk_spin_button_get_value_as_int( GTK_SPIN_BUTTON(spin_mask) );

			if ( entity_filename )
				sprite->entity = g_strdup( entity_filename );


			sprite->visible = gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON(check_visible) );

			gboolean valid;
			valid = gtk_tree_model_get_iter_first( GTK_TREE_MODEL(store_frames), &iter );

			if ( valid )
			{
				/* update the animation details */
				g_slist_free( sprite->animation->frames );
				sprite->animation->frames = NULL;
				while ( valid )
				{
					MokoiAnimationFrame * new_frame = g_new0( MokoiAnimationFrame, 1 );

					gtk_tree_model_get( GTK_TREE_MODEL(store_frames), &iter, 0, &new_frame->sprite, 2, &new_frame->offset.x, 3, &new_frame->offset.y, 4, &new_frame->length_ms, -1);

					sprite->animation->frames = g_slist_append( sprite->animation->frames, new_frame );

					valid = gtk_tree_model_iter_next( GTK_TREE_MODEL(store_frames), &iter );
				}
			}
			SpriteAnimation_Build( sprite );
			Sheet_SaveFile( sheet );
		}
	}
	SpriteAnimation_Clear( anim_data );
	gtk_widget_destroy( dialog );
	return TRUE;
}

