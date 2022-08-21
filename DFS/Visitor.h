#ifndef VISITOR_H
#define VISITOR_H

#include "Vertex.h"

class Visitor {
private:
    unsigned int _count;

public:
    Visitor();
    unsigned int count() const;
    void visit(Vertex* vertex);
};

#endif