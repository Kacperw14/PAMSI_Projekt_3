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
    Vertex* V1 = new Vertex("a");
    Vertex* V2 = new Vertex("b");
    Vertex* V3 = new Vertex("c");
    Edge E1(V1,V2,4);
    
    //Edge E2(V1,V2,5);
    //Edge E3(V1,V2,6);
    G.InsertVertex(V1);
    G.InsertEdge(V1,V2, &E1);
    //cout << G.GetVertexList().Size();
    //cout << G.GetVertexList().First()->GetNext()->GetNext()->GetIncident()->GetEdge()->GetValue();
    cout << G.AreAdjacent(V2, V1);
    
   // cout << G.GetIncidentList().Size() << endl;
   // cout << G.GetIncidentList().First()->GetNext()->GetNext()->GetNext()->GetName();
    //cout << Li.Size() << endl << Li.Last()->GetName();
} //main

