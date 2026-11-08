#include "Node.h"

Node::Node()
{
    small = "";
    large = "";

    left = nullptr;
    right = nullptr;
    middle = nullptr;
    parent = nullptr;
}

Node::Node(const string& title1, const string& title2)
{
    if (title1 < title2)
    {
        small = title1;
        large = title2;
    }
    else
    {
        small = title2;
        large = title1;
    }

    left = nullptr;
    right = nullptr;
    middle = nullptr;
    parent = nullptr;
}