CC = gcc
STD = c99
override CFLAGS += -fPIC -g -pedantic -Wall -Wextra -std=$(STD)
LDFLAGS = -lm
MATRIX_POINTER = matrix-pointer
MATRIX_VECTOR = matrix-vector
MATRIX_UTILS = matrix-utils
TARGETS = $(MATRIX_POINTER).o $(MATRIX_VECTOR).o $(MATRIX_UTILS).o
INCLUDE = -I../

all: compile
	@echo > /dev/null

compile: $(TARGETS)

$(MATRIX_POINTER:=.o): $(MATRIX_POINTER).c
$(MATRIX_VECTOR:=.o): $(MATRIX_VECTOR).c
$(MATRIX_UTILS:=.o): $(MATRIX_UTILS).c

$(TARGETS):
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $? $(LDFLAGS)

clean:
	rm -fv *.o

.PHONY: all clean compile
