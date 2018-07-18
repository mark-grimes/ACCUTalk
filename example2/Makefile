THIS_DIR:=$(shell dirname $(lastword $(MAKEFILE_LIST)))
CPP_STD:=c++98
OPTIMISATION:=0

all: $(SUB_NAME) $(SUB_NAME)Tests

$(SUB_NAME)Tests: tests_main.o $(THIS_DIR)/tests.cpp
	c++ -O$(OPTIMISATION) tests_main.o $(THIS_DIR)/tests.cpp -o $(SUB_NAME)Tests -I$(ROOT_DIR)/tests

$(SUB_NAME): $(SUB_NAME).o $(THIS_DIR)/main.cpp
	c++ --std=$(CPP_STD) -O$(OPTIMISATION) $(SUB_NAME).o $(THIS_DIR)/main.cpp -o $(SUB_NAME)

$(SUB_NAME).o: $(THIS_DIR)/myMain.cpp
	c++ --std=$(CPP_STD) -O$(OPTIMISATION) -c -g $(THIS_DIR)/myMain.cpp -o $(SUB_NAME).o

.PHONY: clean

clean:
	$(RM) $(SUB_NAME) $(SUB_NAME).o $(SUB_NAME)Tests

cleanall: clean
