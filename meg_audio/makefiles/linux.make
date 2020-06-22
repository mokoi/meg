
PLATFORM = LINUX

PLATFORM_LIBS = `sdl2-config --libs` -lSDL2_mixer
PLATFORM_FLAGS = `sdl2-config --cflags`
GTKPACKAGES = error

ifeq (${shell pkg-config gtk+-2.0 --exists && echo 1}, 1)
	GTKPACKAGES = gtk+-2.0 
endif

ifeq (${shell pkg-config gtk+-3.0 --exists && echo 1}, 1)
	GTKPACKAGES = gtk+-3.0 
endif

PLATFORM_FLAGS += `pkg-config $(GTKPACKAGES) --cflags` -fPIC
PLATFORM_LIBS += -shared `pkg-config $(GTKPACKAGES) --libs`
