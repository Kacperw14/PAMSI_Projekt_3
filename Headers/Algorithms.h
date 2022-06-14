#pragma once
#include"Graph.h"

class Algorithms {

public:

	Graph* Kruskal(Graph _G) const
	{
		Graph* Ledge = new Graph();
		Edge* E = nullptr;
		int size = _G.Vertices();//_G.GetVertexList().Size();
		std::cout <<size<< std::endl;
		for (Edge* i = _G.GetEdgeList().First(); i != _G.GetEdgeList().GetTrailer(); i = i->GetNext())
		{
			E = new Edge(*i);
			/*Ledge->GetEdgeList().AddAtEnd(E);
			Ledge->InsertVertex(i->GetBeginning());
			Ledge->InsertVertex(i->GetEnd());*/
			//Ledge->InsertVertex(E->GetBeginning());
			//Ledge->InsertVertex(E->GetEnd());
			Ledge->InsertEdge(i->GetBeginning(), i->GetEnd(), E);     ///!!!
		}
		//std::cout << Ledge->Vertices() << std::endl;
		Ledge->Print();
		Graph* Claster = new Graph();

		Graph* graph = new Graph();
		Edge* min = nullptr;
		////std::cout << Ledge.Size() << std::endl;

		bool isIntheClasterBeg = false;
		bool isIntheClasterEnd = false;

		graph->InsertVertex(new Vertex(*Ledge->MinEdge()->GetBeginning()));
		Claster->InsertVertex(Ledge->MinEdge()->GetBeginning());

		while (graph->Vertices() < size)//_G.GetVertexList().Size()) //Ledge->Vertices())//
		{
			std::cout <<"elo" << graph->GetVertexList().Size() << std::endl;
			isIntheClasterBeg = false;
			isIntheClasterEnd = false;

			min = Ledge->MinEdge();//Ledge.GetEdgeList().First()->MinEdge()
			//Claster->InsertEdge(min->GetBeginning(), min->GetEnd(), min);
			//Claster->Print();
			/*std::cout << min->GetBeginning()->GetName() << std::endl;
			std::cout << min->GetEnd()->GetName() << std::endl;*/
			//std::cout << min->GetValue() << std::endl;

			////for (Edge* i = Claster->GetEdgeList().First(); i != Claster->GetEdgeList().GetTrailer(); i = i->GetNext())
			for (Vertex* i = Claster->GetVertexList().First(); i != Claster->GetVertexList().GetTrailer(); i = i->GetNext())
			{
				/*std::cout << std::endl;
				std::cout << i->GetName() << std::endl;
				std::cout << std::endl;*/

				//std::cout << min->GetBeginning()->GetName() << std::endl;
				//std::cout << min->GetEnd()->GetName() << std::endl;
				if (i == min->GetBeginning()) isIntheClasterBeg = true;
				if (i == min->GetEnd()) isIntheClasterEnd = true;

				//if ((i->GetName().compare(min->GetBeginning()->GetName())) == 0) isIntheClasterBeg = true;
				//if ((i->GetName().compare(min->GetEnd()->GetName())) == 0) isIntheClasterEnd = true;
			}

			//graph->InsertEdge(new Vertex(*min->GetBeginning()), new Vertex(*min->GetEnd()), new Edge(*min));
			std::cout << isIntheClasterBeg << std::endl;
			std::cout << isIntheClasterEnd << std::endl;
			//&&
			/*if (!isIntheClasterBeg && !isIntheClasterEnd)
			{
				std::cout << "lol 0" << std::endl;
				graph->InsertEdge(new Vertex(*min->GetBeginning()), new Vertex(*min->GetEnd()), new Edge(*min));
				Claster->InsertVertex(min->GetBeginning());
				Claster->InsertVertex(min->GetEnd());
			}
			else
			{*/
			if (!isIntheClasterBeg)
			{
				std::cout << "lol 1" << std::endl;
				//graph->InsertEdge(min->GetBeginning(), min->GetEnd()), min);
				//graph->InsertEdge(new Vertex(*min->GetBeginning()), new Vertex(*min->GetEnd()), new Edge(*min));
				graph->InsertEdge(graph->GetVertexList().Last(), new Vertex(*min->GetBeginning()), new Edge(*min));
				Claster->InsertVertex(min->GetBeginning());
				/*graph->InsertEdge(graph->GetVertexList().Last(), new Vertex(*min->GetEnd()), new Edge(*min));
				Claster->InsertVertex(min->GetEnd());*/
			}
			if (!isIntheClasterEnd)
			{
				std::cout << "lol 2" << std::endl;
				graph->InsertEdge(graph->GetVertexList().Last(), new Vertex(*min->GetEnd()), new Edge(*min));
				Claster->InsertVertex(min->GetEnd());
				/*graph->InsertEdge(graph->GetVertexList().Last(), new Vertex(*min->GetBeginning()), new Edge(*min));
				Claster->InsertVertex(min->GetBeginning()); */
			}
			//}
			graph->Print();
			//std::cout << Ledge->Vertices() << std::endl;
			Ledge->RemoveEdge(min);
			//Ledge->GetEdgeList().Remove(min); //????
			//std::cout << Ledge->Vertices() << std::endl;
			//min->SetValue(100);
			//std::cout << Ledge.First()->MinEdge()->GetValue() << std::endl;
		}
		std::cout << "free" << std::endl;
		return graph;
	};


	//Graph* Prim(Graph _G) const
	//{
	//	Graph* Ledge = new Graph();
	//	//Edge* E = nullptr;
	///*	for (Edge* i = _G.GetEdgeList().First(); i != _G.GetEdgeList().GetTrailer(); i = i->GetNext())
	//	{
	//		Ledge->InsertEdge(i->GetBeginning(), i->GetEnd(), new Edge(*i));     ///!!!
	//	}*/
	//	Graph* Claster = new Graph();
	//	Graph* graph = new Graph();
	//	Edge* min = nullptr;

	//	Claster->InsertVertex(new Vertex(*_G.GetVertexList().First()));

	//	for (int i = 0; i < Claster->GetVertexList().First()->IncidentsSize(); i++)
	//	{
	//		Ledge->GetEdgeList().AddAtEnd(Claster->GetVertexList().First()->GetIncident(i)->GetEdge());
	//	}


	//	bool isIntheClasterBeg = false;
	//	bool isIntheClasterEnd = false;

	//	graph->InsertVertex(new Vertex(*Ledge->MinEdge()->GetBeginning()));
	//	Claster->InsertVertex(Ledge->MinEdge()->GetBeginning());

	//	while (Ledge->Edges() > 0)
	//	{
	//		std::cout << "elo" << graph->GetVertexList().Size() << std::endl;
	//		isIntheClasterBeg = false;
	//		isIntheClasterEnd = false;

	//		min = Ledge->MinEdge();
	//
	//		for (Vertex* i = Claster->GetVertexList().First(); i != Claster->GetVertexList().GetTrailer(); i = i->GetNext())
	//		{
	//			if (i == min->GetBeginning()) isIntheClasterBeg = true;
	//			if (i == min->GetEnd()) isIntheClasterEnd = true;
	//		}
	//		std::cout << isIntheClasterBeg << std::endl;
	//		std::cout << isIntheClasterEnd << std::endl;

	//		if (!isIntheClasterBeg)
	//		{
	//			std::cout << "lol 1" << std::endl;
	//			graph->InsertEdge(graph->GetVertexList().Last(), new Vertex(*min->GetBeginning()), new Edge(*min));
	//			Claster->InsertVertex(min->GetBeginning());
	//		}
	//		if (!isIntheClasterEnd)
	//		{
	//			std::cout << "lol 2" << std::endl;
	//			graph->InsertEdge(graph->GetVertexList().Last(), new Vertex(*min->GetEnd()), new Edge(*min));
	//			Claster->InsertVertex(min->GetEnd());
	//		}

	//		graph->Print();
	//		Ledge->RemoveEdge(min);

	//	}
	//	std::cout << "free" << std::endl;
	//	return graph;
	//};

}; //CLASS