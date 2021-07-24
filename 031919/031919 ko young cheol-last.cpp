/*
Name: young cheol ko
Class: CS52
Lab #: 3
Compiler Used: visual studio
Operating System Used: windows 10
Date and Time of Last successful Compilation: 3/24 18:30
Date and Time of when program verified all test results: 3/24 11:23
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

void BingroupToDec(const string & bin, int & dec);
void PaddingFunction(const string & original, string & Padded);
void BinToDec();
void printmenu();
void OctToDe();

int main() {
	bool done = false;
	int menu;

	while(!done){
	printmenu();
	cin >> menu;
		switch (menu) {
		case 1:
			BinToDec();
			break;
		case 2:
			OctToDe();
			break;
		case 3:
			done = true;
			break;
		default:
			cout << "This choice is not yet implemented." << endl;
			break;
		}
	}
	return 0;
}

void printmenu() {
	cout << "Caution!No validation is done on numbers entered.They must conform to required input form." << endl;
	cout << "******Main Menu******" << endl;
	cout << "1. Convert binary to decimal." << endl;
	cout << "2. Convert Octal to decimal." << endl;
	cout << "3. Exit. " << endl;
}

void PaddingFunction(const string & original, string & Padded)
{
	size_t howMany = 4 - original.length() % 4;
	Padded = original;

	for (size_t i = 0; i < howMany; i++) {
		Padded = "0" + Padded;
	}
}
void BinToDec()
{
	string binNumber;
	cout << "Enter your binary number." << endl
	     << ":";
	cin >> binNumber;
	size_t len = binNumber.length();
	cout << "Original binary Number : " << binNumber << endl;
	int Mydec = 0;
	size_t count = 0;
	if (len % 4 == 0) {
		int i = pow(16, ((len / 4) - 1));
		for (count = 0; count < len; count+=4) {
			string group = binNumber.substr(count, 4);
			int dec;
			BingroupToDec(group, dec);
			Mydec += dec * i;
			i = i / 16;
		}
		cout << "Its decimal conversion : " << Mydec << endl;
	}
	else {
		string Padded;
		PaddingFunction(binNumber, Padded);
		len = Padded.length();
		int i = pow(16, ((len / 4) - 1));
		for (count = 0; count < len; count += 4) {
			string group = Padded.substr(count, 4);
			int dec;
			BingroupToDec(group, dec);
			Mydec += dec * i;
			i = i / 16;
		}
		cout << "Its decimal conversion : " << Mydec << endl;
	}
}

void BingroupToDec(const string & bin, int & dec)
{
	if (bin == "0000") {
		dec = 0;
	}
	else if (bin == "0001")
	{
		dec = 1;
	}
	else if (bin == "0010")
	{
		dec = 2;
	}
	else if (bin == "0011")
	{
		dec = 3;
	}
	else if (bin == "0100")
	{
		dec = 4;
	}
	else if (bin == "0101")
	{
		dec = 5;
	}
	else if (bin == "0110")
	{
		dec = 6;
	}
	else if (bin == "0111")
	{
		dec = 7;
	}
	else if (bin == "1000")
	{
		dec = 8;
	}
	else if (bin == "1001")
	{
		dec = 9;
	}
	else if (bin == "1010")
	{
		dec = 10;
	}
	else if (bin == "1011")
	{
		dec = 11;
	}
	else if (bin == "1100")
	{
		dec = 12;
	}
	else if (bin == "1101")
	{
		dec = 13;
	}
	else if (bin == "1110")
	{
		dec = 14;
	}
	else if (bin == "1111")
	{
		dec = 15;
	}
}

void OctToDe() {
	long int value;
	long int arr[30];
	int length = 0;
	long int result = 0;
	int mult = 1;

	cout << "Enter the octal number" << endl;
	cout << ":";
	cin >> value;
	for (int i = 0; value > 0; i++) {
		arr[i] = value % 10;
		length++;
		value = value / 10;
	}
	for (int j = 0; j < length; j++) {
		if (arr[j] < 8 && arr[j] >= 0) {
			result = result + arr[j] * mult;
		}
		mult = mult * 8;
	}
	cout << "Its decimal conversion : " << result << endl;
}
