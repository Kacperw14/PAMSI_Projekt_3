#include <iostream>
#include "../Headers/Graph.h"

using namespace std;
int main()
{
    Graph G;
    Vertex* V1 = new Vertex("a");
    Vertex* V2 = new Vertex("b");
    Edge E1(V1,V2,4);
    Edge E2(V1,V2,5);
    Edge E3(V1,V2,6);
    Node<Edge> Ne1(E1);
    Node<Edge> Ne2(E2); 
    Node<Edge> Ne3(E3);
    
    G.InsertEdge(&E1);
    G.InsertEdge(&E2);
    G.InsertEdge(&E3);
    
    cout << G.GetEdgeList().First()->GetValue();

} //main

