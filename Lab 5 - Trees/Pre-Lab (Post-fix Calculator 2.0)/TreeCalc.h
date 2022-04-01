//Nathaniel Goldammer (wsn8pk) 3/1/2022 TreeNode.h

#ifndef TREECALC_H
#define TREECALC_H
#include <stack>
#include "TreeNode.h"
using namespace std;

class TreeCalc 
{
    public:
        //Default Constructor
        TreeCalc();

        //Destructor                     
        ~TreeCalc();                    

        //Deletes tree/frees memory
        void cleanTree(TreeNode* tree); 

        //Gets data from user 
        void readInput(); 

        //Inserts the val into the Tree              
        void insert(const string& val);

        //Prints data in prefix form
        void printPrefix(TreeNode* tree) const; 

        //Prints data in infix form
        void printInfix(TreeNode* tree) const; 

        //Prints data in postfix form 
        void printPostfix(TreeNode* tree) const;

        //Prints in post, in, prefix form
        void printOutput() const;  

        //Calls private calculate method             
        int calculate();                         

    private:
        //Stack to hold the expression
        stack<TreeNode*> expressionStack;   

        //Evaluates tree, returns value
        int calculate(TreeNode* tree) const;
};
#endif