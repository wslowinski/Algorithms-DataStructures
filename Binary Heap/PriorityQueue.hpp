#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Container.h"

template <typename T>
class PriorityQueue : public Container 
{
public:
    virtual void enqueue(T element) = 0;
    virtual T find_min() const = 0;
    virtual T dequeue_min() = 0;
};

#endif
