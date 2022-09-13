#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <iostream>

class Vertex 
{    
private:
    int number;
    int weight;
    std::string label;

public:

    Vertex(int n);
    int get_number() const;
    int get_weight() const;
    void set_weight(int w);
    std::string get_label() const;
    void put(std::ostream& s) const;
};

#endif