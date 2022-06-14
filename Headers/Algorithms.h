#pragma once
#include"Graph.h"

class Algorithms {

public:

	Graph* Kruskal(const Graph& _G) const
	{
		List<Edge> Ledge;
		for (Edge* i = _G.GetEdgeList().First(); i != _G.GetEdgeList().GetTrailer(); i = i->GetNext())
		{
			Ledge.AddAtEnd(new Edge(*i));
		}
		Graph* Claster = new Graph();

		///*for (Vertex* i = _G.GetVertexList().First(); i != _G.GetVertexList().GetTrailer(); i = i->GetNext())
		//{
		//	Claster->InsertVertex(new Vertex(*i));
		//}*/

		Graph* graph = new Graph();
		Edge* min = nullptr;
		////std::cout << Ledge.Size() << std::endl;
		min = Ledge.First()->MinEdge();
	
		bool isIntheClasterBeg = false;
		bool isIntheClasterEnd = false;
		
		
		//while (graph->Vertices() <= _G->Vertices())
		//{
		//Claster->InsertEdge(min->GetBeginning(), min->GetEnd(), min);
		
		////for (Edge* i = Claster->GetEdgeList().First(); i != Claster->GetEdgeList().GetTrailer(); i = i->GetNext())
		for (Vertex* i = Claster->GetVertexList().First(); i != Claster->GetVertexList().GetTrailer(); i = i->GetNext())
		{
			if (i == min->GetBeginning()) isIntheClasterBeg = true;	
			if (i == min->GetEnd()) isIntheClasterEnd = true;
		}
		if (!isIntheClasterBeg && !isIntheClasterEnd)
		{
			graph->InsertEdge(new Vertex(*min->GetBeginning()), new Vertex(*min->GetEnd()), new Edge(*min));
			//Claster->InsertEdge(new Vertex(*min->GetBeginning()), new Vertex(*min->GetEnd()), new Edge(*min));
			Claster->InsertEdge(min->GetBeginning(), min->GetEnd(), min);
		}

				//break;
			//else break;
			//if (i == Ledge.First()->MinEdge()->GetBeginning())
		//}
		//std::cout << Claster->Vertices() << std::endl;

		Ledge.Remove(Ledge.First()->MinEdge());

			/*

			}*/

			return graph;
		};

	}; //CLASS