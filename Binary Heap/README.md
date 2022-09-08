# Priority Queue
Priority queue is an abstract data-type similar to a regular queue or stack data 
structure in which each element additionally has a priority associated with it. 
In a priority queue, an element with high priority is served before an element 
with low priority This directory contains priority queue implementation using 
Binary Heap.

## Interface
```cpp
template <typename T>
class BinaryHeap : public PriorityQueue<T> {
    BinaryHeap(unsigned int n);   // Constructs the priority queue
    void enqueue(T element);      // Inserts element
    T find_min() const;           // Finds minimum
    T dequeue_min();              // Removes the top element
    bool is_empty() const;        // Checks whether the underlying container is empty
    unsigned int count() const;   // Returns the number of elements
};
```

## Content
* ```Container.h``` - Container interface;
* ```PriorityQueue.hpp``` - Priority Queue interface;
* ```BinaryHeap.hpp``` - Priority Queue implementation using Binary Heap;

## Technologies
Project is created with ```C++17```.
