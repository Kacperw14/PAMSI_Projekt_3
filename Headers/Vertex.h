#pragma once
//#include "List.h"
#include "Incident.h"
#include <string>
#include <vector>

class Incident;  //definiuje klase aby preprocesor mogl zalaczyc plik Incident.h

class Vertex
{
private:

	//::vector<Vertex>* branch;
	std::string name;
	//std::vector<Incident*> incident;
	std::vector<Incident*> incident;

public:

	Vertex() = default; //?{ name = "0"; };
	Vertex(const std::string& _name) : name("V" + _name) {};//{ incident.push_back(new Incident(0)); };
	//Vertex(incident)

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const std::string& GetName() const { return name; };
	Incident* GetFirstIncident() const 
	{
		if (incident.empty())  return nullptr;
		else return incident.front(); 
	};
	Incident* GetEndIncident() const
	{
		if (incident.empty())  return nullptr;
		else return std::next(incident.back());
	};
	//Funkcje umozliwiajace zmiane atrybutow.
	void SetName(const std::string& _name) { name = _name; };
	void AddIncident(Incident* _incident) { incident.push_back(_incident); };          ////number!!!
	
}; //class