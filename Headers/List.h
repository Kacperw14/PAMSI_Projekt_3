#pragma once
#include "Node.h"
#include "Edge.h"
#include "Vertex.h"
//Mozliwosc rozszerzenia struktury o nowe wezly dwukietrunkowe (template)

template <class T>
class List 
{
private:
	T* header;
	T* trailer;

public:
	//Konstruktory
	List();
	//Konstruktor kopiujacy
	//List(const List<T>& _lista)
	//{
	//	//T* node = nullptr;
	//	for (T* i = First(); i != trailer; i = i->GetNext())
	//	{
	//		//node = new T(i);
	//		_lista.AddAtEnd(*i);
	//	}
	//}
	//: header(_lista.GetHeader()), trailer(_lista.GetTrailer()) {}; //??

	//void operator+ (List<T>* _lista);
	
	// Podstaowe funkcje dla priorytetowej listy dwukierunkowej:
	const bool IsEmpty() const;
	int Size() const;
	T* Last() const { return trailer->GetPrevious(); };
	T* First() const { return header->GetNext(); };
	
	//Metody dodajace
	void AddAtEnd(T* _node);
	//
	//void AddAtEnd(const T& _node)  //
	//{
	//	T* _tNode = new T(Last(), trailer);
	//	//_node->SetNext(trailer);
	//	//_node->SetPrevious(Last());
	//	Last()->SetNext(_tNode);
	//	trailer->SetPrevious(_tNode);
	//}
	//Metody usuwajace
	void Remove(T* _node);
	void ClearList();

	//Dodatkowe przydatne metody
	T* operator[](int _index)
	{
		return AtIndex(_index);
	};

	T* AtIndex(int _index)
	{
		int number = 0;
		for (T* i = First(); i != trailer; i = i->GetNext())
		{
			if (number++ == _index) return i;
			//number++;
		}
		throw "Brak elementu o podanym indeksie";
	}

	int IndexOf(T* _node)
	{
		int number = 0;
		//T* element;
		for (T* i = First(); i != GetTrailer(); i = i->GetNext())
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

	/*Edge* MinEdge()
	{
		Edge* min = First();
		for (Edge* i = First(); i != GetTrailer(); i = i->GetNext())
		{
			if (min->GetValue() > i->GetValue()) min = i;
		}
		return min;
	}*/

	//Metody umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const T* GetHeader() const { return header; };
	const T* GetTrailer() const { return trailer; };
	//
}; //CLASS

