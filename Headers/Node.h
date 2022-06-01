#pragma once
#include <iostream>
#include <string>
#include"Edge.h"

template <typename T>
class Node : public T
{
private:
	//T* current;
	T* previous;
	T* next;

public:

	//Konstruktory
	Node() = delete;
	Node(T* _current, T* _previous, T* _next);
	Node(const T& _current) : T(_current) {};//current(_current) {};
	Node(const Node<T>& newNode); 	//Konstruktor kopiuj¹cy

	//Funkcje umozliwiajace dostep do atrybutow.
	T* GetNext() const;
	T* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetNext(T* newNode);
	void SetPrevious(T* newNode);


}; //CLASS

