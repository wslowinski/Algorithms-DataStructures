# Stack
Stack is an abstract data type that serves as a collection of elements, 
with two main operations:
* Push, which adds an element to the collection;
* Pop, which removes the most recently added element that was not yet removed.
This directory contains two versions of stack implementation:
* using Array;
* using Linked List;

## Interface
```cpp
class Stack {
    Stack(int capacity);  // Constructs the stack
    void push(int x);     // Inserts element at the top
    int pop();            // Removes the top element and returns value
    int size();           // Returns the number of elements
    bool empty();         // Checks whether the underlying container is empty
};
```

## Content
* ```ArrayStack.h```,  ```ArrayStack.cpp``` - Stack Implementation using an Array;
* ```LinkedStack.h```, ```LinkedStack.cpp``` - Stack Implementation using a Linked List;
* ```RPN.cpp``` - program to convert arithmetic expressions in infix notation to Reverse Polish Notation (RPN);

## Technologies
Project is created with ```C++17```.
