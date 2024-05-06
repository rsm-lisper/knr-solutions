
CC=gcc
CFLAGS=-Wall -Werror

CFILES=$(wildcard *.c)

BINARY=visible_esc

all: $(BINARY)

$(BINARY): $(CFILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(BINARY)
