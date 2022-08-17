#ifndef VISITOR_H
#define VISITOR_H

class Visitor {
private:
    unsigned int _count;

public:
    Visitor();
    int count() const;
    void visit();
};

#endif