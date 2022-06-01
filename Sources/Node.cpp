#include"../Headers/Node.h"

template <typename T>
Node<T>::Node()
{
	previous = nullptr;
	next = nullptr;
}

template <typename T>
Node<T>::Node(Node<T>* _previous, Node<T>* _next)
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
Node<T>* Node<T>::GetNext() const
{
	if (this == nullptr) throw nullptr; //std::cout << "Funkcja \"GetNext:\": otrzymala nullptr" << std::endl;
	else return next;
}

template <typename T>
Node<T>* Node<T>::GetPrevious() const
{
	if (this == nullptr) throw nullptr; //std::cout << "Funkcja \"GetPrevious:\": otrzymala nullptr" << std::endl;
	else return previous;
}

template <typename T>
void Node<T>::SetNext(Node<T>* newNode)
{
	if (this == nullptr)  std::cout << "Funkcja \"SetNext:\": otrzymala nullptr" << std::endl;
	else next = newNode;
}

template <typename T>
void Node<T>::SetPrevious(Node<T>* newNode)
{
	if (this == nullptr)  std::cout << "Funkcja \"SetPrevious:\": otrzymala nullptr" << std::endl;
	else previous = newNode;
}




