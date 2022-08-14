#include "SetAsArray.h"

SetAsArray::SetAsArray(unsigned int n) : Set(n), array(n) {
    set_size = 0;
    for (unsigned int i = 0; i < universeSize; i++) {
        array[i] = false;
    }
}

bool SetAsArray::is_full() const {
    return (count() == universe_size());
}

void SetAsArray::insert(int element) {
    if (!array[element]) {
        array[element] = true;
        set_size++;
    }
}

void SetAsArray::make_null() {
    for (unsigned int i = 0; i < universeSize; i++) {
        array[i] = false;
    }
    set_size = 0;
}

bool SetAsArray::is_member(int element) const {
    return array[element];
}

void SetAsArray::withdraw(int element) {
    if (array[element]) {
        array[element] = false;
        set_size--;
    }    
}

void SetAsArray::print_set() const {
    for (unsigned int i = 0; i < universeSize; i++) {
        if (array[i])
            std::cout << i << " ";
    }
    std::cout << std::endl;
}

void SetAsArray::accept(Visitor<int>& v) {
    for (int i = 0; i < universeSize; i++) {
        if (array[i]) v.visit(i);
    }
}

void SetAsArray::Accept(Visitor<int>& v) {
    int index = 0;
    for (int i = 0; i < universeSize && !v.is_done(); i++) {
        if (array[i]) {
            v.visit(i);
            index = i;
        }
    }
    std::cout << "Cell number: " << index << std::endl;
}

SetAsArray operator+(SetAsArray const& A, SetAsArray const& B) {
    if (A.universeSize != B.universeSize) {
        throw std::out_of_range("A.universeSize != B.universeSize");
    }
    SetAsArray result(A.universeSize);
    for (unsigned int i = 0; i < A.universeSize; i++) {
        result.array[i] = A.array[i] || B.array[i];
        if (result.array[i]) {
            result.set_size++;
        }
    }
    return result;
}

SetAsArray operator-(SetAsArray const& A, SetAsArray const& B) {
    if (A.universeSize != B.universeSize) {
        throw std::length_error("A.universeSize != B.universeSize");
    }
    SetAsArray result(A.universeSize);
    for (unsigned int i = 0; i < A.universeSize; i++) {
        result.array[i] = A.array[i] && !B.array[i];
        if (result.array[i]) {
            result.set_size++;
        }
    }
    return result;
}

SetAsArray operator*(SetAsArray const& A, SetAsArray const& B) {
    if (A.universeSize != B.universeSize) {
        throw std::length_error("A.universeSize != B.universeSize");
    }
    SetAsArray result(A.universeSize);
    for (unsigned int i = 0; i < A.universeSize; i++) {
        result.array[i] = A.array[i] && B.array[i];
        if (result.array[i]) {
            result.set_size++;
        }
    }
    return result;
}

bool operator==(SetAsArray const& A, SetAsArray const& B) {
    if (A.universeSize != B.universeSize) {
        throw std::length_error("A.universeSize != B.universeSize");
    }
    for (unsigned int i = 0; i < A.universeSize; i++) {
        if (A.array[i] != B.array[i]) {
            return false;
        }
    }
    return true;
}

bool operator<=(SetAsArray const& A, SetAsArray const& B) {
    if (A.universeSize != B.universeSize) {
        throw std::length_error("A.universeSize != B.universeSize");
    }
    if ((A * B == A) && (A + B == B)) {
        return true;
    }
    return false;
}

SetAsArray::Iter::Iter(SetAsArray* set, std::vector<bool> array, int us) {
    universeSize = us;
    data = array;
    counter = 0;
    setAsArray = set;
    for (int i = 0; i < universeSize; i++) {
        if (data[i]) {
            index = i;
            break;
        }
    }
}

const int& SetAsArray::Iter::operator*() {
    counter++;
    return index;
}

void SetAsArray::Iter::operator++() {
    for (int i = index + 1; i < universeSize; i++) {
        if (data[i]) {
            index = i;
            break;
        }
    }
}

bool SetAsArray::Iter::is_done() const {
    if (counter > setAsArray->count() - 1) {
        return true;
    }
    return false;
}