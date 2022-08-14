#include "SetAsArray.h"
#include "AddingVisitor.hpp"
#include "OddVisitor.hpp"


int main() {
    SetAsArray A(10);
    SetAsArray B(10);
    SetAsArray C(10);
    SetAsArray D(10);
    A.insert(0);
    A.insert(2);
    A.insert(4);
    A.insert(6);
    A.insert(8);
    
    B.insert(1);
    B.insert(3);
    B.insert(5);
    B.insert(7);
    B.insert(9);
    C = A + B;
    D = C - B;
    std::cout << "A: "; A.print_set();
    std::cout << "B: "; B.print_set();
    std::cout << "C: "; C.print_set();
    std::cout << "D: "; D.print_set();
    
    std::cout << "D == A: " << (D == A) << std::endl;
    std::cout << "D <= A: " << (D <= A) << std::endl;
    std::cout << "C == B: " << (C == B) << std::endl;
    std::cout << "B <= C: " << (B <= C) << std::endl;
    
    A.insert(1);
    std::cout << "D == A: " << (D == A) << std::endl;
    std::cout << "D <= A: " << (D <= A) << std::endl;

    A.insert(5);
    AddingVisitor v_A;
    A.accept(v_A);
    std::cout << "v_A: "<< v_A << std::endl;

    SetAsArray E = A * B;
    AddingVisitor v_E;
    E.accept(v_E);
    std::cout << "v_E: " << v_E << std::endl;

    E.withdraw(1);
    AddingVisitor v_E2;
    E.accept(v_E2);
    std::cout << "v_E: " << v_E2 << std::endl;

    OddVisitor ov_B;
    B.Accept(ov_B);
    std::cout << "B is_odd: " << ov_B.is_odd() << std::endl;

    OddVisitor ov_A;
    A.Accept(ov_A);
    std::cout << "A is_odd: " << ov_A.is_odd() << std::endl;

    A.withdraw(1);
    A.withdraw(5);
    A.insert(9);
    OddVisitor ov_A2;
    A.Accept(ov_A2);
    std::cout << "A is_odd: " << ov_A2.is_odd() << std::endl;

    std::cout << "A: ";
    SetAsArray::Iter& it = A.new_iterator();
    while (!it.is_done()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    delete &it;

    std::cout << "B: ";
    SetAsArray::Iter& iter = B.new_iterator();
    while (!iter.is_done()) {
        std::cout << *iter << " ";
        ++iter;
    }
    std::cout << std::endl;
    delete &iter;
    return 0;
}