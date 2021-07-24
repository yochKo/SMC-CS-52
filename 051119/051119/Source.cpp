/*
Name: young cheol ko
Class: CS52
Lab# : 9
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Start Date: 5/11 12:23
Date and Time of Copletion Date : 5/14 14:47
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class ZeroOrNagativeInitialBalanceException {
private:
	double initBalance;
	string Message;
public:
	ZeroOrNagativeInitialBalanceException(double bal = 0.0, const string & msg = "Message not set") :
		initBalance(bal), Message(msg)
	{
	}
	double getInitBalnace() {
		return initBalance;
	}
	const string getMessage() {
		return Message;
	}
};

class BankAccount
{
private:
	string ActNum;
	double balance;
	string FirstName;
	string LastName;
public:
	BankAccount() {
		balance = 0.0;
		FirstName = "First Name not set";
		LastName = "Last Name not set";
		ActNum = "Account Number not set";
	}
	BankAccount(const string & actN, const string & fname, const string &lname, double bal) {
		ActNum = actN;
		FirstName = fname;
		LastName = lname;
		if (bal < 0) {
			cout << "Balance can not be negative." << endl;
			balance = 0;
		}
		if (bal > 0) {
			balance = bal;
		}
	}
	void deposit(double money) {
		if (money < 0 ) {
			cout << "You can not deposit negative value." << endl;
		}
		if (money == 0) {
			cout << "You can not deposit zero value." << endl;
		}
		if (money > 0) {
			balance += money;
		}
	}
	string getAccountNumber()const {
		return ActNum;
	}
	double getBalance() const {
		return balance;
	}
	const string getFirstName() const {
		return FirstName;
	}
	const string getFullName() const {
		return FirstName + " " + LastName;
	}
	const string getLastName() const {
		return LastName;
	}
	void setAccountNumber(const string & actN) {
		ActNum = actN;
	}
	void setLastName(const string & lname) {
		LastName = lname;
	}
	const string toString() const {
		ostringstream buffer;
		buffer << fixed << showpoint << setprecision(2)
			<< "Name: " << getFullName() << endl
			<< "Account Number: " << getAccountNumber() << endl
			<< "Balance: $" << getBalance() << endl
			<< " -------------------------------------------------" << endl;
		return buffer.str();
	}
	void withdraw(double money) {
		if (money < 0) {
			cout << "You can not withdraw negative value." << endl;
		}
		if (money == 0) {
			cout << "You can not withdraw zero value." << endl;
		}
		if (money > 0) {
			if ((balance - money) >= 0) {
				balance -= money;
			}
			else {
				cout << "Balance can not be negative." << endl;
			}
		}
	}
	void print(ostream & out = cout) const {
		out << this->toString();
	}
	static void getInstance(BankAccount & BA) {
		if (!cin) {
			return;
		}
		cout << "Enter the balance or intial deposit: ";
		double bal;
		cin >> bal;
		ZeroOrNagativeInitialBalanceException zon;
		if (bal < 0) {
			string msg = "Initial balance of negative dollars is not allowed.";
			throw ZeroOrNagativeInitialBalanceException(bal, msg);
		}
		if (bal == 0) {
			string msg = "Initial balance of zero dollars is insufficient.";
			throw ZeroOrNagativeInitialBalanceException(bal,msg);
		}
		cout << "Enter the new (unique) account number: ";
		string actN;
		cin >> actN;
		cout << "Enter the first name on account: ";
		string fname;
		cin >> fname;
		cout << "Enter the last name on account: ";
		string lname;
		cin >> lname;
		BA = BankAccount(actN, fname, lname, bal);
	}
};

void PrintMenu();

int main() {
	
	BankAccount BA;
	BankAccount * BAptr;
	bool done = false;
	bool menu = false;
	bool Create = false;
	int Select = 0;
	while (!menu)
	{
		PrintMenu();
		cin >> Select;
		if (Select == 1) {
			while (!done) {
				try {
					BankAccount::getInstance(BA);
					done = true;
				}
				catch (ZeroOrNagativeInitialBalanceException EC) {
					cout << EC.getMessage() << endl;
					done = false;
				}
			}
			Create = true;
		}
		if (Select == 2) {
			cout << "Your input file should follow order. ex)" << endl;
			cout << "Balance\nFirstname\nLastname\nAccountnumber." << endl;
			cout << "Enter full path to input file: ";
			cin.ignore(10000, '\n');
			string inFilename;
			getline(cin, inFilename);

			ifstream in;
			in.open(inFilename, ios::app);

			if (in.is_open()) {
				string in_line;
				double bal;
				string actN;
				string fname;
				string lname;

				for (int i = 0; i < 4; i++) {
					string x;
					getline(in, in_line);
					if (i == 0) {
						bal = stod(in_line);
					}
					if (i == 1) {
						fname = in_line;
					}
					if (i == 2) {
						lname = in_line;
					}
					if (i == 3) {
						actN = in_line;
					}
				}
				BA = BankAccount(actN, fname, lname, bal);
			}
			else {
				cout << "could not open input file." << endl;
			}
			in.close();

			Create = true;
		}
		if (Create == false)
		{
			cout << "An instance of BankAccount is yet" << endl;
		}
		else {
			if (Select == 3) {
				cout << "Account balance is $";
				cout << fixed << setprecision(2) << BA.getBalance() << endl;
			}
			if (Select == 4) {
				int money;
				cout << "Enter the number of withdraw" << endl;
				cin >> money;
				BA.withdraw(money);
			}
			if (Select == 5) {
				int money;
				cout << "Enter the number of deposit" << endl;
				cin >> money;
				BA.deposit(money);
			}
			if (Select == 6) {
				BA.print();
			}
			if (Select == 7) {
				cout << "Enter full path to output file: ";
				cin.ignore(10000, '\n');
				string outFilename;
				getline(cin, outFilename);

				ofstream out;
				out.open(outFilename, ios::app);

				if (out.is_open()) {
					BA.print(out);
				}
				else {
					cout << "could not open output file." << endl;
				}
				out.close();
			}
			if (Select == 8) {
				cout << "The full name of account holder is " + BA.getFullName() << endl;
			}
			if (Select == 9) {
				cout << "The account number is " + BA.getAccountNumber() << endl;
			}
		}
		if (Select == 10) {
			menu = true;
		}
	}
	
	system("pause");
	return 0;
}

void PrintMenu() {
	cout << "********* Main Menu ***********" << endl
		<< "1. Create an account from keyboard data entry" << endl
		<< "2. Create an account from input file data entry" << endl
		<< "3. Print account balance to console.[Must have $ sign and 2 digits in output]." << endl
		<< "4. Withdraw money" << endl
		<< "5. Deposit money" << endl
		<< "6. Print account details to console" << endl
		<< "7. Print account details to an output file." << endl
		<< "8. Print full name of account holder to console only." << endl
		<< "9. Print account number only of the account holder to console." << endl
		<< "10. Exit" << endl;
}
