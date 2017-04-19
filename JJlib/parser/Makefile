CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -c -W -fPIC
BIN=test_target

SRC=test.cpp JJparser.cpp
LIBSRC=JJparser.cpp

OBJ=$(SRC:%.cpp=%.o)
LIBOBJ=$(LIBSRC:%.cpp=%.o)
STA_LIBFILE=lib$(LIBSRC:%.cpp=%.a)
DYN_LIBFILE=lib$(LIBSRC:%.cpp=%.so)
VER=0.0.1
LIBPATH=../libfile/

all: $(OBJ)
	$(CXX) -o $(BIN) $^

%.o: %.c
	$(CXX) $@ -c $<

lib: 
	ar rc $(STA_LIBFILE) $(LIBOBJ) 
	$(CXX) -shared -Wl,-soname,$(DYN_LIBFILE) -o $(DYN_LIBFILE).$(VER) $(LIBOBJ)
	chmod 777 $(STA_LIBFILE)
	chmod 777 $(DYN_LIBFILE).$(VER)
	cp lib* $(LIBPATH)

clean:
	rm -f *.o $(BIN) core* $(STA_LIBFILE) $(DYN_LIBFILE).$(VER)
