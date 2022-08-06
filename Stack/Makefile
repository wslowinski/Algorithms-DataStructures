CXX = g++
CXXFLAGS = -c
DIR = `basename $(CURDIR)`

all: Stack.x Generator.x ONP.x

ONP.x: ONP.o ArrayStack.o
	$(CXX) ONP.o ArrayStack.o -o ONP.x

ONP.o: ONP.cpp ArrayStack.h
	$(CXX) $(CXXFLAGS) ONP.cpp

ArrayStack.o: ArrayStack.cpp ArrayStack.h
	$(CXX) $(CXXFLAGS) ArrayStack.cpp

Generator.x: Generator.o
	$(CXX) Generator.o -o Generator.x

Generator.o: Generator.cpp
	$(CXX) $(CXXFLAGS) Generator.cpp

Stack.x: Stack.o LinkedStack.o
	$(CXX) Stack.o LinkedStack.o -o Stack.x

Stack.o: Stack.cpp LinkedStack.h
	$(CXX) $(CXXFLAGS) Stack.cpp

LinkedStack.o: LinkedStack.cpp LinkedStack.h
	$(CXX) $(CXXFLAGS) LinkedStack.cpp

.PHONY: clean
clean:                                                     
	rm -f *.o Stack.x Generator.x ONP.x
