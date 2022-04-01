//Nathaniel Goldammer (wsn8pk) 1/31/2022 ListItr.cpp
#include "ListItr.h"
#include <iostream>
using namespace std; 

/* Default Constructor */
ListItr::ListItr()
{
	current = nullptr; //The ListNode* current is a nullptr by default
}
/* Overloaded Constructor */
ListItr::ListItr(ListNode* theNode)
{
	current = theNode; //Set the ListNode* current to the ListNode* theNode
}
/* Returns true if the ListItr is currently pointing to the dummy tail, and false if otherwise */
bool ListItr::isPastEnd() const
{
	if(current->next == nullptr)
		return true; 
	else
		return false;
}
/* Returns true if the ListItr is currently pointing to the dummy head, and false if otherwise */
bool ListItr::isPastBeginning() const
{
	if(current->previous == nullptr)
		return true; 
	else
		return false;
}
/* Points current to the next position in the List if current is not already pointing past the tail of the List */
void ListItr::moveForward()
{
	if(isPastEnd() == false)
		current = current->next;
}
/* Points current to the previous position in the List if current is not already pointing past the head of the List */
void ListItr::moveBackward()
{
	if(isPastBeginning() == false)
		current = current->previous;
}
/* Returns the value of the element in the current position of the List */
int ListItr::retrieve() const
{
	return current->value; 
}