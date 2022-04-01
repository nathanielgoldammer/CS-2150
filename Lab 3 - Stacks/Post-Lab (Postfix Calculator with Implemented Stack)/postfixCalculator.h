//Nathaniel Goldammer (wsn8pk) 2/8/2022 postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include "stack.h"

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

		//The stack of operands
		stack operands; 
};
#endif