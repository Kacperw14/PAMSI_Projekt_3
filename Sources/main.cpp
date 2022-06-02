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
    Node<Edge> Ne1(E1); //= new Node<Edge>(E1);
    Node<Edge> Ne2(E2); //= new Node<Edge>(E2);
    Node<Edge> Ne3(E3);// = new Node<Edge>(E3);
   List<Edge> Le;
   Le.AddAtEnd(&E1);
   Le.AddAtEnd(&E2);

   //Ne1.SetPrevious(&Ne2);
   //Ne2.SetNext(&Ne1);
   //Ne1.SetNext(&Ne3);
   //Ne3.SetPrevious(&Ne1);
   //cout << Ne1.GetNext()->GetPrevious()->GetNext()->GetValue() << endl;
   
   //cout << Le.GetHeader()->GetNext()->GetPrevious()->GetNext()->GetValue() << endl;
   
   //cout << Le.First()->GetNext()->GetPrevious()->GetNext()<<endl;
   cout << Le.Size()<<endl;
   cout << Le.Last()->GetValue()<<endl;  
   
   Le.Remove(Le.Last());
  
   // Le.ClearList();
    //cout << Le.GetHeader()->GetValue()<<endl;
    //cout << Le.GetTrailer()->GetValue()<<endl;
    //cout << Le.First()->GetValue()<<endl;
    cout << Le.Last()->GetValue()<<endl;
   cout << Le.Size()<<endl;

} //main

