//#include <iostream>
#pragma once
#include "List.h"
#include <string>
#include <cmath>
//#include "Incident.h"
//#include "Vertex.h"
//#include "Edge.h"


//class Incident;

class Graph
{
private:
	List<Edge> edgeList;
	List<Vertex> vertexList;
	//List<Branch> vertexList;
	//List<Incident> incidentList;

public:
	Graph() = default;
	//Graph(Edge _) : Edge(), Vertex(), Incident() {};

	void InsertEdge(Vertex* _beginning, Vertex* _end, Edge* _edge)
	{
		//bool isNotInTheListBeg = true;
		//bool isNotInTheListEnd = true;

		Incident* _begIncident = new Incident(_beginning->GetName(), _edge);
		Incident* _endIncident = new Incident(_end->GetName(), _edge);


		//incidentList.AddAtEnd(_begIncident);
		_beginning->AddIncident(_begIncident);
		//incidentList.AddAtEnd(_endIncident);
		_end->AddIncident(_endIncident);

		_edge->SetBegInc(_begIncident);
		_edge->SetBeginning(_beginning);

		_edge->SetEndInc(_endIncident);
		_edge->SetEnd(_end);

		edgeList.AddAtEnd(_edge);

		InsertVertex(_beginning);
		InsertVertex(_end);
	}


	Vertex* operator[] (int _number)
	{
		int n = 0;
		if (_number > Vertices()) return nullptr;
		for (Node<Vertex>* _start = vertexList.First(); _start != vertexList.GetTrailer(); _start = _start->GetNext())
		{
			if (n++ == _number) return _start;
		}
		return nullptr;

	};

	void InsertVertex(Vertex* _vertex)
	{
		for (Node<Vertex>* _start = vertexList.First(); _start != vertexList.GetTrailer(); _start = _start->GetNext())
		{
			//std::cout << _start->GetName() << std::endl;
			//if (_vertex->GetName().compare(_start->GetName()) == 0) isNotInTheList = false;
			if (_start == _vertex) return;
		}
		vertexList.AddAtEnd(_vertex);
	}

	List<Edge> GetEdgeList() const { return edgeList; };
	List<Vertex> GetVertexList() const { return vertexList; };
	//List<Incident> GetIncidentList() const { return incidentList; };

	const int& Edges() { return edgeList.Size(); };
	const int& Vertices() { return vertexList.Size(); };
	List<Edge>* IncidentEdges(Vertex* _vertex)
	{
		//if (_vertex->GetFirstIncident() != nullptr)
		List<Edge>* L = new List<Edge>();
		/*for (int i = 0; i < _vertex->IncidentsSize(); i++)
		{
			std::cout << _vertex->GetIncident(i)->GetEdge()->GetValue() << std::endl;
			if (_vertex->GetIncident(i)->GetEdge() != nullptr) L->AddAtEnd(_vertex->GetIncident(i)->GetEdge());
		}*/
		//for (std::vector<Incident*>::iterator i = _vertex->GetIncidentList().begin(); i != _vertex->GetIncidentList().end(); i++)
		for (int i = 0; i < _vertex->IncidentsSize(); i++)
		{
			//std::cout << i->GetName()<< std::endl;
			//if ( ->GetEdge()) != nullptr) L->AddAtEnd(i->GetEdge());
			if (_vertex->GetIncident(i)->GetEdge() != nullptr) L->AddAtEnd(_vertex->GetIncident(i)->GetEdge());
		}
		//if (_vertex->GetEndIncident()->GetEdge() != nullptr) L->AddAtEnd(_vertex->GetEndIncident()->GetEdge());   // sprawdzenie elementu LastIncident
		return L;
	};

	//Metody dostepu
	Vertex* Opposite(Vertex* _vertex, Edge* _edge)
	{
		if (_vertex == _edge->GetBeginning()) return _edge->GetEnd();
		else if (_vertex == _edge->GetEnd()) return _edge->GetBeginning();
		else throw "_vertex nie jest polaczony poprzez _edge";
	};

	bool AreAdjacent(Vertex* _vertexBeg, Vertex* _vertexEnd)
	{
		//List<Edge> L(IncidentEdges(_vertexEnd));
		if (_vertexBeg == nullptr || _vertexEnd == nullptr) return false;
		for (Incident* i = _vertexBeg->GetFirstIncident(); i != _vertexBeg->GetEndIncident();  i = std::next(i))
		{
			for (Incident* j = _vertexEnd->GetFirstIncident(); j != _vertexEnd->GetEndIncident() ; j++)
			{
				//std::cout <<"i " << i->GetEdge()->GetValue() << std::endl;
				std::cout << "i " << i->GetEdge()->GetValue() << std::endl;
				std::cout << j->GetEdge()->GetValue() << std::endl;
				if (i->GetEdge() == j->GetEdge()) return true;
			}
			if (i->GetEdge() == _vertexEnd->GetEndIncident()->GetEdge()) return true;
		}
		for (Incident* j = _vertexEnd->GetFirstIncident(); j != _vertexEnd->GetEndIncident(); j++)
		{
			if (_vertexBeg->GetEndIncident()->GetEdge() == j->GetEdge()) return true;
		}
		if (_vertexBeg->GetEndIncident()->GetEdge() == _vertexEnd->GetEndIncident()->GetEdge()) return true;
		
		
		return false;
	}


	void MinMax()
	{

	}

	inline static Edge* Power(std::string* _board, int _row, int _column, int _size)      //bez flagi; Srodek nie daje 10
	{
		int power = 0;
		//std::cout << _size << std::endl;
		//--_size;

		if (_size > 2) //
		{
			int** flag = new int* [_size];
			for (int i = 0; i < _size; i++)
			{
				flag[i] = new int;//[_board->size()];
				for (int j = 0; j < _size; j++)
				{
					//flag[i] = new int;
					flag[i][j] = 0;
					if (_board[i][j] == 'x') flag[i][j] = 1;
					//std::cout << flag[i][j] << std::endl;
				}
			}

			for (int i = -1; i < 2; i++)
			{
				for (int j = -1; j < 2; j++)
				{
					if (i == 0 && j == 0);
					else
					{
						if ((_row + i) >= 0 && (_row + i) < _size && (_column + j) >= 0 && (_column + j) < _size)
						{
							//std::cout << std::endl << i << " " << j << " " << flag[_row + i][_column + j] << std::endl;
							if (flag[_row + i][_column + j])
							{
								if (_row + (2 * i) >= 0 && _row + (2 * i) < _size && _column + (2 * j) >= 0 && _column + (2 * j) < _size)
								{
									if (flag[_row + 2 * i][_column + 2 * j] == 1) power += 10;
									else power += 1;
								}
								else if (flag[_row + i][_column + j] == 1) power += 1;
							}
						}
					}
				}
			}
			delete[] flag;
			//flag[0];
		}
		return new Edge(power);
	}


	void Print()
	{
		for (Node<Edge>* _start = edgeList.First(); _start != edgeList.GetTrailer(); _start = _start->GetNext())
		{
			std::cout << _start->GetBeginning()->GetName() << " ";
			std::cout << "E" << _start->GetValue() << " ";
			std::cout << _start->GetBegInc()->GetName() << " ";
			std::cout << _start->GetEndInc()->GetName() << " ";
			std::cout << _start->GetEnd()->GetName() << " ";
		}
		std::cout << std::endl;

		/*for (int i = 0; i < Vertices(); i++)
		{
			std::cout << this->operator[](i)->GetName() << " ";
		}
		std::cout << std::endl;
		for (Node<Edge>* _start = edgeList.First(); _start != edgeList.GetTrailer(); _start = _start->GetNext())
		{
			std::cout << _start->GetValue() << " ";
		}
		std::cout << std::endl;*/
		/*
		for (Node<Incident>* _start = incidentList.First(); _start != incidentList.GetTrailer(); _start = _start->GetNext())
		{
			std::cout << _start->GetName() << " ";
		}
		std::cout << std::endl;*/

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