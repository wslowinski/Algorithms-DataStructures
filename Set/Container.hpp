#ifndef CONTAINER_H
#define CONTAINER_H

#include "Visitor.hpp"

template <typename T>
class Container 
{
protected:
    Container(){};

public:
    virtual unsigned int count() const = 0;
    virtual bool is_empty() const {
        return count() == 0;
    }
    virtual bool is_full() const = 0;
    virtual void make_null() = 0;
    virtual void accept(Visitor<T>& v) = 0;
};
#endif