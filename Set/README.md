# Set
set is an abstract data type that can store unique values, without any particular 
order. It is a computer implementation of the mathematical concept of a finite 
set. This directory contains set impelementation using array.

## Interface
```cpp
class SetAsArray : public Set<int> {
    // Iterator
    class Iter : public Iterator<int> {
        Iter(SetAsArray* set, std::vector<bool> array, int us);
        const int& operator*();
        void operator++();
        bool is_done() const;
    };

    SetAsArray(unsigned int n);             // Construct set
    void make_null();                       // Clear content
    void insert(int element);               // Insert element 
    bool is_member(int element) const;      // Test whether container contain element
    void withdraw(int element);             // Erase elements
    
    // Operator overloading
    friend SetAsArray operator+(SetAsArray const& A, SetAsArray const& B);
    friend SetAsArray operator-(SetAsArray const& A, SetAsArray const& B);
    friend SetAsArray operator*(SetAsArray const& A, SetAsArray const& B);
    friend bool operator==(SetAsArray const& A, SetAsArray const& B);
    friend bool operator<=(SetAsArray const& A, SetAsArray const& B);
};
```

## Content
* ```SetAsArray.h```,  ```SetAsArray.cpp``` - Set Implementation;
* ```Set.hpp``` - Set Interface;
* ```Iterator.hpp``` - Iterator Interface;
* ```Container.hpp``` - Container Interface;

## Technologies
Project is created with ```C++17```.

## Setup
1. To run this project, install it locally;
2. The following make command will help you in compiling the Makefile into an executable program:
```
$ make
```
3. Finally, we are ready to run the executable file we created in the last step through the Terminal. Run the following command to do so:
``` 
$ ./main.x
```
