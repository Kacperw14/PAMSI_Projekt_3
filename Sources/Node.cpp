#include"../Headers/Node.h"

Node::Node()
{
	previous = nullptr;
	next = nullptr;
}

Node::Node(Node* _previous, Node* _next)
{
	previous = _previous;
	next = _next;
}

Node::Node(const Node& newNode)
{
	next = newNode.GetNext();
	previous = newNode.GetPrevious();
}

Node* Node::GetNext() const
{
	if (this == nullptr) throw nullptr; //std::cout << "Funkcja \"GetNext:\": otrzymala nullptr" << std::endl;
	else return next;
}

Node* Node::GetPrevious() const
{
	if (this == nullptr) throw nullptr; //std::cout << "Funkcja \"GetPrevious:\": otrzymala nullptr" << std::endl;
	else return previous;
}

void Node::SetNext(Node* newNode)
{
	if (this == nullptr)  std::cout << "Funkcja \"SetNext:\": otrzymala nullptr" << std::endl;
	else next = newNode;
}
void Node::SetPrevious(Node* newNode)
{
	if (this == nullptr)  std::cout << "Funkcja \"SetPrevious:\": otrzymala nullptr" << std::endl;
	else previous = newNode;
}




