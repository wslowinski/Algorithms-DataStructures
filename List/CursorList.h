#ifndef CURSORLIST_H
#define CURSORLIST_H

#define SIZE 3000

#include <iostream>

class CursorList {
    struct Node {
        int data;
        int next;
    };

    Node arr[SIZE];
    int head;
    int tail;
    int length;
    int spare;

public:
    CursorList();
    ~CursorList();
    void push_front(int x);
    int pop_front();
    void push_back(int x);
    int pop_back();
    int size();
    bool empty();
    void clear();
    int find(int x);
    int erase(int i);
    void insert(int i, int x);
    int remove(int x);
    void replace(int i, int x);
};

#endif
