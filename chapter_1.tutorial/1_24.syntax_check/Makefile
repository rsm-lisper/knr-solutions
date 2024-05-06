
CC=gcc
CFLAGS=-Wall -Werror

CFILES=$(wildcard *.c)

BINARY=syntax_check

all: $(BINARY)

$(BINARY): $(CFILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(BINARY)
