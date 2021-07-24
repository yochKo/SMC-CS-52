/*
Name: young cheol ko
Class: CS52
Final Test
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Start Date: 5/31 10:13
Date and Time of Copletion Date : 6/01 14:47
*/

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cctype>

using namespace std;

struct PolyNode {
	int coefficient;
	int power;
	PolyNode * Next;
	PolyNode(int c = 1, int pwr = 0, PolyNode * ptr = nullptr) : coefficient(c), power(pwr), Next(ptr)
	{ }
	const string toString() const {
		string Rtrn;
		if (power > 0) {
			Rtrn = to_string(this->coefficient) + "x^" + to_string(this->power);
		}
		else {

			Rtrn = to_string(this->coefficient);
		}
		return Rtrn;
	}
};

struct PolyLinkedList {
	PolyNode * HeadPtr;
	PolyLinkedList() :HeadPtr(new PolyNode('A', 'B', nullptr))
	{ }

	void copy(const PolyLinkedList & PLL)
	{
		PolyNode * crnt = PLL.HeadPtr->Next;
		PolyNode * Itr = HeadPtr = new PolyNode(1, 0, nullptr);
		while (crnt != nullptr) {
			Itr->Next = new PolyNode(crnt->coefficient, crnt->power, nullptr);
			crnt = crnt->Next;
			Itr = Itr->Next;
		}
	}

	void destroy()
	{
		PolyNode * Current = HeadPtr;
		while (Current != nullptr) {
			PolyNode * save = Current;
			Current = Current->Next;
			delete save;
		}
	}

	PolyLinkedList(const PolyLinkedList & OtherPoly)
	{
		if (this == &OtherPoly) {
			cout << "self copying not allowed. Exiting program.\n";
		}
		else {
			copy(OtherPoly);
		}
	}

	const PolyLinkedList & operator = (const PolyLinkedList & OtherPoly)
	{
		if (this != &OtherPoly) {
			destroy();
			copy(OtherPoly);
		}
		return *this;
	}

	virtual ~PolyLinkedList()
	{
		destroy();
	}

	bool contains(int pwr) {
		bool con = false;
		PolyNode * find = HeadPtr->Next;
		while (find != nullptr) {
			if (pwr == find->power) {
				con = true;
			}
			find = find->Next;
		}
		return con;
	}

	void insertInOrder(int c, int pwr)
	{
		if (contains(pwr) == true) {
			cout << "Exception : power " + to_string(pwr) +" node already exists, this node will be not added.\n";
		}
		else {
			if (HeadPtr->Next == nullptr) {
				insertFront(c, pwr);
			}
			else if (pwr > HeadPtr->Next->power) {
				insertFront(c, pwr);
			}
			else {
				PolyNode *tail = HeadPtr;
				while (tail->Next != nullptr)
				{
					tail = tail->Next;
				}
				if (pwr < tail->power) {
					insertTail(c, pwr);
				}
				else{
					PolyNode * temp = HeadPtr;
					while (temp->Next) {
						if (pwr < temp->power && pwr > temp->Next->power) {
							break;
						}
						temp = temp->Next;
					}
					PolyNode * middle = new PolyNode(c, pwr, temp->Next);
					temp->Next = middle;
				}
			}
		}
	}

	void insertFront(int c, int pwr)
	{
		if (HeadPtr->Next == nullptr) {
			HeadPtr->Next = new PolyNode(c, pwr, HeadPtr->Next);
		}
		else if (pwr > HeadPtr->Next->power) {
			HeadPtr->Next = new PolyNode(c, pwr, HeadPtr->Next);
		}
		else {
			cout << "Exception : you can not add " + to_string(c) + "x^" + to_string(pwr) + " front.\n";
		}
	}
	
	void insertTail(int c, int pwr)
	{
		PolyNode *tail = HeadPtr;
		while (tail->Next != nullptr)
		{
			tail = tail->Next;
		}
		if (pwr < tail->power) {
			tail->Next = new PolyNode(c, pwr, nullptr);
		}
		else {
			cout << "Exception : you can not add " + to_string(c) +"x^" + to_string(pwr) +" to the tail.\n";
		}
	}

	size_t getSize() const
	{
		size_t count = 0;
		PolyNode * size = HeadPtr;
		while (size->Next != nullptr) {
			size = size->Next;
			count++;
		}
		return count;
	}

	int getValue(int arg)
	{
		PolyNode * value = HeadPtr;
		int val = 0;
		while (value->Next != nullptr) {
			val += (value->Next->coefficient) * pow(arg, value->Next->power);
			value = value->Next;
		}
		return val;
	}
	
	friend bool operator == (const PolyLinkedList & left, const PolyLinkedList & right)
	{
		bool answer = true;
		PolyNode * Lptr = left.HeadPtr;
		PolyNode * Rptr = right.HeadPtr;
		while (Lptr->Next != nullptr || Rptr->Next != nullptr) {
			if (Lptr->Next->coefficient != Rptr->Next->coefficient) {
				answer = false;
				break;
			}
			if (Lptr->Next->power != Rptr->Next->power) {
				answer = false;
				break;
			}

			Lptr = Lptr->Next;
			Rptr = Rptr->Next;
		}
		return answer;
	}

	const string toString() const {
		if (!(HeadPtr == nullptr))
		{
			string text = "";
			PolyNode * iterator = HeadPtr->Next;
			while (iterator != nullptr)
			{
				if (iterator->coefficient != 0) {
					text += (iterator->toString());
					if (iterator->Next != nullptr) {
						text += " + ";
					}
				}
				iterator = iterator->Next;
			}

			text += "\n";
			return text;
		}
		else
		{
			throw "Exception thrown";
		}
	}
};


	
void Printmenu();

int main() {
	PolyLinkedList Test;
	Test.insertInOrder(1, 0);
	Test.insertInOrder(4, 3);
	Test.insertInOrder(2, 1);
	Test.insertInOrder(3, 2);
	//check the exception
	Test.insertInOrder(9, 3);
	Test.insertFront(3, 2);
	Test.insertTail(6, 2);

	PolyLinkedList copy;
	copy = PolyLinkedList(Test);

	cout << Test.toString();
	cout << copy.toString();

	if ((Test == copy) == true) {
		cout << "Cheking copy constructor is worked. Test and copy are identical!\n";
	}
	PolyLinkedList copy2;
	copy2 = Test;
	if ((Test == copy2) == true) {
		cout << "Cheking copy by an operator is worked. Test and copy2 are identical!\n";
	}

	cout << "Size of Test is "+ to_string(Test.getSize()) << endl;

	PolyLinkedList test1;
	test1.insertInOrder(-2 ,4);
	test1.insertInOrder(3, 3);
	test1.insertInOrder(-5, 2);
	test1.insertInOrder(2, 1);
	test1.insertInOrder(10 , 0);
	cout << test1.getValue(1) << endl;

	PolyLinkedList test2;
	test2.insertInOrder(-2, 4);
	test2.insertInOrder(3, 3);
	test2.insertInOrder(-5, 2);
	test2.insertInOrder(2, 1);
	test2.insertInOrder(10, 0);
	cout << test2.getValue(2) << endl;

	PolyLinkedList test3;
	test3.insertInOrder(-2, 4);
	test3.insertInOrder(-5, 2);
	test3.insertInOrder(2, 1);
	test3.insertInOrder(10, 0);
	cout << test3.getValue(2) << endl;

	PolyLinkedList test4;
	test4.insertInOrder(2, 5);
	test4.insertInOrder(-2, 4);
	test4.insertInOrder(-5, 2);
	test4.insertInOrder(2, 1);
	test4.insertInOrder(10, 0);
	cout << test4.getValue(2) << endl;

	PolyLinkedList test5;
	test5.insertInOrder(2, 5);
	test5.insertInOrder(-2, 4);
	test5.insertInOrder(-5, 2);
	test5.insertInOrder(2, 1);
	test5.insertInOrder(10, 0);
	cout << test5.getValue(3) << endl;

	
	vector<PolyLinkedList> PolyVec;
	bool run = true;
	int menu=0;
	size_t size=0;
	bool Create = false;
	while(run) {
		Printmenu();
		cin >> menu;
		int coe=0;
		int pwr=0;
		if (menu==1) {
			cout << "Enter the number of terms for polynomials:" << endl;
			cin >> size;
			PolyLinkedList newPoly;
			for (size_t i = 0; i < size; i++) {
				cout << "Enter the number of coefficient:" << endl;
				cin >> coe;
				cout << "Enter the number of power:" << endl;
				cin >> pwr;
				if (coe==0){
					cout << "You tried to add the terms with coefficient 0. It will be not added to the poly.\n";
				}
				else {
					newPoly.insertInOrder(coe, pwr);
				}
			}
			PolyVec.push_back(newPoly);
			Create = true;
		}
		if (Create == false)
		{
			cout << "Polynomianl is not created." << endl;
		}
		else {
			if (menu == 2) {
				for (int i = 0; i < PolyVec.size(); i++)
				{
					cout << to_string(i+1) +". "+ PolyVec[i].toString();
				}
			}
			if (menu == 3) {
				cout << "Enter full path to output file: ";
				cin.ignore(10000, '\n');
				string outFilename;
				getline(cin, outFilename);

				ofstream out;
				out.open(outFilename, ios::app);

				if (out.is_open()) {
					for (int i = 0; i < PolyVec.size(); i++)
					{
						out << PolyVec[i].toString();
					}
				}
				else {
					cout << "Could not open output file." << endl;
				}
				out.close();
			}
			if (menu == 4) {
				for (int i = 0; i < PolyVec.size(); i++)
				{
					for (int j = 1; j < 6; j++) {
						cout << "when X = " + to_string(j) + ", the value is " + to_string(PolyVec[i].getValue(j)) + "\n";
					}
				}
			}
			if (menu == 5) {
				cout << "You need to select two polynomials in the vector to compare them\nbelow is list of the polynomials\n";
				for (int i = 0; i < PolyVec.size(); i++)
				{
					cout << to_string(i + 1) + ". " + PolyVec[i].toString();
				}
				int left;
				int right;
				cout << "Enter the number of polynomianls in left : ";
				cin >> left;
				cout << "Enter the number of polynomianls in right : ";
				cin >> right;

				if ((PolyVec[left-1] == PolyVec[right-1]) == true) {
					cout << "The two polynomial are identical!\n";
				}
				else {
					cout << "The two polynomial are not identical.\n";
				}
			}
			if (menu == 6) {
				for (int i = 0; i < PolyVec.size(); i++)
				{
					cout << to_string(i + 1) + ". polynomial has " + to_string(PolyVec[i].getSize()) + "terms\n";
				}
			}
			if (menu == 7) {
				cout << "The list of the polynomials in the vector\n";
				for (int i = 0; i < PolyVec.size(); i++)
				{
					cout << to_string(i + 1) + ". " + PolyVec[i].toString();
				}
				cout << "Enter the number of the order of polynomial that you want to add the terms in the head.\n:";
				int in_head;
				cin >> in_head;
				cout << "Enter the number of coefficient:" << endl;
				cin >> coe;
				cout << "Enter the number of power:" << endl;
				cin >> pwr;
				PolyVec[in_head - 1].insertFront(coe,pwr);
			}
			if (menu == 8) {
				cout << "The list of the polynomials in the vector\n";
				for (int i = 0; i < PolyVec.size(); i++)
				{
					cout << to_string(i + 1) + ". " + PolyVec[i].toString();
				}
				cout << "Enter the number of the order of polynomial that you want to add the terms in the tail.\n:";
				int in_tail;
				cin >> in_tail;
				cout << "Enter the number of coefficient:" << endl;
				cin >> coe;
				cout << "Enter the number of power:" << endl;
				cin >> pwr;
				PolyVec[in_tail - 1].insertTail(coe, pwr);
			}	
		}
		if (menu == 9) {
			run = false;
		}
	}
	system("pause");
	return 0;
}

void Printmenu() {
	cout << "********* Main Menu ***********" << endl
		<< "1. Add Polynomials to PolyVec from keyboard data entry." << endl
		<< "2. Print all polynomials to the console." << endl
		<< "3. Print all polynomials to an output file." << endl
		<< "4. Print to console values of all polynomials when X = 1, X = 2, X = 5." << endl
		<< "5. Test == operator for those two polynomials in PolyVec, that are identical in content." << endl
		<< "6. Print to console, the number of terms(using getSize function) for all polynomials in PolyVec." << endl
		<< "7. Repeat the test you did for testing function insertFront" << endl
		<< "8. Repeat the test you did for testing function insertTail" << endl
		<< "9. Exit" << endl;
}