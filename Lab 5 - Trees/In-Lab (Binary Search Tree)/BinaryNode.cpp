//Nathaniel Goldammer (wsn8pk) 3/1/2022 BinaryNode.cpp

#include "BinaryNode.h"
using namespace std;

//Default Constructor
BinaryNode::BinaryNode() 
{
    //The BinaryNode's key value equal to "?" by default
    value = "?";

    //The BinaryNode's left and right childen equal to NULL by default
    left = NULL;
    right = NULL;
}

//Overloaded Constructor
BinaryNode::BinaryNode(const string& x)
{
    //Set the BinaryNode's value = the parameter x
    value = x;

    //Set the BinaryNode's left and right children = NULL
    left = NULL;
    right = NULL;
}

//Destructor
BinaryNode::~BinaryNode() 
{
    //Delete the BinaryNode's left and right children
    delete left;
    delete right;

    //Set the BinaryNode's left and right childen equal to NULL
    left = NULL;
    right = NULL;
}