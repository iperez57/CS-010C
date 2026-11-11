#include "AVLTree.h"
#include <algorithm>

void AVLTree::rotate(Node* node)
{
    int bF = balanceFactor(node);
    int bFL = balanceFactor(node->left);
    int bFR = balanceFactor(node->right);
    if (bF == 2)
    {
        //left heavy
        if (bFL == -1)
        {
            rotateLeft(node->left);
            rotateRight(node);
        }
        else
        {
            rotateRight(node);
        }
    }
    else if (bF == -2)
    {
        //right heavy
        if (bFR == 1)
        {
            rotateRight(node->right);
            rotateLeft(node);
        }
        else
        {
            rotateLeft(node);
        }
    }
}

Node* AVLTree::rotateLeft(Node* node)
{
    Node* parent = node->parent;
    Node* right = node->right;
    Node* left = node->right->left;

    right->setLeft(node);
    node->setRight(left);

    if (node == root)
    {
        root = right;
        right->parent = nullptr;
    }
    else
    {
        parent->replaceChild(node, right);
    }

    return right;
}

void AVLTree::printBalanceFactors(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    printBalanceFactors(node->left);
    cout << node->data << "(" << balanceFactor(node) << "), ";
    printBalanceFactors(node->right);
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

void AVLTree::printBalanceFactors()
{
    printBalanceFactors(root);
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
