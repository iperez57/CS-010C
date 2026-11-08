#include "Tree.h"

void Tree::preOrder() const
{
    preOrder(node);
}

void Tree::preOrder(Tree* node) const
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
    inOrder(node);
}

void Tree::inOrder(Tree* node) const
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
    postOrder(node);
}

void Tree::postOrder(Tree* node) const
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