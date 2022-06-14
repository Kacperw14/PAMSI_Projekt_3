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
	std::string name;
	//std::vector<Incident*> incident;
	std::vector<Incident*> incident;

public:

	Vertex() = default; //?{ name = "0"; };
	/*Vertex(const Vertex& _vertex)
	{
		name = _vertex.GetName(); 
		incident = std::vector<Incident*>(_vertex.GetIncidentList());
	};*/
	Vertex(const std::string& _name) : name("V" + _name) {};//{ incident.push_back(new Incident(0)); };
	//Vertex(incident)

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const std::string& GetName() const { return name; };

	Incident* GetIncident(int _number) const
	{
		if (incident.empty())  throw "Empty";
		if(incident[_number] != nullptr) return incident[_number];
		//for (size_t i = 0; i < incident.size(); i++)
		//{
		//	//std::cout << incident.at(i)->GetName() << " ";
		//	if (i == _number) return incident[i];
		//}
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

	//void RemoveIncident(int _number)
	//{
	//	//std::cout << "lol" << " ";
	//	//RemoveIncident(incident.at(_number));
	//	//if (incident.empty())  throw "Empty";
	//	//for (auto i = incident.begin(); i != incident.end(); i++)
	//	//{
	//	//	//std::cout << incident.at(i)->GetName() << " ";
	//	//	if (*i == GetIncident(_number))  incident.erase(i, std::next(i));
	//	//}
	//}

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
	void Swap(Vertex* _swap)
	{
		std::string s = name;
		std::vector<Incident*> in = incident;
		//name = _swap->GetName()
		SetName(_swap->GetName());
		_swap->SetName(s);

		incident.clear();
		while (_swap->IncidentsSize() > 0)
		{
			//std::cout << _swap->GetFirstIncident()->GetName()<< std::endl;
			//std::cout << incident.front()->GetName()<< std::endl;
			incident.push_back(_swap->GetEndIncident());
			_swap->RemoveIncident(_swap->GetEndIncident());

		}

		while (in.size() > 0)
		{
			_swap->GetIncidentList().push_back(in.back());
			in.pop_back();
		}
	}
	//Funkcje umozliwiajace zmiane atrybutow.
	void SetName(const std::string& _name) { name = _name; };
	void AddIncident(Incident* _incident) { incident.push_back(_incident); };          ////number!!!
	int IncidentsSize() const { return incident.size(); };
}; //class