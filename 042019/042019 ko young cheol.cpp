/*
Name: young cheol ko
Class: CS52
Lab #: 7
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Last successful Compilation: 4/24 20:24
Date and Time of when program verified all test results: 4/24 19:43
*/

#include "letterFrequencyNode.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

LetterFrequencyList::LetterFrequencyList() : HeadPtr(new LetterNode('a', 'a', nullptr)) {
}

void LetterFrequencyList::copy(const LetterFrequencyList & other) {
	LetterNode *Current = other.HeadPtr->Next;
	LetterNode *ltr = HeadPtr = new LetterNode(0, 'a', nullptr);
	while (Current != nullptr) {
		ltr->Next = new LetterNode(Current->letter, Current->frequency, nullptr);
		Current = Current->Next;
		ltr = ltr->Next;
	}
}

LetterFrequencyList::LetterFrequencyList(const LetterFrequencyList & other) {
	if (this == &other) {
		cout << "self copying not allowed. Exiting program.\n";
		exit(0);
	}
	copy(other);
}

void LetterFrequencyList::destroy() {
	LetterNode * Current = HeadPtr;
	while (Current != nullptr) {
		LetterNode * save = Current;
		Current = Current->Next;
		delete save;
	}
}

LetterFrequencyList & LetterFrequencyList::operator=(const LetterFrequencyList&other) {
	if (this != &other) {
		destroy();
		copy(other);
	}
	return *this;
}

LetterFrequencyList::~LetterFrequencyList() {
	destroy();
}

const string LetterFrequencyList::toString() const {
	if (!(HeadPtr == nullptr))
	{
		string text = "";
		LetterNode * iterator = HeadPtr->Next;
		while (iterator != nullptr)
		{
			text += (iterator->toString());
			text += '\n';
			iterator = iterator->Next;
		}
		return text;
	}
	else
	{
		throw "Exception thrown";
	}
}

void LetterFrequencyList::insert(char ltr, size_t frq) {

	HeadPtr->Next = new LetterNode(ltr, frq, HeadPtr->Next);
}

void LetterFrequencyList::insertInOrder(char ltr) { 
	if(contains(ltr)==true){
		LetterNode * find = HeadPtr->Next;
		while (find != nullptr) {
			if (ltr == find->letter) {
				find->frequency = find->frequency + 1;
			}
			find = find->Next;
		}
    }
	else {
		if (HeadPtr->Next == nullptr) {
			HeadPtr->Next = new LetterNode(ltr, 1, HeadPtr->Next);
		}
		else if (to_string(ltr) < to_string(HeadPtr->Next->letter)) {
			HeadPtr->Next = new LetterNode(ltr, 1, HeadPtr->Next);
		}
		else {
			LetterNode *tail = HeadPtr;
			while (tail->Next != nullptr)
			{
				tail = tail->Next;
			}
			if (to_string(ltr) > to_string(tail->letter))
				tail->Next = new LetterNode(ltr, 1, nullptr);
			else {
				LetterNode * temp = HeadPtr;
				while(temp->Next){
					if (ltr > temp->letter&&ltr <= temp->Next->letter) {
						break;
					}
					temp = temp->Next;
				}
				LetterNode * middle = new LetterNode;
				middle->letter = ltr;
				middle->frequency = 1;
				middle->Next = temp->Next;
				temp->Next = middle;
			}
		}
	}
}
/*
		LetterNode *p;
		p = new LetterNode;
		p->letter = ltr;
		p->frequency = 1;
		p->Next = HeadPtr;
		HeadPtr = p;

		LetterNode *temp = HeadPtr;
		while (temp != nullptr)
		{
			temp = temp->Next;
		}
		temp->Next = new LetterNode(ltr, 1, nullptr);

		LetterNode *save;
		save = new LetterNode;
		save->letter = ltr;
		save->frequency = 1;
		temp->Next = save;
		save->Next = nullptr;
*/
/*

LetterNode * save = temp->Next;

if (ltr < temp->letter) {
	HeadPtr->Next = new LetterNode(ltr, 1, HeadPtr->Next);
}
else {
	LetterNode * find = HeadPtr->Next;
	while (find != nullptr) {
		if (ltr == find->letter) {
			find->frequency += 1;
		}
		find = find->Next;
	}
}
*/
bool LetterFrequencyList::contains(char ltr) {
	bool con = false;
	LetterNode * find = HeadPtr->Next;
	while (find != nullptr) {
		if (ltr == find->letter) {
			con = true;
		}
		find = find->Next;
	}
	return con;
}

int main() {

	string inFilename;
	cout << "Enter full path to input file: ";
	getline(cin, inFilename);
	//C:\Users\aqr17\Desktop\042019\042019\TesFrequencyOfAllCharacters.txt
	ifstream in;
	in.open(inFilename, ios::app);

	LetterFrequencyList list;
	char read;
	string k;
	while (in>>read) {
		if ((read >= 'a'&&read <= 'z') || (read >= 'A'&&read <= 'Z')) {
			if (read >= 'a' && read <= 'z') {
				read = read - 'a' + 'A';
			}
			list.insertInOrder(read);
		}	
	}
	cout << list.toString();
	in.close();

	string outFilename;
	ofstream out;
	cout << "Enter full path to output file: ";
	getline(cin, outFilename);
	//C:\Users\aqr17\Desktop\output.txt
	out.open(outFilename, ios::app);
	if (out.is_open()) {
		out << list.toString();
		cout << "Done!" << endl;
	}
	else {
		cout << "could not open output file." << endl;
	}

	out.close();



	system("pause");
	return 0;
}
