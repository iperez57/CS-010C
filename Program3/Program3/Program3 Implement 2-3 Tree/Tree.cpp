#include "Tree.h"

Tree::Tree()
{
    root = nullptr;
}

Tree::~Tree()
{
    destroyTree(root);
}

void Tree::preOrder() const
{
    preOrder(root);
}

void Tree::preOrder(Node* node) const
{
    if (node == nullptr)
    {
        return;
    }

    cout << node->small;
    preOrder(node->left);

    if (node->large != "")
    {
        cout << node->large;
    }
    preOrder(node->middle);
    preOrder(node->right);
}

void Tree::inOrder() const
{
    inOrder(root);
}

void Tree::inOrder(Node* node) const
{
    if (node == nullptr)
    {
        return;
    }

    inOrder(node->left);
    cout << node->small;
    inOrder(node->middle);
    if (node->large != "")
    {
        cout << node->large;
        inOrder(node->right);
    }
}

void Tree::postOrder() const
{
    postOrder(root);
}

void Tree::postOrder(Node* node) const
{
    if (node == nullptr)
    {
        return;
    }

    postOrder(node->left);
    postOrder(node->middle);
    cout << node->small;
    postOrder(node->right);

    if (node->large != "")
    {
        cout << node->large;
    }
}

void Tree::destroyTree(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    destroyTree(node->left);
    destroyTree(node->middle);
    destroyTree(node->right);

    delete node;
}