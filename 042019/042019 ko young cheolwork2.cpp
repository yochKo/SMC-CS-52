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
		cout << "asdf" << endl;
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
	if (HeadPtr->Next == nullptr) {
		HeadPtr->Next = new LetterNode(ltr, 1, HeadPtr->Next);
		LetterNode *p;
		p = new LetterNode;
		p->letter = ltr;
		p->frequency = 1;
		p->Next = HeadPtr;
		HeadPtr = p;
	}
	else if (HeadPtr->Next == nullptr){
		LetterNode *temp;
		while (temp!=nullptr)
		{
			temp = temp->Next;
		}
		if (ltr > temp->letter) {
			temp->Next = new LetterNode(ltr, 1, temp->Next);
		}
		else {
			HeadPtr->Next = new LetterNode(ltr, 1, temp);
		}
	}
	else {
		LetterNode * find = HeadPtr->Next;
		LetterNode * save = HeadPtr;
		while (find!=nullptr)
		{
			if(ltr>find->letter){
				find = find->Next;
				save = save->Next;
			}
			else{
				break;
			}
		}
		if (find==nullptr) {
			save = new LetterNode(ltr, 1, find);
		}
		else {
			if (ltr==find->letter) {
				find->frequency = find->frequency + 1;
			}
			else {

			}
		}
	}
}
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

void printLinkedList(LetterFrequencyList IL);

int main() {

	string filename;
	cout << "reading file" << endl;
	//getline(cin, filename);
	ifstream input("TesFrequencyOfAllCharacters.txt");
	LetterFrequencyList list;
	char read;
	string k;
	while (input>>read) {
		if ((read >= 'a'&&read <= 'z') || (read >= 'A'&&read <= 'Z')) {
			if (read >= 'a' && read <= 'z') {
				read = read - 'a' + 'A';
			}
		}	
	}
	list.insertInOrder('A');
	list.insertInOrder('B');
	
	cout << endl;

	cout << list.toString() << endl;
	input.close();
/*
	string outFilename = "output.txt";
	ofstream out;
	out.open(outFilename, ios::app);

	if (!out.is_open()) {
		cout << "could not open output file." << endl;
	}
	else {
		LetterFrequencyList list;
		list.toString();
	}
	out.close();
*/
	system("pause");
	return 0;
}

void printLinkedList(LetterFrequencyList IL)
{
	cout << IL.toString() << endl;
}