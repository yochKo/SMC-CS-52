//
//  CertDeposit.h
//  CertificateOfDepositClassProject
//
//  Created by Satish Singhal on 3/27/19.
//  Copyright © 2019 Satish Singhal. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
/*
 Class Description
 Class CertDeposit approximately, models a certificate of deposit in a bank.
 Followings are the characteristics of certificate of deposit in a bank.
 1. A principal deposit is made.
 2. principal is kept in deposit for certain number of years.
 3. A fixed annual interest rate is applied.
 4. Interest is compounded with certain frequency per year.
 The formula for total money accumulation after certain number of years
 is given as follows:
 A = P*( 1 + r/q)^n*q  (^ is the power symbol)
 Where:
 A = Total accumulation after n years
 P = Initial deposit or principal
 r = Annual interest rate in decimalized fraction (not in percent)
 q = Number of times the compounding is done per year.
 n = Number of years P is left in deposit.
 Class would have data members that would allow input for P, r, n, and q,
 though we would use descriptive names rather than single letter names.
 Class would also have data members for account holders, first, last names,
 account number.
 Class member functions would include, constructors, get (accessor)
 functions for all private data members and additional querey functions.
 Class would have set functions for those data members, that may need
 safe mutation.
 Main function using the class would have a vector of CertDeposit class;
 that would need following operations from a menu driven program in
 a loop:
 1. Populate the CertDeposit vector from keyboard data entry.
 2. Print the CertDeposit vector to console and output file.
 3. Sort the CertDeposit vector based on account number.
 */
class CertDeposit
{
private:
    /*
     Principal is the amount of money in dollars (xx.yy) started as a deposit.
     */
    double Principal;
    /*
     AccountNumber is the unique number assigned to the account.
     */
    int AccountNumber;
    /*
     FirstName is the first name of the account holder
     */
    string FirstName;
    /*
     LastName is the last name of the account holder
     */
    string LastName;
    /*
     InterestRate is the annual interest rate accrued as decimalized
     fraction. For example if annual interest rate advertised is 7.2 %,
     then data member InterestRate would actually store 0.072.
     */
    double InterestRate;
    /*
     DepositYears, is number of years of deposit.
     */
    double DepositYears;
    /*
     NumCompounding is the number of times interest is compounded each year.
     In compounding, interest is added to the principal, and this sum
     becomes the new principal for next accrual period.
     */
    int NumCompounding;
    /*
     Accumulation is a computed field which uses the formula given in
     class description, to find overall money accumulated at the end of
     deposit period. This would simply be sum of principal and interest
     earned.
     */
    double Accumulation;
    /*
     InterestEarned is the amount of interest earned on the deposit at the
     end of deposit period.
     */
    double InterestEarned;
public:
    /*
     Default constructor assigns the following values to the class data
     members in it's body in the constructor implementaion:
     Principal = 0.0
     AccountNumber = 0
     FirstName = "First name not set"
     LastName = "Last name not set"
     InterestRate = 0.0
     DepositYears = 0
     NumCompounding = 0
     */
    CertDeposit();
    /*
     Explicit constructor takes user-defined arguments to initialize
     all class membersexcept for Accumulation and InterestEarned,
     which are to be computed from other data members.
     Initializations to be done are as follows:
     If a class data member name is Foo, then constructor argument In_Foo
     initializes it as follows:
     Foo = In_Foo;
     If a negative value is entered for any of the below, the
     constructor body uses abs function in cmath header file
     to take only the absolute value of the negative number.
     In_Principal
     InterestRate
     DepositYears
     NumCompounding
     */
    CertDeposit(double In_Principal, int In_AccountNumber, string In_FirstName,
                string In_LastName, double In_InterestRate, double In_DepositYears,
                int In_NumCompounding);
    /*
     Member function  getPrincipal is accessor for data member Principal
     and returns it. See Savicth 10th edition pages 574 lines 85 to 88
     and page 575 lines 90 to 93 for design of get functions.
     */
    double getPrincipal()const;
    /*
     Member function  getFirstName is accessor for data member FirstName
     and returns it.
     */
    const string getFirstName() const;
    /*
     Member function  getLastName is accessor for data member LastName
     and returns it.
     */
    const string getLastName() const;
    /*
     Member function  getFullName concatenates data members
     FirstName and LastName and returns the full name thus created.
     */
    const string getFullName() const;
    /*
     Member function  getAccountNumber is accessor for data member AccountNumber
     and returns it.
     */
    int getAccountNumber() const;
    /*
     Member function  getDepositYears is accessor for data member DepositYears
     and returns it.
     */
    double getDepositYears() const;
    /*
     Member function  getNumComoundings is accessor for data member
     NumCompoundings and returns it.
     */
    int getNumComoundings() const;
    /*
     Member function  getAnnualInterestRate is accessor for data member
     InterestRate and returns it.
     */
    double getAnnualInterestRate() const;
    /*
     Member function  getAnnualInterestRate comoutes the accumulation
     according to the accumulation formula stated earlier in class description
     and returns the accumulated amount over the life of Certificate of deposit.
     */
    double getAccumulation() const;
    /*
     Function getInterestAccrued, computes the interest
     accrued during the life of certificate of deposit
     and returns it.
     */
    double getInterestAccrued() const;
    /*
     toString function prints to a string all class member
     information, so that one CertDeposit object is made
     into a string in the format such as below:
     Account Number: 9999
     Name: Jim Wim
     Original Deposit: $2000.00
     Annual Interest rate: 5.60
     Number of years of deposit: 15.00
     Number of times compounded per year: 12
     Total accumulation: $4623.69
     Interest accrued: $2623.69
     You can use ostringstream object to write
     the various class data members.
     Finally the str() member function would return the
     string version of the object.
     Link below gives you more information on ostringstream object
     http://www.cplusplus.com/reference/sstream/ostringstream/?kw=ostringstream
     One use example is given at the link below
     http://www.cplusplus.com/reference/sstream/ostringstream/str/
     Chapter on functions in my own website at the link below also
     discusses the ostringstream object
     https://sites.google.com/site/cplusplussmc/c-user-defined-functions
     */
    const string toString() const;
    
    /*
     setName member function sets the LastName data member to
     user provided value In_LastName
     */
    void setLastName(string In_LastName);
};

/*
 Blank bodies of member functions and constructors are provided below.
 All member functions have throw statements in them. Whole program will compile
 as such. You are to fill code inside the body of each function and compile
 after the code is filled. Delete throw statement once you
 start to code the body of a function.
 You must compile often to keep program in
 compiled state pretty much as you complete coding of one item. Only then
 move to next item.
 */

CertDeposit::CertDeposit()
{
    
}
CertDeposit::CertDeposit(double In_Principal, int In_AccountNumber,
                         string In_FirstName,string In_LastName,
                         double In_InterestRate, double In_DepositYears,
                         int In_NumCompounding)
{
   
}
double CertDeposit::getAccumulation() const
{
    throw "To be completed";
}
double CertDeposit::getInterestAccrued() const
{
    throw "To be completed";
}
const string CertDeposit::toString() const
{
   throw "To be completed";
}
// All function starting with word get ONLY Have one line of code!
// That code is just one return statement.
// See Savitch to see how to write get functions.
double CertDeposit::getPrincipal()const
{
    throw "To be completed";
}

const string CertDeposit::getFirstName() const
{
    throw "To be completed";
}

const string CertDeposit::getLastName() const
{
    throw "To be completed";
}

const string CertDeposit::getFullName() const
{
    throw "To be completed";
}

int CertDeposit::getAccountNumber() const
{
    throw "To be completed";
}

double CertDeposit::getDepositYears() const
{
    throw "To be completed";
}

int CertDeposit::getNumComoundings() const
{
    throw "To be completed";
}

double CertDeposit::getAnnualInterestRate() const
{
    throw "To be completed";
}

void CertDeposit::setLastName(string In_LastName)
{
   throw "To be completed";
}
// Below are the additional functions and main function
/*
 Sort function sorts populated vector CDVec in ascending order of account
 number. Use std::sort function. See basic description of this function at
 http://www.cplusplus.com/reference/algorithm/sort/
 See excellent detailed description at link
 https://www.codeproject.com/Articles/38381/STL-Sort-Comparison-Function#funcobject
 */
void Sort(vector<CertDeposit> & CDVec);
/*
 Function operator< is used as third argument in call to std::sort
 to sort CertDeposit vector in ascending other of account numbers.
 See more in description of sort function above.
 */
inline bool operator<(const CertDeposit & a, const CertDeposit & b);
/*
 main function performs following action.
 A. Creates a vector of CertDeposit type.
 B. Executes a menu driven program that has following menus:
 1 . Add a new Certificate of deposit account to the
 CertDeposit Vector from keyboard data entry.
 2. Print all certificate of deposit accounts in the vector
 to the console.
 3. Print all certificate of deposit accounts in the vector to an output file
 Following actions are required to properly open, validate, write, and
 close output file. Please read Savitch for learning how to accomplish this.
 3.1. User of program must be able to specify full path of the output file.
 3.2. Programmer is NOT ALLOWED to "hard code" file name.
 3.2. Full path to the file MAY HAVE gaps and whitespaces.
 3.3. Program must do validation, whether output file opening
 succeeded or failed. Writing to file must be done if file opening
 test shows that file is indeed successfully opened.
 3.4. Output file MUST BE CLOSED after writing to it is completed.
 4. Sort CertDeposit Vector based on account number in asccending order.
 5. Exit
 */
int main()
{
    
    
    //system ("pause"); // uncomment for Visual Studio 2017
    return 0;
}

inline bool operator<(const CertDeposit & a, const CertDeposit & b)
{
    return a.getAccountNumber() < b.getAccountNumber();
}
void Sort(vector<CertDeposit>  & CDVec)
{
    
}
/*
 Program output:
 
 This program would demo certificate of deposit account in a bank.
 ********* Main Menu ***********
 1. Add a new Certificate of deposit account to the CertDeposit Vector:
 2. Print all certificate of deposit accounts to console:
 3. Print all certificate of deposit accounts to an output file
 [User would be asked for the output file full path]:
 4. Sort CertDeposit Vector based on account number in asccending order:
 5. Exit
 1
 Enter account holder's first name:
 Jim
 Enter account holder's last name:
 Wim
 Enter account number [whole number only]:
 9999
 Enter amount of original deposit:
 2000.0
 Enter annual interest rate. For example for 7.2% enter 0.072:
 0.056
 Enter number of years for certificate of deposit:
 15
 Enter number of times interest is compounded per year
 [whole number only]: 12
 ********* Main Menu ***********
 1. Add a new Certificate of deposit account to the CertDeposit Vector:
 2. Print all certificate of deposit accounts to console:
 3. Print all certificate of deposit accounts to an output file
 [User would be asked for the output file full path]:
 4. Sort CertDeposit Vector based on account number in asccending order:
 5. Exit
 1
 Enter account holder's first name:
 Lisa
 Enter account holder's last name:
 Adams
 Enter account number [whole number only]:
 1234
 Enter amount of original deposit:
 1000.0
 Enter annual interest rate. For example for 7.2% enter 0.072:
 0.072
 Enter number of years for certificate of deposit:
 10
 Enter number of times interest is compounded per year
 [whole number only]: 1
 ********* Main Menu ***********
 1. Add a new Certificate of deposit account to the CertDeposit Vector:
 2. Print all certificate of deposit accounts to console:
 3. Print all certificate of deposit accounts to an output file
 [User would be asked for the output file full path]:
 4. Sort CertDeposit Vector based on account number in asccending order:
 5. Exit
 1
 Enter account holder's first name:
 Adam
 Enter account holder's last name:
 Adamson
 Enter account number [whole number only]:
 1111
 Enter amount of original deposit:
 500.0
 Enter annual interest rate. For example for 7.2% enter 0.072:
 0.089
 Enter number of years for certificate of deposit:
 20
 Enter number of times interest is compounded per year
 [whole number only]: 6
 ********* Main Menu ***********
 1. Add a new Certificate of deposit account to the CertDeposit Vector:
 2. Print all certificate of deposit accounts to console:
 3. Print all certificate of deposit accounts to an output file
 [User would be asked for the output file full path]:
 4. Sort CertDeposit Vector based on account number in asccending order:
 5. Exit
 1
 Enter account holder's first name:
 Bertha
 Enter account holder's last name:
 Jones
 Enter account number [whole number only]:
 2222
 Enter amount of original deposit:
 5000.0
 Enter annual interest rate. For example for 7.2% enter 0.072:
 0.1
 Enter number of years for certificate of deposit:
 5
 Enter number of times interest is compounded per year
 [whole number only]: 9
 ********* Main Menu ***********
 1. Add a new Certificate of deposit account to the CertDeposit Vector:
 2. Print all certificate of deposit accounts to console:
 3. Print all certificate of deposit accounts to an output file
 [User would be asked for the output file full path]:
 4. Sort CertDeposit Vector based on account number in asccending order:
 5. Exit
 2
 Account Number: 9999
 Name: Jim Wim
 Original Deposit: $2000.00
 Annual Interest rate: 5.60
 Number of years of deposit: 15.00
 Number of times compounded per year: 12
 Total accumulation: $4623.69
 Interest accrued: $2623.69
 -------------------------------------------------
 Account Number: 1234
 Name: Lisa Adams
 Original Deposit: $1000.00
 Annual Interest rate: 7.20
 Number of years of deposit: 10.00
 Number of times compounded per year: 1
 Total accumulation: $2004.23
 Interest accrued: $1004.23
 -------------------------------------------------
 Account Number: 1111
 Name: Adam Adamson
 Original Deposit: $500.00
 Annual Interest rate: 8.90
 Number of years of deposit: 20.00
 Number of times compounded per year: 6
 Total accumulation: $2926.42
 Interest accrued: $2426.42
 -------------------------------------------------
 Account Number: 2222
 Name: Bertha Jones
 Original Deposit: $5000.00
 Annual Interest rate: 10.00
 Number of years of deposit: 5.00
 Number of times compounded per year: 9
 Total accumulation: $8220.91
 Interest accrued: $3220.91
 -------------------------------------------------
 ********* Main Menu ***********
 1. Add a new Certificate of deposit account to the CertDeposit Vector:
 2. Print all certificate of deposit accounts to console:
 3. Print all certificate of deposit accounts to an output file
 [User would be asked for the output file full path]:
 4. Sort CertDeposit Vector based on account number in asccending order:
 5. Exit
 4
 ********* Main Menu ***********
 1. Add a new Certificate of deposit account to the CertDeposit Vector:
 2. Print all certificate of deposit accounts to console:
 3. Print all certificate of deposit accounts to an output file
 [User would be asked for the output file full path]:
 4. Sort CertDeposit Vector based on account number in asccending order:
 5. Exit
 2
 Account Number: 1111
 Name: Adam Adamson
 Original Deposit: $500.00
 Annual Interest rate: 8.90
 Number of years of deposit: 20.00
 Number of times compounded per year: 6
 Total accumulation: $2926.42
 Interest accrued: $2426.42
 -------------------------------------------------
 Account Number: 1234
 Name: Lisa Adams
 Original Deposit: $1000.00
 Annual Interest rate: 7.20
 Number of years of deposit: 10.00
 Number of times compounded per year: 1
 Total accumulation: $2004.23
 Interest accrued: $1004.23
 -------------------------------------------------
 Account Number: 2222
 Name: Bertha Jones
 Original Deposit: $5000.00
 Annual Interest rate: 10.00
 Number of years of deposit: 5.00
 Number of times compounded per year: 9
 Total accumulation: $8220.91
 Interest accrued: $3220.91
 -------------------------------------------------
 Account Number: 9999
 Name: Jim Wim
 Original Deposit: $2000.00
 Annual Interest rate: 5.60
 Number of years of deposit: 15.00
 Number of times compounded per year: 12
 Total accumulation: $4623.69
 Interest accrued: $2623.69
 -------------------------------------------------
 ********* Main Menu ***********
 1. Add a new Certificate of deposit account to the CertDeposit Vector:
 2. Print all certificate of deposit accounts to console:
 3. Print all certificate of deposit accounts to an output file
 [User would be asked for the output file full path]:
 4. Sort CertDeposit Vector based on account number in asccending order:
 5. Exit
 3
 Enter full path to output file: /Users/satishsinghal/Documents/CoursesTaught/_BasicCPP/_SMC_CS52_Spring2019/Labs/CertificateOfDepositClassProject/OutCDVector.txt
 ********* Main Menu ***********
 1. Add a new Certificate of deposit account to the CertDeposit Vector:
 2. Print all certificate of deposit accounts to console:
 3. Print all certificate of deposit accounts to an output file
 [User would be asked for the output file full path]:
 4. Sort CertDeposit Vector based on account number in asccending order:
 5. Exit
 1
 Enter account holder's first name:
 Miss
 Enter account holder's last name:
 Genius
 Enter account number [whole number only]:
 7777
 Enter amount of original deposit:
 10000.0
 Enter annual interest rate. For example for 7.2% enter 0.072:
 .087
 Enter number of years for certificate of deposit:
 15
 Enter number of times interest is compounded per year
 [whole number only]: 12
 ********* Main Menu ***********
 1. Add a new Certificate of deposit account to the CertDeposit Vector:
 2. Print all certificate of deposit accounts to console:
 3. Print all certificate of deposit accounts to an output file
 [User would be asked for the output file full path]:
 4. Sort CertDeposit Vector based on account number in asccending order:
 5. Exit
 2
 Account Number: 1111
 Name: Adam Adamson
 Original Deposit: $500.00
 Annual Interest rate: 8.90
 Number of years of deposit: 20.00
 Number of times compounded per year: 6
 Total accumulation: $2926.42
 Interest accrued: $2426.42
 -------------------------------------------------
 Account Number: 1234
 Name: Lisa Adams
 Original Deposit: $1000.00
 Annual Interest rate: 7.20
 Number of years of deposit: 10.00
 Number of times compounded per year: 1
 Total accumulation: $2004.23
 Interest accrued: $1004.23
 -------------------------------------------------
 Account Number: 2222
 Name: Bertha Jones
 Original Deposit: $5000.00
 Annual Interest rate: 10.00
 Number of years of deposit: 5.00
 Number of times compounded per year: 9
 Total accumulation: $8220.91
 Interest accrued: $3220.91
 -------------------------------------------------
 Account Number: 9999
 Name: Jim Wim
 Original Deposit: $2000.00
 Annual Interest rate: 5.60
 Number of years of deposit: 15.00
 Number of times compounded per year: 12
 Total accumulation: $4623.69
 Interest accrued: $2623.69
 -------------------------------------------------
 Account Number: 7777
 Name: Miss Genius
 Original Deposit: $10000.00
 Annual Interest rate: 8.70
 Number of years of deposit: 15.00
 Number of times compounded per year: 12
 Total accumulation: $36703.69
 Interest accrued: $26703.69
 -------------------------------------------------
 ********* Main Menu ***********
 1. Add a new Certificate of deposit account to the CertDeposit Vector:
 2. Print all certificate of deposit accounts to console:
 3. Print all certificate of deposit accounts to an output file
 [User would be asked for the output file full path]:
 4. Sort CertDeposit Vector based on account number in asccending order:
 5. Exit
 5
 
 */


