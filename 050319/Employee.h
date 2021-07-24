/*
Name: young cheol ko
Class: CS52
Lab# : 8
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Start Date: 5/03 12:23
Date and Time of Copletion Date : 5/05 18:32
*/


#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>
#include<iostream>
using namespace std;
class Employee {
protected:
	string FirstName;
	string LastName;
	static const int MIN_NUM_CHARS_NAMES = 2;
public:
	Employee(const string & Fname = "First name not set", const string & Lname = "LastName not set");
	virtual const string getFirstName() const = 0;
	virtual const string getLastName() const = 0;
	virtual const string getFullName() const = 0;
	virtual const string toString() const = 0;
	virtual void setFirstName(const string & Fname) = 0;
	virtual void setLastName(const string & Lname) = 0;
};
#endif
