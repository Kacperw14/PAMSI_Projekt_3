﻿#include <iostream>
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
	int number = 0;
	string s = "         ";
	int cell = 0;
	int n = 0;
	//cin >> number;


	for (int i = 0; i < 9; i++)
	{
		//G.InsertEdge(new Vertex(to_string(i)), new Vertex(to_string(i + 1)), new Edge());
	}
	Vertex* V1 = new Vertex(to_string(1));
	Vertex* V2 = new Vertex(to_string(2));
	Vertex* V3 = new Vertex(to_string(3));
	Vertex* V4 = new Vertex(to_string(4));
	Edge* E1= new Edge(1);
	Edge* E2= new Edge(2);
	G.InsertEdge(V1, V2, E1);
	G.InsertEdge(V1, V3, E1);
	G.InsertEdge(V3, V4, E1);

	//G.InsertEdge(V1, V4, E1);
	//G.InsertEdge(V1, V2, E1);

	//cout << G.AreAdjacent(G[0],G[1]);
	//cout << G[2]->GetName();
	//cout << G[1]->GetIncident()->GetEdge()->GetEnd()->GetName();
	
	//cout<<G.Edges()<<endl;
	G.Print();
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

