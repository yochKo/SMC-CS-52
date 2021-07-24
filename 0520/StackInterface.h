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
#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H

using namespace std;

template <typename T>
class StackInterface {
public:
	StackInterface() {};
	virtual ~StackInterface() {};
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual void push(T&data) = 0;
	virtual void pop() = 0;
	virtual T top() const = 0;
};
#endif