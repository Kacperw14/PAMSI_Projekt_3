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
		bool isNotInTheListBeg = true;
		bool isNotInTheListEnd = true;

		//duplikaty vertex
		for (Node<Vertex>* _start = vertexList.First(); _start != vertexList.GetTrailer(); _start = _start->GetNext())
		{
			//std::cout << _start << std::endl;
			//std::cout << _end->GetName() << std::endl;
			//std::cout << _start->GetName() << std::endl;
			//std::cout << std::endl;
			if (_beginning->GetName().compare(_start->GetName()) == 0)
			{
				_beginning = _start;
				isNotInTheListBeg = false;
			}
			if (_end->GetName().compare(_start->GetName()) == 0)
			{
				_end = _start;
				isNotInTheListEnd = false;
			}
		}

		if (!isNotInTheListBeg && !isNotInTheListEnd)return;    //nie ma dwoch tych samych krawedzi

		Incident* _begIncident = new Incident(_beginning->GetName(), _edge);
		incidentList.AddAtEnd(_begIncident);

		_edge->SetBegInc(_begIncident);
		_edge->SetBeginning(_beginning);
		_beginning->SetIncident(_edge->GetBegInc());

		if (isNotInTheListBeg)
		{
			//inicjuje krawedz incydentna
		//dodaj vertex do listy
			//ustalam polaczenie krawedzi
			//ustalenie incydentnej dla vertex
			//dodaje elementy do atrybutow grafu
			//_beginning->SetIncident(_begIncident); 
			vertexList.AddAtEnd(_beginning);
		}
		else
		{
			//_edge->SetBeginning(_beginning);
			//_beginning->SetIncident(_edge->GetBegInc());
		}


		Incident* _endIncident = new Incident(_end->GetName(), _edge);
		incidentList.AddAtEnd(_endIncident);

		_edge->SetEndInc(_endIncident);
		_edge->SetEnd(_end);
		_end->SetIncident(_edge->GetEndInc());

		if (isNotInTheListEnd)
		{
			//_end->SetIncident(_endIncident);  //to samo
			vertexList.AddAtEnd(_end);
		}
		/*else
		{
			_edge->SetEnd(_end);
			_end->SetIncident(_edge->GetEndInc());
		}*/

		edgeList.AddAtEnd(_edge);

		if (isNotInTheListBeg || isNotInTheListEnd)
		{
			//_endIncident->SetEdge(_edge);
			//_begIncident->SetEdge(_edge);
			//edgeList.AddAtEnd(_edge);


		}


	}

	void InsertVertex(Vertex* _vertex)
	{
		bool isNotInTheList = true;
		for (Node<Vertex>* _start = vertexList.First(); _start != vertexList.GetTrailer(); _start = _start->GetNext())
		{
			//std::cout << _start->GetName() << std::endl;
			if (_vertex->GetName().compare(_start->GetName()) == 0) isNotInTheList = false;
		}
		if (isNotInTheList) vertexList.AddAtEnd(_vertex);
	}

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
		//else if (_vertexBeg->GetIncident()->GetEdge() == _vertexEnd->GetIncident()->GetEdge()) return true;
		else if (_vertexBeg->GetIncident()->GetEdge()->GetBeginning() == _vertexEnd) return true;
		else if (_vertexBeg->GetIncident()->GetEdge()->GetEnd() == _vertexEnd) return true;
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
		std::cout << std::endl;
		for (Node<Incident>* _start = incidentList.First(); _start != incidentList.GetTrailer(); _start = _start->GetNext())
		{
			std::cout << _start->GetName() << " ";
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