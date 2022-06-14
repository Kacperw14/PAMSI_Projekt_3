#pragma once
//#include "List.h"
#include "Incident.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <vector>

class Incident;  //definiuje klase aby preprocesor mogl zalaczyc plik Incident.h


class Vertex : public Node<Vertex>
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

	Incident* GetIncident(int _number) const
	{
		if (incident.empty())  throw "Empty";
		for (int i = 0; i < incident.size(); i++)
		{
			//std::cout << incident.at(i)->GetName() << " ";
			if (i == _number) return incident[i];
		}
		//return nullptr
		throw "Zly indeks";
	};

	//void SetIncydent(const int& _number, Incident* _incydent)
	//{
	//	if (incident.empty())  throw "Empty";
	//	for (int i = 0; i < incident.size(); i++)
	//	{
	//		//std::cout << incident.at(i)->GetName() << " ";
	//		if (i == _number) incident[i] = _incydent;
	//	}
	//	//return nullptr
	//	throw "Zly indeks";
	//}

	void RemoveIncident(int _number)
	{
		//std::cout << "lol" << " ";
		//RemoveIncident(incident.at(_number));
		//if (incident.empty())  throw "Empty";
		//for (auto i = incident.begin(); i != incident.end(); i++)
		//{
		//	//std::cout << incident.at(i)->GetName() << " ";
		//	if (*i == GetIncident(_number))  incident.erase(i, std::next(i));
		//}
	}

	void RemoveIncident(Incident* _incident)
	{
		if (incident.empty())  throw "Empty";
		for (std::vector<Incident*>::iterator i = incident.begin(); i != incident.end(); i++)
		{
			if (*i == _incident)
			{
				//std::cout << *i<< " ";
				//std::cout << "jest" << " ";
				incident.erase(i, i+1);
				return;
			}
		}
		//std::cout << "nie ma" << " ";
	}

	//void RemoveIncident(const Incident& _incident)
	//{
	//	//std::remove(incident.begin(), incident.end(), _incident);

	//}

	std::vector<Incident*> GetIncidentList() const
	{
		return incident;
	};

	Incident* GetFirstIncident() const
	{
		if (incident.empty())  throw "Empty";
		else return incident.front();
	};
	Incident* GetEndIncident() const
	{
		if (incident.empty())  throw "Empty";
		else return incident.back(); //std::next(
	};
	//Funkcje umozliwiajace zmiane atrybutow.
	void SetName(const std::string& _name) { name = _name; };
	void AddIncident(Incident* _incident) { incident.push_back(_incident); };          ////number!!!
	size_t IncidentsSize() const { return incident.size(); };
/*void Incidents()
	{
		for (int i = 0; i < incident.size(); i++)
		{
			std::cout << incident.at(i)->GetName() << " ";
		}
		std::cout << std::endl;
	}*/
}; //class