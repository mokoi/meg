# Mokoi Editor (Gtk) make file
# Build Options
# BUILDOS - windows, linux, apple
# OPTIMIZE - FULL, SOME, NONE
# BUILDDEBUG - TRUE, FALSE
# PLATFORMBITS 64, 32
# CC (Compiler)
# BIN (Binary output)

#Default Settings
include setting.mk

#Compiled Files
OBJDIR = $(OBJECTDIR)-$(BUILDMODE)-$(PLATFORMOS)-$(PLATFORMPROCESSOR)
include files.mk

#Read platform and custom settings
include makefiles/$(PLATFORMOS).make
ifneq ($(CUSTOMSETTINGS), )
	include custom/$(CUSTOMSETTINGS).make
endif

#Compiler
PROJECT_FLAGS += -I"src/libs" -I"include" -I"src" -I"src/physfs" -DPHYSFS_NO_CDROM_SUPPORT=1 -DPHYSFS_SUPPORTS_MOKOIRESOURCE=1 -DPHYSFS_SUPPORTS_ZIP=1
COMPILER_FLAGS += -DPLATFORM_$(PLATFORMOSUC) -DPLATFORM_BITS=$(PLATFORMBITS) -DPLATFORM_ARCH=$(PLATFORMPROCESSOR) $(PROJECT_FLAGS) $(PLATFORM_FLAGS)
COMPILER_LIBS += $(PLATFORM_LIBS)

#Extras Platform Objects
OBJ += $(PLATFORM_OBJECTS)

# UI header
UI = $(wildcard res/ui/*.gui)
UIH = include/ui_resources.h

#Build
.PHONY: all-before all clean modules


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

clean:
	@echo Clean up $(BIN)
	@${RM} $(OBJ) $(BIN)  $(UIH)
ifneq ($(SKIP_MODULES), TRUE)
	@$(MAKE) -C meg_audio clean BUILDDIR=$(CURDIR)/$(BUILDDIR)
	@$(MAKE) -C meg_pawn clean BUILDDIR=$(CURDIR)/$(BUILDDIR)
endif


# Resource Headers
$(UIH): $(UI)
	@$(MKDIR) $(OBJDIR)
	@echo --------------------------------
	@echo Converting UI to Header

ifneq ($(SKIP_HEADER), TRUE)
	@$(CC) -o $(OBJDIR)/buildheaderfile.exe buildheaderfile.c
	@$(OBJDIR)/buildheaderfile.exe res/ui/ $(UIH)
	@${RM} $(OBJDIR)/buildheaderfile.exe
else
$(warning Skipping UI header compiling, Debug version will use file version of UI);
endif




$(OBJDIR)/%.o: src/%.c $(UIH)
	@echo Compiling $@ $(MESSAGE)
	@-$(MKDIR) $(dir $@)
	@$(CC) -c $(COMPILER_FLAGS) -o $@ $<

modules:
ifneq ($(SKIP_MODULES), TRUE)
	@echo Building Modules
	@$(MAKE) -C meg_audio all BUILDDIR=$(CURDIR)/$(BUILDDIR)
	@$(MAKE) -C meg_pawn all BUILDDIR=$(CURDIR)/$(BUILDDIR)
else
$(warning Skipping Modules. Audio Playback and Script Compiling may not work);
endif

buildmodules:
	@echo --------------------------------
	@echo Building Modules
	@$(MAKE) -C meg_audio all BUILDDIR=$(CURDIR)/$(BUILDDIR)
	@$(MAKE) -C meg_pawn all BUILDDIR=$(CURDIR)/$(BUILDDIR)

cleanmodules:
	@echo --------------------------------
	@echo Cleaning Modules
	@$(MAKE) -C meg_audio clean BUILDDIR=$(CURDIR)/$(BUILDDIR)
	@$(MAKE) -C meg_pawn clean BUILDDIR=$(CURDIR)/$(BUILDDIR)

installmodules:
	@echo --------------------------------
	@echo Installing Modules
	@$(MAKE) -C meg_audio install BUILDDIR=$(CURDIR)/$(BUILDDIR) INSTALLDIR=$(CURDIR)/$(INSTALLDIR)
	@$(MAKE) -C meg_pawn install BUILDDIR=$(CURDIR)/$(BUILDDIR) INSTALLDIR=$(CURDIR)/$(INSTALLDIR)

$(BIN): $(UIH) modules $(OBJ)
	@echo --------------------------------
	@echo Building $(BIN) $(MESSAGE)
	@-$(MKDIR) $(BUILDDIR)
	@$(CC) $(OBJ) -o $(BUILDDIR)/$(BIN) $(COMPILER_LIBS)

install: $(BIN)
	@echo Installing $< to $(INSTALLDIR)
	@-$(MKDIR) $(INSTALLDIR)
	@-$(MKDIR) $(INSTALLDIR)/bin/
	@cp $(BUILDDIR)/$(BIN) $(INSTALLDIR)/bin/
	@cp -r ./share/ $(INSTALLDIR)/
ifneq ($(SKIP_MODULES), TRUE)
	@$(MAKE) -C meg_audio install BUILDDIR=$(CURDIR)/$(BUILDDIR) INSTALLDIR=$(CURDIR)/$(INSTALLDIR)
	@$(MAKE) -C meg_pawn install BUILDDIR=$(CURDIR)/$(BUILDDIR) INSTALLDIR=$(CURDIR)/$(INSTALLDIR)
endif

