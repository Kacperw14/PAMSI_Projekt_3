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



int main()
{

	Graph* G = new Graph();
	int row = 0;
	int column = 0;
	int n = 0, iter = 0;
	int size = 3; //////////////!!!

	//do cin >> size;
	//while (size < 3);
	string* s = new string[size];

	for (int i = 0; i < size; i++)	for (int j = 0; j < size; j++) s[i][j] = (char)' ';

	//G->Create(s, G, size, row, column);
	G->MinMaxWithAlphaBeta(s, size, row, column);
	cout << "koniec" << endl;

	//cout << G->GetVertexList().First()->GetFirstIncident()->GetEdge()->GetValue() << endl;
	//cout << G->GetVertexList().First()->GetNext()->GetNext()->GetFirstIncident()->GetEdge()->GetValue()<< endl;
	//cout << G->Vertices() << endl;
	//cout << G->GetVertexList().First()->GetEndIncident() << endl;
	//G->InsertEdge(G->GetVertexList().First(), new Vertex("lol"), new Edge(100));
	//cout << G->IncidentEdges(G->GetVertexList().First())->First()->GetNext()->GetValue()<< endl;
	//cout<< G->AreAdjacent(G->GetVertexList().First(), G->GetVertexList().Last())<<endl;

	G->Print();

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
