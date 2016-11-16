# (C) 2015, Xiaofeng Gu, all rights reserved.

APPL_INCLUDES = -I./include -I./lib/include
LIB_INCLUDES = -I../../include
CFLAGS = -Wall -O2 -std=c++11
ARCFLAGS = -cvq
CC = g++
ARC = ar
SRC = src
LIBS = -L./lib/libs
BIN = ./bin
MAKE = make