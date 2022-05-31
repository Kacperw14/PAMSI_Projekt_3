#pragma once
#include "Incident.h"
#include <string>

class Incident;  //definiuje klase aby preprocesor mogl zalaczyc plik Incident.h

class Vertex
{
private:

	std::string name;
	Incident* incident;

public:

	//Vertex() = default;//: value(0), incident(nullptr){};  //?
	Vertex(std::string _value);
	//Vertex(incident)

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const std::string& GetName() const { return name; };
	const Incident* GetIncident() const { return incident; };

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetName(std::string _name) { name = _name; };
	void SetIncident(Incident* _incident) { incident = _incident; };

}; //class