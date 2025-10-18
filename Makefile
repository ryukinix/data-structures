CC = gcc
WARN = -Wall -Wextra
DEBUG ?= -g
SRCDIR = src
LIBNAME = libds-lerax
LIBDIR = lib
HEADER = ds-lerax.h
CFLAGS = $(DEBUG) -pedantic $(WARN) -std=c99 -fPIC
SOURCES = $(shell find $(SRCDIR) -iname '*.c')
COMPILED = $(shell find $(SRCDIR) -type f -iname '*.o' -or -iname "*.out" -or -iname "*.a")
BLACKLIST = "(list-iter|main|test).c|*.-static.c|matrix-vector"
LIB_SOURCES = $(shell echo $(SOURCES) | tr ' ' '\n' | grep -E -v $(BLACKLIST))
LIB_OBJECTS = $(shell echo $(LIB_SOURCES) | tr ' ' '\n' | sed "s/\.c/\.o/")
INCLUDE=-I./$(SRCDIR)
LIBPATH = $(LIBDIR)/$(LIBNAME)
INCLUDE_TARGET = /usr/include
LIB_TARGET = /usr/lib
SUBSYSTEMS = $(shell find src -iname "Makefile" -exec dirname '{}' \;)

STATUS_PREFIX = "\033[1;32m[+]\033[0m "
TEST_PREFIX = "\033[1;32m[>>]\033[0m "
ATTENTION_PREFIX =  "\033[1;36m[!]\033[0m "


all: compile static shared header

install: all
	@printf $(STATUS_PREFIX); echo "INSTALLING LIB INTO: " $(LIB_TARGET)
	install -d $(INCLUDE_TARGET)/ds-lerax
	cp -f -v -r $(LIBDIR)/headers/* $(INCLUDE_TARGET)/ds-lerax/
	install -m 755 $(LIBDIR)/libds-lerax.a $(LIB_TARGET)
	install -m 755 $(LIBDIR)/libds-lerax.so $(LIB_TARGET)

uninstall:
	rm -rfv $(INCLUDE_TARGET)/ds-lerax $(LIB_TARGET)/libds-lerax.a $(LIB_TARGET)/libds-lerax.so

mkdir-%:
	@mkdir -p "$*"

sources:
	echo $(LIB_SOURCES) | tr ' ' '\n'

compile: $(LIB_OBJECTS)

%.o: %.c
	$(CC) -c -o $@ $(INCLUDE) $(CFLAGS) "$<"

clean:
	@printf $(STATUS_PREFIX); echo "CLEANING ALL"
	rm -vrf $(COMPILED) $(LIBDIR)

static: mkdir-$(LIBDIR) $(LIBDIR)/$(LIBNAME).a
shared: mkdir-$(LIBDIR) $(LIBDIR)/$(LIBNAME).so

$(LIBPATH).a: $(LIB_OBJECTS)
	ar rcs $@ $(LIB_OBJECTS)

$(LIBPATH).so: $(LIB_OBJECTS)
	gcc -o $@ -shared $(LIB_OBJECTS)


header: mkdir-$(LIBDIR) $(LIBDIR)/$(HEADER)

$(LIBDIR)/$(HEADER): $(SRCDIR)/$(HEADER)
	@printf $(STATUS_PREFIX); echo "GENERATING HEADER: " $(SRCDIR)/$(HEADER)
	cd $(SRCDIR) && find . -name '*.h' | cpio -pdmu --quiet ../$(LIBDIR)/headers

lib: static shared header

test: all
	@printf $(STATUS_PREFIX); echo "TESTING SUBSYTEMS"
	@for s in $(SUBSYSTEMS); do \
		printf $(STATUS_PREFIX); echo "SYSTEM: $$s"; \
		make -C $$s -q test > /dev/null 2>&1; \
		if [ $$? -lt 2 ]; then \
			make -C $$s test; \
		else \
			printf $(STATUS_PREFIX); echo "No test target in $$s"; \
		fi; \
	done

check: test

docs-worktree:
	@if [ ! -d docs/gh-pages ]; then \
		git worktree add docs/gh-pages gh-pages -f; \
	fi


docs: docs-worktree
	doxygen doxygen.cfg

docs-open: docs
	xdg-open docs/gh-pages/index.html

docs-publish:
	cd docs/gh-pages && git add . && git commit -m "Auto-generated commit from make docs-publish" && git push || true

open-docs: docs
	cd api_docs/html/ && python -m http.server 8000

tags: $(SOURCES)
	ctags -Re -f TAGS src/

.PHONY: clean docs
