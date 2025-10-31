ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
WARN = -Wall -Wextra
DEBUG = -g
override CFLAGS = -fPIC $(DEBUG) -pedantic $(WARN) -std=c99
LDFLAGS = -lhash-table -llist -lm
INCLUDE = -I../ -L../list/single -L../hash-table

# targets to compile
TEST_TARGET = test
TARGETS = pqueue.o
LIBRARY_OBJS = TARGETS
TARGETS += $(TEST_TARGET).o

TEST_BINARY = $(TEST_TARGET).$(EXTENSION)

# static library
LIBRARY_TARGET = libpqueue.a

all: compile
	@echo > /dev/null

compile: $(TARGETS)

deps:
	make clean library -C ../hash-table CFLAGS=-DLIST_PRINT_KEY
	make clean library -C ../list/single CFLAGS=-DLIST_PRINT_KEY


%.o: %.c
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $<

$(TEST_BINARY): deps $(TARGETS) $(TEST_TARGET).c
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ $(TARGETS) $(LDFLAGS)

test: $(TARGETS) $(TEST_BINARY)
	./$(TEST_BINARY)

$(LIBRARY_TARGET): $(LIBRARY_OBJS)
	ar rcs $@ $?

library: $(LIBRARY_TARGET)

clean:
	rm -fv *.o *.$(EXTENSION) *.a

.PHONY: all clean compile test
