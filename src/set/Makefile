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
LDFLAGS := -lhash-table -llist -lm
INCLUDE := -I../ -L../list/single -L../hash-table/

# targets to compile
TEST_TARGET = test
TARGETS = set.o set-disjoint.o
LIBRARY_OBJS = $(TARGETS)

TEST_BINARY = $(TEST_TARGET).$(EXTENSION)

# static library
LIBRARY_TARGET = libset.a

all: compile
	@echo > /dev/null

compile: deps $(TARGETS) $(TEST_TARGET).o $(MAIN_TARGET).o

deps:
	make clean library -C ../list/single CFLAGS=-DLIST_PRINT_KEY
	make clean library -C ../hash-table


%.o: %.c
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $<

$(TEST_BINARY): deps $(TARGETS) $(TEST_TARGET).c
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ $(TARGETS) $(TEST_TARGET).c $(LDFLAGS)

test: $(TARGETS) $(TEST_BINARY)
	./$(TEST_BINARY)

main: $(TARGETS) $(MAIN_BINARY)
	./$(MAIN_BINARY)

$(LIBRARY_TARGET): $(LIBRARY_OBJS)
	ar rcs $@ $(TARGETS)

library: $(LIBRARY_TARGET)

clean:
	rm -fv *.o *.$(EXTENSION) *.a

.PHONY: all clean compile test stats
