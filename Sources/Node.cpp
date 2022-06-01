#include"../Headers/Node.h"

template <typename T>
Node<T>::Node()
{
	previous = nullptr;
	next = nullptr;
}

template <typename T>
Node<T>::Node(T* _previous, T* _next)
{
	previous = _previous;
	next = _next;
}

template <typename T>
Node<T>::Node(const Node<T>& newNode)
{
	next = newNode.GetNext();
	previous = newNode.GetPrevious();
}

template <typename T>
T* Node<T>::GetNext() const
{
	if (this == nullptr) throw nullptr; //std::cout << "Funkcja \"GetNext:\": otrzymala nullptr" << std::endl;
	else return next;
}

template <typename T>
T* Node<T>::GetPrevious() const
{
	if (this == nullptr) throw nullptr; //std::cout << "Funkcja \"GetPrevious:\": otrzymala nullptr" << std::endl;
	else return previous;
}

template <typename T>
void Node<T>::SetNext(T* newNode)
{
	if (this == nullptr)  std::cout << "Funkcja \"SetNext:\": otrzymala nullptr" << std::endl;
	else next = newNode;
}

template <typename T>
void Node<T>::SetPrevious(T* newNode)
{
	if (this == nullptr)  std::cout << "Funkcja \"SetPrevious:\": otrzymala nullptr" << std::endl;
	else previous = newNode;
}

template
class  Node<Edge>;

