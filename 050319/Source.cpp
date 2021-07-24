/*
Name: young cheol ko
Class: CS52
Lab# : 8
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Start Date: 5/03 12:23
Date and Time of Copletion Date : 5/05 16:32
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

#include "Employee.h"
#include "Manager.h"

void print();

int main() {
	bool done = false;
	int menu;
	bool create = false;
	Manager * E = new Manager();
	while (done != true) {
		print();
		cin >> menu;
		if (menu == 1) {
			string Fn;
			string Ln;
			double Sl;
			string Ti;

			cout << "Enter first name of Manager : ";
			cin >> Fn;
			cout << "Enter last name of Manager : ";
			cin >> Ln;
			cout << "Enter title of Manager's Boss: ";
			cin >> Ti;
			cout << "Enter Manager's salary [xx.yy] ";
			cin >> Sl;
			E = new Manager(Fn, Ln, Sl, Ti);
			create = true;
		}
		else if (menu > 1 && menu < 8) {
			if (create == false) {
				cout << "Please create a Manager instance using option 1 before using this option." << endl;
			}
			else {
				if (menu == 2) {
					cout << E->toString();
				}
				if (menu == 3) {
					cout << "Enter Manager's new last name: ";
					string new_ln;
					cin >> new_ln;
					E->setLastName(new_ln);
				}
				if (menu == 4) {
					cout << "Type manager's new salary and press enter key: ";
					double new_sl;
					cin >> new_sl;
					E->setSalary(new_sl);
				}
				if (menu == 5) {
					cout << "Enter Manager's new boss'es title: ";
					string new_Ti;
					cin >> new_Ti;
					E->setBossTitle(new_Ti);
				}
				if (menu == 6) {
					cout << "Name : " << E->getFullName() << endl
						<< "Salary : $" << E->getSalary() << endl;
				}
				if (menu == 7) {
					cout << "Boss'es Title : " << E->getBossTitle() << endl;
				}
			}
		}
		else if (menu == 8) {
			break;
		}
		cout << "----------------------------------------------" << endl;
	}
	system("pause");
	return 0;
}

void print(){
	cout << "************** Main Menu*****************************" << endl
		<< "Enter the menu item of choice and press enter key." << endl
		<< "1. Create Manager instance from keyboard:" << endl
		<< "2. Print Manager to Console." << endl
		<< "3. Change Manager's last name." << endl
		<< "4. Change Manager's Salary." << endl
		<< "5. Change Manager's Boss'es Title." << endl
		<< "6. Print only Manager's name and Salary to console." << endl
		<< "7. Print only Manager's boss'es title to console." << endl
		<< "8. Exit" << endl;
}