//Nathaniel Goldammer (wsn8pk) 2/2/2022 List.cpp

#include "List.h"
#include <iostream>
using namespace std; 

/* 
Default Constructor: 
Initializes all private data members and 
sets up the basic list structure with the 
dummy head and tail nodes. 
*/
List::List()
{
	//Set count equal to 0 by default
	count = 0;

	//Let head and tail point to a dummy ListNodes by default
	head = new ListNode();
	tail = new ListNode();

	//Set head->next = tail and tail->next = nullptr by default
	head->next = tail; 
	tail->next = nullptr; 

	//Set head->previous = nullptr and tail->previous = head by default
	head->previous = nullptr; 
	tail->previous = head; 
}

/* 
Copy Constructor: 
Creates a new List of ListNodes whose contents 
are the same values as the ListNodes in source. 
*/
List::List(const List& source)
{
	head = new ListNode();
	tail = new ListNode();
	head->next = tail;
	tail->previous = head;
	count = 0;

	//Make a deep copy of the List
	ListItr iter(source.head->next);
	while(!iter.isPastEnd())
	{
		insertAtTail(iter.retrieve());
		iter.moveForward();
	}
}

/* 
Destructor: Empties the List and reclaims the memory 
allocated in the constructor for head and tail. 
*/
List::~List()
{
	//Clear the contents of the List 
	makeEmpty();

	//Reclaim the memory allocated for head and tail
	delete head; 
	delete tail;
}

/* 
Copy Assignment Operator: 
Copies the contents of every ListNode in source into an 
existing List (the reference to the calling List object itself).
*/
List& List::operator=(const List& source)
{
	//If the two Lists are the same
	if(this == &source)
		return *this; 
	else
	{
		//Clear the contents of the List before copying the other List's contents
		makeEmpty();

		//Make a deep copy of the List
		ListItr iter(source.head->next);

		while(!iter.isPastEnd())
		{
			insertAtTail(iter.retrieve());
			iter.moveForward();
		}
	}
	return *this;
}

/* Returns true if the calling List is empty and false if otherwise. */ 
bool List::isEmpty() const
{
	return (count == 0);
}

/* Removes all items except the dummy head/tail. The List should be a working empty list after this. */
void List::makeEmpty()
{
	//Create a ListItr that currently points to the first ListNode in the calling List
	ListItr iterator = first();

	//Create a temporary ListNode* 
	ListNode* temporary;

	//While iterator.isPastEnd() == false
	while(iterator.isPastEnd() == false)
	{
		//Let temporary point to iterator.current
		temporary = iterator.current; 

		//Let iterator point to the next ListNode in the calling List
		iterator.moveForward();

		//Delete the ListNode held in *temporary 
		delete temporary; 

		//Update the count of the calling List
		count--; 
	}

	//Update head->next and tail->previous
	head->next = tail; 
	tail->previous = head; 
}

/* Returns a ListItr that points to the first occurrence of x. When the parameter is not in the List, returns a ListItr that points to the dummy tail node. */
ListItr List::find(int x)
{
	//Create a ListItr that currently points to the first ListNode in the calling List
	ListItr iterator = first();

	//While iterator.isPastEnd() == false
	while(iterator.isPastEnd() == false)
	{
		//If iterator.current->value == x, return iterator
		if(iterator.current->value == x)
			return iterator; 

		//Let iterator point to the next ListNode in the calling List
		iterator.moveForward();
	}

	//Return the iterator 
	return iterator; 
}

/* Removes the first occurance of x. */
void List::remove(int x)
{
	//Create a ListItr that currently points to the first ListNode with a value of x in the calling List
	ListItr iterator = find(x); 

	//If a ListNode with a value of x has been found in the calling List
	if(iterator.current->value == x)
	{
		//Update iterator.current->next->previous and iterator.current->previous->next
		iterator.current->next->previous = iterator.current->previous; 
		iterator.current->previous->next = iterator.current->next; 

		//Delete iterator.current
		delete iterator.current; 

		//Update the count of the calling List
		count--; 
	}
}

/* Returns a ListItr that points to the first ListNode after the dummy head node (even on an empty list) */
ListItr List::first()
{
	return ListItr(head->next);
}

/* Returns a ListItr that points to the last ListNode before the dummy tail node (even on an empty list) */
ListItr List::last()
{
	return ListItr(tail->previous);
}

/* Inserts x after current ListItr position */
void List::insertAfter(int x, ListItr position)
{
	//Create a new ListNode*
	ListNode* node = new ListNode(); 

	//Set node->value equal to x 
	node->value = x; 

	//Set node->previous and node->next 
	node->previous = position.current; 
	node->next = position.current->next; 

	//Update position.current->next->previous and position.current->next 
	position.current->next->previous = node; 
	position.current->next = node; 

	//Update the count of the calling List
	count++;
}

/* Inserts x after before ListItr position */
void List::insertBefore(int x, ListItr position)
{
	//Create a new ListNode*
	ListNode* node = new ListNode(); 

	//Set node->value equal to x 
	node->value = x; 

	//Set node->next and node->previous 
	node->next = position.current;
	node->previous = position.current->previous; 

	//Update position.current->previous->next and position.current->previous
	position.current->previous->next = node; 
	position.current->previous = node; 

	//Update the count of the calling List
	count++;
}

/* Inserts x into the tail of the calling List */
void List::insertAtTail(int x)
{
	//Create a new ListNode*
	ListNode* node = new ListNode();

	//Set node->value equal to x
	node->value = x; 

	//Set node->next and node->previous
	node->next = tail; 
	node->previous = tail->previous; 

	//Update tail->previous->next and tail->previous
	tail->previous->next = node; 
	tail->previous = node; 

	//Update the count of the calling List
	count++; 
}

/* Returns the number of elements in the calling List */ 
int List::size() const
{
	return count;
}

/* Prints the List from head to tail (forward) when forward is true */
void printList(List& source, bool forward)
{
	//If forward == true
	if(forward == true)
	{
		//If the calling List is empty
		if(source.isEmpty() == true)
		{
			//Print a blank line
			cout << " " << endl;

			//Return control back to the driver
			return;
		}

		//Create a ListItr that currently points to the first ListNode in the source
		ListItr iterator = source.first(); 

		//While iterator.isPastEnd() == false
		while(iterator.isPastEnd() == false)
		{
			//Print iterator.retrieve() followed by a space
			cout << iterator.retrieve() << " ";

			//Let iterator point to the next ListNode in the source
			iterator.moveForward();
		}

		//End the current line of character output
		cout << endl; 
	}
	else
	{
		//If the calling List is empty
		if(source.isEmpty() == true)
		{
			//Print a blank line
			cout << " " << endl;

			//Return control back to the driver
			return;
		}

		//Create a ListItr that currently points to the last ListNode in the source
		ListItr iterator = source.last();

		//While iterator.isPastBeginning() == false
		while(iterator.isPastBeginning() == false)
		{
			//Print iterator.retrieve() followed by a space
			cout << iterator.retrieve() << " ";

			//Let iterator point to the previous ListNode in the source
			iterator.moveBackward();
		}

		//End the current line of character output
		cout << endl; 
	}
}