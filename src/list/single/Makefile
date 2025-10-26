ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
override CFLAGS += -fPIC -g -pedantic -Wall -Wextra
LDFLAGS = -lm

TEST_TARGET = test
INCLUDE = -I../../

# object-code
TARGETS = list.o list-gen.o

# linking test binary
OBJS = $(TARGETS) $(TEST_TARGET).o
TEST_BINARY = $(TEST_TARGET).$(EXTENSION)

# static library
LIBRARY_TARGET = liblist.a
LIBRARY_OBJS = $(TARGETS)

all: compile
	@echo > /dev/null

compile: $(TARGETS)

%.o: %.c
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $<

$(TEST_BINARY): $(TARGETS) $(TEST_TARGET).o
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

test: $(TARGETS) $(TEST_BINARY)
	./$(TEST_BINARY)

$(LIBRARY_TARGET): $(LIBRARY_OBJS)
	ar rcs $@ $?

library: $(LIBRARY_TARGET)

clean:
	rm -fv *.o *.$(EXTENSION) *.a

.PHONY: all clean compile
