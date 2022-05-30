#include <iostream>
#include"../Headers/Graph.h"

int main()
{
    Graph G;
    List<Node> L;
    Node* N1 = new Node();
    Node* N3 = new Node();
    Node* N2 = new Node();
    
    Node* D1 = new Node(N1, N2);
    Node* D2 = new Node(N2, N3);

    L.AddAtEnd(N1);
    //L.AddAtEnd(N2);
    //L.AddAtEnd(N3);



} //main

