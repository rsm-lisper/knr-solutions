SUBDIRS=$(wildcard 2_*/)

TOPTARGETS=all check clean

MAKEFLAGS+=--silent

$(TOPTARGETS): $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS)  $(SUBDIRS)
