ROOT_DIR:=$(shell dirname $(lastword $(MAKEFILE_LIST)))

tests: tests_main.o $(ROOT_DIR)/example4/tests.cpp
	c++ tests_main.o $(ROOT_DIR)/example4/tests.cpp -o tests -I$(ROOT_DIR)/tests

tests_main.o: $(ROOT_DIR)/tests/main.cpp
	c++ -c $(ROOT_DIR)/tests/main.cpp -o tests_main.o

.PHONY: clean
clean:
	$(RM) *.o tests
