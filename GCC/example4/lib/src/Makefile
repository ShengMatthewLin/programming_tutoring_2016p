# (C) 2015, Xiaofeng Gu, all rights reserved.

include ../../makefile.inc

DIRS = libmisc
BUILDDIRS = $(DIRS:%=build-%)
CLEANDIRS = $(DIRS:%=clean-%)

.PHONY: $(DIRS)
.PHONY: $(BUILDDIRS)
.PHONY: $(CLEANDIRS)

all: $(BUILDDIRS)

$(BUILDDIRS):
	$(MAKE) -C $(@:build-%=%)

clean: $(CLEANDIRS)

$(CLEANDIRS):
	$(MAKE) -C $(@:clean-%=%) clean
