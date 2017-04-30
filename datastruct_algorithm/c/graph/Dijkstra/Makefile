.SUFFIXES : .c .o .cpp   
#surfix format for target file

OBJECTS =ShortestPath.o PriorityQueue.o Graph.o Test.o
#object file name

CC = g++
#compiler

CFLAGS = -g -c -W -Wall
#g++/gcc option macro

TARGET = test_target
#target file name

.c.o.cpp:
	$(CC) $(CFLAGS) $
#object file making option


$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^
#target file making option

clean:
	rm -rf $(OBJECTS) $(TARGET) core
#clean command option
