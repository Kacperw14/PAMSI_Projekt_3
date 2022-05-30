#pragma once
#include"Node.h"
#include"Edge.h"

class Incident : Node
{
private:
	Edge edge;
	
public:
	Incident(Edge _edge) : edge(_edge) {};
	const Edge& GetEdge() const {return edge; };
	

}; //class