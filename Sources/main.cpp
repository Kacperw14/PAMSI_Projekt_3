#include <iostream>
//#include"../Headers/Graph.h"  //!!!
//#include "../Headers/Edge.h"
//#include "../Headers/Node.h"
#include "../Headers/List.h"
using namespace std;
int main()
{
    //Graph G;
    Vertex* V1 = new Vertex("a");
    Vertex* V2 = new Vertex("b");
    Edge E1(V1,V2,5);
    Edge E2(V1,V2,4);
    Edge E3(V1,V2,6);
    Node<Edge> Ne1(E1);
    Node<Edge> Ne2(E2);
   List<Edge> Le;
   Le.AddAtEnd(&E1);
   Le.AddAtEnd(&E2);

    cout << Le.Last()->GetValue();
    //cout << Ne.GetPrevious()->GetValue();
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

