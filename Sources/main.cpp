#include <iostream>
#include <cmath>
#include "../Headers/Graph.h"

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

void Create(string* s, Graph* _G, int _size, int _row, int _column) {

	//int i = 0;
	while (_row < _size-1 || _column < _size-1)
	{

		s[_row][_column] = 'x';
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


		//if (_row < (_size - 1) || _column < (_size - 1))
		//{
			if (_column < _size - 1)
			{
				//if (_column == 0 && _row > 0)     // czy przeskoczyl do nastepnego wiersza
				//{
				//	//cout << ((10 * _row) + _size) << endl;
				//	//cout << (10 * (_row + 1) + _column + 1) << endl;
				//	_G->InsertEdge(new Vertex(std::to_string(10 * (_row)+_size)),
				//		new Vertex(std::to_string(10 * (_row + 1) + _column + 1)), new Edge(10 * (_row)+_size));//_G->Power(s,_row,_column,_size));
				//}
				//else
				//{
					//cout << (10 * (_row + 1) + _column + 1) << endl;
					_G->InsertEdge(new Vertex(std::to_string(10 * (_row + 1) + _column + 1)),
						new Vertex(std::to_string(10 * (_row + 1) + _column + 2)), new Edge(10 * (_row + 1) + _column + 1));//_G->Power(s,_row,_column,_size));
				//}

				_column++;
			}
			else
			{

				//cout << (10 * (_row + 1) + _column + 1) << endl;
				_G->InsertEdge(new Vertex(std::to_string(10 * (_row + 1) + _size)),
					new Vertex(std::to_string(10 * (_row + 2) + 1)), new Edge(10 * (_row + 1) + _column + 1));//_G->Power(s,_row,_column,_size));

				_column = 0;
				_row++;
				//s[_row][_column] = 'x';
			}

			//_row++;
		//}

		//_G->InsertEdge(new Vertex(std::to_string(10 * (_row)+_column + 1)),
			//new Vertex(std::to_string(10 * (_size)+_column + 1)), new Edge(10 * (_size)+_column + 1));//_G->Power(s,_row,_column,_size));

		//_G->InsertEdge(new Vertex(std::to_string(10 * _row + _column)),
			//new Vertex(std::to_string(10*(_row+=1) + _column)), new Edge(i++));

		//if(_row < _size) 
		//
		//Create(s, _G, _size, _row, ++_column);
		//if(-1) Create(_G, _size, _row, _column+1);

		//if () return;

		//cout << _row << _column << endl;


		/// <summary>

		//if (_row < _size)
		//{
		//	if (_column < _size - 1) Create(s, _G, _size, _row, ++_column);
		//	//else
		////{
		//	_column = 0;
		//	_row++;
		//	//Create(s, _G, _size, ++_row, _column);
		////}
		//	//_row = 0;
		//	//system("CLS");
		//}
		//s = new string(_size, 0);
	}

	return;
}

int main()
{

	Graph* G = new Graph();
	int row = 0;
	int column = 0;
	int n = 0, iter = 0;
	int size = 2; //////////////!!!

	//do cin >> size;
	//while (size < 3);
	string* s = new string[size];

	for (int i = 0; i < size; i++)	for (int j = 0; j < size; j++) s[i][j] = (char)' ';

	

	Create(s, G, size, row, column);
	G->Print();
	cout << "koniec" << endl;
	//cout << G->Vertices()<<endl;
	//for (int i = 0; i < size; i++)
	//{
	//	//G.InsertVertex(new Vertex(to_string(i+1)));
	//	//iter++;
	//	//G.InsertEdge(new Vertex(to_string(i + 1)), new Vertex(to_string(10 * (i + 1) + i + 1)), G.Power(s,i,i,size));
	//	G.InsertEdge(new Vertex(to_string(i + 1)), new Vertex(to_string(10 * (i + 1) + i + 1)), new Edge(i));

	//	for (int j = 0; j < size - 1; j++)
	//	{
	//		G.InsertEdge(new Vertex(to_string(10 * (i + 1) + i + 1)), new Vertex(to_string(100 * (i + 1) + 10 * (i + 1) + j + 1)), new Edge(10 * (i + 1) + i + 1));
	//		//for (int k = 0; k < number-1; k++)
	//		//{
	//		//	G.InsertEdge(G[iter++], new Vertex(to_string(100 * (i + 1) + (10*(j+1))+k+1)), new Edge(100 * (i + 1) + 10 * j + k));
	//		//	//cout << iter++ <<endl;
	//		//}
	//	}
	//	//G.InsertEdge(new Vertex(to_string(i)), new Vertex(to_string(i + 1)), new Edge());
	//}


	//cout << G.Vertices()<< endl;
	//cout << endl;
	//cout << G[0]->GetIncident()->GetEdge()->GetBegInc()->GetName() << endl;
	//cout << G[1]->GetIncident()->GetEdge()->GetEndInc()->GetName()<< endl;
	//cout << G.GetVertexList().First()->GetIncident()<< endl;
	//cout << G[2]->GetIncident()<< endl;
	//cout << G.AreAdjacent(G[0], G[1]);

	for (int i = 0; i < size - 1; i++)
	{
		cout << "_";
		for (int j = 0; j < size - 1; j++)
		{
			cout << s[i][j] << "_|_";
		}
		cout << s[i][size - 1] << "_" << endl;
	}
	cout << " ";
	for (int j = 0; j < size - 1; j++)
	{
		cout << s[size - 1][j] << " | ";
	}
	cout << s[size - 1][size - 1] << endl;// << " ";

	for (int i = 0; i < pow(size, 2); i++)
	{
		do
		{
			cin >> row;
			cin >> column;
			if (!cin.good())
			{
				cin.clear();
				//cin.unget();
				cin.ignore(100, ' ');
				//cout << "bad" << endl;
				row = 1000;  //zamkniecie petli
			}
		} while (row >= size || row < 0 || column >= size || column < 0 || s[row][column] != ' ');

		//--row;    //uzytkownik wybiera pola od 1 do size
		//--column;



		if (n++ % 2) s[row][column] = 'x';
		else s[row][column] = 'x';             //o!!!!
		system("CLS");

		for (int i = 0; i < size - 1; i++)
		{
			cout << "_";
			for (int j = 0; j < size - 1; j++)
			{
				cout << s[i][j] << "_|_";
			}
			cout << s[i][size - 1] << "_" << endl;
		}
		cout << " ";
		for (int j = 0; j < size - 1; j++)
		{
			cout << s[size - 1][j] << " | ";
		}
		cout << s[size - 1][size - 1] << endl << " ";


		Graph* G1 = new Graph();
		//G1->Power(s, row, column, size)-;
		cout << endl << endl << G1->Power(s, row, column, size)->GetValue() << endl;
	}



} //main


		/*cout <<
			"_" << s[0][0] << "_|_" << s[0][1] << "_|_" << s[0][2] << "_" << endl <<
			"_" << s[1][0] << "_|_" << s[1][1] << "_|_" << s[1][2] << "_" << endl <<
			" " << s[2][0] << " | " << s[2][1] << " | " << s[2][2] << " " << endl;*/
