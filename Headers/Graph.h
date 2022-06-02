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
	void InsertEdge(Vertex* _beginning, Vertex* _end, Edge* _edge)  //!!!!
	{
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

}; //class