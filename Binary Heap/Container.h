#ifndef CONTAINER_H
#define CONTAINER_H

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
};

#endif