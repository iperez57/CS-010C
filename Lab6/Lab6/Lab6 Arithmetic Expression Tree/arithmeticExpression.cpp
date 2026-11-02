#include "arithmeticExpression.h"
#include <stack>
#include <sstream>

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