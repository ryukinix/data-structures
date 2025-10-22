ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
WARN = -Wall -Wextra
DEBUG = -g
override CFLAGS += $(DEBUG) -pedantic $(WARN) -std=c99
LDFLAGS := -lset -lhash-table -llist -lm
INCLUDE := -I../ -L../ -L../list/single  -L../hash-table -L../set

# targets to compile
TEST_TARGET = test
TARGETS = graph.o
LIBRARY_OBJS = $(TARGETS)

TEST_BINARY = $(TEST_TARGET).$(EXTENSION)

# static library
LIBRARY_TARGET = libgraph.a

all: compile
	@echo > /dev/null

compile: $(TARGETS) $(TEST_TARGET).o

deps:
	make clean library -C ../list/single CFLAGS=-DLIST_PRINT_KEY
	make clean library -C ../hash-table
	make clean library -C ../set


%.o: %.c
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $<

$(TEST_BINARY): deps library $(TARGETS) $(TEST_TARGET).c
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ $(TARGETS) $(TEST_TARGET).c $(LDFLAGS)

test: library $(TEST_BINARY)
	./$(TEST_BINARY)

$(LIBRARY_TARGET): $(LIBRARY_OBJS)
	ar rcs $@ $?

library: $(LIBRARY_TARGET)

clean:
	rm -fv *.o *.$(EXTENSION) *.a

.PHONY: all clean compile test
