CXX=g++
LIBPATH=../../libfile/
HEADPATH=../../parser/
LIBNAME=JJparser
BIN=test_target
CXXFLAGS=-g -std=c++11 -Wall -c -W -L$(LIBPATH) -l$(LIBNAME) -I$(HEADPATH)

SRC=ExpressionTree.cpp Test.cpp
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^ -L$(LIBPATH) -l$(LIBNAME)

%.o: %.c
	$(CXX) $@ -c $<

clean:
	rm -f *.o $(BIN) core*
