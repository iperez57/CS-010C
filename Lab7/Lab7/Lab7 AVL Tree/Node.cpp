#include "Node.h"

void Node::replaceChild(Node* oldNode, Node* newNode)
{
    if (oldNode == this->left)
    {
        this->left = newNode;
    }
    else if (oldNode == this->right)
    {
        this->right = newNode;
    }
    if (newNode != nullptr)
    {
        new->parent = this;
    }
}