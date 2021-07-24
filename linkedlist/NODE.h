#pragma once
#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;
struct Node
{
	int data;
	Node * Next;
	Node(int val = 'C', Node * ptr = nullptr) :data(val), Next(ptr)
	{

	}

	const string toString() const
	{
		return (to_string(this->data) + " ");
	}
};
#endif