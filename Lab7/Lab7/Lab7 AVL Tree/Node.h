#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node {
public:
    string data;
    Node* left;
    Node* right;
    Node* parent;
    Node(string data = 0, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr) : data(data), parent(parent), left(left), right(right) {}
};
#endif