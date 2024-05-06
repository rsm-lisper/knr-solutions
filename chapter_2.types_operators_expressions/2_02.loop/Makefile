
CC=gcc
CFLAGS=-Wall -Werror

CFILES=$(wildcard *.c)

BINARY=loop

all: $(BINARY)

$(BINARY): $(CFILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(BINARY)
