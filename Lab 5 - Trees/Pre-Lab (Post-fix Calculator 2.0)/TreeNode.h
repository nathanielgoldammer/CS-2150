//Nathaniel Goldammer (wsn8pk) 3/1/2022 TreeNode.h

#ifndef TREENODE_H
#define TREENODE_H
#include <string>
using namespace std;

class TreeNode 
{
    public:

        //Default Constructor
        TreeNode();  

        //Overloaded Constructor                
        TreeNode(const string& val);

    private:

        //The value of the TreeNode
        string value;

        //The TreeNode's left child
        TreeNode* left;

        //The TreeNode's right child
        TreeNode* right;

        //Give TreeCalc access to private data
        friend class TreeCalc;
};
#endif