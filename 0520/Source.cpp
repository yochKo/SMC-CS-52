/*
Name: young cheol ko
Class: CS52
Lab# : 10
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Start Date: 5/20 9:23
Date and Time of Copletion Date : 5/24 23:39
*/

#include "Stack.h"
#include <string>

int main() {
	cout << "int" <<endl;
	Stack<int> S1;

	//exception
	try {
		S1.top();
	}
	catch (excpt ex) {
		cout << ex.getMessage() << endl;
	}


	for (int i = 1; i < 13; i++) {
		S1.push(i);
	}
	for (int i = 1; i < 13; i++) {
		S1.pop();
	}
	
	cout << "double" << endl;
	Stack<double> S2;
	for (double i = 1; i < 13; i++) {
		S2.push(i);
	}
	for (double i = 1; i < 13; i++) {
		S2.pop();
	}
	
	cout << "float" << endl;
	Stack<float> S3;
	for (float i = 1; i < 13; i++) {
		S3.push(i);
	}
	for (float i = 1; i < 13; i++) {
		S3.pop();
	}
	
	cout << "Char" << endl;
	Stack<char> S4;
	char ch[15] = "abcdefghijklmn";
	for (int i = 0; i < 13; i++) {
		S4.push(ch[i]);
	}
	for (int i = 0; i < 13; i++) {
		S4.pop();
	}
	
	cout << "size_t" << endl;
	Stack<size_t>S5;
	for (size_t i = 1; i < 13; i++) {
		S5.push(i);
	}
	for (size_t i = 1; i < 13; i++) {
		S5.pop();
	}

	system("pause");
	return 0;
}
