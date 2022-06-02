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
		edgeList.AddAtEnd(_edge);
	}

	List<Edge> GetEdgeList() const { return edgeList;};
	List<Vertex> GetVertexList() const { return vertexList;};
	List<Incident> GetIncidentList() const { return incidentList;};

	const int& Edges() { return edgeList.Size(); };
	const int& Vertices() { return vertexList.Size(); };

}; //class