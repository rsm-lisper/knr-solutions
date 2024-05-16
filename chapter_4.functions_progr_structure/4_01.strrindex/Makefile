BINARY=strrindex

CFILES=$(wildcard *.c)
TESTDIR=tests/
TESTS=$(wildcard $(TESTDIR)*.tin)
TEST_RESULTS=$(patsubst %.tin,%.res,$(TESTS))

CC=gcc
CFLAGS=-Wall -Wextra -Werror -ggdb -std=c89

ANSIGREEN="\033[32m"
ANSIYELLOW="\033[33m"
ANSIBOLD="\033[1m"
ANSIRST="\033[0m"
ANSIGOK=" ["$(ANSIGREEN)"OK"$(ANSIRST)"] "

all: $(BINARY)

$(BINARY): $(CFILES)
	$(CC) $(CFLAGS) -o $@ $^

check: $(TEST_RESULTS)
	@echo $(ANSIBOLD)$(BINARY)$(ANSIRST) test results:$(ANSIBOLD)$(ANSIGOK)

%.res: %.tin
	@echo -n "- Testing "$(ANSIBOLD)$(BINARY)$(ANSIRST): \
		$(ANSIYELLOW)$(patsubst $(TESTDIR)%.tin,%,$?)$(ANSIRST)
	@./$(BINARY) <$? >$@ult
	@diff --color=always --text $@ult $(patsubst %.tin,%.tout,$?)
	@echo $(ANSIGOK)

clean:
	rm -f $(BINARY)
	rm -f $(TESTDIR)*.result
