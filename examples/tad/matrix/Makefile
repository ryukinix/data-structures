ifeq ($(OS),Windows_NT)
	EXTENSION := exe
else
	EXTENSION := out
endif

CC= gcc
CFLAGS = -L./../../../lib -I././../../../src -pedantic -g -Wall -Wextra
LDFLAGS = -lds-lerax -lm -static
TARGET = main

all: generate-binary
	@echo > /dev/null

deps:
	@+$(MAKE) --no-print-directory -C ../../../

$(TARGET).o: $(TARGET).c
	$(CC) $(CFLAGS) -c -o $(TARGET).o $(TARGET).c

$(TARGET:=.$(EXTENSION)): $(TARGET).c
	$(CC) $(CFLAGS) $(TARGET).o -o $@ $(LDFLAGS)

compile: $(TARGET).o

generate-binary: deps compile $(TARGET:=.$(EXTENSION))

clean:
	rm -rfv *.$(EXTENSION) *.o

run: generate-binary
	./$(TARGET).$(EXTENSION)

.PHONY: clean
