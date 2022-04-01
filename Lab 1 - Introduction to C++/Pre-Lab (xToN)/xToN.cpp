//Name: Nathaniel Goldammer (wsn8pk) - Date: January 23, 2022 - File Name: xToN.cpp

#include <iostream>
using namespace std;

//Computes x to the power n recursively for non-negative integers n, where x to the power 1 is equal to 0 for all x.
int xton(int x, int n)
{
	if(n == 0)		
		return 1;
	else 			
	{
		return x * xton(x, n - 1);
	}
}

int main()
{
	int a, b;
	cin >> a; 
	cin >> b; 
	cout << xton(a, b);
	return 0;
}