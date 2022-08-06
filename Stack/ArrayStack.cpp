#include "ArrayStack.h"

Stack::Stack(int size) {
    array = new std::string[size];
    capacity = size;
    top_ = -1;
}

Stack::~Stack() {
    delete[] array;
}
 
bool Stack::full() {
    return top_ == capacity - 1;
}

bool Stack::empty() {
    return top_ == -1;
}

void Stack::push(std::string x) {
    if (full()) {
        throw std::out_of_range("Overflow");
    }
    array[++top_] = x;
}
 
std::string Stack::pop() {
    if (!empty()) {
        return array[top_--];
    }
    return "EMPTY";
}

int Stack::size() {
    return top_ + 1;
}

std::string Stack::top() {
    return array[top_];
}

