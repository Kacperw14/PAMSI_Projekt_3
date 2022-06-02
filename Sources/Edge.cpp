#include "..\Headers\Edge.h"

Edge::Edge(Vertex* _beginning, Vertex* _end, const int& _value)// : beginning(_beginning), end(_end), value(_value) {};
{
	Incident* Ibeg = new Incident(_beginning->GetName(), this);
	Incident* Iend = new Incident(_end->GetName(), this);
	beginning = _beginning;
	end = _end;
	value = _value;
	begIncident = Ibeg;//beginning->GetIncident();
	endIncident = Iend;//end->GetIncident();
	beginning->SetIncident(begIncident);
	end->SetIncident(endIncident);
}

const int& Edge::GetValue() const
{
	if (this != nullptr) return value; 
	else throw "Funkcja \"GetValue:\": otrzymala nullptr";
}