//Nathaniel Goldammer (wsn8pk) 3/1/2022 BinarySearchTree.h

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BinaryNode.h"
using namespace std;

//You do not need to know how Trunk works.
struct Trunk 
{
    Trunk* prev;
    string str;

    Trunk(Trunk* prev, string str) 
    {
        this->prev = prev;
        this->str = str;
    }
};

class BinarySearchTree 
{
    public:

        //Default Constructor
        BinarySearchTree();

        //Destructor
        ~BinarySearchTree();

        //Finds a position for x in the BinarySearchTree and places it there
        void insert(const string& x);

        //Finds x's position in the BinarySearchTree and removes it
        void remove(const string& x);

        //Pretty-prints the BinarySearchTree to aid debugging
        void printTree();

        //Finds x in the BinarySearchTree and returns a string representing the path it took to get there
        string pathTo(const string& x);

        //Determines whether or not x exists in the BinarySearchTree
        bool find(const string& x);

        //Returns the total number of nodes in the tree.
        int numNodes() const;

    private:

        //The root BinaryNode of the BinarySearchTree
        BinaryNode* root;

        //The number of BinaryNodes in the BinarySearchTree
        int treeSize; 

        //Private helper for remove() to allow recursion over different nodes. Returns a BinaryNode* that is assigned to the original BinaryNode
        BinaryNode* remove(BinaryNode*& n, const string& x);

        //Finds the BinaryNode with the smallest value in a sub-BinarySearchTree rooted at the BinaryNode parameter
        string min(BinaryNode* node) const;

        //Private helper for printTree() to allow recursion over different nodes
        void printTree(BinaryNode* root, Trunk* prev, bool isRight);

        //Finds a position for x in the sub-BinarySearchTree rooted at BinaryNode parameter
        void insert(BinaryNode*& node, const string& x);

        //Determines whether or not x exists in the sub-BinarySearchTree rooted at the BinaryNode parameter
        bool find(BinaryNode* node, const string& x);

        //Finds x in the sub-BinarySearchTree rooted at the BinaryNode parameter and returns a string representing the path it took to get there
        string pathTo(BinaryNode* node, const string& x);

        //Give BinaryNode access to the private members of BinarySearchTree
        friend class BinaryNode;
};
#endif