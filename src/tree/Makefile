ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
WARN = -Wall -Wextra
DEBUG = -g
override CFLAGS += $(DEBUG) -pedantic $(WARN) -std=c99
LDFLAGS = -lm -L./ascii-tree/ -L./avl/ -lavl -lascii-tree
LDFLAGS = -L./ascii-tree/ -L./avl/ -B static -lavl -lascii-tree -B dynamic -lm
MAIN = main
INCLUDE = -I../

# targets to compile
TARGETS = $(MAIN).o

# linking test binary
OBJS += $(MAIN).o
MAIN_BINARY = $(MAIN).$(EXTENSION)
all: compile
	@echo > /dev/null

compile: $(TARGETS)

deps:
	make -C ascii-tree library
	make -C avl library

%.o: %.c
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $<

$(MAIN_BINARY): $(TARGETS)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

main: deps $(TARGETS) $(MAIN_BINARY)
	./$(MAIN_BINARY)

run: main

test:
	@echo "Test manually with: make main"

clean:
	rm -fv *.o *.$(EXTENSION) *.a

.PHONY: all clean compile test deps
