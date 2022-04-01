//Nathaniel Goldammer (wsn8pk) 2/6/2022 testPostfixCalculator.cpp 

#include "postfixCalculator.h"
#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
using namespace std; 

int main()
{
	//Postfix calculator 
	postfixCalculator calculator;

	//Arithmetic expression 
	string token; 

	//While the user providing input 
	while(cin >> token)
	{
		//If the token is not an operator, push the token into calculator.operands
		if((token != "+") && (token != "-"))
			calculator.operands.push(stoi(token));

		//Else if the token is the + operator, call calculator.add() 
		else if(token == "+")
			calculator.add();

		//Else if the token is the - operator, call calculator.subtract()
		else if(token == "-")
			calculator.subtract();
	}	

	//Display the result of the postfix expression 
	cout << calculator.operands.top(); 

	//End of main()
	return 0; 	
}