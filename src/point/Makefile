CC = gcc
STD = c99
override CFLAGS += -fPIC -g -pedantic -Wall -Wextra -std=$(STD)
LDFLAGS = -lm
TARGET = point
OBJ = $(TARGET).o
SRC = $(TARGET).c
INCLUDE = -I../

all: compile
	@echo > /dev/null

compile: $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(INCLUDE) -c $(CFLAGS) -o $@ $? $(LDFLAGS)

clean:
	rm -fv *.o

.PHONY: all clean compile
