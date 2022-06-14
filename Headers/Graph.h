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

	int Edges() { return edgeList.Size(); };
	int Vertices() { return vertexList.Size(); };

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
		Edge* min = edgeList.Last();
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

	int MinMaxWithAlphaBeta(std::string* s, int _size, int _row, int _column)
	{
		Graph graph;
		//Create(s, &graph, _size, _row, _column);
		Create(s, this, _size, _row, _column);

		//edgeList.First()

		return 1;
	}

	void Create(std::string* s, Graph* _G, int _size, int _row, int _column) {
		while (s[_row][_column] != 'x')
		{
			if (_row == 0 && _column == 0)
			{

				s[_row][_column] = 'x';
				//_G->InsertVertex(new Vertex(std::to_string(10 * (_row + 1) + _column + 1)));
				_G->InsertEdge(new Vertex(std::to_string(10 * (_row + 1) + _column + 1)),
					new Vertex(std::to_string(10 * (_row + 1) + _column + 2)), _G->Power(s, _row, _column, _size));//new Edge(10 * (_row + 1) + _column + 1));//_G->Power(s,_row,_column,_size));
				
				_column++;
			}
			else
			{
				if (_column < _size - 1)
				{
					s[_row][_column] = 'x';
					_G->InsertEdge(_G->GetVertexList().Last(),
						new Vertex(std::to_string(10 * (_row + 1) + _column + 2)), _G->Power(s, _row, _column + 1, _size));//new Edge(10 * (_row + 1) + _column + 1));//_G->Power(s,_row,_column,_size));
					_column++;
				}
				else
				{
					if (_row < _size - 1)
					{
						s[_row][_column] = 'x';
						//cout << (10 * (_row + 1) + _column + 1) << endl;
						_G->InsertEdge(_G->GetVertexList().Last(),
							new Vertex(std::to_string(10 * (_row + 2) + 1)), _G->Power(s, _row + 1, 0, _size));//new Edge(10 * (_row + 1) + _column + 1));//_G->Power(s,_row,_column,_size));

						_column = 0;
						_row++;
					}
					else
					{
						s[_row][_column] = 'x';
						_column = 0;
						_row = 0;
					}
				}
			}
				for (int i = 0; i < _size - 1; i++)
				{
					std::cout << "_";
					for (int j = 0; j < _size - 1; j++)
					{
						std::cout << s[i][j] << "_|_";
					}
					std::cout << s[i][_size - 1] << "_" << std::endl;
				}
				std::cout << " ";
				for (int j = 0; j < _size - 1; j++)
				{
					std::cout << s[_size - 1][j] << " | ";
				}
				std::cout << s[_size - 1][_size - 1] << std::endl;// << " ";
				std::cout << std::endl;// << " ";

		}
		for (int i = 0; i < _size; i++)	for (int j = 0; j < _size; j++) s[i][j] = (char)' ';
		//system("CLS");
		_row = 0;
		_column = 0;
		while(_column + 1 < _size && _row + 1 < _size)
		{
			Create(s, _G, _size, _row, _column+1);
		}
		//_row = 0;

		//_row = 0;
		//_column = 0;

		return;
	}

	inline static Edge* Power(std::string* _board, int _row, int _column, int _size)      //bez flagi; Srodek nie daje 10
	{
		int power = 0;

		if (_size > 1) //
		{
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
							if (_board[_row + i][_column + j] == 'x')
							{
								if (_row + (2 * i) >= 0 && _row + (2 * i) < _size && _column + (2 * j) >= 0 && _column + (2 * j) < _size)
								{
									if (_board[_row + 2 * i][_column + 2 * j] == 'x') power += 10;
									else power += 1;
								}
								else if (_board[_row + i][_column + j] == 'x') power += 1;
							}
						}
					}
				}
			}
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