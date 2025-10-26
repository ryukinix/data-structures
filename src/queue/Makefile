ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
CFLAGS = -fPIC -g -pedantic -Wall -Wextra
LDFLAGS = -llist -lm
QUEUE_STATIC = queue-static
QUEUE_DYNAMIC = queue-dynamic
TEST_TARGET = test
INCLUDE = -I../ -L../list/single/

# object-code
TARGETS = $(QUEUE_DYNAMIC).o
TARGETS += $(QUEUE_STATIC).o
TARGETS += $(TEST_TARGET).o


# linking test binary
QUEUE_OBJ = $(QUEUE_DYNAMIC).o
OBJS += $(QUEUE_OBJ)
OBJS += $(TEST_TARGET).o
TEST_BINARY = $(TEST_TARGET).$(EXTENSION)

# static library
LIBRARY_TARGET = libqueue.a
LIBRARY_OBJS = $(QUEUE_OBJ)

all: library
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
