SUBDIRS=$(wildcard chapter_*/)

TOPTARGETS=all check clean

ANSIGREEN="\033[32m"
ANSIYELLOW="\033[33m"
ANSIBOLD="\033[1m"
ANSIRST="\033[0m"
ANSIGOK=" ["$(ANSIGREEN)"OK"$(ANSIRST)"] "

MAKEFLAGS+=--silent

$(TOPTARGETS): $(SUBDIRS)

$(SUBDIRS):
	echo "* Directory "$(ANSIBOLD)$(ANSIYELLOW)$@$(ANSIRST)":"
	$(MAKE) -C $@ $(MAKECMDGOALS)
	echo " "$(ANSIYELLOW)$@$(ANSIRST)" done.\n"

.PHONY: $(TOPTARGETS) $(SUBDIRS)
