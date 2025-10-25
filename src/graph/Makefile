ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
WARN = -Wall -Wextra
DEBUG = -g
override CFLAGS += $(DEBUG) -pedantic $(WARN) -std=c99
LDFLAGS := -lset -lhash-table -llist -lqueue -lstack -lm
INCLUDE := -I../ -L../list/single  -L../hash-table -L../set -L../queue -L ../stack

# targets to compile
TEST_TARGET = test
TARGETS = graph.o bfs.o dfs.o acyclical.o
LIBRARY_OBJS = $(TARGETS)

TEST_BINARY = $(TEST_TARGET).$(EXTENSION)

# static library
LIBRARY_TARGET = libgraph.a

all: compile

compile: $(TARGETS) $(TEST_TARGET).o

deps:
	make clean library -C ../list/single CFLAGS=-DLIST_PRINT_KEY
	make clean library -C ../hash-table
	make clean library -C ../set
	make clean library -C ../queue
	make clean library -C ../stack


%.o: %.c
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $<

$(TEST_BINARY): deps library $(TARGETS) $(TEST_TARGET).c
	$(CC) $(INCLUDE) -L. $(CFLAGS) -o $@ $(TARGETS) $(TEST_TARGET).c -lgraph $(LDFLAGS)

test: library $(TEST_BINARY)
	./$(TEST_BINARY)

$(LIBRARY_TARGET): $(LIBRARY_OBJS)
	ar rcs $@ $?

library: $(LIBRARY_TARGET)

clean:
	rm -fv *.o *.$(EXTENSION) *.a

.PHONY: all clean compile test library
