/*
Name: young cheol ko
Class: CS52
Test# : 2
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Last successful Compilation: 4/24 20:24
Date and Time of when program verified all test results: 4/24 19:43
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <string>


using namespace std;


class Distance
{
private:
	int feet;
	int inches;
public:
	Distance(int in_feet = 0, int in_inches = 0);
	
	int getFeet()const;
	int getInches()const;

	friend const Distance operator + (const Distance & left, const Distance & right);
	friend const Distance operator + (const int left, const Distance & right);
	friend const Distance operator + (const Distance & left, const int right);
	friend const Distance operator - (const Distance & left, const Distance & right);
	friend const Distance operator - (const int left, const Distance & right);
	friend const Distance operator - (const Distance & left, const int right);

	const string toString() const;
};

Distance::Distance(int in_feet, int in_inches) {
	feet = in_feet;
	if (in_inches < 12) {
		inches = in_inches;
	}
	else {
		int inTofe;
		inTofe = in_inches / 12;
		inches = in_inches % 12;
		feet = feet + inTofe;
	}
}

int Distance::getFeet()const {
	return feet;
}
int Distance::getInches()const {
	return inches;
}

const Distance operator + (const Distance & left, const Distance & right) {
	Distance D = (left.feet + right.feet, left.inches + right.inches);
	return D;
}

const Distance operator + (const int left, const Distance & right) {
	Distance L = (0, left);
	Distance D = (L.getFeet() + right.getFeet(), L.getInches() + right.getInches());
	return D;
}

const Distance operator + (const Distance & left, const int right) {
	Distance R = (0, right);
	Distance D = (left.getFeet() + R.getFeet(), left.getInches()+ R.getInches() );
	return D;
}

const Distance operator - (const Distance & left, const Distance & right) {
	Distance D = (abs(left.feet - right.feet), abs(left.inches - right.inches));
	return D;
}

const Distance operator - (const int left, const Distance & right) {
	Distance L = (0, left);
	Distance D = (abs(L.getFeet() - right.getFeet()), abs(L.getInches() - right.getInches()));
	return D;
}

const Distance operator - (const Distance & left, const int right) {
	Distance R = (0, right);
	Distance D = (abs(left.getFeet() - R.getFeet()), abs(left.getInches() - R.getInches()));
	return D;
}

const string Distance::toString() const {
	ostringstream buffer;
	buffer << fixed;
	buffer << "Feet : " << getFeet() <<endl
		<< "Inches : " << getInches() <<endl
		<< "---------------------------" << endl;
	
	return buffer.str();

}

int main() 
{

}