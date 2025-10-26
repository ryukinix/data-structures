ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC = gcc
CFLAGS = -fPIC -g -pedantic -Wall -Wextra
LDFLAGS = -lm
LIST_CIRCULAR = list-circular
TEST_TARGET = test
INCLUDE = -I../../

# object-code
TARGETS = $(LIST_CIRCULAR).o
TARGETS += $(TEST_TARGET).o

# linking test binary
LIST_OBJ = $(LIST_CIRCULAR).o
OBJS += $(LIST_CIRCULAR).o
OBJS += $(TEST_TARGET).o
TEST_BINARY = $(TEST_TARGET).$(EXTENSION)

# static library
LIBRARY_TARGET = liblistcircular.a
LIBRARY_OBJS = $(LIST_CIRCULAR)

all: compile
	@echo > /dev/null

compile: $(TARGETS)

%.o: %.c
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $<

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
