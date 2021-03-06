PLATFORM = LINUX

PLATFORM_LIBS =
PLATFORM_FLAGS =
GTKVERSION = error

ifeq (${shell pkg-config gtk+-3.0 --exists && echo 1}, 1)
	GTKVERSION = gtk+-3.0
	GTKPACKAGES = gtk+-3.0 gmodule-2.0 gthread-2.0
	ifeq (${shell pkg-config libcurl --exists && echo 1}, 1)
		PLATFORM_FLAGS += -DUSE_CURL
		GTKPACKAGES += libcurl
	else
$(warning Curl not found. Will not be able to access internet features.)
	endif

	ifeq (${shell pkg-config gtksourceview-3.0 --exists && echo 1}, 1)
		GTKPACKAGES += gtksourceview-3.0
		PLATFORM_FLAGS += -DUSEGTKSOURCEVIEW
	else

$(warning GtkSourceView not found. Syntax highlighting disabled. )

	endif
else
	ifeq (${shell pkg-config gtk+-2.0 --exists && echo 1}, 1)
			GTKVERSION = gtk+-2.0
			GTKPACKAGES = gtk+-2.0 gmodule-2.0 gthread-2.0
			ifeq ( ${shell pkg-config libcurl --exists && echo 1}, 1)
				PLATFORM_FLAGS += -DUSE_CURL
				GTKPACKAGES += libcurl
			else
$(warning Curl not found. Will not be able to access internet features.)
			endif

			ifeq (${shell pkg-config gtksourceview-2.0 --exists && echo 1}, 1)
				GTKPACKAGES += gtksourceview-2.0
				PLATFORM_FLAGS += -DUSEGTKSOURCEVIEW
			else
$(warning GtkSourceView not found. Syntax highlighting disabled. )
			endif
	endif

endif

PLATFORM_FLAGS += `pkg-config $(GTKPACKAGES) --cflags` -Dunix
PLATFORM_LIBS += `pkg-config $(GTKPACKAGES) --libs`


#used for builderheader
MINI_PLATFORM_LIBS = `pkg-config $(GTKVERSION) --libs`
MINI_PLATFORM_FLAGS = `pkg-config $(GTKVERSION) --cflags`

RES =
CC = gcc

BIN = meg

ifeq ($(GTKVERSION), error)
$(error GTK+ is required. Please install it via your Package Manager )
else
$(info Gtk Version $(GTKVERSION))

endif


#installdeps-gtk2:
#	apt-get install libgtk2.0-dev libgtksourceview-2.0-dev libcurl-dev

#installdeps-gtk3:
#	apt-get install libgtk-3-dev libgtksourceview-3.0-dev libcurl-dev
