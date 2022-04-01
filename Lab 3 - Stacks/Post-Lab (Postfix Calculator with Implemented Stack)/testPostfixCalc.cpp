//Nathaniel Goldammer (wsn8pk) 2/8/2022 testPostfixCalculator.cpp 

#include "postfixCalculator.h"
#include <iostream>
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
		//If the token is not an operator, push the token's integer representation into calculator.operands
		if((token != "+") && (token != "-") && (token != "*") && (token != "/") && (token != "~"))
			calculator.operands.push(stoi(token));

		//Else if the token is the + operator, call calculator.add() 
		else if(token == "+")
			calculator.add();

		//Else if the token is the - operator, call calculator.subtract()
		else if(token == "-")
			calculator.subtract();

		//Else if the token is the * operator, call calculator.multiply()
		else if(token == "*")
			calculator.multiply();

		//Else if the token is the / operator, call calculator.divide()
		else if(token == "/")
			calculator.divide();

		//Else if the token is the ~ operator, call calculator.negate()
		else if(token == "~")
			calculator.negate();
	}	

	//Display the result of the postfix expression 
	cout << calculator.operands.top(); 

	//End of main()
	return 0; 	
}