//Name: Nathaniel Goldammer (wsn8pk) - Date: January 25, 2022 - File Name: LifeCycle.cpp

#include "LifeCycle.h"
#include <iostream>
#include <string>
using namespace std; 

//Default Constructor
MyObject::MyObject()
{
	name = "--default--";
	id = ++numObjs;
	cout << "MyObject Default constructor: " << *this << endl;
}
//Overloaded Constructor
MyObject::MyObject(string n) 
{
    name = n;
    id = ++numObjs;
    cout << "MyObject Parameter constructor: " << *this << endl;
}
//Overloaded Constructor 
MyObject::MyObject(const MyObject& rhs) 
{
    name = rhs.name;
    id = ++numObjs;
    cout << "MyObject Copy constructor: " << *this << endl;
}
//Destructor
MyObject::~MyObject() 
{
    cout << "MyObject Destructor: " << *this << endl;
}
//Returns the calling MyObject's name
string MyObject::getName() const 
{
    return name;
}
//Sets the calling MyObject's name equal to the newName
void MyObject::setName(const string& newName) 
{
    name = newName;
}
//Lets cout know how to print MyObjects
ostream& operator<<(ostream& output, const MyObject& obj) 
{
    //Output in format: ("object name", id)
    return output << "(\"" << obj.name << "\", " << obj.id << ")";
}