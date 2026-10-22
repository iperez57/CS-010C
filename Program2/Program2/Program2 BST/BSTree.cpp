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
bool BSTree::search(const string& data) const
{
    return search(root, data);
}

bool BSTree::search(Node* current, const string& data) const
{
    //cant find data
    if (current == nullptr)
    {
        return false;
    }
    //found data
    if (current->get_data() == data)
    {
        return true;
    }
    //search left
    if (data < current->get_data())
    {
        return search(current->get_leftNode(), data);
    }
    //search right
    return search(current->get_rightNode(), data);
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
    Node* current = root;
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

int BSTree::height(const string& data) const
{
    int height = 0;
    Node* current = root;

    if (root == nullptr)
    {
        return height;
    }
    else
    {
        while (current != nullptr)
        {
            if (current->get_data() == data)
            {
                return height;
            }
            else if (current->get_data() > data)
            {
                current = current->get_leftNode();
            }
            else
            {
                current = current->get_rightNode();
            }
            height++;
        }
    }
    return -1;
}

void BSTree::remove(const string& data)
{
    Node* parent = nullptr;
    Node* current = root;

    while (current != nullptr)
    {
        //check if current data is equal to data wanted to be removed
        if (current->get_data() == data)
        {
            if (current->get_leftNode() == nullptr && current->get_rightNode() == nullptr)
            {
                //remove leaf
                if (parent == nullptr)
                {
                    root = nullptr;
                }
                else if (parent->get_leftNode() == current)
                {
                    parent->set_leftNode(nullptr);
                }
                else
                {
                    parent->set_rightNode(nullptr);
                }
                delete current;
                return;
            }
            else if (current->get_rightNode() == nullptr)
            {
                //remove node with only left child
                if (parent == nullptr)
                {
                    root = current->get_leftNode();
                }
                else if (parent->get_leftNode() == current)
                {
                    parent->set_leftNode(current->get_leftNode());
                }
                else
                {
                    parent->set_rightNode(current->get_leftNode());
                }

                delete current;
                return;
            }
            else if (current->get_leftNode() == nullptr)
            {
                //removes node with only right child
                if (parent == nullptr)
                {
                    root = current->get_rightNode();
                }
                else if (parent->get_leftNode() == current)
                {
                    parent->set_leftNode(current->get_rightNode());
                }
                else
                {
                    parent->set_rightNode(current->get_rightNode());
                }

                delete current;
                return;
            }
            else
            {
                //remove node with two children
                //Find leftmost child of right subtree
                Node* successor = current->get_rightNode();
                while (successor->get_leftNode() != nullptr)
                {
                    successor = successor->get_leftNode();
                }
                //copy key to current node
                current->set_data(successor->get_data());
                parent = current;

                //reassign current and key so loop continues with new key
                current = current->get_rightNode();
            }
        }
        else if (current->get_data() < data)
        {
            //search right
            parent = current;
            current = current->get_rightNode();
        }
        else
        {
            //search left
            parent = current;
            current = current->get_leftNode();
        }
    }
}