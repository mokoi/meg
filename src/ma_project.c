/****************************
Copyright © 2007-2014 Luke Salisbury
This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
****************************/

/* Global Header */
#include "global.h"
#include "ma_project.h"

/* GtkWidget */
GtkWidget * meg_project_title = NULL;
GtkWidget * meg_project_path = NULL;

/* Local Variables */
extern gchar * project_file_path;

/* External Functions */
void MegWidget_Project_EditSetting( GtkCellRendererText *cellrenderertext, gchar *path_string, gchar *new_text, gpointer user_data );
void Project_Publish( GtkButton *button, gpointer user_data);
void MegWidget_Project_Refresh( GtkWidget * widget, gpointer user_data );
void AL_Settings_RefreshAdvance( void );

/* UI */


/********************************
* MegWidget_Project_Create
* Creates the Project Page Widget
*/
void MegWidget_Project_Create()
{
	GtkWidget * widget;
	GtkListStore * advance = NULL;

	GtkBuilder * ui = Meg_Builder_Load("page_project", __func__, __LINE__);
	g_return_if_fail( ui );


	widget = GET_WIDGET( ui, "alchera_project_widget");

	meg_project_path = GET_WIDGET( ui, "project_path");
	advance = GET_LISTSTORE( ui, "meg_settings_advance_store" ); /* G_TYPE_STRING, G_TYPE_STRING, G_TYPE_BOOLEAN */

	/* Signal */
	g_signal_connect( widget, "realize", G_CALLBACK(MegWidget_Project_Refresh), advance );

	SET_OBJECT_SIGNAL( ui, "meg_advance_value", "edited", G_CALLBACK(MegWidget_Project_EditSetting), advance);
	SET_OBJECT_SIGNAL( ui, "alchera_project_config", "button-press-event", G_CALLBACK(MegWidget_Project_Menu_Click), advance);
	SET_OBJECT_SIGNAL( ui, "alchera_project_config", "popup-menu", G_CALLBACK(MegWidget_Project_Menu_Button), advance);
	SET_OBJECT_SIGNAL( ui, "alchera_project_config", "realize", G_CALLBACK(AL_Settings_RefreshAdvance), advance);

	//SET_OBJECT_SIGNAL( ui, "publish_button", "clicked", G_CALLBACK(Project_Publish), NULL );

	AL_Setting_Widget( ui );

	/* tab settings */
	g_object_set_data( G_OBJECT(widget), "meg-help-page", g_strdup("Editor/Project.xml") );
	Meg_Main_AddSection( widget, "Settings", PAGE_ICON_PROJECT );
}

/********************************
* MegWidget_Project_Init
* Initialises Project Page
*/
void MegWidget_Project_Init()
{
	gtk_label_set_label(GTK_LABEL(meg_project_path), project_file_path);
}

/********************************
* MegWidget_Project_Refresh
*
*/
void MegWidget_Project_Refresh( GtkWidget * widget, gpointer user_data )
{
	AL_Settings_Refresh();
}

/********************************
* MegWidget_Project_Close
*
*/
void MegWidget_Project_Close()
{
	gtk_label_set_label(GTK_LABEL(meg_project_path), "");
	AL_Settings_Clear();
}


