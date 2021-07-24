/*
Name: young cheol ko
Class: CS52
Test# : 2
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Last successful Compilation: 4/28 00:20
Date and Time of when program verified all test results: 4/27 11:35
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
	void Normalize(int &fe, int &inc) const;

	friend const Distance operator + (const Distance & left, const Distance & right);
	friend const Distance operator + (const int & left, const Distance & right);
	friend const Distance operator + (const Distance & left, const int & right);
	friend const Distance operator - (const Distance & left, const Distance & right);
	friend const Distance operator - (const int & left, const Distance & right);
	friend const Distance operator - (const Distance & left, const int & right);

	const string toString() const;
};

Distance::Distance(int in_feet, int in_inches) {
	Normalize(in_feet, in_inches);
	feet = in_feet;
	inches = in_inches;
}

void Distance::Normalize(int &fe, int &inc) const
{
	if (inc >= 12) {
		int change;
		change = inc / 12;
		inc = inc % 12;
		fe = fe + change;
	}
}

const Distance operator + (const Distance & left, const Distance & right) {
	Distance D(left.feet + right.feet, left.inches + right.inches);
	return D;
}

const Distance operator + (const int & left, const Distance & right) {
	Distance L(0, left);
	Distance D(L.feet + right.feet, L.inches + right.inches);
	return D;
}

const Distance operator + (const Distance & left, const int & right) {
	Distance R(0, right);
	Distance D(left.feet + R.feet, left.inches+ R.inches );
	return D;
}

const Distance operator - (const Distance & left, const Distance & right) {
	int temp;
	temp = ((left.feet * 12 + left.inches)-(right.feet * 12 + right.inches));
	Distance D(0,abs(temp));
	return D;
}

const Distance operator - (const int & left, const Distance & right) {
	Distance L(0, left);
	int temp;
	temp = ((L.feet * 12 + L.inches) - (right.feet * 12 + right.inches));
	Distance D(0, abs(temp));
	return D;
}

const Distance operator - (const Distance & left, const int & right) {
	Distance R(0, right);
	int temp;
	temp = ((left.feet * 12 + left.inches) - (R.feet * 12 + R.inches));
	Distance D(0, abs(temp));
	return D;
}

const string Distance::toString() const {
	ostringstream buffer;
	buffer << fixed;
	buffer << "Feet : " << feet <<endl
		<< "Inches : " << inches <<endl
		<< "---------------------------" << endl;
	
	return buffer.str();
}

int main() 
{
	Distance D1(12,25);
	cout << D1.toString();
	Distance D2(2, 7);
	cout << D2.toString();
	Distance D3(3, 9);
	cout << D3.toString();
	Distance D4(0, 55);
	cout << D4.toString();
	Distance D5(0, 16);
	cout << D5.toString();
	cout << "Plus" << "========="<<endl;
	Distance D6 = D2 + D3;
	cout << D6.toString();
	Distance D7 = 55 + D2;
	cout << D7.toString();
	Distance D8 = D2 + 16;
	cout << D8.toString();
	cout << "Minus" << "=========" << endl;
	Distance D9 = D2 - D3;
	cout << D9.toString();
 	Distance D10 = 55 - D2;
 	cout << D10.toString();
	Distance D11 = D2 - 16;
	cout << D11.toString();
	Distance D12(7, 0);
	Distance D13(0, 11);
	Distance D14 = D12 - D13;
	cout << D14.toString();

	system("pause");
	return 0;
}