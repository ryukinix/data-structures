ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
WARN = -Wall -Wextra
DEBUG ?= -g
SRCDIR = src
LIBNAME = libds-lerax
LIBDIR = lib
HEADER = ds-lerax.h
override CFLAGS += $(DEBUG) -pedantic $(WARN) -std=c99 -fPIC
SOURCES = $(shell find $(SRCDIR) -iname '*.c')
COMPILED = $(shell find $(SRCDIR) -type f -iname '*.o' -or -iname "*.out" -or -iname "*.a")
TEST_TRASH = $(shell find $(SRCDIR) -type f -iname 'test*.dot*')
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
PROJECT_NUMBER = $(shell git describe --tags --abbrev=4 2> /dev/null || printf 0.0.0)

override VALGRIND_ARGS += --quiet --trace-children=yes --track-fds=yes \
                          --leak-check=full --show-leak-kinds=all --error-exitcode=1 \
	                      --undef-value-errors=no


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
	rm -vrf $(COMPILED) $(LIBDIR) $(TEST_TRASH)

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

compile-tests/%:
	@printf $(STATUS_PREFIX); echo "COMPILE TESTS OF SUBSYTEMS"
	for s in $(foreach S,$(SUBSYSTEMS),$(if $(findstring $*,$S),$S)); do \
		printf $(STATUS_PREFIX); echo "SYSTEM: $$s"; \
	    make --no-print-directory  -C $$s -q test.$(EXTENSION) > /dev/null 2>&1; \
		if [ $$? -lt 2 ]; then \
			make --no-print-directory  -C $$s test.$(EXTENSION); \
		else \
			printf $(STATUS_PREFIX); echo "No test target in $$s"; \
		fi; \
	done

compile-tests: compile-tests/src

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

check/%:
	make test -C src/$*

check-valgrind/%:
	make compile-tests/$* > /dev/null
	@printf $(STATUS_PREFIX); echo "CHECKING FOR MEMORY LEAK OVER FOLLOWING TESTS:"
	@find $(SRCDIR) -path "*$**" -and -iname "test.out" \
		| tee /dev/stderr \
        | xargs -L 1 valgrind $(VALGRIND_ARGS)  > /dev/null
	@printf $(STATUS_PREFIX); echo "NO MEMORY LEAK FOUND."

check-valgrind: check-valgrind/src

docs-worktree:
	@if [ ! -d docs/gh-pages ]; then \
		git worktree add docs/gh-pages gh-pages -f; \
	fi

docs: docs-worktree
	PROJECT_NUMBER=$(PROJECT_NUMBER) doxygen doxygen.cfg

docs-open: docs
	xdg-open docs/gh-pages/index.html

docs-publish:
	cd docs/gh-pages && git add . && git commit -m "Auto-generated commit from make docs-publish" && git push || true

tags: $(SOURCES)
	ctags -Re -f TAGS src/

wc:
	@echo "LINES\tWORDS\tMAX-LINE"
	@find src -regextype posix-extended -regex ".*\.(c|h)" \
		| xargs wc --lines --words --max-line-length \
        | sort -n

lint:
	cppcheck $(SRCDIR)

.PHONY: clean docs
