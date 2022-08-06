#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdexcept>
#include <iostream>
#include <string>

#define SIZE 1000000

class Stack {

private:
    std::string* array;
    int top_;
    int capacity;

public:
    Stack(int size = SIZE);
    ~Stack();

    void push(std::string x);
    std::string pop();
    int size();
    bool empty();

    std::string top();
    bool full();
};

#endif
