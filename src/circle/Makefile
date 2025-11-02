CC = gcc
STD = c99
override CFLAGS += -fPIC -g -pedantic -Wall -Wextra -std=$(STD)
LDFLAGS = -lm
TARGET = circle
OBJ = $(TARGET).o
SRC = $(TARGET).c
INCLUDE = -I../../

all: compile
	@echo > /dev/null

compile: $(OBJ)

%.o: %.c
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $? $(LDFLAGS)

clean:
	rm -fv *.o

.PHONY: clean all compile
