//Stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

template <typename T>
class stack
{
private:
    T data[MAX_SIZE];
    int size;

public:
    stack();
    void push(T val);
    void pop();
    void pop_two();
    T top();
    bool empty();
    ~stack();
    stack(const stack& other) = delete;
    stack& operator=(const stack& other) = delete;
};


template <typename T>
stack<T>::stack()
{
    data;
    size = 0;
}

template <typename T>
void stack<T>::push(T val)
{
    if (size == MAX_SIZE)
    {
        throw overflow_error("Called push on full stack.");
    }

    data[size] = val;
    size++;
}

template <typename T>
void stack<T>::pop()
{
    if (size == 0)
    {
        throw out_of_range("Called pop on empty stack.");
    }

    size--;
}

template <typename T>
void stack<T>::pop_two()
{
    if (size == 0)
    {
        throw out_of_range("Called pop_two on empty stack.");
    }
    if (size == 1)
    {
        throw out_of_range("Calledpop_twpon stack of size 1.");
    }
    size -= 2;
}

#endif