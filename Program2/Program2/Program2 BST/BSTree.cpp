#include "BSTree.h"
#include "Node.h"

BSTree::BSTree()
{
    root = nullptr;
}

void BSTree::insert(const string& data)
{
    Node* newNode = new Node(data);
    Node* current = root;

    if (root == nullptr)
    {
        root = newNode;
    }
    else
    {
        while (current != nullptr)
        {
            if (newNode->get_data() < current->get_data())
            {
                if (current->get_leftNode() == nullptr)
                {
                    current->set_leftNode(newNode);
                    current = nullptr;
                }
                else
                {
                    current = current->get_leftNode();
                }
            }
            else if (newNode->get_data() > current->get_data())
            {
                if (current->get_rightNode() == nullptr)
                {
                    current->set_rightNode(newNode);
                    current = nullptr;
                }
                else
                {
                    current = current->get_rightNode();
                }
            }
            else
            {
                current->increaseCounter();
                delete newNode;
                current = nullptr;
            }
        }
    }
}

string BSTree::largest() const
{
    Node* current;
    if (root == nullptr)
    {
        return "";
    }
    else
    {
        current = root;
        while (current->get_rightNode() != nullptr)
        {
            current = current->get_rightNode();
        }
    }
    return current->get_data();
}


string BSTree::smallest() const
{
    Node* current;
    if (root == nullptr)
    {
        return "";
    }
    else
    {
        while (current->get_leftNode() != nullptr)
        {
            current = current->get_leftNode();
        }
    }
    return current->get_data();
}