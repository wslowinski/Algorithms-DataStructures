#include "Edge.h"

Edge::Edge(Vertex* v0, Vertex* v1) {
    _v0 = v0;
    _v1 = v1;
}

Vertex* Edge::v0() {
    return _v0;
}

Vertex* Edge::v1() {
    return _v1;
}

Vertex* Edge::mate(Vertex* v) {
    if (v == _v0) return _v1;
    else if (v == _v1) return _v0;
    else throw std::invalid_argument("ERROR\n");
}

void Edge::set_weight(int w) {
    _weight = w;
}

int Edge::get_weight() const {
    return _weight;
}

void Edge::print_vertex() {
    std::cout << "v0: " << _v0->get_number() << ", " << "v1: " << _v1->get_number() << std::endl;
}