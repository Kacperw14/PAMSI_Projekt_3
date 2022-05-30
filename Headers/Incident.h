#pragma once
#include"Node.h"

class Incident 
{
private:
	Edge edge;
	
public:
	Incident(Edge _edge) : edge(_edge) {};
	const Edge& GetEdge() const {return edge; };
	

}; //class