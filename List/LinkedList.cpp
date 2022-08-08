#include "LinkedList.h"

LinkedList::Node::Node(int value) {
    data = value;
    next = prev = nullptr;
}

LinkedList::LinkedList() {
    head = tail = nullptr;
    _size = 0;
}

bool LinkedList::empty() {
    if (_size <= 0) {
        return true;
    }
    return false;
}

void LinkedList::push_front(int x) {
    Node *temp = new Node(x);
    if (head == nullptr) {
        head = tail = temp;
    }
    else {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    _size++;
}

void LinkedList::push_back(int x) {
    Node *temp = new Node(x);
    if (tail == nullptr) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    _size++;
}
 
int LinkedList::pop_front() {
    if (empty()) {
        throw std::out_of_range("List is empty!");
    }
    int delValue = head->data;
    if (head == tail) {
        delete head;
        head = tail = 0;
    }
    else {
        head = head->next;
        delete head->prev;
        head->prev = 0;
    }
    _size--;
    return delValue;
}
 
int LinkedList::pop_back() {
    if (empty()) {
        throw std::out_of_range("List is empty!");
    }
    int delValue = tail->data;
    if (head == tail) {
        delete head;
        head = tail = 0;
    }
    else {
        tail = tail->prev;
        delete tail->next;
        tail->next = 0;
    }
    _size--;
    return delValue;
}

int LinkedList::size() {
    return _size;
}

int LinkedList::find(int x) {
    if (!empty()) {
        Node *temp = head;
        int position = 0;
        while (temp) {
            if (temp->data == x) {
                return position;
            }
            position++;
            temp = temp->next;
        }
    }
    return -1;
}

int LinkedList::erase(int i) {
    int delValue;
    if (i == size() - 1) {
        pop_back();
    }
    else if (i < 0 || i > _size) {
        throw std::out_of_range("Index is out of range of the list!");
    }
    else if (i == 0 && head != nullptr) { 
        Node* nodeToDelete = head;
        head = head->next;
        delValue = nodeToDelete->data;
        delete nodeToDelete;
        if(head != nullptr)
            head->prev = nullptr;
        _size--;
        return delValue;
    }
    else {
        Node* temp = head;
        for (int j = 0; j < i - 1; j++) {
            if (temp != nullptr) {
                temp = temp->next;
            }
        }
        if (temp != nullptr && temp->next != nullptr) {
            Node* nodeToDelete = temp->next;
            delValue = nodeToDelete->data;
            temp->next = temp->next->next;
            if (temp->next->next != nullptr)
                temp->next->next->prev = temp->next;  
            delete nodeToDelete; 
        }     
    _size--;
    }
    return delValue;
}

void LinkedList::insert(int i, int x) {
    Node* newNode = new Node(x); 
    newNode->data = x;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if (i < 0 || i > _size) {
        throw std::out_of_range("Index is out of range of the list!");
    }
    else if (i == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        _size++;
    }
    else if (i == size() - 1) {
        push_back(x);
    }
    else {
        Node* temp = head;
        for (int j = 0; j < i - 1; j++) {
            if (temp != nullptr) {
                temp = temp->next;
            }
        }

        if (temp != nullptr) {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            if (newNode->next != nullptr)
                newNode->next->prev = newNode;  
        }
        _size++;
    }
}

void LinkedList::clear() {
    while (!empty()) {
        pop_back();
    }
}

int LinkedList::remove(int x) {
    int count = 0;
    for (int i = 0; i < _size; i++) {
        if (find(x) != -1) {
            erase(find(x));
            count++;
        }
    }
    return count;
}

LinkedList::~LinkedList() {
    clear();
}
