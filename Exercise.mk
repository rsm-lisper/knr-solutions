
CFILES=$(wildcard *.c)
TESTDIR=tests/
TESTS=$(wildcard $(TESTDIR)*.tin)
TEST_RESULTS=$(patsubst %.tin,%.res,$(TESTS))

CC=gcc
CFLAGS=-Wall -Wextra -Werror -ggdb -std=c89

ANSI_COLORS=$(shell tput colors 2>/dev/null)
ifeq ($(ANSI_COLORS),$(filter $(ANSI_COLORS),8 16 88 256))
 ANSIGREEN="\033[32m"
 ANSIYELLOW="\033[33m"
 ANSIBOLD="\033[1m"
 ANSIRST="\033[0m"
 ANSIGOK=" ["$(ANSIGREEN)"OK"$(ANSIRST)"] "
 ANSIYBIN=$(ANSIYELLOW)$(BINARY)$(ANSIRST)
else
 ANSIGREEN=""
 ANSIYELLOW=""
 ANSIBOLD=""
 ANSIRST=""
 ANSIGOK=" [OK] "
 ANSIYBIN=$(BINARY)
endif

MAKEFLAGS+=--silent

all: $(BINARY)

$(BINARY): $(CFILES)
	echo -n " - Building "$(ANSIYBIN)":"
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)
	echo $(ANSIGOK)

check: $(TEST_RESULTS)
	echo "** "$(ANSIBOLD)$(ANSIYBIN)" test results:"$(ANSIBOLD)$(ANSIGOK)

%.res: %.tin
	echo -n " - testing "$(ANSIBOLD)$(BINARY)$(ANSIRST)":" \
		$(ANSIYELLOW)$(patsubst $(TESTDIR)%.tin,%,$?)$(ANSIRST)
	TEST_ARGS=$$(cat $(patsubst %.tin,%.targs,$?) 2>/dev/null) ; \
	./$(BINARY) $$TEST_ARGS <$? >$@ult
	diff --color=always --text $@ult $(patsubst %.tin,%.tout,$?)
	echo $(ANSIGOK)

clean:
	echo -n " - Cleaning "$(ANSIYBIN)":"
	rm -f $(BINARY)
	rm -f $(TESTDIR)*.result
	echo $(ANSIGOK)
