CC = gcc
WARN = -Wall -Wextra
DEBUG ?= -g
SRCDIR = src
LIBNAME = libds-ufc
LIBDIR = lib
HEADER = ds-ufc.h
CFLAGS = $(DEBUG) -pedantic $(WARN) -std=c99 -fPIC
SOURCES = $(shell find $(SRCDIR) -iname '*.c')
BLACKLIST = "(list-iter|main|test).c|avl|*.-static.c|matrix-vector"
LIB_SOURCES = $(shell echo $(SOURCES) | tr ' ' '\n' | grep -E -v $(BLACKLIST))
LIB_OBJECTS = $(shell echo $(LIB_SOURCES) | tr ' ' '\n' | sed "s/\.c/\.o/")
INCLUDE=-I./$(SRCDIR)
LIBPATH = $(LIBDIR)/$(LIBNAME)
INCLUDE_TARGET = /usr/local/include
LIB_TARGET = /usr/local/lib
SUBSYSTEMS = $(shell find src -iname "Makefile" -exec dirname '{}' \;)

STATUS_PREFIX = "\033[1;32m[+]\033[0m "
TEST_PREFIX = "\033[1;32m[>>]\033[0m "
ATTENTION_PREFIX =  "\033[1;36m[!]\033[0m "


all: compile static shared header

install: all
	@printf $(STATUS_PREFIX); echo "INSTALLING LIB INTO: " $(LIB_TARGET)
	cp -f $(LIBDIR)/ds-ufc.h $(INCLUDE_TARGET)
	cp -f $(LIBDIR)/libds-ufc.a $(LIBDIR)/libds-ufc.so $(LIB_TARGET)


mkdir-%:
	@mkdir -p "$*"

sources:
	echo $(LIB_SOURCES) | tr ' ' '\n'

compile: $(LIB_OBJECTS)

%.o: %.c
	$(CC) -c -o $@ $(INCLUDE) $(CFLAGS) "$<"

clean:
	@printf $(STATUS_PREFIX); echo "CLEANING ALL"
	rm -vrf $(LIB_OBJECTS) $(LIBDIR)

static: mkdir-$(LIBDIR) $(LIBDIR)/$(LIBNAME).a
shared: mkdir-$(LIBDIR) $(LIBDIR)/$(LIBNAME).so

$(LIBPATH).a: $(LIB_OBJECTS)
	ar rcs $@ $(LIB_OBJECTS)

$(LIBPATH).so: $(LIB_OBJECTS)
	gcc -o $@ -shared $(LIB_OBJECTS)


header: mkdir-$(LIBDIR) $(LIBDIR)/$(HEADER)

$(LIBDIR)/$(HEADER): $(SRCDIR)/$(HEADER)
	@printf $(STATUS_PREFIX); echo "GENERATING HEADER: " $(SRCDIR)/$(HEADER)
	rm -rf $@
	touch $@
	echo "#include <stdio.h>" >> $@
	echo "#include <stdlib.h>" >> $@
	echo "#include <math.h>" >> $@
	$(CC) -CC -E -Isrc/ "$<" >> $@

test: all
	@printf $(STATUS_PREFIX); echo "TESTING SUBSYTEMS"
	@for s in $(SUBSYSTEMS); do \
		printf $(STATUS_PREFIX); echo "SYSTEM: $$s"; \
		make -C $$s test; \
	done

check: test

docs:
	doxygen doxygen.cfg

open-docs: docs
	cd api_docs/html/ && python -m http.server 8000

.PHONY: clean docs
