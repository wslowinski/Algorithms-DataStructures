# Doubly Linked List
This directory contains Doubly Linked List implementation.

## Interface
```cpp
class List {
    void push_front(int x); // Inserts an element to the beginning
    int pop_front(); // Removes the first element
    void push_back(int x); // Adds an element to the end
    int pop_back(); // Removes the last element
    int size(); // Returns the number of elements
    bool empty(); // Checks whether the container is empty
    void clear(); // Clears the contents
    int find(int x); // Returns a position to the first element that compares equal to x
    int erase(int i); // Erases elements
    void insert(int i, int x); // Inserts elements
    int remove(int x); // Removes all elements that are equal to x
};
```

## Content
* ```LinkedList.h```, ```LinkedList.cpp``` - Doubly Linked List implementation;

## Technologies
Project is created with ```C++17```.
