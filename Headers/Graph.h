//#include <iostream>
#pragma once
#include "List.h"
#include <string>
//#include "Incident.h"
//#include "Vertex.h"
//#include "Edge.h"


//class Incident;

class Graph
{
private:
	List<Edge> edgeList;
	List<Vertex> vertexList;
	List<Incident> incidentList;

public:
	Graph() = default;
	//Graph(Edge _) : Edge(), Vertex(), Incident() {};
	void InsertEdge(Vertex* _beginning, Vertex* _end, Edge* _edge)  //!!!! privtave aby nie bylo duplikatow
	{
		bool isInTheListBeg = false;
		bool isInTheListEnd = false;

		//inicjuje krawedz incydentna
		Incident* _begIncident = new Incident(_beginning->GetName(), _edge);
		Incident* _endIncident = new Incident(_end->GetName(), _edge);

		_edge->SetBegInc(_begIncident);
		_edge->SetEndInc(_endIncident);
		_beginning->SetIncident(_begIncident);
		_end->SetIncident(_endIncident);

		//ustalam polaczenie krawedzi
		_edge->SetBeginning(_beginning);
		_edge->SetEnd(_end);

		//dodaje elementy do atrybutow grafu


		//duplikaty vertex
		for (Node<Vertex>* _start = vertexList.First(); _start != vertexList.GetTrailer(); _start = _start->GetNext())
		{
			//std::cout << _start << std::endl;
			std::cout << _end->GetName() << std::endl;
			std::cout << _start->GetName() << std::endl;
			std::cout << std::endl;
			if (_beginning->GetName().compare(_start->GetName()) == 0) isInTheListBeg = true;
			if (_end->GetName().compare(_start->GetName()) == 0) isInTheListEnd = true;
		}

		//std::cout << !isInTheListBeg << std::endl;
		if (!isInTheListBeg) vertexList.AddAtEnd(_beginning);
		if (!isInTheListEnd) vertexList.AddAtEnd(_end);

		//dodaj vertex do listy

		if (!isInTheListBeg || !isInTheListEnd)
		{
			edgeList.AddAtEnd(_edge);
			incidentList.AddAtEnd(_begIncident);
			incidentList.AddAtEnd(_endIncident);
		}
	}

	void InsertVertex(Vertex* _vertex) { vertexList.AddAtEnd(_vertex); }

	List<Edge> GetEdgeList() const { return edgeList; };
	List<Vertex> GetVertexList() const { return vertexList; };
	List<Incident> GetIncidentList() const { return incidentList; };

	const int& Edges() { return edgeList.Size(); };
	const int& Vertices() { return vertexList.Size(); };
	const int& Incidents() { return incidentList.Size(); };

	Incident* IncidentEdges(Vertex* _vertex) { return _vertex->GetIncident(); }
	/*{
		Edge* tab;
		tab = { _vertex->GetIncident()->GetEdge() };
		return tab;
	}*/

	//Metody dostepu
	Vertex* Opposite(Vertex* _vertex, Edge* _edge)
	{
		if (_vertex == _edge->GetBeginning()) return _edge->GetEnd();
		else if (_vertex == _edge->GetEnd()) return _edge->GetBeginning();
		else throw "_vertex nie jest polaczony poprzez _edge";
	};

	bool AreAdjacent(Vertex* _vertexBeg, Vertex* _vertexEnd)
	{
		//std::cout << _vertexBeg->GetIncident()->GetEdge()<<std::endl;
		//std::cout << _vertexEnd->GetIncident()->GetEdge();
		if (_vertexBeg->GetIncident() == nullptr) return false;
		else if (_vertexBeg->GetIncident()->GetEdge() == _vertexEnd->GetIncident()->GetEdge()) return true;
		//else if (_vertexBeg->GetIncident()->GetEdge()->GetEnd() == _vertexEnd) return true;
		else return false;
	}

	Vertex* operator[] (int _number)
	{
		int n = 0;
		if (_number > Vertices()) return nullptr;
		for (Node<Vertex>* _start = vertexList.First(); _start != vertexList.GetTrailer(); _start = _start->GetNext())
		{
			if (n++ == _number) return _start;
		}

	}

	void MinMax()
	{

	}
	void Print()
	{
		for (int i = 0; i < Vertices(); i++)
		{
			std::cout << this->operator[](i)->GetName() << " ";
		}
		std::cout << std::endl;
		for (Node<Edge>* _start = edgeList.First(); _start != edgeList.GetTrailer(); _start = _start->GetNext())
		{
			std::cout << _start->GetValue() << " ";
		}
			//for (int j = 0; j < Vertices(); j++)

			/*
			if (AreAdjacent(this->operator[](i), this->operator[](i + 1)))
		{
			std::cout << this->operator[](i)->GetName() << " ";
		}
	}
		std::cout << std::endl;
	for (int i = 0; i < Vertices(); i++)
	{

		if (!AreAdjacent(this->operator[](i), this->operator[](i + 1)))
		{
			std::cout << this->operator[](i)->GetName() << " ";
		}
	*/
	
	}

}; //class