//Nathaniel Goldammer (wsn8pk) 2/8/2022 node.cpp

#include "node.h"
#include <iostream>
using namespace std; 

//Default Constructor
node::node()
{
	//Default value
	value = 0;

	//Default next and previous
	next = nullptr; 
	previous = nullptr;
}