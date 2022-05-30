#pragma once
#include <iostream>
#include <string>
#include"Vertex.h"
#include"Edge.h"
#include"Incident.h"

template<typename T>
class Node
{
protected:

	T* previous;
	T* next;

public:

	//Konstruktory
	Node();
	Node(T* _previous, T* _next);
	Node(const T& newNode); 	//Konstruktor kopiuj¹cy

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	T* GetNext() const;
	T* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetNext(T* newNode);
	void SetPrevious(T* newNode);


}; //CLASS

