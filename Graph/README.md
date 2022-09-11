# Graph
Graph is an abstract data type that is meant to implement the undirected graph 
and directed graph concepts from the field of graph theory within mathematics. 
A graph data structure consists of a finite set of vertices, together with a set 
of unordered pairs of these vertices for an undirected graph or a set of ordered 
pairs for a directed graph. These pairs are known as edges. This directory 
contains graph impelementation using adjacency matrix.

## Interface
```cpp
class GraphAsMatrix
{
    // Iterators
    class AllVerticesIter : Iterator<Vertex> {
        AllVerticesIter(GraphAsMatrix& owner);
        bool is_done();
        Vertex& operator*();
        void operator++(); 
    };

public:
    class AllEdgesIter : Iterator<Edge> {
        AllEdgesIter(GraphAsMatrix& owner, int row);
        void next();
        bool is_done();
        Edge& operator*();
        void operator++(); 
    };

public:
    class EmanEdgesIter : Iterator<Edge> {
        EmanEdgesIter(GraphAsMatrix& owner, int v);
        void next();
        bool is_done();
        Edge& operator*();
        void operator++(); 
    };    

public:
    class InciEdgesIter : Iterator<Edge> {
        InciEdgesIter(GraphAsMatrix& owner, int v);
        void next();
        bool is_done();
        Edge& operator*();
        void operator++(); 
    };  

    GraphAsMatrix(int n, bool b);      // Construct graph
    ~GraphAsMatrix();                  // Graph destructor  
    int number_of_vertices() const;    // Returns the number of vertices
    bool is_directed();                // Checks whether the container is directed
    int number_of_edges() const;       // Returns the number of edges
    bool is_edge(int u, int v);        // Test whether container contain edge
    void make_null();                  // Clear content
    void add_edge(int u, int v);       // Adds edge
    Edge* select_edge(int u, int v);   // Selects and returns the edge pointer
    Vertex* select_vertex(int v);      // Selects and returns the vertex pointer
};
```

## Content
* ```GraphAsArray.h```,  ```GraphAsArray.cpp``` - Graph Implementation;
* ```Edge.h```,  ```Edge.cpp``` - Edge class implementation;
* ```Vertex.h```,  ```Vertex.cpp``` - Edge class implementation;
* ```Iterator.hpp``` - Iterator Interface;

## Technologies
Project is created with ```C++17```.

## Setup
1. To run this project, install it locally;
2. The following make command will help you in compiling the Makefile into an executable program. Finally, we are ready to run the executable file we created in the last step through the Terminal. Run the following command to do so
```
$ bash build.sh
```
