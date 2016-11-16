# (C) 2015, Xiaofeng Gu, all rights reserved.

include ../../../makefile.inc

CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(notdir $(CPP_FILES:.cpp=.o))
AR_FILE := libmisc.a

all: $(OBJ_FILES)
	$(ARC) $(ARCFLAGS) $(AR_FILE) $(OBJ_FILES)
	mkdir -p ../../libs
	cp $(AR_FILE) ../../libs

%.o: %.cpp
	$(CC) $(CFLAGS) $(LIB_INCLUDES) -c -o $@ $<

clean:
	rm -f libutil.a
	rm -f *.o
