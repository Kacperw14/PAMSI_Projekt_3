#include <iostream>
//#include"../Headers/Graph.h"  //!!!
#include "../Headers/Edge.h"
#include "../Headers/Node.h"

using namespace std;
int main()
{
    //Graph G;
    Vertex* V1 = new Vertex("a");
    Vertex* V2 = new Vertex("b");
    Edge E1(V1,V2,5);
    Edge E2(V1,V2,4);
    Edge E3(V1,V2,6);
    Node<Edge> Ne(&E1, &E2, &E3);
    //Node<Edge> Ne(&E,&E);
    //Ve = E;
    //cout << Ne;
    cout << Ne.GetPrevious()->GetValue();
    //Incident I(&E);
    ////Incident I2(E);
    //List<Edge> L;
    //L.AddAtEnd(new Edge(1));
    //L.AddAtEnd(new Edge(2));
    //L.AddAtEnd(new Edge(3));
    //L.AddAtEnd(&E);

   //cout << E.GetEnd()->GetIncident()->GetEdge()->GetEnd()->GetName()<< endl;
    //I.GetEdge();
    //L.AddAtEnd(&I2);
    

} //main

