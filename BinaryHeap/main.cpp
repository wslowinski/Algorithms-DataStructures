#include "BinaryHeap.hpp"

void test(unsigned int size) {
    BinaryHeap<int> binaryHeap(size);
    std::cout << "Is empty: " << binaryHeap.is_empty() << std::endl;
    binaryHeap.enqueue(5);
    std::cout << "Is empty: " << binaryHeap.is_empty() << std::endl;
    std::cout << "Print Heap: "; 
    binaryHeap.print_heap();
    try {
        std::cout << "Min: " << binaryHeap.find_min() << std::endl;
    }
    catch(std::out_of_range) {
        std::cout << "EMPTY" << std::endl;
    }
    binaryHeap.enqueue(6);
    std::cout << "Print Heap: "; 
    binaryHeap.print_heap();
    try {
        std::cout << "Min: " << binaryHeap.find_min() << std::endl;
    }
    catch(std::out_of_range) {
        std::cout << "EMPTY" << std::endl;
    }
    binaryHeap.enqueue(8);
    std::cout << "Print Heap: ";
    binaryHeap.print_heap();
    try {
        std::cout << "Min: " << binaryHeap.find_min() << std::endl;
    }
    catch(std::out_of_range) {
        std::cout << "EMPTY" << std::endl;
    }
    binaryHeap.enqueue(3);
    std::cout << "Print Heap: ";
    binaryHeap.print_heap();
    try {
        std::cout << "Min: " << binaryHeap.find_min() << std::endl;
    }
    catch(std::out_of_range) {
        std::cout << "EMPTY" << std::endl;
    }
    binaryHeap.enqueue(9);
    std::cout << "Print Heap: ";
    binaryHeap.print_heap();
    try {
        std::cout << "Min: " << binaryHeap.find_min() << std::endl;
    }
    catch(std::out_of_range) {
        std::cout << "EMPTY" << std::endl;
    }
    binaryHeap.enqueue(2);
    std::cout << "Print Heap: ";
    binaryHeap.print_heap();
    try {
        std::cout << "Min: " << binaryHeap.find_min() << std::endl;
    }
    catch(std::out_of_range) {
        std::cout << "EMPTY" << std::endl;
    }
    binaryHeap.enqueue(1);
    std::cout << "Print Heap: ";
    binaryHeap.print_heap();
    try {
        std::cout << "Min: " << binaryHeap.find_min() << std::endl;
    }
    catch(std::out_of_range) {
        std::cout << "EMPTY" << std::endl;
    }
    try {
        std::cout << "Dequeue Min: " << binaryHeap.dequeue_min() << std::endl;
    }
    catch(std::out_of_range) {
        std::cout << "EMPTY" << std::endl;
    }
    std::cout << "Print Heap: ";
    binaryHeap.print_heap();
    try {
        std::cout << "Min: " << binaryHeap.find_min() << std::endl;
    }
    catch(std::out_of_range) {
        std::cout << "EMPTY" << std::endl;
    }
    try {
        std::cout << "Dequeue Min: " << binaryHeap.dequeue_min() << std::endl;
    }
    catch(std::out_of_range) {
        std::cout << "EMPTY" << std::endl;
    }
    std::cout << "Print Heap: ";
    binaryHeap.print_heap();
    try {
        std::cout << "Min: " << binaryHeap.find_min() << std::endl;
    }
    catch(std::out_of_range) {
        std::cout << "EMPTY" << std::endl;
    }
    binaryHeap.make_null();
    std::cout << "Is empty: " << binaryHeap.is_empty() << std::endl;
}

int main() {
    test(10);
    std::cout << "***************" << std::endl;
    test(2);
    return 0;
}