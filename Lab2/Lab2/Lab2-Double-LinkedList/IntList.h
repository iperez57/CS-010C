//IntList.h

#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
    int data;
    IntNode* prev;
    IntNode* next;
    IntNode(int data) : data(data), prev(0), next(0) {}
};


class IntList
{
private:
    IntNode* dummyHead;
    IntNode* dummyTail;
public:
    IntList();
    ~IntList();
    void push_front(int value);
    void pop_front();
    void push_back(int value);
    void pop_back();
    bool empty() const
    {
        return dummyHead->next == dummyTail;
    }
    friend ostream& operator<<(ostream& out, const IntList& rhs);
    void printReverse() const
    {
        IntNode* current = dummyTail->prev;

        while (current != dummyHead)
        {
            cout << current->data;
            
            if (current->prev != dummyHead)
            {
                cout << " ";
            }

            current = current->prev;
        }
    }
};
#endif