/*
Name: young cheol ko
Class: CS52
Lab #: 4
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Last successful Compilation: 3/28 19:24
Date and Time of when program verified all test results: 3/28 12:43
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void FillNames(vector<string> & vecNames);
void SortNames(vector<string> & vecNames);

int main() {
	
	vector<string> vecNames;
	string input;
	
	cout << "Information: "
		<< "EOF character in windows is Control + Z" << endl
		<< "and EOF character on Mac is Control + D :" << endl
		<< "---------------------------------------------- - " << endl;

	FillNames(vecNames);

	cout << "The original names in the vector are:\n";
	for (int i = 0; i < vecNames.size(); i++) {
		cout << vecNames[i] << " ";
	}
	cout << "\n";


	SortNames(vecNames);
	cout << "After sorting alphabetically in ascending order" <<endl
		<< "the names in the vector are :\n";
	for (int i = 0; i < vecNames.size(); i++) {
		cout << vecNames[i] << " ";
	}
	cout << "\n";
	
	system("pause");
	return 0;
}

void FillNames(vector<string> & vecNames) {
	
	string input;
	
	cout << "Enter first name only in all caps(example: JOHN)" << endl
		<< "Enter EOF character to exit name entry :";
	cin >> input;
	cout << "---------------------------------------------- - " << endl;
	while (cin)
	{
		vecNames.push_back(input);
		cout << "Enter first name only in all caps(example: JOHN)" << endl
			<< "Enter EOF character to exit name entry :";
		cin >> input;
		cout << "---------------------------------------------- - " << endl;
	}
}

void SortNames(vector<string> & vecNames) {
	//buble sort
	int k;
	string Temp, a, b;
	for (int i = (vecNames.size()-1); i > 0; i--) {
		for (int j = 0; j < i; j++) {
			a = vecNames.at(j);
			b = vecNames.at(j+1);
			k = a.compare(b);
			if (k>0){
				string temp = vecNames.at(j + 1);
				vecNames.at(j + 1) = vecNames.at(j);
				vecNames.at(j) = temp;
			}
		}
	}
}
