#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string data;
    Node* left;
    Node* right;
    Node* parent;
    Node(string data = 0, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr) : data(data), parent(parent), left(left), right(right) {}

    void replaceChild(Node*, Node*);
    void setLeft(Node*);
    void setRight(Node*);
};
#endif