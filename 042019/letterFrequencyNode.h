/*
Name: young cheol ko
Class: CS52
Lab #: 7
Compiler Used: visual studio 2017 community
Operating System Used: windows 10
Date and Time of Last successful Compilation: 4/24 20:24
Date and Time of when program verified all test results: 4/24 19:43
*/

#pragma once
#ifndef letterFrequencyNODE_H
#define letterFrequencyNODE_H
#include "letterNode.h"
#include <iostream>

using namespace std;

struct LetterFrequencyList {

	LetterNode *HeadPtr;
	LetterFrequencyList();
	void copy(const LetterFrequencyList & other);
	LetterFrequencyList(const LetterFrequencyList & other);
	void destroy();
	LetterFrequencyList & operator=(const LetterFrequencyList&other);
	virtual~LetterFrequencyList();
	const string toString() const;
	void insert(char ltr, size_t frq);
	void insertInOrder(char ltr);
	bool contains(char ltr);
};
#endif letterFrequencyNODE_H