#pragma once
#include <iostream>
#include <string>

class Node
{
private:

	Node* previous;
	Node* next;

public:

	//Konstruktory
	Node();
	Node(Node* _previous, Node* _next);
	Node(const Node& newNode); 	//Konstruktor kopiuj¹cy

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	Node* GetNext() const;
	Node* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetNext(Node* newNode);
	void SetPrevious(Node* newNode);


}; //CLASS

