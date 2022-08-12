#ifndef DICT_H
#define DICT_H

#include <iostream>
#include <utility>
#include <string>
#include <cmath>

class HashNode {
private:
    std::string key;
    std::string value;
    HashNode *next;

public:
    HashNode(const std::string& key, const std::string& value);
    std::string getKey();
    std::string getValue();
    HashNode *getNext();
    void setValue(const std::string& value);
    void setNext(HashNode *next);
};

class Dict {
public:
    int capacity, elemNumber;
    HashNode **table;

    using Pair = std::pair<std::string, std::string>;

public:
    Dict(const int& capacity);
    ~Dict();
    int encrypt(const std::string& key);
    int hash_function(const std::string& key);

    void clear();
    bool insert(const Pair& p);
    bool find(const std::string& key);
    std::string operator[](const std::string& key);
    void erase(const std::string& key);
    int size();
    bool empty();
    void buckets();
};

#endif
