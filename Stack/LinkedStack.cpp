#include "LinkedStack.h"

Stack::Stack() {
    top = NULL;
}

bool Stack::empty() {
    return (top == NULL);
} 

void Stack::push(int x) {
    Node *temp = new Node;
    temp->data = x;
    temp->next = top;
    top = temp;
    count++;
}

int Stack::pop() {
    if (!empty()) {
        int value = top->data;
        Node *oldtop = top;
        top = oldtop->next;
        delete oldtop;
        count--;
        return value;
    }
    else {
        return -1;
    }
}

int Stack::size() {
    return count;
}

Stack::~Stack() {
    while (!empty()){
        pop();
    }    
}