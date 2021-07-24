
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main()
{
	string first;
	string last;
	int score = 0;
	int sum = 0;
	int count = 0;
	double avg = 0;
	double temp = 0;
	char grade;

	stringstream ss;
	string str;
	string print;


	cout.setf(ios::fixed);
	cout.precision(1);

	cout << "This program will process test scores to provide individuals\nwith letter grades according to the following scale : \n";
	cout << "\n90 < average       : A\n80 < average <= 90 : B\n68 < average <= 80 : C\n55 < average <= 68 : D\n0 <= average <= 55 : F\n";

	while (cin) {
		sum = avg = count = 0;
		cout << "Enter first name : ";
		cin >> first;
		cout << "Enter last name : ";
		cin >> last;
		cout << "Please enter your test scores, end of score entry must be indicated by a negative integer.\n";
		cout << "For example, if you took three tests and you scored 90, 91, 89 respectively, then you will enter : 90 91 89 - 5\n";
		cin >> score;
		while (score >= 0) {
			sum += score;
			ss << score;
			str = ss.str();
			print = print + str + " ";
			count++;
			cin >> score;
		}
		cout << "Your name is         " << first << " " << last << "\n";
		cout << "your score is" <<print;
		if (count == 0) {
			cout << first << " " << last << ", you did not take any test.\n";
		}
		else {
			avg = (double)sum / count;
			temp = avg;
			round(avg);
			if (avg < 55) {
				grade = 'F';
			}
			else if (avg <= 68) {
				grade = 'D';
			}
			else if (avg <= 80) {
				grade = 'C';
			}
			else if (avg <= 90) {
				grade = 'B';
			}
			else if (avg <= 100) {
				grade = 'A';
			}

			cout << first << " " << last << ", your average is :" << temp << " and your letter grade is " << grade << "\n";
		}
	}
	return 0;
}
