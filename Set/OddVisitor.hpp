#ifndef ODDVISITOR_H
#define ODDVISITOR_H

#include "Visitor.hpp"

class OddVisitor : public Visitor<int> {
protected:
    bool odd;

public:
    OddVisitor() {
        odd = false;
    }

    void visit(int& element) {
        if (element % 2 == 1) odd = true;
    }

    bool is_done() const {
        if (odd) return true;
        return false;
    }

    bool is_odd() {
        return odd;
    }


};
#endif