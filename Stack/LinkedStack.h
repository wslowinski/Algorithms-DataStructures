#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <iostream>

struct Node {
    int data;
    Node *next;
};

class Stack {
    
private:
    Node *top;

public:
    int count = 0;
    
    Stack();
    ~Stack();

    void push(int x);
    int pop();
    bool empty();
    int size();
};

#endif
