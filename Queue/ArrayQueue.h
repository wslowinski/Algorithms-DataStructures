#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#define SIZE 1000000

#include <stdexcept>
#include <iostream>

class Queue {

private:
    int* array;
    int capacity;
    int front;
    int rear;

public:
    Queue(int size = SIZE);
    ~Queue();
    void enqueue(int x);
    int dequeue();
    int size();
    bool empty();
    bool full();
};

#endif