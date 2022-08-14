#ifndef SETASARRAY_H
#define SETASARRAY_H

#include "Set.hpp"
#include "Iterator.hpp"

#include <vector>
#include <iostream>

class SetAsArray : public Set<int> 
{
public:
    class Iter : public Iterator<int> {
        std::vector<bool> data;
        int universeSize;
        int index;
        unsigned int counter;
        SetAsArray* setAsArray;

    public:
        Iter(SetAsArray* set, std::vector<bool> array, int us);
        ~Iter() = default;
        const int& operator*();
        void operator++();
        bool is_done() const;
    };
    
    std::vector<bool> array;

public:
    SetAsArray(unsigned int n);
    ~SetAsArray() = default;
    void make_null();
    bool is_full() const;
    void insert(int element);
    bool is_member(int element) const;
    void withdraw(int element);
    void accept(Visitor<int>& v);
    
    void Accept(Visitor<int>& v);

    void print_set() const;

    friend SetAsArray operator+(SetAsArray const& A, SetAsArray const& B);
    friend SetAsArray operator-(SetAsArray const& A, SetAsArray const& B);
    friend SetAsArray operator*(SetAsArray const& A, SetAsArray const& B);
    friend bool operator==(SetAsArray const& A, SetAsArray const& B);
    friend bool operator<=(SetAsArray const& A, SetAsArray const& B);

    Iter& new_iterator() {
        return *new Iter(this, array, universeSize);
    }
};

#endif