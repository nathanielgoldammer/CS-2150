//Nathaniel Goldammer (wsn8pk) 1/31/2022 List.cpp

#include "List.h"
#include <iostream>
using namespace std; 

/* Default Constructor: Initializes all private data members and sets up the basic list structure with the dummy head and tail nodes. */
List::List()
{
	count = 0; //The count (number of elements in the List) is 0 by default

	head = new ListNode; //ListNode* head points to a dummy ListNode by default
	tail = new ListNode; //ListNode* tail points to a dummy ListNode by default

	head->next = tail; //The ListNode* next of the dummy ListNode in *head points to the dummy ListNode* tail by default
	tail->next = nullptr; //The ListNode* next of the dummy ListNode in *tail is a nullptr by default

	head->previous = nullptr; //The ListNode* previous of the dummy ListNode in *head is a nullptr by default
	tail->previous = head; //The ListNode* previous of the dummy ListNode in *tail points to the dummy ListNode* head by default
}

/* Copy Constructor: Creates a **new** List of ListNodes whose contents are the same values as the ListNodes in source. */
List::List(const List& source){}
/* Destructor: Empties the List and reclaims the memory allocated in the constructor for head and tail. */
List::~List(){}
/* Copy Assignment Operator: Copies the contents of every ListNode in source into an **existing** List (the reference to the calling List object itself).*/
List& List::operator=(const List& source)
{
	return *this; //Dummy Return Value
}
/* Returns true if the calling List is empty and false if otherwise. */ 
bool List::isEmpty() const
{
	return false; //Dummy Return Value
}
/* Removes (deletes) all items except the dummy head/tail. The list should be a working empty list after this. */
void List::makeEmpty(){}

/* Returns a ListItr that points to the first ListNode **after** the dummy head node (even on an empty list) */
ListItr List::first()
{
	return ListItr(head->next);
}
/* Returns a ListItr that points to the last ListNode **before** the dummy tail node (even on an empty list) */
ListItr List::last()
{
	return NULL; //Dummy Return Value
}

/* Inserts x after current ListItr position */
void List::insertAfter(int x, ListItr position){}

/* Inserts x after before ListItr position */
void List::insertBefore(int x, ListItr position){}

/* Inserts x into the tail of the calling List */
void List::insertAtTail(int x)
{
	ListNode* node = new ListNode; //Let the ListNode* node point to a new ListNode
	node->value = x; //Set the value of the ListNode in *node equal to x

	node->next = tail; //Let the ListNode* next of the ListNode in *node point to the ListNode* tail
	node->previous = tail->previous; //Let the ListNode* previous of the ListNode in *node point to the ListNode* previous of the ListNode* tail

	tail->previous->next = node; //Let the ListNode* next of the ListNode* previous of the ListNode* tail point to the ListNode* node
	tail->previous = node; //Let the ListNode* previous of the ListNode* tail point to the ListNode* node

	count++; //Update the count (number of elements) of the List
}

/* Returns a ListItr that points to the first occurrence of x. When the parameter is not in the List, returns a ListItr that points to the dummy tail node. */
ListItr List::find(int x)
{
	return NULL;
}

/* Removes the first occurance of x. */
void List::remove(int x){}

/* Returns the number of elements in the calling List */ 
int List::size() const
{
	return count;
}

/* Prints the List from head to tail (forward) when forward is true */
void printList(List& source, bool forward)
{
	if(forward == true)
	{
		ListItr iterator = source.first(); //Obtain a ListItr that currently points to the first ListNode* after the dummy head ListNode in source
		while(iterator.isPastEnd() == false)
		{
			cout << iterator.retrieve() << " ";
			iterator.moveForward();
		}
		cout << endl;
	}
}