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
	int count = 1;
	Node* leftNode = nullptr;
	Node* rightNode = nullptr;
public:
	Node();
	void set_leftNode();
	void set_rightNode();
};

#endif