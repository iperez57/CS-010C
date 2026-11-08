#include "Tree.h"

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