//Nathaniel Goldammer (wsn8pk) 2/8/2022 list.h

#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "node.h"
#include "iteratorr.h"
using namespace std;
class iteratorr;

class list 
{
    public:
    
        //Default Constructor: Initializes all private data members and sets up the basic list structure with the dummy head and tail nodes.
        list();

        //Copy Constructor: Creates a new list of nodes whose contents are the same values as the nodes in source.
        list(const list& source);

        //Destructor: Empties the list and reclaims the memory allocated in the constructor for head and tail.
        ~list();

        //Copy Assignment Operator: Copies the contents of every node in source into an existing list (the reference to the calling list object itself).
        list& operator=(const list& source);

        //Returns true if the calling list is empty and false if otherwise.
        bool isEmpty() const;

        //Removes all items except the dummy head/tail. The list should be a working empty list after this.
        void makeEmpty();

        //Returns an iterator that points to the first node after the dummy head node (even on an empty list)
        iteratorr first();

        //Returns an iteratorr that points to the last node before the dummy tail node (even on an empty list)
        iteratorr last();

        //Inserts x after current iteratorr position.
        void insertAfter(int x, iteratorr position);

        //Inserts x after before the current iteratorr position.
        void insertBefore(int x, iteratorr position);

        //Inserts x into the tail of the calling list. 
        void insertAtTail(int x);

        //Returns an iteratorr that points to the first occurrence of x. When the parameter is not in the list, returns an iterator that points to the dummy tail node.
        iteratorr find(int x);

        //Removes the first occurance of x. 
        void remove(int x);

        //Returns the number of elements in the calling list. 
        int size() const;

    private:

        //Dummy node representing the beginning of the list
        node* head;  

        //Dummy node representing the end of the list
        node* tail; 

        //The number of elements in the list      
        int count; 

        //Grant stack access to private members of list
        friend class stack;
};

//Prints the list from head to tail (forward) if forward is true, and prints the list from tail to head (backward) if otherwise. 
void printList(list& source, bool forward);

#endif