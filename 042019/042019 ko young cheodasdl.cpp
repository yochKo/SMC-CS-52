
#include "letterFrequencyNode.h"
/*
#include<iostream>
#include<string>
#include<fstream>
#include<cstddef>
*/

using namespace std;

/*
struct LetterNode {
	size_t frequency;
	char letter;
	LetterNode * Next;

	LetterNode(char ch, size_t frq, LetterNode* ptr) {
		letter = ch;
		frequency = frq;
		Next = ptr;
	}
	const string toString()
	{
		return (to_string(this->letter) + to_string(this->frequency));
	}
};*/
/**/
LetterFrequencyList::LetterFrequencyList():HeadPtr(new LetterNode('a', 0, nullptr)) {
	cout << "From constructor.\n";
}
struct LetterFrequencyList {
	LetterNode *HeadPtr;
	
	void copy(const LetterFrequencyList & other) {
		LetterNode*Current = other.HeadPtr->Next;
		LetterNode*ltr = HeadPtr = new LetterNode('a', 0, nullptr);
		while (Current != nullptr) {
			ltr->Next = new LetterNode(Current->letter, Current->frequency, nullptr);
			Current = Current->Next;
			ltr = ltr->Next;
		}
	}
	LetterFrequencyList(const LetterFrequencyList & other) {
		cout << "From copy constructor.\n";
		if (this == &other) {
			cout << "self copying not allowed. Exiting program.\n";
			exit(0);
		}
		copy(other);
	}
	LetterFrequencyList & operator=(const LetterFrequencyList&other) {
		cout << "From assignment operator.\n";
		if (this != &other) {
			destroy();
			copy(other);
		}
		return *this;
	}

	~LetterFrequencyList() {
		cout << "From destructor.\n";
		destroy();
	}

	void destroy() {
		LetterNode * Current = HeadPtr;
		while(Current != nullptr) {
			LetterNode * save = Current;
			Current = Current->Next;
			delete save;
		}
	}

	void insert(char ltr, size_t frq) {
		HeadPtr->Next = new LetterNode(ltr, frq, HeadPtr->Next);
	}
	void insertInOrder(char ltr) {

	}

	bool contains(char ltr) {

	}
	
	const string toString() const {
		if (!(HeadPtr == nullptr)) {
			string text = "";
			LetterNode * ltr = HeadPtr->Next;
			while (ltr != nullptr)
			{
				text += (ltr->toString());
			}
			return(text + '\n');
		}
		else {
			throw "Exception thrown";
		}
	}
};


int main() {
	string filename;
	cout << "reading file" << endl;
	getline(cin, filename);
	//C:\Users\aqr17\Desktop\042019\TesFrequencyOfAllCharacters.txt
	ifstream in;
	in.open(filename);
	if (!in.is_open()) {
		cout << "the path" << filename << " is invlaid" << endl;
	}
	else {
		LetterFrequencyList a;
		cout << a.toString();
	}
	in.close();

	system("pause");
	return 0;
}