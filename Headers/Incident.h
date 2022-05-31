#pragma once
#include"Edge.h"
#include <string>

class Edge;  //definiuje klase aby preprocesor mogl zalaczyc plik Edge.h

class Incident
{
private:

	std::string name;
	Edge* edge;
	//Incident* previous;
	//Incident* next;

public:
	Incident() = default;
	Incident(Edge* _edge) : edge(_edge) {}; //, previous(nullptr), next(nullptr) {};
	Incident(const std::string& _name, Edge* _edge) : name(_name) ,edge(_edge) {};

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const Edge* GetEdge() const { return edge; };
	const std::string& GetName() const { return name; };
	//Incident* GetNext() const;
	//Incident* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	//void SetNext(Incident* newNode);
	//void SetPrevious(Incident* newNode);

}; //class