//Nathaniel Goldammer (wsn8pk) 2/8/2022 stack.h 

#ifndef STACK_H 
#define STACK_H
#include "node.h"
#include "iteratorr.h"
#include "list.h"

class stack
{
	public:

		//Default Constructor 
		stack(); 

		//Destructor
		~stack();

		//Pushes the int parameter into the stack
		void push(int e);

		//Removes the top element from the stack 
		void pop(); 

		//Accesses the top element from the stack 
		int top(); 

		//Checks if the stack is empty
		bool empty();

	private:

		//Each stack is implemented internally as a list
		list* stacc;

		//Grant postfixCalculator access to the private members of stack
		friend class postfixCalculator;
};
#endif