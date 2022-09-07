# Dictionary
A dictionary is an abstract data type that defines an unordered collection 
of data as a set of key-value pairs. Each key, which must be unique, has 
an associated value. Typically, the keys in a dictionary must be simple types 
(such as integers or strings) while the values can be of any type. 
This directory contains dictionary impelementation using linked list.

## Interface
```cpp
class Dict {
    using Pair = std::pair<std::string, std::string>;
    
    Dict(const int& capacity);                       // Constructs the dictionary
    void clear();                                    // Clears the contents 
    bool insert(const Pair& p);                      // Inserts key-value pair
    bool find(const std::string& key)                // Checks if the container contains element with specific key
    std::string& operator[](const std::string& key); // Returns value
    bool erase(const std::string& key);              // Erases elements
    int size();                                      // Returns the number of elements
    bool empty();                                    // Checks whether the container is empty
}
```

## Content
* ```Dict.h```,  ```Dict.cpp``` - Dictionary Implementation;

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
$ ./main pairs.txt < input.txt > output.txt
$ diff -s results.txt output.txt
```
