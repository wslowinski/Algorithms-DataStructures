#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include "PriorityQueue.hpp"

#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
class BinaryHeap : public PriorityQueue<T> 
{
protected:
    int heap_size;
    int capacity;
    std::vector<T> data;

public:
    BinaryHeap(unsigned int n);
    ~BinaryHeap() = default;

    void swap(T* x, T* y);
    void heapify(T index);

    void make_null();
    void enqueue(T element);
    T find_min() const;
    T dequeue_min();
    bool is_empty() const;
    bool is_full() const;
    void print_heap() const;
    unsigned int count() const;
};

template<typename T>
void BinaryHeap<T>::heapify(T index) {
    T left = 2*index + 1;
    T rigth = 2*index + 2;
    T smallest = index;
    if (left < heap_size && data[left] < data[index])
        smallest = left;
    if (rigth < heap_size && data[rigth] < data[smallest])
        smallest = rigth;
    if (smallest != index) {
        swap(&data[index], &data[smallest]);
        heapify(smallest);
    }
}

template<typename T>
void BinaryHeap<T>::swap(T* x, T* y) {
    T tmp = *x;
    *x = *y;
    *y = tmp;
}

template <typename T>
BinaryHeap<T>::BinaryHeap(unsigned int n): 
    heap_size(0), 
    data(n) 
{
    capacity = n;
}

template <typename T>
unsigned int BinaryHeap<T>::count() const {
    return heap_size;
}

template <typename T>
bool BinaryHeap<T>::is_empty() const {
    return heap_size == 0;
}

template <typename T>
bool BinaryHeap<T>::is_full() const {
    return false;
}

template <typename T>
void BinaryHeap<T>::make_null() {
    heap_size = 0;
}

template <typename T>
T BinaryHeap<T>::find_min() const {
    if (is_empty()) {
        throw std::out_of_range("Heap is empty!");
    }
    return data[0];
}

template <typename T>
void BinaryHeap<T>::enqueue(T element) {
    if (heap_size >= data.size()) {
        data.resize(heap_size + 1);
    }
    ++heap_size;
    unsigned int i = heap_size - 1;
    data[i] = element;
    while (i != 0 && data[(i - 1) / 2] > data[i]) {
        swap(&data[i], &data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

template <typename T>
T BinaryHeap<T>::dequeue_min() {
    if (is_empty()) {
        throw std::out_of_range("Heap is empty!");
    }
    T root = data[0];
    data[0] = data[heap_size - 1];
    heap_size--;
    if (capacity < heap_size) {
        data.pop_back();
    }
    else {
        swap(&data[heap_size], &data[capacity - 1]);
        data.pop_back();
    }
    heapify(0);
    capacity--;
    return root;
}

template <typename T>
void BinaryHeap<T>::print_heap() const {
    for (size_t i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

#endif
