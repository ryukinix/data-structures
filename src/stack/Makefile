ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
STD = c99
override CFLAGS += -fPIC -g -pedantic -Wall -Wextra -std=$(STD)
LDFLAGS = -llist -lm
STACK_STATIC = stack-static
STACK_DYNAMIC = stack-dynamic
TEST_TARGET = test
INCLUDE = -I../ -L../list/single/

# object-code
TARGETS = $(STACK_DYNAMIC).o
TARGETS += $(STACK_STATIC).o
TARGETS += $(TEST_TARGET).o


# linking test binary
STACK_OBJ = $(STACK_DYNAMIC).o
OBJS += $(STACK_OBJ)
OBJS += $(TEST_TARGET).o
TEST_BINARY = $(TEST_TARGET).$(EXTENSION)

# static library
LIBRARY_TARGET = libstack.a
LIBRARY_OBJS = $(STACK_OBJ)

all: compile
	@echo > /dev/null


deps:
	make library -C ../list/single/

compile: $(TARGETS)

%.o: %.c
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $<

$(TEST_BINARY): deps $(TARGETS) $(TEST_TARGET).c
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

test: $(TARGETS) $(TEST_BINARY)
	./$(TEST_BINARY)

$(LIBRARY_TARGET): $(LIBRARY_OBJS)
	ar rcs $@ $?

library: $(LIBRARY_TARGET)

clean:
	rm -fv *.o *.$(EXTENSION) *.a

.PHONY: all clean compile test deps
