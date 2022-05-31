#pragma once
#include "Incident.h"

class Incident;  //definiuje klase aby preprocesor mogl zalaczyc plik Incident.h

class Vertex
{
private:

	int value;
	Incident* incident;

public:

	Vertex() = default;//: value(0), incident(nullptr){};  //?
	Vertex(int _value) : value(_value), incident(nullptr) {};
	//Vertex(incident)

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const int& GetValue() const { return value; };
	Incident* GetIncident() const { return incident; };


}; //class