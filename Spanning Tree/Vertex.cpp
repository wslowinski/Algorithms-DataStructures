#include "Vertex.h"

Vertex::Vertex(int n) {
    number = n;
    weight = 0;
}

int Vertex::get_number() const {
    return number;
}

int Vertex::get_weight() const {
    return weight;
}

void Vertex::set_weight(int w) {
    weight = w;
}

std::string Vertex::get_label() const {
    return label;
}

void Vertex::put(std::ostream& s) const {
    s << number << " ";
}