//Nathaniel Goldammer (wsn8pk) 2/8/2022 list.cpp

#include "list.h"
#include <iostream>
using namespace std; 

//Default Constructor: Initializes all private data members and sets up the basic list structure with the dummy head and tail nodes.
list::list()
{
	//Set count equal to 0 by default
	count = 0;

	//Let head and tail point to a dummy nodes by default
	head = new node();
	tail = new node();

	//Set head->next = tail and tail->next = nullptr by default
	head->next = tail; 
	tail->next = nullptr; 

	//Set head->previous = nullptr and tail->previous = head by default
	head->previous = nullptr; 
	tail->previous = head; 
}

//Copy Constructor: Creates a new list of nodes whose contents are the same values as the nodes in source.
list::list(const list& source)
{
	head = new node();
	tail = new node();
	head->next = tail;
	tail->previous = head;
	count = 0;

	//Make a deep copy of the List
	iteratorr iter(source.head->next);
	while(!iter.isPastEnd())
	{
		insertAtTail(iter.retrieve());
		iter.moveForward();
	}
}

//Destructor: Empties the list and reclaims the memory allocated in the constructor for head and tail.
list::~list()
{
	//Clear the contents of the list 
	makeEmpty();

	//Reclaim the memory allocated for head and tail
	delete head; 
	delete tail;
}

//Copy Assignment Operator: Copies the contents of every node in source into an existing list (the reference to the calling list object itself).
list& list::operator=(const list& source)
{
	//If the two lists are the same
	if(this == &source)
		return *this; 
	else
	{
		//Clear the contents of the list before copying the other list's contents
		makeEmpty();

		//Make a deep copy of the List
		iteratorr iter(source.head->next);

		while(!iter.isPastEnd())
		{
			insertAtTail(iter.retrieve());
			iter.moveForward();
		}
	}
	return *this;
}

//Returns true if the calling list is empty and false if otherwise. 
bool list::isEmpty() const
{
	return (count == 0);
}

//Removes all items except the dummy head/tail. The list should be a working empty list after this.
void list::makeEmpty()
{
	//Create an iteratorr that currently points to the first node in the calling list
	iteratorr iter = first();

	//Create a temporary node*
	node* temporary;

	//While iter.isPastEnd() == false
	while(iter.isPastEnd() == false)
	{
		//Let temporary point to iter.current
		temporary = iter.current; 

		//Let iter point to the next node in the calling list
		iter.moveForward();

		//Delete the node held in *temporary 
		delete temporary; 

		//Update the count of the calling list
		count--; 
	}

	//Update head->next and tail->previous
	head->next = tail; 
	tail->previous = head; 
}

//Returns an iteratorr that points to the first occurrence of x. When the parameter is not in the list, returns an iteratorr that points to the dummy tail node.
iteratorr list::find(int x)
{
	//Create an iteratorr that currently points to the last node in the calling list
	iteratorr iter = last();

	//While iter.isPastBeginning() == false
	while(iter.isPastBeginning() == false)
	{
		//If iter.current->value == x, return iter
		if(iter.current->value == x)
			return iter; 

		//Let iter point to the previous node in the calling list
		iter.moveBackward();
	}

	//Return iter
	return iter; 
}

//Removes the first occurance of x. 
void list::remove(int x)
{
	//Create an iteratorr that currently points to the first node with a value of x in the calling list
	iteratorr iter = find(x); 

	//If a node with a value of x has been found in the calling list
	if(iter.current->value == x)
	{
		//Update iter.current->next->previous and iter.current->previous->next
		iter.current->next->previous = iter.current->previous; 
		iter.current->previous->next = iter.current->next; 

		//Delete iter.current
		delete iter.current; 

		//Update the count of the calling list
		count--; 
	}
}

//Returns an iteratorr that points to the first node after the dummy head node (even on an empty list)
iteratorr list::first()
{
	return iteratorr(head->next);
}

//Returns an iteratorr that points to the last node before the dummy tail node (even on an empty list)
iteratorr list::last()
{
	return iteratorr(tail->previous);
}

//Inserts x after current iteratorr position 
void list::insertAfter(int x, iteratorr position)
{
	//Create a new node*
	node* n = new node(); 

	//Set n->value equal to x 
	n->value = x; 

	//Set n->previous and n->next 
	n->previous = position.current; 
	n->next = position.current->next; 

	//Update position.current->next->previous and position.current->next 
	position.current->next->previous = n; 
	position.current->next = n; 

	//Update the count of the calling list
	count++;
}

//Inserts x after before iteratorr position
void list::insertBefore(int x, iteratorr position)
{
	//Create a new node*
	node* n = new node(); 

	//Set n->value equal to x 
	n->value = x; 

	//Set n->next and n->previous 
	n->next = position.current;
	n->previous = position.current->previous; 

	//Update position.current->previous->next and position.current->previous
	position.current->previous->next = n; 
	position.current->previous = n; 

	//Update the count of the calling list
	count++;
}

//Inserts x into the tail of the calling list
void list::insertAtTail(int x)
{
	//Create a new node*
	node* n = new node();

	//Set n->value equal to x
	n->value = x; 

	//Set n->next and n->previous
	n->next = tail; 
	n->previous = tail->previous; 

	//Update tail->previous->next and tail->previous
	tail->previous->next = n; 
	tail->previous = n; 

	//Update the count of the calling list
	count++; 
}

//Returns the number of elements in the calling list
int list::size() const
{
	return count;
}

//Prints the list from head to tail (forward) if forward is true, and prints the list from tail to head (backward) if otherwise
void printList(list& source, bool forward)
{
	//If forward == true
	if(forward == true)
	{
		//If the calling list is empty
		if(source.isEmpty() == true)
		{
			//Print a blank line
			cout << " " << endl;

			//Return control back to the driver
			return;
		}

		//Create an iteratorr that currently points to the first node in the source
		iteratorr iter = source.first(); 

		//While iter.isPastEnd() == false
		while(iter.isPastEnd() == false)
		{
			//Print iter.retrieve() followed by a space
			cout << iter.retrieve() << " ";

			//Let iter point to the next node in the source
			iter.moveForward();
		}

		//End the current line of character output
		cout << endl; 
	}
	else
	{
		//If the calling list is empty
		if(source.isEmpty() == true)
		{
			//Print a blank line
			cout << " " << endl;

			//Return control back to the driver
			return;
		}

		//Create an iteratorr that currently points to the last node in the source
		iteratorr iter = source.last();

		//While iter.isPastBeginning() == false
		while(iter.isPastBeginning() == false)
		{
			//Print iter.retrieve() followed by a space
			cout << iter.retrieve() << " ";

			//Let iter point to the previous node in the source
			iter.moveBackward();
		}

		//End the current line of character output
		cout << endl; 
	}
}