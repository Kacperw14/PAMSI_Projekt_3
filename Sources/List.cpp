#include "../Headers/List.h"


//Konstruktor glowny inicjuje poczatek i koniec tablicy oraz polaczenie miedzy nimi.
template <typename T>
List<T>::List()
{
	header = new Node<T>();
	trailer = new Node<T>();//this, header, nullptr);
	header->SetNext(trailer);
	trailer->SetPrevious(header);
}

//template<typename T>
//void List<T>::operator+(List<T>* _lista)
//{
//	for (T* head = _lista->First(); head != _lista->Last()->GetNext(); head = head->GetNext())
//	{
//		AddAtEnd(head);
//	}
//}

template <typename T>
const bool List<T>::IsEmpty() const
{
	if (header->GetNext() == trailer)
	{
		return true;
	}
	else return false;
}

template <typename T>
int List<T>::Size() const
{
	if (IsEmpty()) return 0;
	else
	{
		int size = 0;
		//Node<T>* head = header->GetNext();	//Nie liczymy header'a, jesli IsEmpty != true to header->GetNext() istnieje.
		//while (head != trailer)
		for (Node<T>* head = header->GetNext(); head != trailer; head = head->GetNext())
		{
			size++;
		}
		return size;
	}
}

template <typename T>
void List<T>::AddAtEnd(T* _node)  //
{	
	Node<T>* _tNode = new Node<T>(_node, trailer->GetPrevious(), trailer);
	trailer->GetPrevious()->SetNext(_tNode);
	trailer->SetPrevious(_tNode);
}

template<typename T>
void List<T>::Remove(Node<T>* _node)
{
	if (_node != nullptr && _node != header && _node != trailer)
	{
		_node->GetNext()->SetPrevious(_node->GetPrevious());	 //Aby nie doszlo do wyciekow pamieci ustalane sa nowe wezly.
		_node->GetPrevious()->SetNext(_node->GetNext());
		delete _node;                                            //Zwolnienie pamieci komputera.
	}
	else std::cout << "Funkcja \"Remove\": Nie mozna usunac nullptr, header ani trailer" << std::endl; //Informacja o nieprawidlowych dzialaniach
}

template<typename T>
void List<T>::ClearList()
{
	while (!IsEmpty())
	{
		Remove(Last());
	}
}


//Przykladowy szablon wezla dwukierunkowego uzyty w projektcie
template
class List<Edge>;

template
class List<Vertex>;

template
class List<Incident>;