#pragma once
#include"Edge.h"
#include <string>

class Edge;  //definiuje klase aby preprocesor mogl zalaczyc plik Edge.h

class Incident
{
private:

	std::string name;
	Edge* edge;

public:
	Incident() : name("I"), edge(nullptr) {};// = default;
	Incident(Edge* _edge) : name("I"), edge(_edge) {}; // ?
	Incident(const std::string& _name) : name("I"+_name), edge(nullptr) {}; // ?
	Incident(const std::string& _name, Edge* _edge) : name("I" + _name), edge(_edge) {};

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	Edge* GetEdge() const { return edge; };
	const std::string& GetName() const { return name; };

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetName(const std::string& _name) { name = _name; };
	void SetEdge(Edge* _edge) { edge = _edge; };
}; //class