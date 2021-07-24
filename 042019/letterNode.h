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
#ifndef letterNODE_H
#define letterNODE_H
#include <string>
using namespace std;
struct LetterNode {
	size_t frequency;
	char letter;
	LetterNode * Next;
	LetterNode(char ch = 0 , size_t frq = 'c', LetterNode * ptr = nullptr) :letter(ch), frequency(frq), Next(ptr)
	{

	}
	const string toString()
	{
		string k ;
		k.push_back(letter);
		string q = "Letter " + k + " occured: " + to_string(this->frequency) + " times";
		return q;
	}
};
#endif letterNODE_H