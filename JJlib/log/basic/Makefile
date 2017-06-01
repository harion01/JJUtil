CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -c -W
SYSLIBS=-lpthread
BIN=test_target

SRC=test.cpp JJlog.cpp

OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^ $(SYSLIBS)

%.o: %.c
	$(CXX) $@ -c $<

clean:
	rm -f *.o $(BIN) core* *.log
