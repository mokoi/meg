#Build options
USE_GTKSOURCEVIEW=FALSE
USE_SOUP=FALSE
USE_CURL=FALSE

#Base Setting, so variables aren't empty
CPP=g++
CC=gcc
MAKE=make
MKDIR=mkdir -p
RM=rm -f
MESSAGE =

BIN=meg
INSTALLDIR=/opt/mokoi

OBJECTDIR=./obj
SRCDIR=./src
BUILDDIR?=./bin

#
BUILDDEBUG?=TRUE
PLATFORMPROCESSOR?=32
PLATFORMBITS?=unknown

#Build platform & target platform
BUILDPLATFORM=$(strip ${shell uname})
BUILDMACHINE=$(strip ${shell uname -m})
BUILDMODE=release

ifeq ($(PLATFORMOS), ) # No traget platform set, so we guess and build for that
	PLATFORMOS=windows
	ifeq ($(BUILDPLATFORM), Linux)
		PLATFORMOS	= linux
	endif
	ifeq ($(BUILDPLATFORM), Windows)
		PLATFORMOS	= windows
	endif
	ifeq ($(BUILDPLATFORM), Apple)
		PLATFORMOS	= apple
	endif
	ifeq ($(BUILDPLATFORM), Darwin)
		PLATFORMOS	= apple
	endif
	ifeq ($(BUILDPLATFORM), Haiku)
		PLATFORMOS	= haiku
	endif

	#Plaform bits
	ifeq ($(BUILDMACHINE), x86_64)
		PLATFORMBITS=64
		PLATFORMPROCESSOR=x86_64
	endif
	ifeq ($(BUILDMACHINE), x86)
		PLATFORMBITS=32
		PLATFORMPROCESSOR=x86
	endif
	ifeq ($(BUILDMACHINE), i686)
		PLATFORMBITS=32
		PLATFORMPROCESSOR=x86
	endif
	ifeq ($(BUILDMACHINE), i386)
		PLATFORMBITS=32
		PLATFORMPROCESSOR=x86
	endif
endif

PLATFORMOSUC= ${shell echo $(PLATFORMOS) | tr 'a-z' 'A-Z'}

ifeq ($(OPTIMIZE), FULL)
	OPTIMIZER=-O3
else
	ifeq ($(OPTIMIZE), SOME)
		OPTIMIZER=-O1
	else
		ifeq ($(OPTIMIZE), NONE)
			OPTIMIZER=-O0 -DNDEBUG
		else
			OPTIMIZER=
		endif
	endif

endif

ifeq ($(BUILDDEBUG), TRUE)
	DEBUG=-g
	OPTIMIZER=-O0 -Wall -DDEBUG -Wformat -Wno-unused-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls
	MESSAGE= with debugging support
	HASDEBUG=Yes
	BUILDMODE=debug
else
	HASDEBUG=No
	ifneq ($(OPTIMIZE), NONE)
		OPTIMIZER+= -DNDEBUG -Wformat
	endif
endif

#Compiler
COMPILER_LIBS= $(OPTIMIZER) $(DEBUG) -lz $(LDFLAGS)
COMPILER_FLAGS+= $(OPTIMIZER) $(DEBUG) $(CFLAGS)

ifeq ($(PLATFORMBITS), 64)
	COMPILER_FLAGS += -m64
	COMPILER_LIBS += -m64
endif
ifeq ($(PLATFORMBITS), 32)
	COMPILER_FLAGS += -m32
	COMPILER_LIBS += -m32
endif



