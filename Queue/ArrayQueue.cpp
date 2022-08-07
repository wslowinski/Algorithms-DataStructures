#include "ArrayQueue.h"

Queue::Queue(int size) {
    front = -1;
    rear = -1;
    capacity = size;
    array = new int[capacity];
}

Queue::~Queue() {
    delete[] array;
}

bool Queue::empty() {
    if (front == -1 && rear == -1) {
        return true;
    }
    return false;
}

bool Queue::full() {
    if (rear == capacity - 1) {
        return true;
    }
    return false;
}

void Queue::enqueue(int x) {
    if(full()) {
        throw std::out_of_range("Overflow!");
    }
    else if(empty()) {
        rear = 0;
        front = 0;
    }
    else {
        rear++;
    }
    array[rear] = x;
}

int Queue::dequeue() {
    int elem = 0;
    if (empty()) {
        return -1;
    }
    else if (front == rear) {
        elem = array[front];
        front = rear = -1;
    }
    else {
        elem = array[front];
        front++;
    }
    return elem;
}

int Queue::size() {
    if (empty()) {
        return 0;
    }
    return (rear - front + 1);  
}