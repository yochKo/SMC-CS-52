/*
Name: young cheol ko
Class: CS52
Lab# : 8
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Start Date: 5/03 12:23
Date and Time of Copletion Date : 5/05 18:32
*/


#include "Manager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

Manager::Manager(const string & Fname, const string & Lname,
	double sal, const string & BTitle)
	: Employee(Fname, Lname), salary(abs(sal)), TitleOfBoss(BTitle)
{
	if (Fname.length() < MIN_NUM_CHARS_NAMES) {
		cout << "The first name F does not have enough characters." << endl
			<< "We will set first name to a default value of 'First name not set.'" << endl;
		FirstName = "Fisrt name not set";
	}
	if (Lname.length() < MIN_NUM_CHARS_NAMES) {
		cout << "The last name L does not have enough characters." << endl
			<< "We will set last name to a default value of 'Last name not set.'" << endl;
		LastName = "Last name not set";
	}
	if (BTitle.length() < MIN_NUM_CHARS_NAMES) {
		cout << "Title of boss cannot be less than 2 characters.\nThe default value is used." << endl;
		TitleOfBoss = "Boss'es Title not set";
	}
}

const string Manager::getFirstName() const {
	return FirstName;
}
const string Manager::getLastName() const {
	return LastName;
}
const string Manager::getFullName() const {
	return FirstName + " " + LastName;
}
const string Manager::toString() const {
	ostringstream buffer;
	buffer << fixed << showpoint << setprecision(2)
		<< "Manager's Data :" << endl
		<< "Name : " << getFullName() << endl
		<< "Boss'es Title : " << getBossTitle() << endl
		<< "Salary : $" << getSalary() << endl;
	return buffer.str();
}
void Manager::setFirstName(const string & Fname) {
	if (Fname.length() < MIN_NUM_CHARS_NAMES) {
		cout << "The new First Name " << Fname << " is too short. There is no change." << endl;
	}
	else {
		FirstName = Fname;
	}
}
void Manager::setLastName(const string & Lname) {
	if (Lname.length() < MIN_NUM_CHARS_NAMES) {
		cout << "The new Last Name " << Lname << " is too short. There is no change." << endl;
	}
	else {
		LastName = Lname;
	}
}

const string Manager::getBossTitle() const {
	return TitleOfBoss;
}
double Manager::getSalary() const {
	return salary;
}
void Manager::setBossTitle(string & Title) {
	if (Title.length() < MIN_NUM_CHARS_NAMES) {
		cout << "The boss's title cannot be less than 2 characters. \nNo change is made.\n";
	}
	else {
		TitleOfBoss = Title;
	}
}
void Manager::setSalary(double sal) {
	salary = abs(sal);
}