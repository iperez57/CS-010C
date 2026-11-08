#include "Tree.h"

Tree::Tree()
{
    root = nullptr;
}

Tree::~Tree()
{
    destroyTree(root);
}

void Tree::insert(const string& data)
{
    if (root == nullptr)
    {
        root = new Node();
        root->small = data;
        return;
    }

    Node* curr = root;

    //travel to leaf node
    while (curr->left != nullptr || curr->middle != nullptr || curr->right != nullptr)
    {
        if (data < curr->small)
        {
            curr = curr->left;
        }
        else if (curr->large == "")
        {
            curr = curr->right;
        }
        else if (data < curr->large)
        {
            curr = curr->middle;
        }
        else
        {
            curr = curr->right;
        }
    }

    //at correct leaf node
    if (curr->small != "" && curr->large != "")
    {
        split(curr, data);
    }
    else
    {
        if (curr->small == "")
        {
            curr->small = data;
        }
        else if (data < curr->small)
        {
            curr->large = curr->small;
            curr->small = data;
        }
        else
        {
            curr->large = data;
        }
    }
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

    cout << node->small << ", ";
    preOrder(node->left);

    if (node->large != "")
    {
        cout << node->large << ", ";
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
    cout << node->small << ", ";
    inOrder(node->middle);
    if (node->large != "")
    {
        cout << node->large << ", ";
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
    cout << node->small << ", ";
    postOrder(node->right);

    if (node->large != "")
    {
        cout << node->large << ", ";
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

void Tree::split(Node* node, const string& data)
{
    Node* parentN = node->parent;

    string min;
    string mid;
    string max;

    if (data < node->small)
    {
        min = data;
        mid = node->small;
        max = node->large;
    }
    else if (data > node->small && data < node->large)
    {
        min = node->small;
        mid = data;
        max = node->large;
    }
    else
    {
        min = node->small;
        mid = node->large;
        max = data;
    }

    //create children and assign values
    Node* leftChild = new Node();
    Node* rightChild = new Node();

    leftChild->small = min;
    rightChild->small = max;

    //split from root
    if (parentN == nullptr)
    {
        Node* newRoot = new Node();
        newRoot->small = mid;

        newRoot->left = leftChild;
        newRoot->right = rightChild;

        leftChild->parent = newRoot;
        rightChild->parent = newRoot;

        root = newRoot;

        delete node;
    }
    //split from left
    else if (parentN->left == node)
    {
        parentN->left = leftChild;
        parentN->middle = rightChild;
        parentN->large = parentN->small;
        parentN->small = mid;

        leftChild->parent = parentN;
        rightChild->parent = parentN;

        delete node;

    }
    //split from right
    else if (parentN->right == node)
    {
        parentN->right = rightChild;
        parentN->middle = leftChild;
        parentN->large = mid;

        leftChild->parent = parentN;
        rightChild->parent = parentN;

        delete node;
    }
}