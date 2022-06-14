#pragma once
#include "Vertex.h"
#include "Incident.h"
#include "Node.h"

class Incident;
class Vertex;
//class Edge;

class Edge : public Node<Edge>
{
protected:
	int value;
	Vertex* beginning;
	Vertex* end;
	Incident* begIncident;
	Incident* endIncident;

public:
	Edge() : value(0), beginning(nullptr), end(nullptr), begIncident(nullptr), endIncident(nullptr) {};//, previous(nullptr), next(nullptr) {};  //?
	Edge(Vertex* _beginning, Vertex* _end, const int& _value);
	Edge(const int& _value) : value(_value), beginning(nullptr), end(nullptr), begIncident(nullptr), endIncident(nullptr) {};
	//konstruktor kopiujacy
	//Edge(const Edge& _edge) : beginning(_edge.GetBeginning()), end(_edge.GetEnd()), value(_edge.GetValue()) {};//previous(_edge.GetNext()), next(_edge.GetPrevious()) {}; 



	////Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const int& GetValue() const;
	 Vertex* GetBeginning() const { return beginning; };
	 Vertex* GetEnd() const { return end; };
	 Incident* GetBegInc() const { return begIncident; };
	 Incident* GetEndInc() const { return endIncident; };

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetValue(const int& _value) { value = _value; };
	void SetBeginning(Vertex* _beginning) { beginning = _beginning; };
	void SetEnd(Vertex* _end) { end = _end; };
	void SetBegInc(Incident* _begIncident) { begIncident = _begIncident; };
	void SetEndInc(Incident* _endIncident) { endIncident = _endIncident; };

}; //class