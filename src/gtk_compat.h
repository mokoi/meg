/****************************
Copyright © 2013-2014 Luke Salisbury
This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
****************************/

#ifndef _GTK_COMPAT_H_
#define _GTK_COMPAT_H_

#include <gtk/gtk.h>

#ifndef GDK_BUTTON_PRIMARY
#define GDK_BUTTON_PRIMARY      (1)
#endif
#ifndef GDK_BUTTON_SECONDARY
#define GDK_BUTTON_SECONDARY    (3)
#endif


#ifndef GdkNativeWindow
#define GdkNativeWindow      gpointer
#endif


#if GTK_MAJOR_VERSION == 2
typedef struct {
  gdouble red;
  gdouble green;
  gdouble blue;
  gdouble alpha;
} GdkRGBA;

void gdk_cairo_set_source_rgba( cairo_t * cr, const GdkRGBA * rgba );
GdkPixbuf * gdk_pixbuf_get_from_surface( cairo_surface_t *surface, gint src_x, gint src_y,  gint width, gint height);
GtkWidget * gtk_box_new( GtkOrientation orientation, gint spacing );

#endif

#if !GLIB_CHECK_VERSION(2,32,0)
GThread * g_thread_try_new( const gchar *name, GThreadFunc func, gpointer data, GError **error);
#endif

#if !GLIB_CHECK_VERSION(2,28,0)
void g_slist_free_full( GSList * list, GDestroyNotify free_func);
void g_list_free_full( GList * list, GDestroyNotify free_func);
#endif


#define BUTTON_STOCK_CANCEL "_Cancel"
#define BUTTON_STOCK_OPEN "_Open"
#define BUTTON_STOCK_OK "_OK"
#define BUTTON_STOCK_HELP "_Help"
#define BUTTON_STOCK_YES "gtk-yes"
#define BUTTON_STOCK_NO "gtk-no"
#define BUTTON_STOCK_CLOSE "gtk-close"
#define BUTTON_STOCK_ADD "gtk-add"
#define BUTTON_STOCK_REMOVE "gtk-remove"
#define BUTTON_STOCK_MISSING_IMAGE "broken-image"
#define BUTTON_STOCK_STOP "gtk-stop"
#define BUTTON_STOCK_SAVE "gtk-save"
#define BUTTON_STOCK_MEDIA_PLAY "gtk-media-play"
#define BUTTON_STOCK_MEDIA_PAUSE "gtk-media-pause"
#define BUTTON_STOCK_MEDIA_STOP "gtk-media-stop"

#endif
