//Node.h

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
	string data;
	int count;
	Node* leftNode = nullptr;
	Node* rightNode = nullptr;
public:
	Node();
	Node(string& value);
	void set_leftNode(Node* node);
	void set_rightNode(Node* node);
};

#endif