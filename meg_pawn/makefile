# pawn comiler make file
# Build Options
# BUILDOS - windows, linux, apple
# OPTIMIZE - FULL, SOME, NONE
# BUILDDEBUG - TRUE, FALSE
# PLATFORMBITS 64, 32
# CC (Compiler)
# BIN (Binary output)

#Default Settings
include ../setting.mk
BIN = pawn_compiler

#Compiled Files
OBJDIR = $(OBJECTDIR)-$(BUILDMODE)-$(PLATFORMOS)-$(PLATFORMPROCESSOR)
OBJ = $(OBJDIR)/libpawncc.o $(OBJDIR)/pawn4/keeloq.o $(OBJDIR)/pawn4/lstring.o $(OBJDIR)/pawn4/sc1.o $(OBJDIR)/pawn4/sc2.o $(OBJDIR)/pawn4/sc3.o
OBJ += $(OBJDIR)/pawn4/sc4.o $(OBJDIR)/pawn4/sc5.o $(OBJDIR)/pawn4/sc6.o $(OBJDIR)/pawn4/sc7.o $(OBJDIR)/pawn4/scexpand.o
OBJ += $(OBJDIR)/pawn4/sci18n.o $(OBJDIR)/pawn4/sclist.o $(OBJDIR)/pawn4/scstate.o $(OBJDIR)/pawn4/scvars.o $(OBJDIR)/pawn4/memfile.o $(OBJDIR)/pawn4/scmemfil.o
OBJ += $(OBJDIR)/mokoipawnc.o

#Read platform and custom settings
include makefiles/$(PLATFORMOS).make
ifneq ($(CUSTOMSETTINGS), )
	include custom/$(CUSTOMSETTINGS).make
endif


#Compiler
PROJECT_FLAGS += -I"include" -I"src" -I"src/physfs" -DHAVE_STDINT_H -DPAWN_LIGHT -DPAWN_NO_CODEPAGE -DPAWN=4 -DNO_MAIN=TRUE -DPAWN_CELL_SIZE=64
COMPILER_FLAGS += -DPLATFORM_$(PLATFORMOSUC) -DPLATFORM_BITS=$(PLATFORMBITS) -DPLATFORM_ARCH=$(PLATFORMPROCESSOR) $(PROJECT_FLAGS) $(PLATFORM_FLAGS)
COMPILER_LIBS += $(PLATFORM_LIBS)

#Extras Platform Objects
OBJ += $(PLATFORM_OBJECTS)

# Resources
RESOURCES_FILES = $(wildcard ../share/mokoi-1.0/include/*.inc)
RESOURCES = $(addprefix $(INSTALLDIR)/, $(RESOURCES_FILES) )

#Build
.PHONY: all-before all clean

all: all-before $(BIN)
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
	$(RM) $(OBJ) $(BUILDDIR)/$(BIN)

$(INSTALLDIR)/../share/%: ../share/%
	@$(MKDIR) $(dir $@)
	cp $< $@
	@echo $@

install-bin: $(BIN)
	@cp $(BUILDDIR)/$(BIN)  $(INSTALLDIR)/bin/


install: install-bin
	@echo Installing to $(INSTALLDIR)
	@$(MKDIR) $(INSTALLDIR)/share/mokoi-1.0/include/
	@cp ../share/mokoi-1.0/include/*.* $(INSTALLDIR)/share/mokoi-1.0/include/


$(BIN): $(OBJ)
	@echo --------------------------------
	@$(MKDIR) $(BUILDDIR)
	@$(CPP) $(OBJ) -o $(BUILDDIR)/$(BIN) $(COMPILER_LIBS)


$(OBJDIR)/%.o : src/%.c
	@echo Compiling $@ $(MESSAGE)
	@-$(MKDIR) $(dir $@)
	@$(CC) -c $(COMPILER_FLAGS) -o $@ $<


