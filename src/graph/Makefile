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
LDFLAGS := -lset -lhash-table -llist -lqueue -lstack -lpqueue -lm
INCLUDE := -I../ -L../list/single  -L../hash-table -L../set -L../queue -L../stack -L../pqueue

# targets to compile
TEST_TARGET = test
TARGETS = graph.o bfs.o dfs.o acyclical.o tarjan.o dijkstra.o kruskal.o prim.o
LIBRARY_OBJS = $(TARGETS)

TEST_BINARY = $(TEST_TARGET).$(EXTENSION)

# static library
LIBRARY_TARGET = libgraph.a

all: compile

compile: $(TARGETS) $(TEST_TARGET).o

deps:
	make library -C ../list/single CFLAGS=-DLIST_PRINT_KEY
	make library -C ../hash-table
	make library -C ../set
	make clean library -C ../queue
	make library -C ../stack
	make library -C ../pqueue


%.o: %.c
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $<

$(TEST_BINARY): deps library $(TARGETS) $(TEST_TARGET).c
	$(CC) $(INCLUDE) -L. $(CFLAGS) -o $@ $(TARGETS) $(TEST_TARGET).c -lgraph $(LDFLAGS)

test: library $(TEST_BINARY)
	./$(TEST_BINARY) --extra-tests
	make dot2png

$(LIBRARY_TARGET): $(LIBRARY_OBJS)
	ar rcs $@ $?

dot2png:
	find . -iname "*.dot" | xargs -L 1 dot -T png -O

library: $(LIBRARY_TARGET)

clean:
	rm -fv *.o *.$(EXTENSION) *.a

.PHONY: all clean compile test library
