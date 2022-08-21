#ifndef GRAPHASMATRIX_H
#define GRAPHASMATRIX_H

#include "Edge.h"
#include "Iterator.hpp"
#include "Visitor.h"

#include <vector>

class GraphAsMatrix
{
public:
    class AllVerticesIter : Iterator<Vertex> {
        GraphAsMatrix& graph;
        int current;
    
    public:
        AllVerticesIter(GraphAsMatrix& owner);
        ~AllVerticesIter() = default;
        bool is_done();
        Vertex& operator*();
        void operator++(); 
    };

public:
    class AllEdgesIter : Iterator<Edge> {
        GraphAsMatrix& owner;
        int row;
        int col;
    
    public:
        AllEdgesIter(GraphAsMatrix& owner, int row);
        ~AllEdgesIter() = default;
        void next();
        bool is_done();
        Edge& operator*();
        void operator++(); 
    };

public:
    class EmanEdgesIter : Iterator<Edge> {
        GraphAsMatrix& owner;
        int row;
        int col;
    
    public:
        EmanEdgesIter(GraphAsMatrix& owner, int v);
        ~EmanEdgesIter() = default;
        void next();
        bool is_done();
        Edge& operator*();
        void operator++(); 
    };    

public:
    class InciEdgesIter : Iterator<Edge> {
        GraphAsMatrix& owner;
        int row;
        int col;
    
    public:
        InciEdgesIter(GraphAsMatrix& owner, int v);
        ~InciEdgesIter() = default;
        void next();
        bool is_done();
        Edge& operator*();
        void operator++(); 
    };  

protected:
    std::vector<Vertex*> vertices;
    std::vector<std::vector<Edge*>> adjacencyMatrix;
    bool _isDirected;
    int _numberOfVertices;
    int _numberOfEdges;

public:
    GraphAsMatrix(int n, bool b);
    ~GraphAsMatrix();
    int number_of_vertices() const;
    bool is_directed();
    int number_of_edges() const;
    bool is_edge(int u, int v);
    void make_null();
    void add_edge(int u, int v);
    Edge* select_edge(int u, int v);
    Vertex* select_vertex(int v);
    void DFS(Vertex* v);
    void DFS(Vertex* v, std::vector<bool>& visited);
    void DFS_visitor(Visitor* visitor, Vertex *v, std::vector<bool>& visited);
    void DFS_visitor(Visitor* visitor, Vertex* v);
    bool is_connected();

    AllVerticesIter& vertices_iter() {
        return *(new AllVerticesIter(*this));
    }

    AllEdgesIter& edges_iter(int row) {
        return *(new AllEdgesIter(*this, row));
    }

    EmanEdgesIter& eman_edges_iter(int v) {
        return *(new EmanEdgesIter(*this, v));
    }

    InciEdgesIter& inci_edges_iter(int v) {
        return *(new InciEdgesIter(*this, v));
    }
};

#endif