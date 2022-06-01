#pragma once
#include <iostream>
#include <string>
#include"Edge.h"

template <class T>
class Node : public T
{
private:

	T* previous;
	T* next;

public:

	//Konstruktory
	Node();
	Node(T* _previous, T* _next);
	Node(const Node<T>& newNode); 	//Konstruktor kopiuj¹cy

	//Funkcje umozliwiajace dostep do atrybutow.
	T* GetNext() const;
	T* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetNext(T* newNode);
	void SetPrevious(T* newNode);


}; //CLASS

