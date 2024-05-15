BINARY=itob

CFILES=$(wildcard *.c)
TESTDIR=./tests/
TESTS=$(wildcard $(TESTDIR)*.tin)
TEST_RESULTS=$(patsubst %.tin,%.res,$(TESTS))

CC=gcc
CFLAGS=-Wall -Wextra -Werror -ggdb -std=c89


all: $(BINARY)

$(BINARY): $(CFILES)
	$(CC) $(CFLAGS) -o $@ $^

check: $(TEST_RESULTS)

%.res: %.tin
	@./$(BINARY) <$? >$@ult
	@diff --color=always --text $@ult $(patsubst %.tin,%.tout,$?)

clean:
	rm -f $(BINARY)
	rm -f $(TESTDIR)*.result
