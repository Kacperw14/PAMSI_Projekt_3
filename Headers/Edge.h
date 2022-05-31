#pragma once
#include <iostream>
#include "Vertex.h"
#include "Incident.h"

//class Incident;

class Edge //: public Node
{
private:
	int value;
	Vertex* beginning;
	Vertex* end;
	Incident* begIncident;
	Incident* endIncident;

	//Edge* previous;
	//Edge* next;

public:
	Edge() = default;//: value(0), beginning(nullptr), end(nullptr) {};//, previous(nullptr), next(nullptr) {};  //?
	Edge(Vertex* _beginning, Vertex* _end, const int& _value) : beginning(_beginning), end(_end), value(_value) {};

	//Edge(Edge* _previous, Edge* _next) : value(0), previous(_previous), next(_next) {};
	//konstruktor kopiujacy
	//Edge(const Edge& _edge) : beginning(_edge.GetBeginning()), end(_edge.GetEnd()), value(_edge.GetValue()) {};//previous(_edge.GetNext()), next(_edge.GetPrevious()) {}; 



	//const int& GetValue() const;
	////Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	//Edge* GetNext() const;
	//Edge* GetPrevious() const;

	//Vertex* GetBeginning() const { return beginning; };
	//Vertex* GetEnd() const { return end; };
	//Incident* GetIncBeg() const { return begIncident; };
	//Incident* GetIncEnd() const { return endIncident; };

	//Funkcje umozliwiajace zmiane atrybutow.
	//void SetNext(Edge* newNode);
	//void SetPrevious(Edge* newNode);

	//Edge* GetNext() const override;
	//Edge* GetPrevious() const override;
}; //class