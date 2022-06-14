#pragma once
#include <string>
#include"Edge.h"

class Edge;  //definiuje klase aby preprocesor mogl zalaczyc plik Edge.h

class Incident
{
private:

	std::string name;
	Edge* edge;

public:
	Incident() : name("I"), edge(nullptr) {};// = default;

	//Incident(const Incident& _incident)
	//{
	//	name = _incident.GetName();
	//	//if(_incident.GetEdge() != nullptr) 
	//	edge = new Edge(*_incident.GetEdge());
	//}

	//Incident(Edge* _edge) : name("I"), edge(_edge) {}; // ?
	Incident(const std::string& _name) : name("I"+_name), edge() {}; // ?
	Incident(const std::string& _name, Edge* _edge) : name("I" + _name), edge(_edge){};

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	Edge* GetEdge() const { return edge; };
	const std::string& GetName() const { return name; };

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetName(const std::string& _name) { name = _name; };
	void SetEdge(Edge* _edge) { edge = _edge; };
}; //class