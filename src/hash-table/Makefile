ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
WARN = -Wall -Wextra
DEBUG = -g
override CFLAGS += -fPIC $(DEBUG) -pedantic $(WARN) -std=c99
LDFLAGS := -llist -lm
INCLUDE := -I../ -L../list/single

# targets to compile
TEST_TARGET = test
TARGETS = hash-table.o hash-table-gen.o
LIBRARY_OBJS = $(TARGETS)

TEST_BINARY = $(TEST_TARGET).$(EXTENSION)

# static library
LIBRARY_TARGET = libhash-table.a

all: compile
	@echo > /dev/null

compile: $(TARGETS) $(TEST_TARGET).o $(MAIN_TARGET).o

deps:
	make clean library -C ../list/single CFLAGS=-DLIST_PRINT_KEY


%.o: %.c
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $<

$(TEST_BINARY): deps $(TARGETS) $(TEST_TARGET).c
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ $(TARGETS) $(TEST_TARGET).c $(LDFLAGS)

test: $(TARGETS) $(TEST_BINARY)
	./$(TEST_BINARY)

main: $(TARGETS) $(MAIN_BINARY)
	./$(MAIN_BINARY)

$(LIBRARY_TARGET): $(LIBRARY_OBJS)
	ar rcs $@ $?

library: $(LIBRARY_TARGET)

clean:
	rm -fv *.o *.$(EXTENSION) *.a

.PHONY: all clean compile test stats
