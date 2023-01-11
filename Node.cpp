#include "List.h"

List::Node::Node() :value(0)
{
	next = nullptr;
}

List::Node::Node(int myValue)
{
	value = myValue;
	next = nullptr;
}

List::Node::~Node()
{

}


