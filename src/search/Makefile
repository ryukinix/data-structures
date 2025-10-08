ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
WARN = -Wall -Wextra
DEBUG = -g
override CFLAGS += $(DEBUG) -pedantic $(WARN) -std=c99
LDFLAGS := -lm
INCLUDE := -I../

# targets to compile
TEST_TARGET = test
TARGETS = search.o
LIBRARY_OBJS = TARGETS

TEST_BINARY = $(TEST_TARGET).$(EXTENSION)

# static library
LIBRARY_TARGET = libsearch.a

all: compile
	@echo > /dev/null

compile: $(TARGETS) $(TEST_TARGET).o $(MAIN_TARGET).o

%.o: %.c
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $<

$(TEST_BINARY): $(DEPS_TYPE) $(TARGETS) $(TEST_TARGET).c
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
