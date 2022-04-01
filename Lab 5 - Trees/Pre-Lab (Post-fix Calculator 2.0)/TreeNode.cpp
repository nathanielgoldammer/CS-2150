//Nathaniel Goldammer (wsn8pk) 3/1/2022 TreeNode.cpp

#include "TreeNode.h"
using namespace std; 

//Default Constructor: Sets left and right equal to NULL, and sets value equal to "?".
TreeNode::TreeNode() 
{
    value = "?";
    left = NULL;
    right = NULL;
}

//Overloaded Constructor: Sets left and right equal to NULL, and sets value equal to val.
TreeNode::TreeNode(const string& val) 
{
    value = val;
    left = NULL;
    right = NULL;
}