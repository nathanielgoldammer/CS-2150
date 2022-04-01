//Nathaniel Goldammer (wsn8pk) 3/1/2022 BinaryNode.h

#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <string>
using namespace std;

class BinaryNode 
{
    public:
        //Default Constructor
        BinaryNode();

        //Overloaded Constructor
        BinaryNode(const string& x);

        //Destructor
        ~BinaryNode();

        //The BinaryNode's key value
        string value;

        //The BinaryNode's left child
        BinaryNode* left;

        //The BinaryNode's right child
        BinaryNode* right;

};
#endif