//Nathaniel Goldammer (wsn8pk) 2/6/2022 postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std; 

class postfixCalculator
{
	public:

		//Default Constructor 
		postfixCalculator();
 
		//Addition Operation 
		void add(); 

		//Subtraction Operation 
		void subtract();

		//Multiplication Operation 
		void multiply();

		//Division Operation 
		void divide();

		//Negation Operation 
		void negate();

		//Stack of integers 
		stack<int> operands; 
};
#endif