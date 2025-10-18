ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
WARN = -Wall -Wextra
DEBUG = -g
CFLAGS = $(DEBUG) -pedantic $(WARN) -std=c99
LDFLAGS = -L../bst/ -lbst -lm
ASCII_TREE = ascii-tree
TEST_TARGET = test
INCLUDE = -I../../

# targets to compile
TARGETS = $(ASCII_TREE).o
TARGETS += $(TEST_TARGET).o

# linking test binary
OBJS += $(ASCII_TREE).o
OBJS += $(TEST_TARGET).o
TEST_BINARY = $(TEST_TARGET).$(EXTENSION)

# static library
LIBRARY_TARGET = libascii-tree.a
LIBRARY_OBJS = $(ASCII_TREE).o

all: compile
	@echo > /dev/null

deps:
	make -C ../bst library


compile: $(TARGETS)

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
