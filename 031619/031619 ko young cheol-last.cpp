#include <iostream>
#include <string>
using namespace std;

const double SStax = 0.071;
const int Healthfee = 200;
const int overWork = 40;
const double overWorkrate = 1.5;

void greeting();
double getUserData(double & payRate, string & firstName, string & lastName, bool & healthPlan);
double getGrossSalary(double hoursWorked, double payRate);
double getTaxWitheld(double GrossSalary);
double getNetSalary(double grossSalary, double taxWitheld, bool HealthPlan, string & HealthPlanStatusMessage);
void printResults(const string & firstName, const string & lastName, double hoursWorked, double payRate, double grossSalary, double taxWitheld, double netSalary, const string & HealthPlanStatus);
void goodbye();


int main() {
	int see;
	
	double payRate;
	string firstName;
	string lastName;
	bool healthPlan;
	double hoursWorked;
	double GrossSalary;
	double TaxWitheld;
	double NetSalary;
	string HealthPlanStatusMessage;

	cout.setf(ios::fixed);
	cout.precision(2);

	greeting();
	hoursWorked = getUserData(payRate, firstName, lastName, healthPlan);
	GrossSalary = getGrossSalary(hoursWorked, payRate);
	TaxWitheld = getTaxWitheld(GrossSalary);
	NetSalary = getNetSalary(GrossSalary, TaxWitheld, healthPlan, HealthPlanStatusMessage);
	printResults(firstName, lastName, hoursWorked, payRate, GrossSalary, TaxWitheld, NetSalary, HealthPlanStatusMessage);
	goodbye();

	cin >> see;
	return 0;
}

void greeting() {
	cout << "---------------------------------------------------------------------------------------------\n";
	cout << "Welcome to salary calculation program.\n";
	cout << "In this program we will ask for the information that would allow us to process your pay check.\n";
	cout << "We will collect information about hours worked, hourly pay rate and medical options.\n";
	cout << "Processing will be completed in just few minutes.\n";
	cout << "---------------------------------------------------------------------------------------------\n";
}

double getUserData(double & payRate, string & firstName, string & lastName, bool & healthPlan) {
	int hours;

	cout << "Please enter your first name [One word only]:";
	cin >> firstName;
	cout << "Please enter your last name [One word only]:";
	cin >> lastName;
	cout << "Please enter hours worked (positive number only) :";
	cin >> hours;
	cout << "Please enter your hourly pay rate.\n";
	cout << "[For example enter 15.23 if your hourly pay rate is $15 and 23 cents]:";
	cin >> payRate;
	cout << "Enter 1 to purchase health plan or 0 (zero) to decline:";
	cin >> healthPlan;
	return hours;
}

double getGrossSalary(double hoursWorked, double payRate) {
	double grossSalary;

	if (hoursWorked >40){
		grossSalary = ((hoursWorked - overWork) * payRate *overWorkrate) + (overWork*payRate);
	}
	else {
		grossSalary = (hoursWorked * payRate);
	}
	return grossSalary;
}

double getTaxWitheld(double GrossSalary) {
	double taxwitheld;
	taxwitheld = GrossSalary * SStax;
	return taxwitheld;
}

double getNetSalary(double grossSalary, double taxWitheld, bool HealthPlan, string & HealthPlanStatusMessage) {
	double NetSalary;
	NetSalary = grossSalary - taxWitheld;
	if (HealthPlan == 1) {
		if ((NetSalary - Healthfee) < 0) {
			HealthPlanStatusMessage = "Employee opted for health insurance but was declined because of insufficient salary.\n";
		}
		else {
			NetSalary = NetSalary - Healthfee;
			HealthPlanStatusMessage = "Employee opted for health insurance and was successfully registered.\n";
		}
	}
	else if (HealthPlan == 0) {
		HealthPlanStatusMessage = "Employee did not opt to register in health plan.\n";
	}
	return NetSalary;

}

void printResults(const string & firstName, const string & lastName, double hoursWorked, double payRate, double grossSalary, double taxWitheld, double netSalary, const string & HealthPlanStatus) {
	cout << "------------------------------------------------------------------------ -\n";
	cout << "Here are the Employee Payroll details.\n";
	cout << "Name: " << firstName << " " << lastName <<"\n";
	cout << "Hours worked : " << hoursWorked <<" hours\n";
	cout << "Hourly Pay Rate : $" << payRate << "\n";
	cout << "Gross Salary : $"<< grossSalary << "\n";
	cout << "Tax withheld : $"<< taxWitheld << "\n";
	cout << HealthPlanStatus;
	cout << "Employee net salary : $" << netSalary << "\n";
}

void goodbye() {
	cout << "----------------------------------------------------------------------------------\n";
	cout << "Thank you for using our program.\n";
	cout << "Please have a pleasant day.\n";
}