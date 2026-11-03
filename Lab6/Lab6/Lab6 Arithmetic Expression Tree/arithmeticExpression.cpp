#include "arithmeticExpression.h"
#include <stack>
#include <sstream>
#include <iostream>

int arithmeticExpression::priority(char op) const
{
    int priority = 0;
    if (op == '(') {
        priority = 3;
    }
    else if (op == '*' || op == '/') {
        priority = 2;
    }
    else if (op == '+' || op == '-') {
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix() const 
{
    stack<char> s;
    ostringstream oss;
    char c;
    for (unsigned i = 0; i < infixExpression.size();++i) {
        c = infixExpression.at(i);
        if (c == ' ') {
            continue;
        }
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') { //c is an operator
            if (c == '(') {
                s.push(c);
            }
            else if (c == ')') {
                while (s.top() != '(') {
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else {
                while (!s.empty() && priority(c) <= priority(s.top())) {
                    if (s.top() == '(') {
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else { //c is an operand
            oss << c;
        }
    }
    while (!s.empty()) {
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

arithmeticExpression::arithmeticExpression(const string& expression)
{
    infixExpression = expression;
    root = nullptr;
}

arithmeticExpression::~arithmeticExpression()
{
    destroyTree(root);
}

void arithmeticExpression::destroyTree(TreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    destroyTree(node->left);
    destroyTree(node->right);

    delete node;
}

void arithmeticExpression::buildTree()
{
    //converts infixExpression to postfix string
    string postfix = infix_to_postfix();

    //create stack of treenodes called s
    stack<TreeNode*> s;

    //loop through postfix and stores in c
    for (unsigned i = 0; i < postfix.size(); ++i)
    {
        char c = postfix.at(i);

        //check if c is a arthimetic operator
        if (c != '+' && c != '-' && c != '*' && c != '/')
        {
            //creates newNode and pushing onto stack
            TreeNode* newNode = new TreeNode(c);
            s.push(newNode);
        }
        else
        {
            //when reaching operator if is a variable it assigns left and right
            TreeNode* right = s.top();
            s.pop();

            TreeNode* left = s.top();
            s.pop();

            //creates parent node and combines left and right
            TreeNode* parent = new TreeNode(c);

            parent->left = left;
            parent->right = right;

            s.push(parent);
        }
    }
    root = s.top();
    s.pop();
}

void arithmeticExpression::infix() const
{
    infix(root);
}

void arithmeticExpression::infix(TreeNode* subtree) const
{
    if (subtree == nullptr)
    {
        return;
    }

    cout << "(";
    infix(subtree->left);
    cout << subtree->data;
    infix(subtree->right);
    cout << ")";
}

void arithmeticExpression::prefix() const
{
    infix(root);
}

void arithmeticExpression::prefix(TreeNode* subtree) const
{
    if (subtree == nullptr)
    {
        return;
    }

    cout << "(";
    cout << subtree->data;
    infix(subtree->left);
    infix(subtree->right);
}