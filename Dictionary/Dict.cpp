#include "Dict.h"

HashNode::HashNode(const std::string& key, const std::string& value) {
    this->key = key;
    this->value = value;
    this->next = nullptr;
}

std::string HashNode::getKey() {
    return key;
}

std::string HashNode::getValue() {
    return value;
}

void HashNode::setValue(const std::string& value) {
    this->value = value;
}

HashNode* HashNode::getNext() {
    return next;
}

void HashNode::setNext(HashNode *next) {
    this->next = next;
}

Dict::Dict(const int& capacity) {
    elemNumber = 0;
    this->capacity = capacity;
    table = new HashNode*[capacity];
    for (int i = 0; i < capacity; i++) {
        table[i] = nullptr;
    }
}

int Dict::size() {
    return elemNumber;
}

bool Dict::empty() {
    return size() == 0;
}

int Dict::encrypt(const std::string& key) {
    int result = 0;
    for (int i = 0; i < key.length(); i++) {
        if (key[i] >= 48 && key[i] <= 57) {
            result += (key[i] - 48) * pow(35, key.length() - i - 1);
        } else if (key[i] >= 97 && key[i] <= 122) {
            result += (key[i] - 87) * pow(35, key.length() - i - 1);
        }
    }
    return result;
}

int Dict::hash_function(const std::string& key) {
    return encrypt(key) % capacity;
}

std::string Dict::operator[](const std::string& key) {
    int hash = hash_function(key);
    if (table[hash] == nullptr) {
        return "NotFound";
    }
    else {
        HashNode *ptr = table[hash];
        while (ptr != nullptr && ptr->getKey() != key) {
            ptr = ptr->getNext();
        }
        if (ptr == nullptr) {
            return "NotFound";
        }
        else {
            return ptr->getValue();
        }
    }
}

bool Dict::insert(const Pair& p) {
    int hash = hash_function(p.first);
    bool flag = false;
    if (table[hash] == nullptr) {
        table[hash] = new HashNode(p.first, p.second);
        flag = true;
    }
    else {
        HashNode *ptr = table[hash];
        while (ptr->getNext() != nullptr) {
            ptr = ptr->getNext();
        }
        if (ptr->getKey() == p.first) {
            ptr->setValue(p.second);
            flag = false;
        }
        else {
            ptr->setNext(new HashNode(p.first, p.second));
            flag = true;
        }
    }
    elemNumber++;
    return flag;
}

bool Dict::find(const std::string& key) {
    int hash = hash_function(key);
    bool flag = false;
    HashNode *ptr = table[hash];
    if (ptr != nullptr)  {
        while (ptr != nullptr) {
            if (ptr->getKey() == key) {
                flag = true;
            }
            ptr = ptr->getNext();
        }
    }
    return flag;
}

void Dict::erase(const std::string& key) {
    int hash = hash_function(key);
    if (table[hash] != nullptr) {
        HashNode *prev = nullptr;
        HashNode *ptr = table[hash];
        while (ptr->getNext() != nullptr && ptr->getKey() != key) {
            prev = ptr;
            ptr = ptr->getNext();
        }
        if (ptr->getKey() == key) {
            if (prev == nullptr) {
                HashNode *next = ptr->getNext();
                delete ptr;
                table[hash] = next;
            }
            else {
                HashNode *next = ptr->getNext();
                delete ptr;
                prev->setNext(next);
            }
        }
    }
    elemNumber--;
}

void Dict::buckets() {
    std::cerr << "#" << size() << std::endl;
}

void Dict::clear() {
    for (int i = 0; i < capacity; i++) {
        if (table[i] != nullptr) {
            HashNode *prev = nullptr;
            HashNode *ptr = table[i];
            while (ptr != nullptr) {
                prev = ptr;
                ptr = ptr->getNext();
                delete prev;
            }
        }
    }
    delete[] table;
}

Dict::~Dict() {
    clear();
}

