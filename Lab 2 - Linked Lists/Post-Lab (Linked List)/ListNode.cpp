//Nathaniel Goldammer (wsn8pk) 2/2/2022 ListNode.cpp

#include "ListNode.h"
#include <iostream>
using namespace std;

ListNode::ListNode()
{
	//Set value = 0 by default
	value = 0;

	//Set next = nullptr and previous = nullptr by default
	next = nullptr; 
	previous = nullptr;
}