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
	//void Remove(T* _node);
	void ClearList();

	Node<T>* AtIndex(const int& _index)
	{
		int number = 1;
		for (Node<T>* i = First(); i != GetTrailer(); i = i->GetNext())
		{
			if (number++ == _index) return i;
			//number++;
		}
		throw "Brak elementu o podanym indeksie";
	}

	int IndexOf(Node<T>* _node)
	{
		int number = 0;
		//T* element;
		for (Node<T>* i = First(); i != GetTrailer(); i = i->GetNext())
		{
			/*element = i;
			std::cout <<"i" << i << std::endl;
			std::cout <<"e" << (T*<< std::endl;
			std::cout << _node << std::endl;*/
			//std::cout << static_cast<Node<T>*>(_node) << std::endl;
			
			number++;
			if (i == _node) return number;
		}
		throw "Brak elementu w liscie";
	}
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

