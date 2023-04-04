# Set project directory one level above of Makefile directory. $(CURDIR) is a GNU make variable containing the path to the current working directory
PROJ_DIR := $(realpath $(CURDIR)/..)
CLIENT_DIR := .$(PROJDIR)/Client
KRAKEN_DIR := .$(PROJDIR)/KrakenEngine
BUILD_DIR := .$(PROJDIR)/Build

# Name the final executable
TARGET= prototype.exe

# Commands shown y/n
VERBOSE = TRUE

# List of directories
CLIENT_DIRS=
KRAKEN_DIRS= Core Props
KRAKEN_SOURCE_DIRS = $(foreach dir, $(KRAKEN_DIRS), $(addprefix $(KRAKEN_DIR)/, $(dir)))

# Generate the GCC includes parameters
# KRK_INCLUDES = $(foreach dir, $(KRAKEN_SOURCE_DIRS), $(addprefix -I, $(dir)))

VPATH = $(KRAKEN_SOURCE_DIRS)

# Create a list of *.c sources
SOURCES = $(foreach dir,$(KRAKEN_SOURCE_DIRS),$(wildcard $(dir)/*.cpp))

all:
	@echo $(SOURCES)