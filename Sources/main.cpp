#include <iostream>
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
	int number = 2;
	string s = "         ";
	int cell = 0;
	int n = 0, iter = 0;
	//cin >> number


		

	for (int i = 0; i < number; i++)
	{
		//G.InsertVertex(new Vertex(to_string(i+1)));
		//iter++;
		G.InsertEdge(new Vertex(to_string(i+1)), new Vertex(to_string(10 * (i + 1) + i+1)), new Edge(i+1));

		for (int j = 0; j < number-1; j++)
		{
			G.InsertEdge(new Vertex(to_string(10 * (i + 1) + i + 1)), new Vertex(to_string(100*(i+1) + 10*(i+1)+j+1)), new Edge(10 * (i + 1)+ i+1));
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
	cout << G[0]->GetIncident()->GetEdge()->GetBegInc()->GetName()<< endl;
	//cout << G[1]->GetIncident()->GetEdge()->GetEndInc()->GetName()<< endl;
	//cout << G.GetVertexList().First()->GetIncident()<< endl;
	//cout << G[2]->GetIncident()<< endl;
	cout << G.AreAdjacent(G[0], G[1]);
	/*
	cout <<
		"_ _|_ _|_ _" << endl <<
		"_ _|_ _|_ _" << endl <<
		"   |   |   " << endl;

	for (int i = 0; i < 9; i++)
	{

		do
		{
			//cin.clear();
			//cell = cin.get();
			cin >> cell;
		} while (s[cell] != ' ');


		if (n++ % 2) s[cell] = 'x';
		else s[cell] = 'o';
		system("CLS");
		cout <<
			"_" << s[1] << "_|_" << s[2] << "_|_" << s[3] << "_" << endl <<
			"_" << s[4] << "_|_" << s[5] << "_|_" << s[6] << "_" << endl <<
			" " << s[7] << " | " << s[8] << " | " << s[9] << " " << endl;

	}
	*/
	

} //main

