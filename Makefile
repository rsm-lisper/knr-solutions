SUBDIRS=$(wildcard chapter_*/)

TOPTARGETS=all check clean

$(TOPTARGETS): $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS)  $(SUBDIRS)
