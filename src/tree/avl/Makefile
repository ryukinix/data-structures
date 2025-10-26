ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
WARN = -Wall -Wextra
DEBUG = -g
override CFLAGS += -fPIC $(DEBUG) -pedantic $(WARN) -std=c99
LDFLAGS = -L../ascii-tree/ -lm -lascii-tree
AVL = avl
TEST_TARGET = test
INCLUDE = -I../../

# targets to compile
TARGETS = $(AVL).o
TARGETS += $(TEST_TARGET).o

# linking test binary
OBJS += $(AVL).o
OBJS += $(TEST_TARGET).o
TEST_BINARY = $(TEST_TARGET).$(EXTENSION)

# static library
LIBRARY_TARGET = libavl.a
LIBRARY_OBJS = $(AVL).o

all: compile
	@echo > /dev/null

compile: $(TARGETS)

deps:
	make -C ../ascii-tree/ library

%.o: %.c
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $<

$(TEST_BINARY): deps $(TARGETS) $(TEST_TARGET).c
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

test: $(TARGETS) $(TEST_BINARY)
	./$(TEST_BINARY)

$(LIBRARY_TARGET): $(LIBRARY_OBJS)
	ar rcs $@ $?

library: $(LIBRARY_TARGET)

clean:
	rm -fv *.o *.$(EXTENSION) *.a

.PHONY: all clean compile test deps
