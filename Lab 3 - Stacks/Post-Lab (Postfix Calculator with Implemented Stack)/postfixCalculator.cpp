//Nathaniel Goldammer (wsn8pk) 2/8/2022 postfixCalculator.cpp 

#include "postfixCalculator.h"
#include <iostream>
#include <cstdlib>
using namespace std; 

//Default Constructor
postfixCalculator::postfixCalculator()
{
	//No actions to be taken
}

//Adds the first two elements in operands
void postfixCalculator::add()
{
	//If operands is not empty 
	if(operands.empty() == false)
	{
		//Access the element at the top of operands
		int x = operands.top(); 

		//Remove the element at the top of operands
		operands.pop(); 

		//If operands is not empty  
		if(operands.empty() == false)
		{
			//Access the element at the top of operands
			int y = operands.top(); 

			//Remove the element at the top of operands
			operands.pop();

			//Add x and y 
			int z = x + y; 

			//Push z back into operands
			operands.push(z);
		}
		else
			exit(-1);
	}
	else 
		exit(-1); 
}

/* Subtracts the first element in operands from the second */ 
void postfixCalculator::subtract()
{
	//If operands is not empty 
	if(operands.empty() == false)
	{
		//Access the element at the top of operands
		int x = operands.top(); 

		//Remove the element at the top of operands
		operands.pop(); 

		//If operands is not empty 
		if(operands.empty() == false)
		{
			//Access the element at the top of operands
			int y = operands.top(); 

			//Remove the element at the top of operands
			operands.pop();

			//Subtract x from y
			int z = y - x; 

			//Push z back into operands 
			operands.push(z);
		}
		else
			exit(-1);
	}
	else 
		exit(-1); 
}

/* Multiplies the first element in operands by the second element in operands */ 
void postfixCalculator::multiply()
{
	//If operands is not empty
	if(operands.empty() == false)
	{
		//Access the element at the top of operands
		int x = operands.top(); 

		//Remove the element at the top of operands
		operands.pop(); 

		//If operands is not empty 
		if(operands.empty() == false)
		{
			//Access the element at the top of operands
			int y = operands.top(); 

			//Remove the element at the top of operands
			operands.pop();

			//Multiply x by y 
			int z = x * y;

			//Push z back into operands 
			operands.push(z);
		}
		else
			exit(-1);
	}
	else
		exit(-1);
}

/* Divides the first element in operands by the second element in operands */ 
void postfixCalculator::divide()
{
	//If operands is not empty
	if(operands.empty() == false)
	{
		//Access the element at the top of operands
		int x = operands.top(); 

		//Remove the element at the top of operands
		operands.pop(); 

		//If operands is not empty 
		if(operands.empty() == false)
		{
			//Access the element at the top of operands
			int y = operands.top(); 

			//Remove the element at the top of operands
			operands.pop();

			//Divide y by x
			int z = y / x;

			//Push z back into operands 
			operands.push(z);
		}
		else
			exit(-1);
	}
	else
		exit(-1);
} 

/* Negates the top element in operands */ 
void postfixCalculator::negate()
{
	//If operands is not empty
	if(operands.empty() == false)
	{
		//Access the element at the top of operands
		int x = operands.top();

		//Remove the element at the top of operands
		operands.pop(); 

		//Push the negation of x into operands 
		operands.push(-1 * x);
	}
	else 
		exit(-1);
}