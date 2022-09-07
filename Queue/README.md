# Queue
Queue is a collection of entities that are maintained in a sequence and can be 
modified by the addition of entities at one end of the sequence and the removal 
of entities from the other end of the sequence. This directory contains two 
versions of queue implementation:
* using Array;
* using Linked List;

## Interface
```cpp
class Queue {
    Queue(); // Constructs the queue
    void enqueue(int x); // Inserts element at the end
    int dequeue(); // Removes the first element and returns the value
    int size(); // Returns the number of elements
    bool empty(); // Checks whether the underlying container is empty
};
```

## Content
* ```ArrayQueue.h```,  ```ArrayQueue.cpp``` - Queue Implementation using an Array;
* ```LinkedQueue.h```, ```LinkedQueue.cpp``` - Queue Implementation using a Linked List;
* ```Radix.cpp``` - Radix sort algorithm implementation;

## Technologies
Project is created with ```C++17```.
