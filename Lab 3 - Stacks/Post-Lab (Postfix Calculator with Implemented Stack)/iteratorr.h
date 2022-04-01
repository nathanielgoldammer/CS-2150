//Nathaniel Goldammer (wsn8pk) 2/8/2022 iteratorr.h

#ifndef ITERATORR_H
#define ITERATORR_H
#include "node.h"
#include "list.h"

class iteratorr 
{
    public:

        //Default Constructor
        iteratorr();

        //Overloaded Constructor
        iteratorr(node* theNode);

        //Returns true if the iteratorr is currently pointing to the tail, and false if otherwise
        bool isPastEnd() const;

        //Returns true if the iteratorr is currently pointing to the head, and false if otherwise
        bool isPastBeginning() const;

        //Points current to the next position in the list if current is not already pointing past the tail of the list
        void moveForward();

        //Points current to the previous position in the list if current is not already pointing past the head of the list
        void moveBackward();

        //Returns the value of the element in the current position of the list
        int retrieve() const;

    private:

        //Holds the current position in the list
        node* current; 

        //Grant list and stack access to the private members of iterator
        friend class list;
        friend class stack;
};
#endif