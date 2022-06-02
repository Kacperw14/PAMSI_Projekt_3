#pragma once
#include <iostream>
#include <string>
#include"Edge.h"
#include"Vertex.h"

template <typename T>
class Node : public T
{
private:
	Node<T>* previous;
	Node<T>* next;

public:

	//Konstruktory
	Node(); //= default;//delete;
	//Node(const T& _current, const T& _previous, const T& _next);
	Node(T* _current, Node<T>* _previous, Node<T>* _next);
	Node(const T& _current) : T(_current), previous(nullptr), next(nullptr) {};//current(_current) {};
	Node(const Node<T>& newNode); 	//Konstruktor kopiuj¹cy

	//Funkcje umozliwiajace dostep do atrybutow.
	Node<T>* GetNext() const;
	Node<T>* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetNext(Node<T>* newNode);
	void SetPrevious(Node<T>* newNode);


}; //CLASS

