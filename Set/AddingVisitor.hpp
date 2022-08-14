#ifndef ADDINGVISITOR_H
#define ADDINGVISITOR_H

#include "Visitor.hpp"

class AddingVisitor : public Visitor<int> {
protected:
    int sum;

public:
    AddingVisitor() : sum(0) {
    }

    void visit(int& element) {
        sum += element;
    }

    bool is_done() const {
        if (true) return true;
        return false;
    } 

    friend std::ostream& operator<<(std::ostream &out, const AddingVisitor& v) {
        out << v.sum;
        return out;
    }
};
#endif