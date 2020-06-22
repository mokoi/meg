# megaudio make file
# Build Options
# BUILDOS - windows, linux, apple
# OPTIMIZE - FULL, SOME, NONE
# BUILDDEBUG - TRUE, FALSE
# CC (Compiler)
# INSTALLDIR (Path to install files to, when running make install)
# BIN (Binary output)

#Default Settings
include ../setting.mk
BIN = libmegaudio.so

#Compiled Files
OBJDIR = $(OBJECTDIR)-$(BUILDMODE)-$(PLATFORMOS)-$(PLATFORMPROCESSOR)
OBJ = $(OBJDIR)/main.o

#Read platform and custom settings
include makefiles/$(PLATFORMOS).make
ifneq ($(CUSTOMSETTINGS), )
	include custom/$(CUSTOMSETTINGS).make
endif

#Extras Platform Objects
OBJ += $(PLATFORM_OBJECTS)

#Compiler
PROJECT_FLAGS += -I"include" -I"src" -I"src/physfs" -DPHYSFS_NO_CDROM_SUPPORT=1 -DPHYSFS_SUPPORTS_MOKOIRESOURCE=1 -DPHYSFS_SUPPORTS_ZIP=1
COMPILER_FLAGS += -DPLATFORM_$(PLATFORMOSUC) -DPLATFORM_BITS=$(PLATFORMBITS) -DPLATFORM_ARCH=$(PLATFORMPROCESSOR) $(PROJECT_FLAGS) $(PLATFORM_FLAGS)
COMPILER_LIBS += $(PLATFORM_LIBS)

#Build
.PHONY: all-before all clean

all: all-before $(BIN) $(FINALOUTPUT)
	@echo --------------------------------

all-before:
	@$(MKDIR) $(OBJDIR)
	@echo --------------------------------
	@echo Building $(BIN) $(PROGRAM_VERSION)
	@echo Build Platform: $(BUILDPLATFORM) $(BUILDMACHINE)
	@echo Target Platform: $(PLATFORMOS)/$(PLATFORMPROCESSOR)
	@echo Build Mode: $(BUILDMODE)
	@echo Build C Flags: $(COMPILER_FLAGS)
	@echo Build Libs: $(COMPILER_LIBS)


$(BIN): $(OBJ)
	@echo --------------------------------
	@$(MKDIR) $(BUILDDIR)
	@$(CPP) $(OBJ) -o $(BUILDDIR)/$(BIN) $(COMPILER_LIBS)

install: $(BIN)
	@echo Installing $< to $(INSTALLDIR)
	@-$(MKDIR) $(dir $@)
	@cp $(BUILDDIR)/$(BIN)  $(INSTALLDIR)/bin/

clean: 
	$(RM) $(OBJ) $(BUILDDIR)/$(BIN)

$(OBJDIR)/%.o : src/%.c
	@echo Compiling $@ $(MESSAGE)
	@-$(MKDIR) $(dir $@)
	@$(CC) -c $(COMPILER_FLAGS) -o $@ $<

