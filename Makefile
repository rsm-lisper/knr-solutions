SUBDIRS=$(wildcard chapter_*/)

TOPTARGETS=all check clean

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

MAKEFLAGS+=--silent

$(TOPTARGETS): $(SUBDIRS)

$(SUBDIRS):
	echo "* Directory "$(ANSIBOLD)$(ANSIYELLOW)$@$(ANSIRST)":"
	$(MAKE) -C $@ $(MAKECMDGOALS)
	echo " "$(ANSIYELLOW)$@$(ANSIRST)" done.\n"

.PHONY: $(TOPTARGETS) $(SUBDIRS)
