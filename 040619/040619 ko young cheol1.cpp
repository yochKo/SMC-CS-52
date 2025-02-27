/*
Name: young cheol ko
Class: CS52
Lab #: 5
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Last successful Compilation: 4/07 21:41
Date and Time of when program verified all test results: 4/07 19:23
*/

//
//  CertDeposit.h
//  CertificateOfDepositClassProject
//
//  Created by Satish Singhal on 3/27/19.
//  Copyright � 2019 Satish Singhal. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class CertDeposit
{
private:
	double Principal;
	int AccountNumber;
	string FirstName;
	string LastName;
	double InterestRate;
	double DepositYears;
	int NumCompounding;
	double Accumulation = 0;
	double InterestEarned = 0;
public:
	CertDeposit();
	CertDeposit(double In_Principal, int In_AccountNumber, string In_FirstName,
		string In_LastName, double In_InterestRate, double In_DepositYears,
		int In_NumCompounding);
	double getPrincipal()const;
	const string getFirstName() const;
	const string getLastName() const;
	const string getFullName() const;
	int getAccountNumber() const;
	double getDepositYears() const;
	int getNumComoundings() const;
	double getAnnualInterestRate() const;
	double getAccumulation() const;
	double getInterestAccrued() const;
	const string toString() const;
	void setLastName(string In_LastName);
};

CertDeposit::CertDeposit()
{
	Principal = 0.0;
	AccountNumber = 0;
	FirstName = "First name not set";
	LastName = "Last name not set";
	InterestRate = 0.0;
	DepositYears = 0;
	NumCompounding = 0;
}
CertDeposit::CertDeposit(double In_Principal, int In_AccountNumber,
	string In_FirstName, string In_LastName,
	double In_InterestRate, double In_DepositYears,
	int In_NumCompounding)
{
	Principal = In_Principal;
	AccountNumber = In_AccountNumber;
	FirstName = In_FirstName; 
	LastName = In_LastName;
	InterestRate = In_InterestRate;
	DepositYears = In_DepositYears,
	NumCompounding = In_NumCompounding;
	if (In_Principal < 0) {
		abs(In_Principal);
	}
	if (In_InterestRate < 0) {
		abs(In_InterestRate);
	}
	if (In_DepositYears < 0) {
		abs(In_DepositYears);
	}
	if (In_NumCompounding < 0) {
		abs(In_NumCompounding);
	}
	//Accumulation = Principal * pow(1 + InterestRate / NumCompounding, DepositYears * NumCompounding);
	//InterestEarned = (Accumulation - Principal);
}

double CertDeposit::getAccumulation() const
{	
	double A = Principal * pow(1 + InterestRate / NumCompounding, DepositYears * NumCompounding);
	return A;
	//return Accumulation;
}
double CertDeposit::getInterestAccrued() const
{
	double I = (getAccumulation() - Principal);
	return I;
	//return InterestEarned;
}
const string CertDeposit::toString() const
{
	ostringstream buffer;
	buffer << fixed << showpoint << setprecision(2)
		<< "Account Number: " << getAccountNumber() << endl
		<< "Name: " << getFullName() << endl
		<< "Original Deposit : $" << getPrincipal() << endl
		<< "Annual Interest rate : " << (getAnnualInterestRate() * 100) << endl
		<< "Number of years of deposit : " << getDepositYears() << endl
		<< "Number of times compounded per year : " << getNumComoundings() << endl
		<< "Total accumulation : : $" << getAccumulation() << endl
		<< "Interest accrued : $" << getInterestAccrued() <<endl
		<< " -------------------------------------------------" << endl;
	return buffer.str();
}
double CertDeposit::getPrincipal()const
{
	return Principal;
}
const string CertDeposit::getFirstName() const
{
	return FirstName;
}
const string CertDeposit::getLastName() const
{
	return LastName;
}
const string CertDeposit::getFullName() const
{
	return FirstName + " " + LastName;
}
int CertDeposit::getAccountNumber() const
{
	return AccountNumber;
}
double CertDeposit::getDepositYears() const
{
	return DepositYears;
}
int CertDeposit::getNumComoundings() const
{
	return NumCompounding;
}
double CertDeposit::getAnnualInterestRate() const
{
	return InterestRate;
}
void CertDeposit::setLastName(string In_LastName)
{
	LastName = In_LastName;
}
void Sort(vector<CertDeposit> & CDVec);
inline bool operator<(const CertDeposit & a, const CertDeposit & b);
void printmenu();

int main()
{
	int menu;
	vector <CertDeposit> CDVec;
	
	double Principal;
	int AccountNumber;
	string FirstName;
	string LastName;
	double InterestRate;
	double DepositYears;
	int NumCompounding;
	double Accumulation = 0;
	double InterestEarned = 0;
	bool run = true;
	while(run) {
		printmenu();
		cin >> menu;
		if (menu==1) {
			cout << "Enter account holder's first name:" << endl;
			cin >> FirstName;
			cout << "Enter account holder's last name:" << endl;
			cin >> LastName;
			cout << "Enter account number[whole number only]:" << endl;
			cin >> AccountNumber;
			cout <<	"Enter amount of original deposit :" << endl;
			cin >> Principal;
			cout << "Enter annual interest rate. For example for 7.2% enter 0.072 :" << endl;
			cin >> InterestRate;
			cout << "Enter number of years for certificate of deposit :" << endl;
			cin >> DepositYears;
			cout << "Enter number of times interest is compounded per year" << endl
				 << "[whole number only]: ";
			cin >> NumCompounding;
			CertDeposit newAccount(Principal, AccountNumber, FirstName, LastName, InterestRate, DepositYears, NumCompounding);
			CDVec.push_back(newAccount);
		}
		else if (menu == 2) {
			for (int i = 0; i < CDVec.size(); i++)
			{
				cout << CDVec[i].toString();
			}
		}
		else if (menu == 3) {
			cout << "Enter full path to output file: ";
			cin.ignore(10000, '\n');
			string outFilename;
			getline(cin, outFilename);

			ofstream out;
			out.open(outFilename, ios::app);
			
			if (out.is_open()) {
				for (int i = 0; i < CDVec.size(); i++)
				{
					out << CDVec[i].toString();
				}
			}
			else {
				cout << "could not open output file." << endl;
			}
			out.close();
		}
		else if (menu == 4) {
			Sort(CDVec);
		}
		else if (menu == 5) {
			run = false;
		}
	}
	system("pause"); // uncomment for Visual Studio 2017
	return 0;
}
//C:\Users\aqr17\Desktop\output.txt
inline bool operator<(const CertDeposit & a, const CertDeposit & b)
{
	return a.getAccountNumber() < b.getAccountNumber();
}
void Sort(vector<CertDeposit>  & CDVec)
{
	sort(CDVec.begin(), CDVec.end());
}
void printmenu() {
	cout << "********* Main Menu ***********" << endl
	<< "1. Add a new Certificate of deposit account to the CertDeposit Vector :" << endl
	<< "2. Print all certificate of deposit accounts to console :" << endl
	<< "3. Print all certificate of deposit accounts to an output file" << endl
	<< "[User would be asked for the output file full path] :" << endl
	<< "4. Sort CertDeposit Vector based on account number in asccending order :" << endl
	<< "5. Exit" << endl;
}
