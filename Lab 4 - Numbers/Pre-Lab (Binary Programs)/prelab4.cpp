//Nathaniel Goldammer (wsn8pk) 2/13/2022 prelab4.cpp

#include <iostream>
#include <climits>
#include <stack>
using namespace std;

void sizeOfTest()
{
	//Display the size of an int
	cout << "Size of int: " << sizeof(int) << endl;

	//Display the size of an unsigned int
	cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;

	//Display the size of a float
	cout << "Size of float: " << sizeof(float) << endl; 

	//Display the size of a double
	cout << "Size of double: " << sizeof(double) << endl;

	//Display the size of a char
	cout << "Size of char: " << sizeof(char) << endl; 

	//Display the size of a bool
	cout << "Size of bool: " << sizeof(bool) << endl;

	//Display the size of an int* 
	cout << "Size of int*: " << sizeof(int*) << endl; 

	//Display the size of a char*
	cout << "Size of char*: " << sizeof(char*) << endl; 

	//Display the size of a double*
	cout << "Size of double*: " << sizeof(double*) << endl; 
}

void overflow()
{
	//Create an unsigned int and assign it UINT_MAX
	unsigned int z = UINT_MAX;

	//Increment z by 1 
	z = z + 1; 

	//Display UINT_MAX and the new value of z
	cout << UINT_MAX << " + 1 = " << z << endl; 
}

void outputBinary(unsigned int x)
{
	//If the parameter x = 0
	if(x == 0)
	{
		//Then print the 32-bit representation of x
		cout << "0000 0000 0000 0000 0000 0000 0000 0000" << endl;

		//Return control back to the driver
		return;
	}

	//Stack of binary digits
	stack<int> bits;  

	//While x is greater than 0
	while(x > 0)
	{
		//Push x % 2 into bits
		bits.push(x % 2); 

		//Divide x by 2 
		x = x / 2; 
	}

	//If the size of bits is less than 32
	if(bits.size() < 32)
	{
		//Then while the size of bits is less than 32
		while(bits.size() < 32)
		{
			//Push 0 into bits
			bits.push(0);
		}
	}

	//While bits is not empty
	while(!bits.empty())
	{
		//for i = 1 to i = 4
		for(int i = 1; i <= 4; i++)
		{
			//Print the top element of bits 
			cout << bits.top();

			//Remove the top element of bits 
			bits.pop();
		}

		//Print a space 
		cout << " ";
	}

	//End the current line of output
	cout << endl;
}

int main()
{
	//Unsigned integer for outputBinary() input
	unsigned int x; 
	cin >> x;

	//Call sizeOfTest()
	sizeOfTest(); 

	//Call overflow()
	overflow();

	//Call outputBinary()
	outputBinary(x);

	//End of main
	return 0;
}