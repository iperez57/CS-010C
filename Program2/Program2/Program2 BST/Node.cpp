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

void Node::set_leftNode(Node* node)
{
	leftNode = node;
}

void Node::set_rightNode(Node* node)
{
	rightNode = node;
}