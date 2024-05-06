
CC=gcc
CFLAGS=-Wall -Werror

CFILES=$(wildcard *.c)

BINARY=char_histogram

all: $(BINARY)

$(BINARY): $(CFILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(BINARY)
