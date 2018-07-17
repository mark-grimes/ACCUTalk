THIS_DIR:=$(shell dirname $(lastword $(MAKEFILE_LIST)))

all: $(SUB_NAME)Tests

$(SUB_NAME)Tests: tests_main.o $(THIS_DIR)/tests.cpp
	c++ tests_main.o $(THIS_DIR)/tests.cpp -o $(SUB_NAME)Tests -I$(ROOT_DIR)/tests

.PHONY: clean

clean:
	$(RM) $(SUB_NAME)Tests
