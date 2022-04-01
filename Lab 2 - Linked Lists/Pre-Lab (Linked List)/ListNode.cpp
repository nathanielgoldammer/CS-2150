//Nathaniel Goldammer (wsn8pk) 1/31/2022 ListNode.cpp

#include "ListNode.h"
#include <iostream>
using namespace std;

ListNode::ListNode()
{
	value = 0; //Default int Value
	next = nullptr; //ListNode* next is a nullptr by default
	previous = nullptr; //ListNode* previous is a nullptr by default
}