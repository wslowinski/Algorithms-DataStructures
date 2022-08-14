#ifndef VISITOR_H
#define VISITOR_H

#include <iostream>

template <typename T>
class Visitor
{
public:
    virtual void visit(T& element) = 0;
    virtual bool is_done() const = 0;
};
#endif