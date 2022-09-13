#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

class Edge 
{
protected:
    Vertex* _v0;
    Vertex* _v1;
    int _weight;
    std::string _label;

public:
    Edge(Vertex* v0, Vertex* v1);
    Vertex* v0();
    Vertex* v1();
    Vertex* mate(Vertex* v);
    void set_weight(int w);
    int get_weight() const;
    void print_vertex();
};

#endif