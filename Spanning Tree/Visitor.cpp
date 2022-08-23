#include "Visitor.h"

Visitor::Visitor() : _count() {
}

unsigned int Visitor::count() const {
    return _count;
}

void Visitor::visit(Vertex* vertex) {
    _count++;
}