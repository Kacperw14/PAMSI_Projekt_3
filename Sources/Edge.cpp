#include "..\Headers\Edge.h"
//#include"../Headers/Edge.h"
//
//
//Edge* Edge::GetNext() const
//{
//	if (this == nullptr) throw nullptr; //std::cout << "Funkcja \"GetNext:\": otrzymala nullptr" << std::endl;
//	else return next;
//}
//Edge* Edge::GetPrevious() const
//{
//	if (this == nullptr) throw nullptr; //std::cout << "Funkcja \"GetPrevious:\": otrzymala nullptr" << std::endl;
//	else return previous;
//}
//void Edge::SetNext(Edge* newNode)
//{
//	if (this == nullptr)  std::cout << "Funkcja \"SetNext:\": otrzymala nullptr" << std::endl;
//	else next = newNode;
//}
//void Edge::SetPrevious(Edge* newNode)
//{
//	if (this == nullptr)  std::cout << "Funkcja \"SetPrevious:\": otrzymala nullptr" << std::endl;
//	else previous = newNode;
//}

//, previous(nullptr), next(nullptr) {};  //?

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