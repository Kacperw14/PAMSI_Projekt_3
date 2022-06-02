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
	//List<Vertex> vertex;
	//List<Incident> incident;

public:
	Graph() = default;
	//Graph(Edge _) : Edge(), Vertex(), Incident() {};
	void InsertEdge(Edge* _edge)  //!!!! Vertex* _beginning, Vertex* _end,
	{
		edgeList.AddAtEnd(_edge);
	}

	List<Edge> GetEdgeList() const { return edgeList;};
	const int& Edges() { return edgeList.Size(); };

}; //class