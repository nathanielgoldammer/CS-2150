#Nathaniel Goldammer (wsn8pk) 3/1/2022 Makefile

CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -O2
DEBUG = -g

OBJECTS = TreeNode.o TreeCalc.o TreeCalcTest.o
	
a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "The Expession Tree is Compiled."

TreeNode.o: TreeNode.h TreeNode.cpp

TreeCalc.o: TreeCalc.h TreeCalc.cpp TreeNode.h

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h

.PHONEY: clean
clean:
	-rm -f *.o a.out