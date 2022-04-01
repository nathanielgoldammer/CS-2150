#Nathaniel Goldammer (wsn8pk) - April 1, 2022 - Makefile

CXX = clang++
CXXFLAGS = -Wall -g
AS = nasm
ASFLAGS = -f macho64 -g
OBJECTS = linearSearch.o testLinearSearch.o 

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
clean:
	-rm -f *.o *~