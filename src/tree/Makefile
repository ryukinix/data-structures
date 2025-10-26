ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
WARN = -Wall -Wextra
DEBUG = -g
override CFLAGS += -fPIC $(DEBUG) -pedantic $(WARN) -std=c99
LDFLAGS = -lm -L./ascii-tree/ -L./avl/ -lavl -lascii-tree
LDFLAGS = -L./ascii-tree/ -L./avl/ -B static -lavl -lascii-tree -B dynamic -lm
INCLUDE = -I../

# targets to compile
TARGETS = main.o

OBJS += main.o
MAIN_BINARY = main.$(EXTENSION)

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

clean:
	rm -fv *.o *.$(EXTENSION) *.a

.PHONY: all clean compile deps
