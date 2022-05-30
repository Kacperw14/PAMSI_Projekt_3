#pragma once
#include"Node.h"

class Edge :Node
{
private:
	int value;

public:
	Edge(const int& _value) : value(_value) {};
	const int& GetValue() const{ return value; };
}; //class