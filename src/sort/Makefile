ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
WARN = -Wall -Wextra
DEBUG = -g
override CFLAGS = $(DEBUG) -pedantic $(WARN) -std=c99
LDFLAGS := -lm -lqueue -llist
INCLUDE := -I../ -L../queue/ -L../list/single/

# targets to compile
TEST_TARGET = test
MAIN_TARGET = main
TARGETS = quicksort.o bubblesort.o heapsort.o mergesort.o insertionsort.o utils.o radixsort.o
LIBRARY_OBJS = TARGETS

TEST_BINARY = $(TEST_TARGET).$(EXTENSION)
MAIN_BINARY = $(MAIN_TARGET).$(EXTENSION)
DEPS_TYPE := deps-dynamic

# static library
LIBRARY_TARGET = libsort.a

all: compile
	@echo > /dev/null

deps-dynamic:
	make clean library -C ../queue

deps-static:
	make clean library LIBRARY_OBJS=queue-static.o -C ../queue

compile: $(TARGETS) $(TEST_TARGET).o $(MAIN_TARGET).o

%.o: %.c
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $<

$(TEST_BINARY): $(DEPS_TYPE) $(TARGETS) $(TEST_TARGET).c
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ $(TARGETS) $(TEST_TARGET).c $(LDFLAGS)

$(MAIN_BINARY): $(DEPS_TYPE) $(TARGETS) $(MAIN_TARGET).c
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ $(TARGETS) $(MAIN_TARGET).c  $(LDFLAGS)

test: $(TARGETS) $(TEST_BINARY)
	./$(TEST_BINARY)

main: $(TARGETS) $(MAIN_BINARY)
	./$(MAIN_BINARY)

$(LIBRARY_TARGET): $(LIBRARY_OBJS)
	ar rcs $@ $?

library: $(LIBRARY_TARGET)

clean:
	rm -fv *.o *.$(EXTENSION) *.a

stats:
	python stats.py benchmark/*.csv

.PHONY: all clean compile test stats
