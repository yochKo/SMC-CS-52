#pragma once
#ifndef INTLINKEDLIST_H
#define INTLINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;

struct IntLinkedList
{
	//Head node
	Node * Head;
	//Constructor
	IntLinkedList();
	//Rule of three
	//A. Copy function
	void copy(const IntLinkedList & Other);
	//1. Copy constructor
	IntLinkedList(const IntLinkedList & Other);
	//B. destroy function
	void destroy();
	//2. Assignment operator
	IntLinkedList& operator =(const IntLinkedList & Other);
	//3. Destructor
	virtual ~IntLinkedList();
	//toString function
	const string toString() const;
	//Insert function
	void insert(int val);
};
#endif