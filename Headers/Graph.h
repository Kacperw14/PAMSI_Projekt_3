#pragma once
#include "List.h"
#include <string>
#include <cmath>

class Graph
{
private:
	List<Edge> edgeList;
	List<Vertex> vertexList;

public:
	Graph() = default;

	//Graph(const Graph& _graph) //: edgeList(_graph.GetEdgeList()), vertexList(_graph.GetVertexList()) {};
	//{
	//	edgeList = List<Edge>(_graph.GetEdgeList());
	//	vertexList = List<Vertex>(_graph.GetVertexList());
	//}
	void InsertEdge(Vertex* _beginning, Vertex* _end, Edge* _edge)
	{
		//brak mozliwosci dolaczenia 
		/*for (Vertex* i = vertexList.First(); i != vertexList.GetTrailer(); i = i->GetNext())
		{
			if (i == _beginning)
			{
				for (int j = 0; j < _beginning->IncidentsSize(); i++)
				{
					Opposite(i, IncidentEdges(_beginning)) == _end;
				}
			}
		}*/
		//if (isInTheListBeg && isInTheListEnd);

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
		for (Vertex* _start = vertexList.First(); _start != vertexList.GetTrailer(); _start = _start->GetNext())
		{
			if (n++ == _number) return _start;
		}
		return nullptr;
	};

	void InsertVertex(Vertex* _vertex)
	{
		for (Vertex* _start = vertexList.First(); _start != vertexList.GetTrailer(); _start = _start->GetNext())
		{
			if (_start == _vertex) return;
		}
		vertexList.AddAtEnd(_vertex);
	}

	List<Edge> GetEdgeList() const { return edgeList; };
	//const List<Edge>& GetEdgeList() const { return edgeList; };
	List<Vertex> GetVertexList() const { return vertexList; };

	const int& Edges() { return edgeList.Size(); };
	const int& Vertices() { return vertexList.Size(); };

	Edge* IncidentEdges(Vertex* _vertex) const
	{

		Edge* tabEdges = new Edge[_vertex->IncidentsSize()];

		//List<Edge*>* L = new List<Edge*>();           //new?
		//Edge** edge = nullptr;
		for (int i = 0; i < _vertex->IncidentsSize(); i++)
		{
			if (_vertex->GetIncident(i)->GetEdge() != nullptr)
			{
				tabEdges[i] = *_vertex->GetIncident(i)->GetEdge();
				//*edge = (_vertex->GetIncident(i)->GetEdge());
				//L->AddAtEnd(edge);  //!! addattheend zmienia next i prev
			}
		}
		//std::cout << L->Size()<<std::endl;

		return tabEdges;
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
		if (_vertexBeg == nullptr || _vertexEnd == nullptr) return false;

		for (int i = 0; i < _vertexBeg->IncidentsSize(); i++)
		{
			for (int j = 0; j < _vertexEnd->IncidentsSize(); j++)
			{
				//std::cout << _vertexBeg->GetIncident(i)->GetEdge()->GetValue() << std::endl;
				//std::cout << _vertexEnd->GetIncident(j)->GetEdge()->GetValue() << std::endl;
				if (_vertexBeg->GetIncident(i)->GetEdge() == _vertexEnd->GetIncident(j)->GetEdge()) return true;
			}
		}
		return false;
	}

	Edge* MinEdge()
	{
		Edge* min = edgeList.First();
		for (Edge* i = edgeList.First(); i != edgeList.GetTrailer(); i = i->GetNext())
		{
			if (min->GetValue() > i->GetValue()) min = i;
		}
		return min;
	}

	void RemoveEdge(Edge* _edge)
	{
		_edge->GetBeginning()->RemoveIncident(_edge->GetBegInc());

		_edge->GetEnd()->RemoveIncident(_edge->GetEndInc());

		edgeList.Remove(_edge);
	}

	void RemoveVertex(Vertex* _vertex)
	{
		while (_vertex->IncidentsSize() > 0)
		{
			RemoveEdge(_vertex->GetFirstIncident()->GetEdge());
		}

		vertexList.Remove(_vertex);
	};

	void Replace(Vertex* _first, Vertex* _second)
	{
		_first->Swap(_second);
	}

	void ReplaceBeginning(Edge* _edge, Vertex* _vertex)
	{
		_edge->GetBeginning()->Swap(_vertex);
	}

	void ReplaceEnd(Edge* _edge, Vertex* _vertex)
	{
		_edge->GetEnd()->Swap(_vertex);
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
		for (Vertex* _start = vertexList.First(); _start != vertexList.GetTrailer(); _start = _start->GetNext())
		{
			std::cout << _start->GetName() << " ";
		}
		std::cout << std::endl;
		for (Edge* _start = edgeList.First(); _start != edgeList.GetTrailer(); _start = _start->GetNext())
		{
			std::cout << _start->GetBeginning()->GetName() << " ";
			std::cout << "E" << _start->GetValue() << " ";
			//std::cout << _start->GetBegInc()->GetName() << " ";
			//std::cout << _start->GetEndInc()->GetName() << " ";
			std::cout << _start->GetEnd()->GetName() << " ";
		}
		std::cout << std::endl;
	}

}; //class