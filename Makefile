ROOT_DIR:=$(shell dirname $(lastword $(MAKEFILE_LIST)))
SUBDIRS:=$(wildcard $(ROOT_DIR)/*/Makefile)

all: tests subdirs

tests: tests_main.o $(ROOT_DIR)/example4/tests.cpp
	c++ tests_main.o $(ROOT_DIR)/example4/tests.cpp -o tests -I$(ROOT_DIR)/tests

tests_main.o: $(ROOT_DIR)/tests/main.cpp
	c++ -c $(ROOT_DIR)/tests/main.cpp -o tests_main.o

.PHONY: clean subdirs $(SUBDIRS)

clean: subdirs
	$(RM) tests_main.o tests

subdirs: $(SUBDIRS)

$(SUBDIRS):
	make -f $@ SUB_NAME=$(shell basename $(shell dirname $@)) ROOT_DIR=$(ROOT_DIR) $(MAKECMDGOALS)
