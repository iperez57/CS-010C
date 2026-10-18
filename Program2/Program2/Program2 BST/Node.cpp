//Node.cpp

#include "Node.h"

Node::Node()
{
	data = "";
	count = 1;
	leftNode = nullptr;
	rightNode = nullptr;
}

Node::Node(string& value)
{
	data = value;
	count = 1;
	leftNode = nullptr;
	rightNode = nullptr;
}