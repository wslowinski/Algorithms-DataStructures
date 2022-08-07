#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <iostream>

struct Node {
    int data;
    Node *next ;
};

class Queue {
private:
    Node *front, *rear;
    int count = 0;

public:
    Queue();
    ~Queue() = default;
    void enqueue(int x);
    int dequeue();
    int size();
    bool empty();
};

#endif