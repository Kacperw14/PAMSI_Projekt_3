//#include <iostream>
#pragma once
#include "List.h"
#include <string>
#include <cmath>
#include <vector>
//#include "Incident.h"
//#include "Vertex.h"
//#include "Edge.h"


//class Incident;

class Graph
{
private:
	List<Edge> edgeList;
	std::vector<List<Vertex>> vertexList;
	List<Incident> incidentList;

public:
	Graph() = default;
	//Graph(Edge _) : Edge(), Vertex(), Incident() {};

	void InsertEdge(Vertex* _beginning, Vertex* _end, Edge* _edge)  //!!!! privtave aby nie bylo duplikatow
	{
		bool isNotInTheListBeg = true;
		bool isNotInTheListEnd = true;

		Incident* _begIncident = new Incident(_beginning->GetName(), _edge);
		Incident* _endIncident = new Incident(_end->GetName(), _edge);
		//for (Node<Incident>* _start = incidentList.First(); _start != incidentList.GetTrailer(); _start = _start->GetNext())
		//{
		//	if (_begIncident->GetName().compare(_start->GetName()) == 0 && _beginning->GetIncident() == nullptr)
		//	{
		//		_begIncident = _start;
		//		isNotInTheListBeg = false;
		//	}

		//	if (_endIncident->GetName().compare(_start->GetName()) == 0 )//&& _end->GetIncident() != nullptr)
		//	{
		//		_endIncident = _start;
		//		isNotInTheListEnd = false;
		//	}
		//}

		if (isNotInTheListBeg)
		{
			incidentList.AddAtEnd(_begIncident);
			_beginning->SetIncident(_begIncident);
		}
		if (isNotInTheListEnd)
		{
			incidentList.AddAtEnd(_endIncident);
			_end->SetIncident(_endIncident);
		}

		_edge->SetBegInc(_begIncident);
		_edge->SetBeginning(_beginning);
		//_beginning->SetIncident(_edge->GetBegInc());


		_edge->SetEndInc(_endIncident);
		_edge->SetEnd(_end);


		edgeList.AddAtEnd(_edge);

		isNotInTheListBeg = true;
		isNotInTheListEnd = true;
		//duplikaty vertex
		//for (Node<Vertex>* _start = vertexList.First(); _start != vertexList.GetTrailer(); _start = _start->GetNext())
		//{
		//	if (_beginning->GetName().compare(_start->GetName()) == 0)
		//	{
		//		_beginning = _start;
		//		isNotInTheListBeg = false;
		//	}
		//	if (_end->GetName().compare(_start->GetName()) == 0)
		//	{
		//		_end = _start;
		//		isNotInTheListEnd = false;
		//	}
		//}
		//if (!isNotInTheListBeg && !isNotInTheListEnd)return;    //nie dodaje dwoch tych samych krawedzi
		////if (isNotInTheListBeg) { vertexList.AddAtEnd(_beginning); }
		////if (isNotInTheListEnd) { vertexList.AddAtEnd(_end); }
		//vertexList.AddAtEnd(_beginning);
		//vertexList.AddAtEnd(_end);
	}

	void InsertVertex(Vertex* _vertex)
	{
		bool isNotInTheList = true;
		//for (Node<Vertex>* _start = vertexList.First(); _start != vertexList.GetTrailer(); _start = _start->GetNext())
		//{
		//	//std::cout << _start->GetName() << std::endl;
		//	if (_vertex->GetName().compare(_start->GetName()) == 0) isNotInTheList = false;
		//}
		//if (isNotInTheList) vertexList.AddAtEnd(_vertex);
	}

	List<Edge> GetEdgeList() const { return edgeList; };
	//List<Vertex> GetVertexList() const { return vertexList; };
	List<Incident> GetIncidentList() const { return incidentList; };

	const int& Edges() { return edgeList.Size(); };
	//const int& Vertices() { return vertexList.Size(); };
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
		//std::cout << _vertexBeg->GetIncident()->GetEdge()<<std::endl;
		//std::cout << _vertexEnd->GetIncident()->GetEdge();
		if (_vertexBeg->GetIncident() == nullptr || _vertexEnd->GetIncident() == nullptr || _vertexBeg == _vertexEnd) return false;
		//else if (_vertexBeg->GetIncident()->GetEdge() == _vertexEnd->GetIncident()->GetEdge()) return true;
		else if (_vertexBeg->GetIncident()->GetEdge()->GetEndInc()->GetName().compare(_vertexEnd->GetIncident()->GetEdge()->GetBegInc()->GetName()) == 0) return true;
		else if (_vertexBeg->GetIncident()->GetEdge()->GetBegInc()->GetName().compare(_vertexEnd->GetIncident()->GetEdge()->GetEndInc()->GetName()) == 0) return true;
		//else if (_vertexBeg->GetIncident()->GetEdge()->GetEndInc() == _vertexEnd->GetIncident()->GetEdge()->GetBegInc()) return true;
		//else if (_vertexBeg->GetIncident()->GetEdge()->GetBegInc() == _vertexEnd->GetIncident()) return true;

		//else if (_vertexEnd->GetIncident() == nullptr) return false;
		//else if (_vertexEnd->GetIncident()->GetEdge()->GetBeginning() == _vertexBeg) return true;
		//else if (_vertexEnd->GetIncident()->GetEdge()->GetEnd() == _vertexBeg) return true;

		else if (_vertexBeg->GetIncident()->GetEdge() == _vertexEnd->GetIncident()->GetEdge()) return true; //dla pierwszego elementu
		else return false;
	}

	Vertex* operator[] (int _number)
	{
		/*int n = 0;
		if (_number > Vertices()) return nullptr;
		for (Node<Vertex>* _start = vertexList.First(); _start != vertexList.GetTrailer(); _start = _start->GetNext())
		{
			if (n++ == _number) return _start;
		}*/

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
			std::cout <<_start->GetBeginning()->GetName() << " ";
			std::cout <<"E" << _start->GetValue() << " ";
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