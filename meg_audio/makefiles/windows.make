ifeq ($(SUPPORTPATH), )
	SUPPORTPATH = C:/dev/msys64/mingw64
endif

BIN = libmegaudio.dll
MKDIR = mkdir.cmd
PLATFORM_LIBS = -shared -L"$(SUPPORTPATH)/lib" -lglib-2.0.dll -lSDL2 -lSDL2_mixer 
PLATFORM_FLAGS = -I"$(SUPPORTPATH)/include/SDL2" -I"$(SUPPORTPATH)/include" -I"$(SUPPORTPATH)/include/glib-2.0" -I"$(SUPPORTPATH)/lib/glib-2.0/include" -D_CRT_SECURE_NO_WARNINGS
