ROOT_DIR:=$(shell dirname $(lastword $(MAKEFILE_LIST)))
SUBDIRS:=$(wildcard $(ROOT_DIR)/*/Makefile)

all: tests subdirs

tests: tests_main.o subdirs

tests_main.o: $(ROOT_DIR)/tests/main.cpp
	c++ --std=c++11 -c $(ROOT_DIR)/tests/main.cpp -o tests_main.o

.PHONY: clean cleanall subdirs $(SUBDIRS)

clean: subdirs

# Separate rule for tests_main.o because it takes a while to build and never changes
cleanall: clean
	$(RM) tests_main.o

subdirs: $(SUBDIRS)

$(SUBDIRS):
	make -f $@ SUB_NAME=$(shell basename $(shell dirname $@)) ROOT_DIR=$(ROOT_DIR) $(MAKECMDGOALS)
