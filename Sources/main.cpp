#include <iostream>
#include <cmath>
#include "../Headers/Graph.h"

using namespace std;
int main()
{

	//Egzamin PTM
  /*  uint8_t DDRA = 0x0f;
	uint8_t PORTA = 0xff, h1, PINA, buf;
	PINA = 0b00110000;
	h1 = 0xA5;
	buf = (PINA << 0);
	h1 = (h1 << 1) | ( buf >> 7);
	cout << (int)h1;
	*/
	Graph G;
	int size = 3;
	int number = 4;
	//string s = "         ";
	string* s = new string[size];
	for (int i = 0; i < size; i++)	s[i] = string("   ");
	int row = 0;
	int column = 0;
	int n = 0, iter = 0;
	//cin >> number




	for (int i = 0; i < number; i++)
	{
		//G.InsertVertex(new Vertex(to_string(i+1)));
		//iter++;
		G.InsertEdge(new Vertex(to_string(i + 1)), new Vertex(to_string(10 * (i + 1) + i + 1)), new Edge(i + 1));

		for (int j = 0; j < number - 1; j++)
		{
			G.InsertEdge(new Vertex(to_string(10 * (i + 1) + i + 1)), new Vertex(to_string(100 * (i + 1) + 10 * (i + 1) + j + 1)), new Edge(10 * (i + 1) + i + 1));
			//for (int k = 0; k < number-1; k++)
			//{
			//	G.InsertEdge(G[iter++], new Vertex(to_string(100 * (i + 1) + (10*(j+1))+k+1)), new Edge(100 * (i + 1) + 10 * j + k));
			//	//cout << iter++ <<endl;
			//}
		}
		//G.InsertEdge(new Vertex(to_string(i)), new Vertex(to_string(i + 1)), new Edge());
	}
	G.Print();
	//cout << G.Vertices()<< endl;
	cout << endl;
	cout << G[0]->GetIncident()->GetEdge()->GetBegInc()->GetName() << endl;
	//cout << G[1]->GetIncident()->GetEdge()->GetEndInc()->GetName()<< endl;
	//cout << G.GetVertexList().First()->GetIncident()<< endl;
	//cout << G[2]->GetIncident()<< endl;
	cout << G.AreAdjacent(G[0], G[1]);

	cout << endl <<
		"_ _|_ _|_ _" << endl <<
		"_ _|_ _|_ _" << endl <<
		"   |   |   " << endl;

	for (int i = 0; i < 9; i++)
	{

		do
		{
			cin >> row;
			cin >> column;
			if (!cin.good())
			{
				cin.clear();
				//cin.unget();
				cin.ignore(100, '\n');
				cout << "bad" << endl;
				row = 1000;  //zamkniecie petli
			}
		} while (row >= size || column >= size || s[row][column] != ' ');

		if (n++ % 2) s[row][column] = 'x';
		else s[row][column] = 'x';             //o!!!!
		system("CLS");
		cout <<
			"_" << s[0][0] << "_|_" << s[0][1] << "_|_" << s[0][2] << "_" << endl <<
			"_" << s[1][0] << "_|_" << s[1][1] << "_|_" << s[1][2] << "_" << endl <<
			" " << s[2][0] << " | " << s[2][1] << " | " << s[2][2] << " " << endl;
		
		Graph* G1 = new Graph();
		//G1->Power(s, row, column);
		cout << endl << endl << G1->Power(s, row, column)->GetValue() << endl;
	}



} //main

