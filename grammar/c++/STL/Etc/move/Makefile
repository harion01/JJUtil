CXX=g++
#CXXFLAGS=-g -std=c++11 -Wall -c -W --no-elide-constructors
CXXFLAGS=-g -std=c++11 -Wall -c -W
BIN=test_target

SRC=move_as_constructor.cpp
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^

%.o: %.c
	$(CXX) $@ -c $<

clean:
	rm -f *.o $(BIN) core*
