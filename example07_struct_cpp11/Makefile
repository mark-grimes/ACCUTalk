THIS_DIR:=$(shell dirname $(lastword $(MAKEFILE_LIST)))
HEADERS:=$(wildcard $(THIS_DIR)/*.h)
CPP_STD:=c++11
OPTIMISATION:=0

all: $(SUB_NAME) $(SUB_NAME)Tests

$(SUB_NAME)Tests: $(HEADERS) $(THIS_DIR)/Makefile tests_main.o $(THIS_DIR)/tests.cpp
	c++ -O$(OPTIMISATION) tests_main.o $(THIS_DIR)/tests.cpp -o $(SUB_NAME)Tests -I$(ROOT_DIR)/tests

$(SUB_NAME): $(HEADERS) $(THIS_DIR)/Makefile $(SUB_NAME).o $(THIS_DIR)/main.cpp
	c++ --std=$(CPP_STD) -O$(OPTIMISATION) $(SUB_NAME).o $(THIS_DIR)/main.cpp -o $(SUB_NAME)

$(SUB_NAME).o: $(HEADERS) $(THIS_DIR)/Makefile $(THIS_DIR)/myMain.cpp
	c++ --std=$(CPP_STD) -O$(OPTIMISATION) -c -g $(THIS_DIR)/myMain.cpp -o $(SUB_NAME).o

.PHONY: clean

clean:
	$(RM) $(SUB_NAME) $(SUB_NAME).o $(SUB_NAME)Tests

cleanall: clean
