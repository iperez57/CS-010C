#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

class Tree {
private:
    Node* root;

public:
    Tree();
    ~Tree();
    void insert(const string&);
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    void remove(const string&);
    bool search(const string&) const;

private:
    // Add additional functions/variables here
    void preOrder(Tree* subtree) const;
    void inOrder(Tree* subtree) const;
    void postOrder(Tree* subtree) const;
    void destroyTree(Node* root);
};

#endif