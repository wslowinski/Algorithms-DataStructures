#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class LinkedList {
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int value);
    };
private:
    Node* head;
    Node* tail;
    int _size;

public:
    LinkedList();
    ~LinkedList();
    void push_front(int x);
    void push_back(int x);
    int pop_front();
    int pop_back();
    bool empty();
    int size();
    void clear();
    int find(int x);
    int erase(int i);
    void insert(int i, int x);
    int remove(int x);
};


#endif
