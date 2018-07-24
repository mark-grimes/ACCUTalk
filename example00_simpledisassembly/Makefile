THIS_DIR:=$(shell dirname $(lastword $(MAKEFILE_LIST)))
CPP_STD:=c++98


OPTIMISATION:=0

all: $(SUB_NAME)




$(SUB_NAME): $(THIS_DIR)/Makefile $(SUB_NAME).o
	c++ --std=$(CPP_STD) -O$(OPTIMISATION) $(SUB_NAME).o -o $(SUB_NAME)

$(SUB_NAME).o: $(THIS_DIR)/Makefile $(THIS_DIR)/main.cpp
	c++ --std=$(CPP_STD) -O$(OPTIMISATION) -c -g $(THIS_DIR)/main.cpp -o $(SUB_NAME).o

.PHONY: clean

clean:
	$(RM) $(SUB_NAME) $(SUB_NAME).o

cleanall: clean
