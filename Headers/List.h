#pragma once
#include "Node.h"
//#include "Edge.h"
//#include "Vertex.h"
//Mozliwosc rozszerzenia struktury o nowe wezly dwukietrunkowe (template)

template <class T>
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
	Node<T>* Last() const { return trailer->GetPrevious(); };
	Node<T>* First() const { return header->GetNext(); };
	
	//Metody dodajace
	void AddAtEnd(T* _node);
	//

	//Metody usuwajace
	void Remove(Node<T>* _node);
	void ClearList();
	//

	//Dodatkowe przydatne metody
	Node<T>* operator[](const int& _number)
	{
		int j = 0;
		if (_number > Size()) throw "Index za duzy";
		for (Node<T>* i = First(); i != GetTrailer(); i = i->GetNext())
		{
			if(j++ == _number) return i;
		}
		throw "Nie ma takiego indexu";//nullptr; 
	};
	//

	//Metody umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const Node<T>* GetHeader() const { return header; };
	const Node<T>* GetTrailer() const { return trailer; };
	//
}; //CLASS

