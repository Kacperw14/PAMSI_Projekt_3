#pragma once
#include <iostream>
#include <string>

template <typename T>
class Node : T
{
protected:

	Node<T>* previous;
	Node<T>* next;

public:

	//Konstruktory
	Node();
	Node(Node<T>* _previous, Node<T>* _next);
	Node(const Node<T>& newNode); 	//Konstruktor kopiuj¹cy

	//Funkcje umozliwiajace dostep do atrybutow.
	Node<T>* GetNext() const;
	Node<T>* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetNext(Node<T>* newNode);
	void SetPrevious(Node<T>* newNode);


}; //CLASS

