## -*- Makefile -*-
##
## User: rafopar
## Time: Nov 30, 2021 2:02:45 PM
## Makefile created by Oracle Developer Studio.
##
## This file is generated automatically.
##

CC              = g++ -std=c++11
CC_OBJ_FLAGS    = -c -fPIC
CC_Shared_FLAGS = -shared -Wl,-soname,libVtxAna.so
HIPO_FLAGS	= -I/Work/apps/hipo/hipo4
ROOT_CFLAGS     = $(shell /usr/local/apps/root6.22.02Install/bin/root-config --cflags)
ROOT_LIBS       = $(shell /usr/local/apps/root6.22.02Install/bin/root-config --libs)
libVtxAna       = libVtxAna


## Target: all
all:		    VtxAna.o BankStructures.o
		    rm -f ${libVtxAna}.so*
		    $(CC) $(CC_Shared_FLAGS) -o lib/${libVtxAna}.so.1.0.1 $?
		    cd lib;\
		    ln -sf ${libVtxAna}.so.1.0.1 ${libVtxAna}.so.1; ln -sf ${libVtxAna}.so.1.0.1 ${libVtxAna}.so

VtxAna.o:	    src/TVertexAna.cc include/TVertexAna.h
		    $(CC) $(CC_OBJ_FLAGS) src/TVertexAna.cc -o $@ $(ROOT_CFLAGS) $(HIPO_FLAGS) -I./include
	
BankStructures.o:   src/BankStructures.cc include/BankStructures.h
		    $(CC) $(CC_OBJ_FLAGS) src/BankStructures.cc -o $@ $(ROOT_CFLAGS) $(HIPO_FLAGS) -I./include

## Target: clean
clean: 
		    rm -f *.o lib*.so*

# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-amd64-Linux

