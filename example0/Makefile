THIS_DIR:=$(shell dirname $(lastword $(MAKEFILE_LIST)))
CPP_STD:="c++98"

all: $(SUB_NAME)

$(SUB_NAME): $(SUB_NAME).o
	c++ --std=$(CPP_STD) $(SUB_NAME).o -o $(SUB_NAME)

$(SUB_NAME).o: $(THIS_DIR)/main.cpp
	c++ --std=$(CPP_STD) -c -g $(THIS_DIR)/main.cpp -o $(SUB_NAME).o

.PHONY: clean

clean:
	$(RM) $(SUB_NAME) $(SUB_NAME).o

cleanall: clean
