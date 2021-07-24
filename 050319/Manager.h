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
#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"
#include <string>

class Manager :
	public Employee
{
protected:
	double salary;
	string TitleOfBoss;
public:
	Manager(const string & Fname = "First name not set", const string & Lname = "LastName not set",
		double sal = 0.0, const string & BTitle = "Boss'es Title not set");
	virtual const string getFirstName() const;
	virtual const string getLastName() const;
	virtual const string getFullName() const;
	virtual const string toString() const;
	virtual void setFirstName(const string & Fname);
	virtual void setLastName(const string & Lname);

	const string getBossTitle() const;
	double getSalary() const;
	void setBossTitle(string & Title);
	void setSalary(double sal);
};


#endif