#include <iostream>
#include <cmath>
#include "../Headers/Algorithms.h"
//#include "../Headers/Graph.h"

using namespace std; //////////////!!


	//Egzamin PTM
  /*
  uint8_t DDRA = 0x0f;
	uint8_t PORTA = 0xff, h1, PINA, buf;
	PINA = 0b00110000;
	h1 = 0xA5;
	buf = (PINA << 0);
	h1 = (h1 << 1) | ( buf >> 7);
	cout << (int)h1;
	cin >> DDRA;
	*/
/*
void Create(string* s, Graph* _G, int _size, int _row, int _column) {
	while (s[_row][_column] != 'x')//(_row < _size-1 || _column < _size-1)
	{
		if (_row == 0 && _column == 0)
		{
			s[_row][_column] = 'x';

			//_G->InsertVertex(new Vertex(std::to_string(10 * (_row + 1) + _column + 1)));
			_G->InsertEdge(new Vertex(std::to_string(10 * (_row + 1) + _column + 1)),
				new Vertex(std::to_string(10 * (_row + 1) + _column + 2)), new Edge(10 * (_row + 1) + _column + 1));//_G->Power(s,_row,_column,_size));
			_column++;
		}
		else
		{
			if (_column < _size - 1)
			{
				s[_row][_column] = 'x';

				_G->InsertEdge(_G->GetVertexList().Last(),
					new Vertex(std::to_string(10 * (_row + 1) + _column + 2)), new Edge(10 * (_row + 1) + _column + 1));//_G->Power(s,_row,_column,_size));
				_column++;
			}
			else
			{
				if (_row < _size - 1)
				{
					s[_row][_column] = 'x';
					//cout << (10 * (_row + 1) + _column + 1) << endl;
					_G->InsertEdge(_G->GetVertexList().Last(),
						new Vertex(std::to_string(10 * (_row + 2) + 1)), new Edge(10 * (_row + 1) + _column + 1));//_G->Power(s,_row,_column,_size));

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
			cout << "_";
			for (int j = 0; j < _size - 1; j++)
			{
				cout << s[i][j] << "_|_";
			}
			cout << s[i][_size - 1] << "_" << endl;
		}
		cout << " ";
		for (int j = 0; j < _size - 1; j++)
		{
			cout << s[_size - 1][j] << " | ";
		}
		cout << s[_size - 1][_size - 1] << endl;// << " ";
		cout << endl;// << " ";
	}

	for (int i = 0; i < _size; i++)	for (int j = 0; j < _size; j++) s[i][j] = (char)' ';
	//system("CLS");
		if (_column + 1 < _size)
		{
			Create(s, _G, _size, _row, _column + 1);
			if (_row + 1 < _size)
			{
				_column = 0;
				Create(s, _G, _size, _row + 1, _column);
			}
		}
	return;
}
*/

int main()
{

	Graph G;
	Algorithms A;
	Vertex* V1 = new Vertex("1");
	Vertex* V2 = new Vertex("2");
	Vertex* V3 = new Vertex("3");
	Vertex* V4 = new Vertex("4");
	Vertex* V5 = new Vertex("5");
	G.InsertEdge(V1, V2, new Edge(1));
	G.InsertEdge(V1, V3, new Edge(6));
	G.InsertEdge(V1, V4, new Edge(7));
	G.InsertEdge(V1, V5, new Edge(5));
	G.InsertEdge(V2, V3, new Edge(2));
	G.InsertEdge(V3, V4, new Edge(3));
	G.InsertEdge(V3, V5, new Edge(8));
	G.InsertEdge(V4, V5, new Edge(4));

	//cout << G.Edges()<<endl;
	//cout << G.MinEdge()<<endl;

	G.Print();
	cout << endl;
	A.Kruskal(G)->Print();
	cout << endl;
	G.Print();

	//A.Kruskal(&G)->Print();
} //main
