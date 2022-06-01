#pragma once
#include <iostream>
#include <string>
#include"Edge.h"

template <class T>
class Node : public T
{
private:

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

