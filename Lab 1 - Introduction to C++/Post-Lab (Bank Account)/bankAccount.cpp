//Name: Nathaniel Goldammer (wsn8pk) - Date: January 25, 2022 - File Name: bankAccount.cpp
#include "bankAccount.h"
//Default constructor. Sets the bankAccount's balance = 0. 
bankAccount::bankAccount()
{
	balance = 0;
} 
//Overloaded constructor. Sets the bankAccount's balance = amount. 
bankAccount::bankAccount(double amount)
{
	balance = amount;
}
//Destructor 
bankAccount::~bankAccount(){}
/* 
Withdraws the specified amount of money from the calling bankAccount 
and returns the bankAccount's new balance. If the withdraw amount 
exceeds the bankAccount's current balance, no money will be withdrawn 
and the current balance of the bankAccount will be returned. 
*/
double bankAccount::withdraw(double amount)
{
	if(amount > balance)
		return balance;
	else
	{
		balance = balance - amount;
		return balance;
	}
}
/* 
Deposits the specified amount into the calling bankAccount and returns 
the bankAccount's new balance. 
*/
double bankAccount::deposit(double amount)
{
	balance = balance + amount; 
	return balance;
}
/* Returns the calling bankAccount's balance */ 
double bankAccount::getBalance() const
{
	return balance;
}