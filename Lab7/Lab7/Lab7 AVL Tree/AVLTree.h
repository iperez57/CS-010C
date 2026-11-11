#ifndef AVLTREE_H
#define AVLTREE_H

#include "Node.h"

class AVLTree
{
private:
    Node* root = nullptr;

    void rotate(Node*);
    Node* rotateLeft(Node*);
    Node* rotateRight(Node*);
    void printBalanceFactors(Node*);
    int getHeight(Node*);

public:
    void insert(const string&);
    int balanceFactor(Node*);
    void printBalanceFactors();
    bool search(Node*, const string&) const;
};

#endif