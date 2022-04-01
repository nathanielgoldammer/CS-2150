//Nathaniel Goldammer (wsn8pk) 2/8/2022 iteratorr.cpp

#include "iteratorr.h"
#include <iostream>
using namespace std; 

//Default Constructor
iteratorr::iteratorr()
{
	//Default current
	current = nullptr; 
}

//Overloaded Constructor
iteratorr::iteratorr(node* theNode)
{
	//Set current = theNode
	current = theNode;
}

//Returns true if the iteratorr is currently pointing to the tail, and false if otherwise
bool iteratorr::isPastEnd() const
{
	if(current->next == nullptr)
		return true; 
	else
		return false;
}

//Returns true if the iteratorr is currently pointing to the head, and false if otherwise
bool iteratorr::isPastBeginning() const
{
	if(current->previous == nullptr)
		return true; 
	else
		return false;
}

//Points current to the next position in the list if current is not already pointing past the tail of the list
void iteratorr::moveForward()
{
	if(isPastEnd() == false)
		current = current->next;
}

//Points current to the previous position in the list if current is not already pointing past the head of the list
void iteratorr::moveBackward()
{
	if(isPastBeginning() == false)
		current = current->previous;
}

//Returns the value of the element in the current position of the list
int iteratorr::retrieve() const
{
	return current->value; 
}