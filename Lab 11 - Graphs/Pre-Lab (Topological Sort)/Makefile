#Nathaniel Goldammer (wsn8pk) - April 26, 2022 - Makefile

CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -o2
DEBUG = -g
OBJECTS = middleearth.o topological.o 

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	doxygen

middleearth.o: middleearth.h middleearth.cpp
topological.o: topological.cpp

.PHONEY: clean
clean: 
	-rm -f *.o a.out