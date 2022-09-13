# Spanning tree
Spanning tree T of an undirected graph G is a subgraph that is a tree which 
includes all of the vertices of G. In general, a graph may have several 
spanning trees, but a graph that is not connected will not contain a spanning 
tree. If all of the edges of G are also edges of a spanning tree T of G, then G 
is a tree and is identical to T. This directory contains spanning tree search 
impelementation using DFS.

## Implementation
```cpp
void GraphAsMatrix::DFS_spanning_tree(Vertex* v) {
    if (!is_connected()) return;
    std::vector<bool> visited(this->number_of_vertices(), false);
    std::vector<int> parent(this->number_of_vertices(), -1);
    DFS_spanning_tree(v, visited, parent);

}

void GraphAsMatrix::DFS_spanning_tree(Vertex* v, std::vector<bool>& visited, std::vector<int>& parent) {
    visited[v->get_number()] = true;
    for (GraphAsMatrix::EmanEdgesIter& it = this->eman_edges_iter(v->get_number()); 
        !it.is_done(); ++it) {
            Vertex* vertex = (*it).mate(v);
        if (!visited[vertex->get_number()]) {
            parent[vertex->get_number()] = v->get_number();
            std::cout << vertex->get_number() << "\'s parent is " << parent[vertex->get_number()] << std::endl;
            dfs(vertex, visited, parent);
        }
    }
}
```

## Content
* ```GraphAsArray.h```,  ```GraphAsArray.cpp``` - Graph Implementation, 
Iterators, DFS algorithm, spanning tree search;
* ```Edge.h```,  ```Edge.cpp``` - Edge class implementation;
* ```Vertex.h```,  ```Vertex.cpp``` - Edge class implementation;
* ```Iterator.hpp``` - Iterator Interface;
* ```main.cpp``` - tests;

## Technologies
Project is created with ```C++17```.

## Setup
1. To run this project, install it locally;
2. The following make command will help you in compiling the Makefile into an executable program. Finally, we are ready to run the executable file we created in the last step through the Terminal. Run the following command to do so
```
$ bash build.sh
```
