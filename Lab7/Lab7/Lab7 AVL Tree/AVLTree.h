#ifndef AVLTREE_H
#define AVLTREE_H

#include "Node.h"

class AVLTree
{
private:
    Node* root = nullptr;

    void insert(const string&);
    int balanceFactor(Node*);
    void printBalanceFactors();
    int getHeight(Node*);

public:
    void rotate(Node*);
    Node* rotateLeft(Node*);
    Node* rotateRight(Node*);
    void printBalanceFactors(Node*);
    bool search(Node*, const string&) const;
};

#endif