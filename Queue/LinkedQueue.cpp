#include "LinkedQueue.h"

Queue::Queue() {
    front = rear = NULL;
}

bool Queue::empty() {
    return front == NULL;
}

void Queue::enqueue(int x) {
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = NULL;
        if (empty()) {
            front = rear = newnode;
            count++;
        }
        else {
            rear->next = newnode;
            rear = newnode;
            count++;
        }
}

int Queue::dequeue() {
    if (empty()) {
        return -1;
    }
    int value = front->data;
    Node *temp;
    temp = front;
    front = front->next;
    delete temp;
    count--;
    return value;
}

int Queue::size() {
    if (empty()) {
        return 0;
    }
    return count;
}

