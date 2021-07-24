/*
Name: young cheol ko
Class: CS52
Lab #: Test 1
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Last successful Compilation: 3/30 9:56
Date and Time of when program verified all test results: 3/30 9:56
*/

#include <iostream>
#include <string>

using namespace std;

size_t FillArrays(string Names[], int HoursWorked[], double PayRates[]);
double getSalary(int HoursWorked, double PayRate);

int main() {
	string Names[30];
	int HoursWorked[30];
	double PayRates[30];
	int count = 0;
	int Hours = 0;
	double Pay = 0;
	double Salary = 0;
	double sum = 0;

	cout.setf(ios::fixed);
	cout.precision(2);

	count = FillArrays(Names, HoursWorked, PayRates);
	cout << endl;
	for (int i = 0; i < count; i++) {
		Salary = 0;
		cout << "Welcome" << endl
			<< "Hello " << Names[i] << endl
			<< "You worked " << HoursWorked[i] << " hours in the week." << endl
			<< "Your hourly pay rate : $" << PayRates[i] << endl;
		Hours = HoursWorked[i];
		Pay = PayRates[i];
		Salary = getSalary(Hours, Pay);
		cout << "Your weekly salary : $" << Salary << endl;
		cout << "-----------------------------------" << endl;
		sum += Salary;
	}
	cout << "Number of employees entered " << count << ":" << endl
		 << "Total company pay roll : $" << sum << endl
		 << "Good bye." << endl;

	system("pause");
	return 0;
}

size_t FillArrays(string Names[], int HoursWorked[], double PayRates[]) {
	int index = 0;
	string first, last;
	double pay;
	cout << "Hello, EOF character in windows is Control + Z" << endl
		<< "EOF character on Mac is Control + D" << endl;

	while (cin)
	{			
		cout << "Enter employee`s first name or EOF character to exit:" << endl;
		cin >> first;
		cout << "Enter employee`s last name:" <<endl;
		cin >> last;
		Names[index] = first + " " + last;
		cout << "Enter hours in the week, worked by employee[whole number only]:" << endl;
		cin >> HoursWorked[index];
		cout << "Enter employee's hourly pay rate(xx.yy):" << endl;
		cin >> pay;
		PayRates[index] = pay;
		index++;
	}
	index--;
	return index;
}

double getSalary(int HoursWorked, double PayRate) {
	double Salary;

	const int overWork = 40;
	const double overWorkrate = 1.5;

	if (HoursWorked > 40) {
		Salary = ((HoursWorked - overWork) * PayRate * overWorkrate) + (overWork * PayRate);
	}
	else {
		Salary = (HoursWorked * PayRate);
	}
	return Salary;
}