//Name: Nathaniel Goldammer (wsn8pk) - Date: January 25, 2022 - File Name: bankAccount.h
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
class bankAccount
{
	public:
		//Constructors and Destructors
		bankAccount(); 
		bankAccount(double amount); 
		~bankAccount(); 
		//Functions
		double withdraw(double amount);
		double deposit(double amount);
		double getBalance() const;
	private:
		double balance;
};
#endif