#include <iostream>
#include "../Headers/Graph.h"

using namespace std;
int main()
{
    Graph G;
    Vertex* V1 = new Vertex("a");
    Vertex* V2 = new Vertex("b");
    Vertex* V3 = new Vertex("c");
    Edge E1(V1,V2,4);
    //Edge E2(V1,V2,5);
    //Edge E3(V1,V2,6);
    G.InsertEdge(V1,V2, &E1);
    G.InsertVertex(V3);
    //cout << G.GetVertexList().First().;
    cout << G.GetVertexList().Size()<<endl;
    cout << G.GetIncidentList().Size()<<endl;
    cout << G.GetEdgeList().Size()<<endl;
    //cout << Li.Size() << endl << Li.Last()->GetName();
} //main

