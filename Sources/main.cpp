#include <iostream>
#include"../Headers/Graph.h"

using namespace std;
int main()
{
    Graph G;
    Vertex* V1 = new Vertex("a");
    Vertex* V2 = new Vertex("b");
    Edge E(V1,V2,5);
    //Incident I(&E);
    ////Incident I2(E);
    //List<Edge> L;
    //L.AddAtEnd(new Edge(1));
    //L.AddAtEnd(new Edge(2));
    //L.AddAtEnd(new Edge(3));
    //L.AddAtEnd(&E);

   cout << E.GetEnd()->GetIncident()->GetEdge()->GetEnd()->GetName()<< endl;
    //I.GetEdge();
    //L.AddAtEnd(&I2);
    

} //main

