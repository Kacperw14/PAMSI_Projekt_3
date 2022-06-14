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
		Graph* graph = new Graph();

		//std::cout << Ledge.Size() << std::endl;
		//std::cout << Ledge.First()->MinEdge()->GetValue() << std::endl;

		for (Edge* i = Claster->GetEdgeList().First(); i != Claster->GetEdgeList().GetTrailer(); i = i->GetNext())
		{
			if (i != Ledge.First()->MinEdge())
			{
				graph->InsertEdge(Ledge.First()->MinEdge()->GetBeginning(),
					Ledge.First()->MinEdge()->GetEnd(), Ledge.First()->MinEdge());

				Claster->InsertEdge(Ledge.First()->MinEdge()->GetBeginning(),
					Ledge.First()->MinEdge()->GetEnd(), Ledge.First()->MinEdge());
			}
			//if (i == Ledge.First()->MinEdge()->GetBeginning())
		}

		Ledge.Remove(Ledge.First()->MinEdge());

			/*while (graph->Vertices() <= _G->Vertices())
			{

			}*/

			return graph;
		};

	}; //CLASS