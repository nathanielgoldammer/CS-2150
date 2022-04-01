//Nathaniel Goldammer (wsn8pk) 1/31/2022 ListNode.h

#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
using namespace std;

class ListNode 
{
    public:
        ListNode();//Default Constructor
    private:
        int value; //The value of the node
        ListNode* next; //The next ListNode in the List
        ListNode* previous; //The previous ListNode in the list
        friend class List; //List class needs access to value, next, and previous
        friend class ListItr; //ListItr class needs access to value
};
#endif