BINARY=fahr_celsius_revers

CC=gcc
CFLAGS=-Wall -Wextra -Werror -g -std=c89

CFILES=$(wildcard *.c)


all: $(BINARY)

$(BINARY): $(CFILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(BINARY)
