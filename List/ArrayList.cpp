#include "ArrayList.h"

ArrayList::ArrayList(int size) {
    length = 0;
    array = new int[size];
}

ArrayList::~ArrayList() {
    delete[] array;
}

bool ArrayList::empty() {
    return length == 0;
}

int ArrayList::size() {
    return length;
}

void ArrayList::push_back(int x) {
    array[length] = x;
    length++;
}

void ArrayList::insert(int i, int x) {
    for (int j = length; j > i; j--) {
        array[j] = array[j - 1];
    }
    array[i] = x;
    length++;
}

int ArrayList::erase(int i) {
    if (empty()) {
        throw std::out_of_range("List is empty!");
    }
    int delValue = array[i];
    for (int j = i; j < length; j++) {
        array[j] = array[j + 1];
    }
    length--;
    return delValue;
}

int ArrayList::find(int x) {
    for (int i = 0; i < length; i++) {
        if (array[i] == x) {
            return i;
        }
    }
    return -1;
}

int ArrayList::remove(int x) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (find(x) != -1) {
            erase(find(x));
            count++;
        }
    }
    return count;
}

int ArrayList::pop_back() {
    if (empty()) {
        throw std::out_of_range("List is empty!");
    }
    int delValue = array[length - 1]; 
    erase(length - 1);
    return delValue;
}

void ArrayList::push_front(int x) {
    insert(0, x);
}

int ArrayList::pop_front() {
    if (empty()) {
        throw std::out_of_range("List is empty! (from pop_front)");
    }
    int delValue = array[0];
    erase(0);
    return delValue;
}
