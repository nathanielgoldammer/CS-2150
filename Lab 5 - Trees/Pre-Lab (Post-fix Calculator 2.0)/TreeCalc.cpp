//Nathaniel Goldammer (wsn8pk) 3/1/2022 TreeCalc.cpp

#include "TreeCalc.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

//Default Constructor
TreeCalc::TreeCalc() 
{
    //No actions to be taken
}

//Destructor
TreeCalc::~TreeCalc() 
{
    //If the expressionStack is not empty
    if(!expressionStack.empty())
    {
        //Delete each TreeNode in the expressionStack
        cleanTree(expressionStack.top());
    }
}

//Deletes each TreeNode in the expressionStack and frees memory
void TreeCalc::cleanTree(TreeNode* tree) 
{
    //Base Case: If the TreeNode is a leaf
    if(tree->left == NULL && tree->right == NULL)
    {
        //Delete the TreeNode
        delete tree;
    }
    //Recursive Case: The TreeNode is not a leaf
    else
    {
        //If the TreeNode has a left child
        if(tree->left != NULL)
        {
            //Then clean the subtree rooted at the TreeNode's left child
            cleanTree(tree->left);
        }

        //If the TreeNode has a right child
        if(tree->right != NULL)
        {
            //Then clean the subtree rooted at the TreeNode's right child
            cleanTree(tree->right);
        }

        //Delete the TreeNode
        delete tree;
    }
}

//Gets data from user (DO NOT MODIFY)
void TreeCalc::readInput() 
{
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*' || response[0] == '-' || response[0] == '+') 
    {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Inserts the val into the expressionStack
void TreeCalc::insert(const string& val) 
{
    //If val is an operator
    if(val == "*" || val == "/" || val == "+" || val == "-")
    {
        //If the expressionStack has two or more elements
        if(expressionStack.size() >= 2)
        {
            //Create a new TreeNode with val
            TreeNode* tree = new TreeNode(val);

            //Set tree->right = the top TreeNode in the expressionStack
            tree->right = expressionStack.top();

            //Remove the top TreeNode in the expressionStack
            expressionStack.pop();

            //Set tree->left = the top TreeNode in the expressionStack
            tree->left = expressionStack.top();

            //Remove the top TreeNode in the expressionStack
            expressionStack.pop();

            //Push the new TreeNode into the expressionStack
            expressionStack.push(tree);
        }
    }
    else
    {
        //Create a new TreeNode with val
        TreeNode* tree = new TreeNode(val);

        //Push the new TreeNode into the expressionStack
        expressionStack.push(tree);
    }
}

//Prints the postfix expression in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const 
{
    //Base Case: If the TreeNode is NULL 
    if(tree == NULL)
    {
        //Return control back to the driver
        return; 
    }

    //Recursive Case: The TreeNode is not NULL
    else
    {
        //Print the TreeNode's value followed by a space
        cout << tree->value << " "; 

        //Traverse the subtree rooted at the TreeNode's left child 
        printPrefix(tree->left); 

        //Traverse the subtree rooted at the TreeNode's right child 
        printPrefix(tree->right); 
    }
}

//Prints the postfix expression in infix form
void TreeCalc::printInfix(TreeNode* tree) const 
{
    //Base Case: If the TreeNode is NULL
    if(tree == NULL)
    {
        //Return control back to the driver
        return; 
    }

    //Recursive Case: The TreeNode is not NULL
    else 
    {
        //If the TreeNode's value is an operator 
        if(tree->value == "*" || tree->value == "/" || tree->value == "+" || tree->value == "-")
        {
            //Print open parenthesis
            cout << "("; 
        }

        //Traverse the subtree rooted at the TreeNode's left child 
        printInfix(tree->left);

        //Print the TreeNode's value preceded and followed by a space
        cout << " " << tree->value << " "; 

        //Traverse the subtree rooted at the TreeNode's right child
        printInfix(tree->right);

        //If the TreeNode's value is an operator 
        if(tree->value == "*" || tree->value == "/" || tree->value == "+" || tree->value == "-")
        {
            //Print close parenthesis
            cout << ")"; 
        }
    }
}

//Prints the postfix expression in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const 
{
    //Base Case: If the TreeNode is NULL
    if(tree == NULL)
    {
        //Return control back to the driver
        return; 
    }

    //Recursive Case: The TreeNode is not NULL
    else
    {
        //Traverse the subtree rooted at the TreeNode's left child 
        printPostfix(tree->left); 

        //Traverse the subtree rooted at the TreeNode's right child 
        printPostfix(tree->right); 

        //Print the TreeNode's value followed by a space
        cout << tree->value << " ";
    }
}

//Prints the postfix expression in postfix, infix, and prefix form (DO NOT MODIFY)
void TreeCalc::printOutput() const 
{
    if(expressionStack.size() != 0 && expressionStack.top() != NULL) 
    {
        TreeNode* tree = expressionStack.top();

        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } 
    else 
    {
        cout << "Size is 0." << endl;
    }
}

int TreeCalc::calculate(TreeNode* tree) const 
{
    //Base Case: If the TreeNode is a leaf
    if(tree->left == NULL && tree->right == NULL)
    {
        //Return the TreeNode's value in integer form
        return stoi(tree->value);
    }

    //Recursive Case: The TreeNode is not a leaf
    else
    {
        //If the TreeNode's value is the multiplication operator
        if(tree->value == "*")
        {
            //Return the product of the calculations of the two subtrees rooted at the TreeNode's left and right children
            return calculate(tree->left) * calculate(tree->right);
        }

        //If the TreeNode's value is the division operator  
        else if(tree->value == "/")
        {
            //Return the quotient of the calculations of the two subtrees rooted at the TreeNode's left and right children
            return calculate(tree->left) / calculate(tree->right);
        }

        //If the TreeNode's value is the addition operator 
        else if(tree->value == "+")
        {
            //Return the sum of the calculations of the two subtrees rooted at the TreeNode's left and right children
            return calculate(tree->left) + calculate(tree->right);
        }

        //If the TreeNode's value is the subtraction operator 
        else if(tree->value == "-")
        {
            //Return the difference of the calculations of the two subtrees rooted at the TreeNode's left and right children
            return calculate(tree->left) - calculate(tree->right);
        }

        else
        {
            //Return 0 by default
            return 0;
        }
    }
}

int TreeCalc::calculate() 
{
    //If the expressionStack is not empty
    if(!expressionStack.empty())
    {
        //Let result = the result of the expression tree's evaluation
        int result = calculate(expressionStack.top()); 

        //Clean the tree rooted at the expressionStack's top TreeNode
        TreeNode* tree = expressionStack.top(); 
        cleanTree(tree);

        //Empty the expressionStack
        expressionStack.pop();

        //Return the result of the calculation
        return result;
    }
    else 
    {
        //Return 0 
        return 0;
    }
}