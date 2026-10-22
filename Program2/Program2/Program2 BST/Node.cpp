//Node.cpp

#include "Node.h"

Node::Node()
{
	data = "";
	count = 1;
	leftNode = nullptr;
	rightNode = nullptr;
}

Node::Node(const string& value)
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

void Node::set_data(const string &dataa)
{
	data = dataa;
}

int Node::get_count()
{
	return count;
}

string Node::get_data()
{
	return data;
}

Node* Node::get_leftNode()
{
	return leftNode;
}

Node* Node::get_rightNode()
{
	return rightNode;
}

void Node::increaseCounter()
{
	count++;
}