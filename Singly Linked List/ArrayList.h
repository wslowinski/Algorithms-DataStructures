#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#define MAX_SIZE 3000

#include <iostream>

class ArrayList {
private:
    int *array;
    int length;

public:
    ArrayList(int size = MAX_SIZE);
    ~ArrayList();
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
    void printList();
};

#endif
