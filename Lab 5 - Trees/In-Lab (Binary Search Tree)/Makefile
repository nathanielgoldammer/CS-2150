#Nathaniel Goldammer (wsn8pk) 3/1/2022 Makefile

CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -o2
DEBUG = -g
OBJECTS = BinaryNode.o BinarySearchTree.o BSTPathTest.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "The Binary Search Tree is Compiled."

BinaryNode.o: BinaryNode.h BinaryNode.cpp

BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp

BSTPathTest.o: BSTPathTest.cpp

.PHONEY: clean
clean: 
	-rm -f *.o a.out