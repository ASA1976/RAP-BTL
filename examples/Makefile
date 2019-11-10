# RAP-BTL Examples Makefile

RAPBTL_DIR = ../rap-btl
#CXX = g++
#CXX = clang++
CXX_DEBUG = -O 
CXX_DEFS =
CXX_INCLUDES = -I$(RAPBTL_DIR)
#CC = gcc
#CC = clang
C_DEBUG = -O
C_DEFS =
C_INCLUDES = -I$(RAPBTL_DIR)

CXXFLAGS = $(CXX_DEBUG) $(CXX_DEFS) $(CXX_INCLUDES)
CFLAGS = $(C_DEBUG) $(C_DEFS) $(C_INCLUDES)

###############################################################################

SRC	 =	abstraction.cpp eloper.c example.cpp fastlist.cpp interloper.cpp \
        invocation.cpp processing.cpp provision.cpp represent.cpp \
        sortints.cpp zero.cpp

OBJ	 =	abstraction.o eloper.o example.o fastlist.o interloper.o invocation.o \
        processing.o provision.o represent.o sortints.o zero.o

BINS =  abstraction elope example fastlist invocation processing provision \
        represent sortints zero

all: $(BINS)

abstraction: abstraction.o
	$(CXX) -o $@ abstraction.o

elope: eloper.o interloper.o
	$(CXX) -o $@ eloper.o interloper.o

example: example.o
	$(CXX) -o $@ example.o

fastlist: fastlist.o
	$(CXX) -o $@ fastlist.o

invocation: invocation.o
	$(CXX) -o $@ invocation.o

processing: processing.o
	$(CXX) -o $@ processing.o

provision: provision.o
	$(CXX) -o $@ provision.o
	
represent: represent.o
	$(CXX) -o $@ represent.o
	
sortints: sortints.o
	$(CXX) -o $@ sortints.o
	
zero: zero.o
	$(CXX) -o $@ zero.o

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(BINS)

targets:
	echo $(BINS) 

