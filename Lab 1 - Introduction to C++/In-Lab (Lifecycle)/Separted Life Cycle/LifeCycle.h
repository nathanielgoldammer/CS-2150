//Name: Nathaniel Goldammer (wsn8pk) - Date: January 25, 2022 - File Name: LifeCycle.h

#include <iostream>
#include <string>
using namespace std;

#ifndef LIFECYCLE_H
#define LIFECYCLE_H

class MyObject 
{
	public:
		static int numObjs;

		MyObject(); //Default Constructor 
		MyObject(string n); //Overloaded Constructor 
		MyObject(const MyObject& rhs); //Overloaded Constructor 
		~MyObject(); //Destructor 

		string getName() const;
		void setName(const string& newName);
		friend ostream& operator<<(ostream& output, const MyObject& obj);
	private:
		string name;
		int id;
};
#endif