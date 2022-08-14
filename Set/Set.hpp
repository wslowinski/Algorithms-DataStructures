#ifndef SET_H
#define SET_H

#include "Container.hpp"

template <typename T>
class Set : public virtual Container<T> {
protected:
    int set_size;
    int universeSize;

public:
    Set(unsigned int n) : universeSize(n) {
    }
    unsigned int universe_size() const {
        return universeSize;
    }
    unsigned int count() const {
        return set_size;
    }
    virtual void insert(T element) = 0;
    virtual bool is_member(T element) const = 0;
    virtual void withdraw(T element) = 0;
}; 

#endif