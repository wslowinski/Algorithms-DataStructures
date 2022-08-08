#include "CursorList.h"

CursorList::CursorList() {
    head = 0;
    tail = 0;
    length = 0;
    spare = 0;
    for (int i = 0; i < SIZE; i++) {
        arr[i].next = i + 1;
    }
}

bool CursorList::empty() {
    return length == 0;
}

int CursorList::size() {
    return length;
}

void CursorList::push_front(int x) {
    int cursor = arr[spare].next;
    arr[spare].data = x;
    if (length == 0) {
        tail = spare;
    }
    else {
        arr[spare].next = head;
    }
    head = spare;
    spare = cursor;
    length++;
}

void CursorList::push_back(int x) {
    int cursor = arr[spare].next;
    arr[spare].data = x;
    if (length == 0) {
        head = spare;
    }
    else {
        arr[tail].next = spare;
    }
    tail = spare;
    spare = cursor;
    length++;
}

int CursorList::pop_front() {
    if (empty()) {
        throw std::out_of_range("List is empty!");
    }
    int delValue = arr[head].data;
    int cursor = head;
    head = arr[head].next;
    arr[cursor].next = spare;
    spare = cursor;
    length--;
    return delValue;
}

int CursorList::pop_back() {
    if (empty()) {
        throw std::out_of_range("List is empty!");
    }
    int delValue = arr[tail].data;
    int cursor = head;
    for (int i = 0; i < length - 2; i++) {
        cursor = arr[cursor].next;
    }
    arr[tail].next = spare;
    spare = tail;
    tail = cursor;
    length--;
    return delValue;
}

int CursorList::find(int x) {
    int cursor = head;
    for (int position = 0; position < length; position++) {
        if (arr[cursor].data == x) {
            return position;
        }
        else {
            cursor = arr[cursor].next;
        }
    }
    return -1;
}

int CursorList::erase(int i) {
    if (empty()) {
        throw std::out_of_range("List is empty!");
    }
    int index = head;
    for (int j = 0; j < i - 1; j++) {
        index = arr[index].next;
    }
    int delValue = arr[arr[index].next].data;
    if (i == 0) {
        pop_front();
    }
    else if (i == length - 1) {
        pop_back();
    }
    else {
        int cursor = spare;
        spare = arr[index].next;
        arr[index].next = arr[arr[index].next].next;
        arr[spare].next = cursor;
        length--;
    }
    return delValue;
}

void CursorList::insert(int i, int x) {
    int cursor = head;	
    for (int j = 0; j < i - 1; j++) {
        cursor = arr[cursor].next;
    }
    int temp = spare;
    arr[temp].data = x;
    spare = arr[spare].next;
    if (i == 0) {
        push_front(x);
    }
    else {
        arr[temp].next = arr[cursor].next;
        arr[cursor].next = temp;
        length++;
    }
}

int CursorList::remove(int x) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (find(x) != -1) {
            erase(find(x));
            count++;
        }
    }
    return count;
}

void CursorList::clear() {
    while (!empty()) {
        pop_front();
    }
}

CursorList::~CursorList() {
    clear();
}
