#Nathaniel Goldammer (wsn8pk) - March 30th, 2022 - Makefile

CXX = clang++
CXXFLAGS = -Wall -g
AS = nasm
ASFLAGS = -f macho64 -g
OBJECTS = mergeSort.o testMergeSort.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~