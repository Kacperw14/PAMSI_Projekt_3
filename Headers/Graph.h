//#include <iostream>
#pragma once
#include "List.h"
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
		//bool isInTheListBeg = false;
		//bool isInTheListEnd = false;

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
		edgeList.AddAtEnd(_edge);

		////duplikaty vertex
		//for (Node<Vertex>* _start = vertexList.First(); _start != vertexList.GetTrailer(); _start = _start->GetNext())
		//{
		//	std::cout << _start << std::endl;
		//	if (_beginning == _start) isInTheListBeg = true;
		//	if (_end == _start) isInTheListEnd = true;
		//}
		//std::cout << _beginning << std::endl;
		//if (!isInTheListBeg) 
		//if (!isInTheListEnd) 
		vertexList.AddAtEnd(_beginning);
		vertexList.AddAtEnd(_end);

		incidentList.AddAtEnd(_begIncident);
		incidentList.AddAtEnd(_endIncident);
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
		if (_vertexBeg->GetIncident() == nullptr) return false;
		else if (_vertexBeg->GetIncident()->GetEdge()->GetBeginning() == _vertexEnd) return true;
		else if (_vertexBeg->GetIncident()->GetEdge()->GetEnd() == _vertexEnd) return true;	
		else return false;
	}
}; //class