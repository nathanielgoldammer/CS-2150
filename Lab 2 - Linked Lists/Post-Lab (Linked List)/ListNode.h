//Nathaniel Goldammer (wsn8pk) 2/2/2022 ListNode.h

#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
using namespace std;

class ListNode 
{
    public:
        ListNode(); //Default Constructor
    private:
        int value; //The value of the ListNode
        ListNode* next; //The next ListNode in the List
        ListNode* previous; //The previous ListNode in the List
        friend class List; //The class List needs access to value, next, and previous
        friend class ListItr; //The class ListItr needs access to value
};
#endif