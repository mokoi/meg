#Base Setting, so variables aren't empty

BUILDPLATFORM = ${shell uname}
CPP = g++
CC = gcc
MAKE=make
MKDIR = mkdir -p
RM = rm -f
MESSAGE =

#OBJDIR = objects
#BUILDDIR = build
#INSTALLDIR = ../MokoiGaming/bin
#BUILDOS =


include ../platform.mk
