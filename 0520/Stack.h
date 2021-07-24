/*
Name: young cheol ko
Class: CS52
Lab# : 10
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Start Date: 5/20 9:23
Date and Time of Copletion Date : 5/24 23:39
*/

#pragma once
#ifndef STACK_H
#define STACK_H
#include "StackInterface.h"

#include <iostream>
template <typename T>
class Stack : public StackInterface<T> {
private:
	T * items;
	const static int max = 10;
	const static int GROWBY = 5;
	size_t arrayCapacity;
	size_t numItems;
	int top_position;
public:
	Stack();
	~Stack();
	virtual void push(T&data);
	virtual T top() const;
	virtual void pop();
	virtual bool isEmpty() const;
	virtual bool isFull() const;
	size_t getArrayCapacity();
	size_t getNumItems();
	Stack <T> operator=(const Stack<T>&Other);
	Stack(const Stack<T>& other);
};
#endif
class excpt {
private:
	string Message;
public:
	excpt(const string & msg = "Message not set"):Message(msg){

	}
	const string getMessage() {
		return Message;
	}
};

template <typename T>
Stack<T>::Stack()
{
	arrayCapacity = max;
	items = new T[max];
	numItems = 0;
	top_position = -1;
}

template <typename T>
Stack<T>::~Stack() {
	delete[] items;
}

template <typename T>
void Stack<T>::push(T&data) {
	cout << "inserting " << data << endl;

	if (numItems < arrayCapacity) {
		top_position++;
		items[top_position] = data;
		numItems++;
	}
	else {
		T * temp;
		size_t temp_top = 0;
		temp = new T[arrayCapacity + GROWBY];
		bool done;
		while (temp_top < numItems) {
			temp[temp_top] = items[temp_top];
			temp_top++;
		}
		items = temp;

		top_position++;
		items[top_position] = data;
		arrayCapacity = arrayCapacity + GROWBY;
	}
}
template <typename T>
void Stack<T>::pop() {
	if (isEmpty()) {
		cout << "The stack is empty. Returned value not reliable.\n";
	}
	else {
		cout << "removing " << top() << endl;
		top_position--;
	}
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	if (numItems == 0) {
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
bool Stack<T>::isFull() const
{
	if (numItems == max) {
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
Stack <T> Stack<T>:: operator=(const Stack<T>&Other) {
	if (&Other == this) {
		return *this;
	}
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other) {
	numItems = other.numItems;
	top_position = other.top_position;
	arrayCapacity = other.arrayCapacity;
	items = new T[arrayCapacity];
}

template <typename T>
T Stack<T>::top() const
{
	if (isEmpty() == true) {
		string msg = "The stack is empty";
		throw excpt(msg);
	}
	else {
		return items[top_position];
	}
}

template <typename T>
size_t Stack<T>::getArrayCapacity() {
	return arrayCapacity;
}

template <typename T>
size_t Stack<T>::getNumItems() {
	return numItems;
}