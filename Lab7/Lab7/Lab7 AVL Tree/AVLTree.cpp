#include "AVLTree.h"

bool AVLTree::search(Node* curr, const string& data) const
{
    if (curr == nullptr)
    {
        return false;
    }

    if (data == curr->data)
    {
        return true;
    }
    else if (data < curr->data)
    {
        return search(curr->left, data);
    }
    else
    {
        return search(curr->right, data);
    }
}