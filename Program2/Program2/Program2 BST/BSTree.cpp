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
    if (current != nullptr)
    {
        //found data
        if (data == current->get_data())
        {
            return true;
        }
        //search left
        else if (data < current->get_data())
        {
            return search(current->get_leftNode(), data);
        }
        //search right
        else
        {
            return search(current->get_rightNode(), data);
        }
    }
    return false;
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
    remove(nullptr, root, data);
}

bool BSTree::remove(Node* parent, Node* current, const string& data)
{
    //data not found
    if (current == nullptr)
    {
        return false;
    }

    //search left tree
    if (data < current->get_data())
    {
        return remove(current, current->get_leftNode(), data);
    }

    //search right tree
    if (data > current->get_data())
    {
        return remove(current, current->get_rightNode(), data);
    }

    //found node to remove
    //node has 2 children
    if (current->get_leftNode() != nullptr && current->get_rightNode() != nullptr)
    {
        Node* successorParent = current;
        Node* successor = current->get_rightNode();

        //find left node in right subtree
        while (successor->get_leftNode() != nullptr)
        {
            successorParent = successor;
            successor = successor->get_leftNode();
        }

        //copy successor into current
        current->set_data(successor->get_data());

        return remove(successorParent, successor, successor->get_data());
    }
    // Root node with 1 or 0 children
    else if (current == root)
    {
        if (current->get_leftNode() != nullptr)
        {
            root = current->get_leftNode();
        }
        else
        {
            root = current->get_rightNode();
        }
    }
    //only left children
    else if (current->get_leftNode() != nullptr)
    {
        if (parent->get_leftNode() == current)
        {
            parent->set_leftNode(current->get_leftNode());
        }
        else
        {
            parent->set_rightNode(current->get_leftNode());
        }
    }
    else
    {
        if (parent->get_leftNode() == current)
        {
            parent->set_leftNode(current->get_rightNode());
        }
        else
        {
            parent->set_rightNode(current->get_rightNode());
        }
        return true;
    }
}

void BSTree::preOrder() const
{
    preOrder(root);
}

void BSTree::preOrder(Node* current) const
{
    if (current == nullptr)
    {
        return;
    }

    cout << current->get_data() << "(" << current->get_count() << "), ";

    preOrder(current->get_leftNode());
    preOrder(current->get_rightNode());
}

void BSTree::postOrder() const
{
    postOrder(root);
}

void BSTree::postOrder(Node* current) const
{
    if (current == nullptr)
    {
        return;
    }

    postOrder(current->get_leftNode());
    postOrder(current->get_rightNode());

    cout << current->get_data() << "(" << current->get_count() << "), ";
}

void BSTree::inOrder() const
{
    inOrder(root);
}

void BSTree::inOrder(Node* current) const
{
    if (current == nullptr)
    {
        return;
    }

    inOrder(current->get_leftNode());

    cout << current->get_data() << "(" << current->get_count() << "), ";

    inOrder(current->get_rightNode());
}