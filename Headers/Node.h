#pragma once
#include <iostream>
#include <string>
//#include"Edge.h"
//#include"Vertex.h"
//#include"Incident.h"

template <typename T>
class Node //: public T
{
private:
	T* previous;
	T* next;

public:

	//Konstruktory
	Node() :previous(nullptr), next(nullptr) {}; //= default;//delete;
	//Node(const T& _current, const T& _previous, const T& _next);
	//Node(T* _current, Node<T>* _previous, Node<T>* _next);
	Node(T* _previous, T* _next);
	//Node(const T& _current) : T(_current), previous(nullptr), next(nullptr) {};//current(_current) {};
	Node(const T& newNode); 	//Konstruktor kopiuj¹cy

	//Funkcje umozliwiajace dostep do atrybutow.
	T* GetNext() const;
	T* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetNext(T* newNode);
	void SetPrevious(T* newNode);

}; //CLASS


