#pragma once
#include"Edge.h"

class Edge;  //definiuje klase aby preprocesor mogl zalaczyc plik Edge.h

class Incident
{
private:
	Edge* edge;
	//Incident* previous;
	//Incident* next;

public:
	Incident() = default;
	Incident(Edge* _edge) : edge(_edge) {}; //, previous(nullptr), next(nullptr) {};
	

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const Edge* GetEdge() const { return edge; };
	//Incident* GetNext() const;
	//Incident* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	//void SetNext(Incident* newNode);
	//void SetPrevious(Incident* newNode);

}; //class