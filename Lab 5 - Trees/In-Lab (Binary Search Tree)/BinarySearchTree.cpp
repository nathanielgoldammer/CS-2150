//Nathaniel Goldammer (wsn8pk) 3/1/2022 BinarySearchTree.cpp

#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

//Default Constructor
BinarySearchTree::BinarySearchTree() 
{
    //The root of the BinarySearchTree is NULL by default
    root = NULL;

    //The size of the BinarySearchTree is 0 by default
    treeSize = 0;
}

//Destructor
BinarySearchTree::~BinarySearchTree() 
{
    delete root;
    root = NULL;
}

//Inserts x into the BinarySearchTree if no BinaryNode in the BinarySearchTree has a value of x
void BinarySearchTree::insert(const string& x) 
{
    //If there is no BinaryNode in the BinarySearchTree with a value of x
    if(find(x) == false)
    {
        //If the root of the BinarySearchTree is NULL
        if(root == NULL)
        {
            //Insert x into the root of the BinarySearchTree
            root = new BinaryNode(x);
        }
        else
        {
            //If x is less than the root's value
            if(x.compare(root->value) < 0)
            {
                //Insert x into the sub-BinarySearchTree rooted at the root's left child
                insert(root->left, x);
            }
            
            //If x is greater than the root's value
            if(x.compare(root->value) > 0)
            {
                //Insert x into the sub-BinarySearchTree rooted at the root's right child
                insert(root->right, x);
            }
        }

        //Increment the BinarySearchTree's size by 1
        treeSize++;
    }

}

//Inserts x into the sub-BinarySearchTree rooted at BinaryNode parameter
void BinarySearchTree::insert(BinaryNode*& node, const string& x)
{
    //Base Case: If the node is NULL
    if(node == NULL)
    {
        //Insert x into the node 
        node = new BinaryNode(x);
    }

    //Recursive Case: If the node is not NULL
    else
    {
        //If x is less than the node's value
        if(x.compare(node->value) < 0)
        {
            //Insert x into the sub-BinarySearchTree rooted at the node's left child
            insert(node->left, x);
        }

        //If x is greater than the node's value
        if(x.compare(node->value) > 0)
        {
            //Insert x into the sub-BinarySearchTree rooted at the node's right child
            insert(node->right, x);
        }
    }
}

//Removes x from the BinarySearchTree if there is a BinaryNode with a value of x in the BinarySearchTree
void BinarySearchTree::remove(const string& x) 
{
    //If there is a BinaryNode with a value of x in the BinarySearchTree
    if(find(x) == true)
    {
        root = remove(root, x);

        //Decrement size by 1
        treeSize--;
    }
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) 
{
    if(n == NULL) 
    {
        return NULL;
    }

    //first look for x
    if (x == n->value) 
    {
        //found
        if (n->left == NULL && n->right == NULL) 
        {
            // no children
            // just delete it :)
            delete n;
            n = NULL;
            return NULL;
        } 
        else if (n->left == NULL) 
        {
            // single child (right)
            // remove current node and return right child node for parent
            BinaryNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } 
        else if (n->right == NULL) 
        {
            // single child (left)
            // remove current node and return left child node for parent
            BinaryNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } 
        else 
        {
            // two children
            // replace current node with right child node's minimum, then remove that node
            string value = min(n->right);
            n->value = value;
            n->right = remove(n->right, value);
        }
    } 
    else if (x < n->value) 
    {
        n->left = remove(n->left, x);
    } 
    else 
    {
        n->right = remove(n->right, x);
    }
    return n;
}

//Finds x in the BinarySearchTree and returns a string representing the path it took to get there
string BinarySearchTree::pathTo(const string& x)
{
    //If there is no BinaryNode with a value of x in the BinarySearchTree
    if(find(x) == false)
    {
        //Return an empty string
        return "";
    }
    else
    {
        //If x is equal to the root's value
        if(x.compare(root->value) == 0)
        {
            //Return the root's value
            return root->value;
        }

        //If x is less than the root's value
        if(x.compare(root->value) < 0)
        {
            //Return the root's value followed by the path to x in the sub-BinarySearchTree rooted at the root's left child
            return root->value + " " + pathTo(root->left, x);
        }

        //If x is greater than the root's value
        if(x.compare(root->value) > 0)
        {
            //Return the root's value followed by the path to x in the sub-BinarySearchTree rooted at the root's right child
            return root->value + " " + pathTo(root->right, x);
        }
    }
}

//Finds x in the sub-BinarySearchTree rooted at the BinaryNode parameter and returns a string representing the path it took to get there
string BinarySearchTree::pathTo(BinaryNode* node, const string& x)
{
    //Base Case: If x is equal to the node's value
    if(x.compare(node->value) == 0)
    {
        //Return the node's value
        return " " + node->value;
    }

    //Recursive Case: If x is not equal to the node's value
    else
    {
        //If x is less than the node's value
        if(x.compare(node->value) < 0)
        {
            //Return the node's value followed by the path to x in the sub-BinarySearchTree rooted at the node's left child
            return " " + node->value + " " + pathTo(node->left, x);
        }

        //If x is greater than the node's value
        if(x.compare(node->value) > 0)
        {
            //Return the node's value followed by the path to x in the sub-BinarySearchTree rooted at the node's right child
            return " " + node->value + " " + pathTo(node->right, x);
        }
    }
}

//Determines whether or not x exists in the BinarySearchTree
bool BinarySearchTree::find(const string& x)
{
    //If the root of the BinarySearchTree is NULL
    if(root == NULL)
    {
        //Return false
        return false;
    }
    else
    {
        //If x is equal to the root's value
        if(x.compare(root->value) == 0)
        {
            //Return true
            return true;
        }

        //If x is less than the root's value
        if(x.compare(root->value) < 0)
        {
            //Find x in the sub-BinarySearchTree rooted at the root's left child
            return find(root->left, x);
        }

        //If x is greater than the root's value
        if(x.compare(root->value) > 0)
        {
            //Find x in the sub-BinarySearchTree rooted at the root's right child
            return find(root->right, x);
        }
    }
}

//Determines whether or not x exists in the sub-BinarySearchTree rooted at the BinaryNode parameter
bool BinarySearchTree::find(BinaryNode* node, const string& x)
{
    //Base Case: If the node is NULL
    if(node == NULL)
    {
        //Return false
        return false;
    }

    //Recursive Case: If the node is not NULL
    else
    {
        //If x is equal to the node's value
        if(x.compare(node->value) == 0)
        {
            //Return true
            return true;
        }

        //If x is less than the node's value
        if(x.compare(node->value) < 0)
        {
            //Find x in the sub-BinarySearchTree rooted at the node's left child
            return find(node->left, x);
        }

        //If x is greater than the node's value
        if(x.compare(node->value) > 0)
        {
            //Find x in the sub-BinarySearchTree rooted at the node's right child
            return find(node->right, x);
        }
    }
}

//Returns the total number of nodes in the BinarySearchTree
int BinarySearchTree::numNodes() const 
{
    return treeSize;
}

//Finds the BinaryNode with the smallest value in the sub-BinarySearchTree rooted at the BinaryNode parameter
string BinarySearchTree::min(BinaryNode* node) const 
{
    //If the node's left child is NULL
    if(node->left == NULL) 
    {
        //Return the node's value
        return node->value;
    }
    else
    {
        //Return the smallest value in the sub-BinarySearchTree rooted at the node's left child
        return min(node->left);
    }
}

//Helper function to print branches of the BinarySearchTree
void showTrunks(Trunk* p) 
{
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

//Prints the BinarySearchTree
void BinarySearchTree::printTree() 
{
    printTree(root, NULL, false);
}

//Prints the BinarySearchTree using inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) 
{
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) 
    {
        trunk->str = ".---";
        prev_str = "   |";
    } 
    else 
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}