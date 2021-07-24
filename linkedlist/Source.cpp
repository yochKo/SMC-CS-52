#include "IntLinkedList.h"

IntLinkedList::IntLinkedList() : Head(new Node('A', nullptr))
{
	cout << "From constructor." << endl;
}
void IntLinkedList::copy(const IntLinkedList & Other)
{
	Node *Current = Other.Head->Next;
	Node *Iterator = Head = new Node('A', nullptr); // create dummy node
	while (Current != nullptr) {
		// create a copy of node pointed to by Current, and link up
		Iterator->Next = new Node(Current->data, nullptr); // ??

		// update pointers
		Current = Current->Next;
		Iterator = Iterator->Next;
	}
}
//------------------------------------------------------------------
IntLinkedList::IntLinkedList(const IntLinkedList & Other)
{
	cout << "From Copy constructor.\n";
	if (this == &Other)
	{
		cout << "Self copying not allowed. Exiting program.\n";
		exit(0);
	}
	copy(Other);
}
//-----------------------------------------------------------------
void IntLinkedList::destroy()
{
	Node * Current = Head; // start with dummy node
	while (Current != nullptr) {
		// do something
		Node *save = Current;
		Current = Current->Next;
		delete save;
	}
}
//------------------------------------------------------------------
IntLinkedList& IntLinkedList::operator = (const IntLinkedList & Other)
{
	cout << "From assignment operator.\n";
	if (this != &Other)
	{
		destroy();
		copy(Other);
	}

	return *this;
}
//-----------------------------------------------------------------
IntLinkedList::~IntLinkedList()
{
	cout << "From destructor.\n";
	destroy();
}
//---------------------------------------------------------------------
const string IntLinkedList::toString() const
{
	if (!(Head == nullptr))
	{
		string text = "";

		Node * Iterator = Head->Next;
		//Traverse the linked list using Iterator and add all data to text

		while (Iterator != nullptr)
		{
			text += (Iterator->toString());
			Iterator = Iterator->Next;
		}
		return (text + '\n');
	}
	else {
		throw "Exception thrown";
	}
}
//---------------------------------------------------------------
void IntLinkedList::insert(int val)
{
	Head->Next = new Node(val, Head->Next);
}
//-----------------------------------------------------------

/*
Author: Satish Singhal Ph. D.
Date: 11/3/2014
Operating System: Windows 7
Compiler: Visual Studio 2013
Date and Time of last successful run: 11/3/2014 at 10:30 AM
*/
#include "IntLinkedList.h"

IntLinkedList buildLinkedList();
//In real software must be passed by reference
//Passing by value to confirm that copy constructor works - Use pass by value of large objects only in educational setting
void printLinkedList(IntLinkedList IL);
int main1()
{
	IntLinkedList IL;
	cout << IL.Head->data << endl;
	IL.insert(5);
	IL.insert(10);
	IL.insert(6);
	cout << IL.toString() << endl;
	return 0;
}
int main()
{
	{
		IntLinkedList IL = buildLinkedList();
		printLinkedList(IL);
		//Make a copy
		IntLinkedList ILCopy = IL; // Confirms use of assignment operator
		//print copy
		cout << "Printing the copy of linked list printed earlier.\n";
		printLinkedList(ILCopy);
	}
	system("pause");
	return 0;
}

IntLinkedList buildLinkedList()
{
	bool done = false;
	IntLinkedList IL;

	while (!done)
	{
		int temp;
		cout << "Enter the integer (whole number only) to add to linked list: ";
		cin >> temp;
		IL.insert(temp);
		cout << "More data? Enter 0 to continue or 1 to stop: ";
		cin >> done;
	}

	return IL;
}
void printLinkedList(IntLinkedList IL)
{
	cout << IL.toString() << endl;
}
//------------------------------------------
/*
From constructor.
Enter the integer (whole number only) to add to linked list: 1
More data? Enter 0 to continue or 1 to stop: 0
Enter the integer (whole number only) to add to linked list: 2
More data? Enter 0 to continue or 1 to stop: 0
Enter the integer (whole number only) to add to linked list: 3
More data? Enter 0 to continue or 1 to stop: 0
Enter the integer (whole number only) to add to linked list: 4
More data? Enter 0 to continue or 1 to stop: 0
Enter the integer (whole number only) to add to linked list: 5
More data? Enter 0 to continue or 1 to stop: 0
Enter the integer (whole number only) to add to linked list: 6
More data? Enter 0 to continue or 1 to stop: 1
From Copy constructor.
From destructor.
From Copy constructor.
6 5 4 3 2 1

From destructor.
From Copy constructor.
Printing the copy of linked list printed earlier.
From Copy constructor.
6 5 4 3 2 1

From destructor.
From destructor.
From destructor.
*/