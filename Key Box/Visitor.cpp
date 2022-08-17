#include "Visitor.h"

Visitor::Visitor() : _count() {
}

int Visitor::count() const {
    return _count;
}

void Visitor::visit() {
    _count++;
}