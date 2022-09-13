#ifndef ITERATOR_HPP
#define ITERATOR_HPP

template<typename T>
class Iterator 
{
public:
    virtual bool is_done() = 0;
    virtual const T& operator*() = 0;
    virtual void operator++() = 0;
};

#endif