#pragma once
#include "Node.h"
//#include "Edge.h"
//#include "Vertex.h"
//Mozliwosc rozszerzenia struktury o nowe wezly dwukietrunkowe (template)

template <typename T>
class List 
{
private:
	Node<T>* header;
	Node<T>* trailer;

public:
	//Konstruktory
	List();
	//Konstruktor kopiujacy
	List(const List<T>& _lista) : header(_lista.header), trailer(_lista.trailer) {};

	//void operator+ (List<T>* _lista);
	
	// Podstaowe funkcje dla priorytetowej listy dwukierunkowej:
	const bool IsEmpty() const;
	int Size() const;
	Node<T>* Last() { return trailer->GetPrevious(); };
	Node<T>* First() { return header->GetNext(); };
	
	//Metody dodajace
	void AddAtEnd(T* _node);
	//

	//Metody usuwajace
	void Remove(Node<T>* _node);
	void ClearList();
	//

	//Dodatkowe przydatne metody

	//

	//Metody umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const Node<T>* GetHeader() const { return header; };
	const Node<T>* GetTrailer() const { return trailer; };
	//
}; //CLASS

