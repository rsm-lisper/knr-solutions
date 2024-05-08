BINARY=htoi

CFILES=$(wildcard *.c)
TESTDIR=./tests/
TESTS=$(wildcard $(TESTDIR)*.tin)
TEST_RESULTS=$(patsubst %.tin,%.res,$(TESTS))

CC=gcc
CFLAGS=-Wall -Wextra -Werror -ggdb -std=c89


all: $(BINARY)

$(BINARY): $(CFILES)
	$(CC) $(CFLAGS) -o $@ $^

test: $(TEST_RESULTS)

%.res: %.tin
	$(info Performing $(patsubst %.tin,%,$?) test:)
	@./$(BINARY) <$? >$@ult
	@if diff $@ult $(patsubst %.tin,%.tout,$?) >/dev/null; then \
		echo "ok"; \
		rm $@ult; \
	else \
		echo "ERROR! Test result diff (received vs expected):"; \
		diff --color=always --text $@ult $(patsubst %.tin,%.tout,$?); \
	fi

clean:
	rm -f $(BINARY)
	rm -f $(TESTDIR)*.result
