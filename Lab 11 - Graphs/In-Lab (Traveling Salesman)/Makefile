#Nathaniel Goldammer (wsn8pk) - April 27, 2022 - Makefile

CXX = clang++ 
CXXFLAGS = -Wall -std=c++20 -o2
DEBUG = -g
OBJECTS = middleearth.o traveling.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	doxygen

clean: 
	-rm -f *.o a.out