/*
Name: young cheol ko
Class: CS52
Lab# : 8
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Start Date: 5/03 12:23
Date and Time of Copletion Date : 5/05 18:32
*/


#include"Employee.h"

Employee::Employee(const string & Fname, const string & Lname) 
	: FirstName(Fname), LastName(Lname)
{
	if (FirstName.length() < MIN_NUM_CHARS_NAMES) {
		FirstName = "First name not set";
	}
	if (LastName.length() < MIN_NUM_CHARS_NAMES) {
		LastName = "Last name not set";
	}
}