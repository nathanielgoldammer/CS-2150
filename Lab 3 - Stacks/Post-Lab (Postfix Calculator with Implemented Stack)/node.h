//Nathaniel Goldammer (wsn8pk) 2/8/2022 node.h

#ifndef NODE_H
#define NODE_H

class node 
{
    public:

        //Default Constructor
        node();

    private:

        //The value of the node
        int value;

        //The next node in the list
        node* next;

        //The previous node in the list
        node* previous;

        //Grant list, iterator, and stack access to private members of ListNode
        friend class list; 
        friend class iteratorr;
        friend class stack;
};
#endif