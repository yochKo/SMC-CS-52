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
		LetterNode * save = HeadPtr->Next;
		string text;
		text += save->toString();
		return text;
		/*
		string text = "";
		LetterNode * iterator = HeadPtr->Next;
		while (iterator != nullptr)
		{
			text += (iterator->toString());
			text += '\n';
			iterator = iterator->Next;
		}
		return text;
		*/
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
	LetterNode * temp = HeadPtr -> Next;
	if (HeadPtr == nullptr)
	{
		HeadPtr = new LetterNode(ltr, 1, HeadPtr->Next);
	}
	else 
	{
		if (HeadPtr == nullptr) {
			HeadPtr->Next = new LetterNode(ltr, 1, HeadPtr->Next);
		}
		else {
			if(ltr < temp->letter) {

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
	}
	else {
		bool find = false;
		LetterNode * q = HeadPtr->Next;
		while (q != nullptr) {
			if (ltr == q->letter) {
				bool find = true;
				q->frequency += 1;
			}
			q = q->Next;
		}
		if (find == false) {
			LetterNode * temp = HeadPtr->Next;
			LetterNode * save;

			if (HeadPtr == nullptr) {
				HeadPtr->Next = new LetterNode(ltr, 1, HeadPtr->Next);
			}
			else {
				while (temp != nullptr)
				{
					if (ltr < temp->letter) {
						save = temp->Next;
						temp->Next = new LetterNode(ltr, 1, save->Next);
						break;
					}
					temp = temp->Next;
				}
			}
		}
	}
}

void printLinkedList(LetterFrequencyList IL);

int main() {

	string filename;
	cout << "reading file" << endl;
	//getline(cin, filename);
	//C:\Users\aqr17\Desktop\042019\TesFrequencyOfAllCharacters.txt
	ifstream input("TesFrequencyOfAllCharacters.txt");
	LetterFrequencyList list;
	char read;
	while (input>>read) {
		if ((read >= 'a'&&read <= 'z') || (read >= 'A'&&read <= 'Z')) {
		cout << read;
		}	
	}
	char k[10] = "abcdefghi";
	list.insert(k[0], 1);


	list.toString();
	input.close();
	/*
	in.open(filename);
	if (!in.is_open()) {
		cout << "the path" << filename << " is invlaid" << endl;
	}
	else {
		
		LetterFrequencyList list = LetterFrequencyList(); 
		char read;
		while (in.good()) {
			in >> read;
			if (isalpha(read) == 1) {
				cout << read;
			}
		}
	}
	in.close();
	*/
	/*
	LetterFrequencyList test = LetterFrequencyList();
	char arr[10] = "apwerdszr";
	for (int i = 0; i < 10; i++) {
		test.insertInOrder(arr[i]);
	}
	cout << test.toString() << endl;
*/
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