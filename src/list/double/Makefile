ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
CFLAGS = -fPIC -g -pedantic -Wall -Wextra
LDFLAGS = --static -lm
LIST_DOUBLE = list-double
TEST_TARGET = test
INCLUDE = -I../../

# object-code
TARGETS = $(LIST_DOUBLE).o
TARGETS += $(TEST_TARGET).o


# linking test binary
LIST_OBJ = $(LIST_DOUBLE).o
OBJS += $(LIST_DOUBLE).o
OBJS += $(TEST_TARGET).o
TEST_BINARY = $(TEST_TARGET).$(EXTENSION)

# static library
LIBRARY_TARGET = liblistcircular.a
LIBRARY_OBJS = $(LIST_DOUBLE)

all: compile
	@echo > /dev/null

compile: $(TARGETS)

%.o: %.c
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $< $(LDFLAGS)

$(TEST_BINARY): $(TARGETS) $(TEST_TARGET).c
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

test: $(TARGETS) $(TEST_BINARY)
	./$(TEST_BINARY)

$(LIBRARY_TARGET): $(LIBRARY_OBJS)
	ar rcs $@ $?

library: $(LIBRARY_TARGET)

clean:
	rm -fv *.o *.$(EXTENSION) *.a

.PHONY: all clean compile
