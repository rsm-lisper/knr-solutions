
CC=gcc
CFLAGS=-Wall -Werror

CFILES=$(wildcard *.c)

BINARY=trim_lines

all: $(BINARY)

$(BINARY): $(CFILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(BINARY)
