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

#endif