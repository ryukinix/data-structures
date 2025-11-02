ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
WARN = -Wall -Wextra
DEBUG = -g
STD = c99
override CFLAGS += -fPIC $(DEBUG) -pedantic $(WARN) -std=$(STD)
LDFLAGS = -L../ascii-tree/ -lm -lascii-tree
BST = bst
TEST_TARGET = test
INCLUDE = -I../../

# targets to compile
TARGETS = $(BST).o
TARGETS += $(TEST_TARGET).o

# linking test binary
OBJS += $(BST).o
OBJS += $(TEST_TARGET).o
TEST_BINARY = $(TEST_TARGET).$(EXTENSION)

# static library
LIBRARY_TARGET = libbst.a
LIBRARY_OBJS = $(BST).o

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
