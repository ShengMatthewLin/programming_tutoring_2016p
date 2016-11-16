# (C) 2015, Xiaofeng Gu, all rights reserved.

include ./makefile.inc

OBJS = $(SRC)/Student.o $(SRC)/main.o
OBJ_DEPS = Student.o main.o
LINK_ARCHIVES = -lmisc

all: main

lib_dep:
	$(MAKE) -C ./lib/src

main: $(OBJ_DEPS) lib_dep
	mkdir -p bin
	$(CC) -o $(BIN)/main $(OBJS) $(LIBS) $(LINK_ARCHIVES)

%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $(APPL_INCLUDES) -c -o $(SRC)/$@ $<

clean:
	rm -f $(BIN)/*
	rm -f $(SRC)/*.o
	rm -f lib/libs/*.a
	$(MAKE) -C ./lib/src clean
