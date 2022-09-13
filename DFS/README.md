# Depth-first search (DFS)
Depth-first search (DFS) is an algorithm for traversing or searching tree 
or graph data structures. The algorithm starts at the root node (selecting some 
arbitrary node as the root node in the case of a graph) and explores as far 
as possible along each branch before backtracking. This directory contains 
DFS algorithm impelementation using adjacency matrix.

## Interface
```cpp
void GraphAsMatrix::DFS(Vertex* v) {
    std::vector<bool> visited(this->number_of_vertices(), false);
    DFS(v, visited);
}

void GraphAsMatrix::DFS(Vertex* v, std::vector<bool>& visited) {
    visited[v->get_number()] = true;
    std::cout << v->get_number() << std::endl;
    for (GraphAsMatrix::EmanEdgesIter& it = this->eman_edges_iter(v->get_number()); 
        !it.is_done(); ++it) {
            Vertex* vertex = (*it).mate(v);
        if (!visited[vertex->get_number()]) {
            DFS(vertex, visited);
        }
    }
}
```

## Content
* ```GraphAsArray.h```,  ```GraphAsArray.cpp``` - Graph Implementation, 
iterators, DFS algorithm, ;
* ```Edge.h```,  ```Edge.cpp``` - Edge class implementation;
* ```Vertex.h```,  ```Vertex.cpp``` - Edge class implementation;
* ```Iterator.hpp``` - Iterator Interface;
* ```main.cpp``` - tests;

## Technologies
Project is created with ```C++20```.

## Setup
1. To run this project, install it locally;
2. The following make command will help you in compiling the Makefile into an executable program. Finally, we are ready to run the executable file we created in the last step through the Terminal. Run the following command to do so
```
$ bash build.sh
```
