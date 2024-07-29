
CFILES=$(wildcard *.c)
TESTDIR=tests/
TESTS=$(wildcard $(TESTDIR)*.tin)
TEST_RESULTS=$(patsubst %.tin,%.res,$(TESTS))

CC=gcc
CFLAGS=-Wall -Wextra -Werror -ggdb -std=c89

ANSI_COLORS=$(shell tput colors 2>/dev/null)
ifeq ($(ANSI_COLORS),$(filter $(ANSI_COLORS),8 16 88 256))
ANSIRED="\033[31m"
ANSIGREEN="\033[32m"
ANSIYELLOW="\033[33m"
ANSIBOLD="\033[1m"
ANSIRST="\033[0m"
DIFFCOLOR="always"
else
ANSIRED=""
ANSIGREEN=""
ANSIYELLOW=""
ANSIBOLD=""
ANSIRST=""
DIFFCOLOR="never"
endif
ANSIGOK=" ["$(ANSIGREEN)"OK"$(ANSIRST)"] "
ANSIYBIN=$(ANSIYELLOW)$(BINARY)$(ANSIRST)

MAKEFLAGS+=--silent

all: $(BINARY)

$(BINARY): $(CFILES)
	echo -n " - Building "$(ANSIYBIN)":"
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)
	echo $(ANSIGOK)

check: $(TEST_RESULTS)
	echo "** "$(ANSIBOLD)$(ANSIYBIN)" test results:"$(ANSIBOLD)$(ANSIGOK)

%.res: TESTNAME=$(strip $(patsubst $(TESTDIR)%.tin,%,$?))
%.res: TESTARGS=$$(cat $(strip $(patsubst %.tin,%.targs,$?)) 2>/dev/null)
%.res: TESTOUT=$(strip $(patsubst %.tin,%.tout,$?))
%.res: TESTERR=$(strip $(patsubst %.tin,%.terr,$?))
%.res: %.tin
	echo -n " - testing "$(ANSIBOLD)$(BINARY)$(ANSIRST)":" \
		$(ANSIYELLOW)$(TESTNAME)$(ANSIRST)
ifeq (,$(wildcard $(BINARY)))
	echo "\n"$(ANSIRED)"Error! "$(ANSIBOLD)"./"$(BINARY)$(ANSIRST)$(ANSIRED)" not found." \
		"Please 'make'."$(ANSIRST)
	false
else
	./$(BINARY) $(TESTARGS) <$? >$@ult 2>$@ult_err || true
	diff --color=$(DIFFCOLOR) --text $@ult $(TESTOUT)
	if [ -f $(strip $(TESTERR)) ]; then \
		diff --color=$(DIFFCOLOR) --text $@ult_err $(TESTERR); \
	fi
	echo $(ANSIGOK)
endif

clean:
	echo -n " - Cleaning "$(ANSIYBIN)":"
	rm -f $(BINARY)
	rm -f $(TESTDIR)*.result
	rm -f $(TESTDIR)*.result_err
	echo $(ANSIGOK)
