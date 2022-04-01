//Nathaniel Goldammer (wsn8pk) 2/17/2022 bitCounter.cpp

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <stack>
using namespace std;

//Returns the number of 1's in the binary representation of n
int numberOfOnes(int n)
{
	//Base Case: If n = 0 or n = 1
	if(n == 0 || n == 1)
	{
		//If n = 0
		if(n == 0)
		{
			//Then there are zero 1's in the binary representation of n
			return 0;
		}

		//Else n = 1
		else
		{
			//Then there is one 1 in the binary representation of n
			return 1;
		}
	}

	//Recursive Case: If n != 0 or n != 1
	else 
	{
		//Recursive Case 1: n is even
		if(n % 2 == 0)
		{
			//Then the number of 1's in the binary representation of n is the same as that of n/2
			return numberOfOnes(n / 2);
		}

		//Recursive Case 2: n is odd
		else
		{
			//Then the number of 1's in the binary representation of n is one more than that of floor(n/2)
			return 1 + numberOfOnes(floor(n / 2)); 
		}
	}
}

string baseConverter(string number, int startBase, int endBase)
{
	//If the startBase is not 10
	if(startBase != 10)
	{
		//Let numDigits = the number of digits in the number
		int numDigits = number.length();

		//Let decimalNumber = the number in base 10
		int decimalNumber = 0; 

		//For each digit of the number
		for(int i = 0; i < number.length(); i++)
		{
			//Decrement numDigits by 1 
			numDigits = numDigits - 1;

			//If the i'th digit of the number is itself a number
			if(isdigit(number[i]))
			{
				//Convert the i'th digit of the number into it's integer form
				int ithDigit = number[i] - '0';

				//Increment decimalNumber by ithDigit * startBase^numDigits
				decimalNumber = decimalNumber + (ithDigit * pow(startBase, numDigits));
			}

			//Else the i'th digit of the number is not itself a number
			else 
			{
				//Convert the i'th digit of the number into it's integer form
				int ithDigit = number[i] - 55;

				//Increment decimalNumber by ithDigit * startBase^numDigits
				decimalNumber = decimalNumber + (ithDigit * pow(startBase, numDigits));
			}
		}

		//If the endBase is 10
		if(endBase == 10)
		{
			//Then return the string representation of the decimalNumber 
			return to_string(decimalNumber);
		}
	}

	//Else the startBase is 10
	else
	{
		//Stack of digits in base endBase 
		stack<string> stacc; 

		//Let decimalNumber = the integer representation of the number 
		int decimalNumber = stoi(number);

		//While decimalNumber is not 0
		while(decimalNumber != 0)
		{
			//Let quotient = the result of decimalNumber / endBase 
			int quotient = (decimalNumber / endBase);

			//Let remainder = the result of decimalNumber % endBase 
			int remainder = (decimalNumber % endBase);

			//Push the string representation of the remainder into the stacc 
			stacc.push(to_string(remainder));

			//Set decimalNumber = quotient
			decimalNumber = quotient;
		}

		//Let endBaseNumber = the number in base endBase 
		string endBaseNumber = "";

		//While the stacc is not empty
		while(!stacc.empty())
		{
			//Append endBaseNumber with the top element of stack
			endBaseNumber.append(stacc.top());

			//Remove the top element from the stacc
			stacc.pop();
		}

		//Return the endBaseNumber
		return endBaseNumber;
	}

	//Default Return 
	return "";
} 

int main(int argc, char *argv[])
{
	//If no command-line parameters are passed into main(), terminate the program
	if(argc == 0)
	{
		cout << "Error: No command-line parameters have been entered." << endl;
		exit(1);
	}

	//Convert argv[1], argv[3], and argv[4] into integers
	int number1 = atoi(argv[1]);
	int startBase = atoi(argv[3]);
	int endBase = atoi(argv[4]);

	//Convert argv[2] into a C++ string
	string number2 = argv[2];

	//Print the number of 1's in the binary representation of n
	cout << number1 << " has " << numberOfOnes(number1) << " bit(s) " << endl;

	//Print the conversion of number2 in base startBase to number2 in base endBase
	cout << number2 << " (base " << startBase << ") = " << baseConverter(number2, startBase, endBase) << " (base " << endBase << ")" << endl;

	//End of main
	return 0;
}