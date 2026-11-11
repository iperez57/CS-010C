#include "AVLTree.h"

void AVLTree::insert(const string& data)
{
    //tree is empty
    if (root == nullptr)
    {
        root = new Node(data);
        return;
    }

    //data already exists
    if (search(root, data))
    {
        return;
    }

    Node* curr = root;
    Node* parent = nullptr;

    //find correct parent node
    while (curr != nullptr)
    {
        parent = curr;

        if (data < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    Node* newNode = new Node(data);

    //insert data at correct location
    if (data < parent->data)
    {
        parent->setLeft(newNode);
    }
    else
    {
        parent->setRight(newNode);
    }

    Node* iparent = parent;

    while (iparent != nullptr)
    {
        rotate(iparent);
        iparent = iparent->parent;
    }
}

int AVLTree::balanceFactor(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    return leftHeight - rightHeight;
}


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

int AVLTree::getHeight(Node* node)
{
    if (node == nullptr)
    {
        return -1;
    }

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    return max(leftHeight, rightHeight) + 1;
}