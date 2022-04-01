//Nathaniel Goldammer (wsn8pk) 2/8/2022 stack.cpp

#include "stack.h"
#include <iostream>
using namespace std; 

//Default Constructor
stack::stack()
{
	//The stack is implemented interally as a list
	stacc = new list();
}

//Destructor 
stack::~stack()
{
	//Delete stack's underlying list 
	delete stacc;
}

//Pushes the int parameter e into the stack
void stack::push(int e)
{
	stacc->insertAtTail(e);
}

//Removes the top element from the stack 
void stack::pop()
{
	//Create an iteratorr that currently points to the last node before the dummy tail node
	iteratorr iter = stacc->last();

	//Retrieve the value of iter
	int x = iter.retrieve();

	//Remove x from the stack
	stacc->remove(x);
}

//Returns the top element from the stack 
int stack::top()
{
	//Create an iteratorr that currently points to the last node before the dummy tail node
	iteratorr iter = stacc->last();

	//Return the value of iter
	return iter.retrieve();
}

//Returns if the stack is empty, and false if otherwise
bool stack::empty()
{
	return stacc->isEmpty();
}