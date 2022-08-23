#include "GraphAsMatrix.h"

GraphAsMatrix::GraphAsMatrix(int n, bool b):
    adjacencyMatrix(n, std::vector<Edge*> (n, nullptr)) {
    _isDirected = b;
    _numberOfVertices = n;
    _numberOfEdges = 0;
    for (int i = 0; i < n; i++) {
        vertices.push_back(new Vertex(i));
    }
}

int GraphAsMatrix::number_of_vertices() const {
    return _numberOfVertices;
}

int GraphAsMatrix::number_of_edges() const {
    return _numberOfEdges;
}

bool GraphAsMatrix::is_directed() {
    return _isDirected ? true : false;
}

void GraphAsMatrix::add_edge(int u, int v) {
    if (adjacencyMatrix[u][v] == nullptr) {
        adjacencyMatrix[u][v] = new Edge(vertices[u], vertices[v]);
        if (!_isDirected && 
            adjacencyMatrix[v][u] == nullptr) {
            adjacencyMatrix[v][u] = new Edge(vertices[v], vertices[u]);
        }
        _numberOfEdges++;
    }
    else std::cout << "Edge(" << u << "," << v << ") already exists!" << std::endl;
}

bool GraphAsMatrix::is_edge(int u, int v) {
   return (adjacencyMatrix[u][v] == nullptr) ? false : true; 
}


Vertex* GraphAsMatrix::select_vertex(int v) {
    return vertices[v];
}

Edge* GraphAsMatrix::select_edge(int u, int v) {
    return adjacencyMatrix[u][v];
}

void GraphAsMatrix::make_null() {
    _numberOfVertices = 0;
    _numberOfEdges = 0;
    for (int i = 0; i < _numberOfVertices; i++) {
        vertices.push_back(nullptr);
        for (int j = 0; j < _numberOfVertices; j++) {
            adjacencyMatrix[i].push_back(nullptr);
        }
    }   
}

GraphAsMatrix::~GraphAsMatrix() {
    make_null();
}

GraphAsMatrix::AllVerticesIter::AllVerticesIter(GraphAsMatrix& owner):
    graph(owner),
    current(0)
{
}

bool GraphAsMatrix::AllVerticesIter::is_done() {
    return current >= graph.number_of_vertices();
}

Vertex& GraphAsMatrix::AllVerticesIter::operator*() {
    return *(graph.vertices[current]);
}

void GraphAsMatrix::AllVerticesIter::operator++() {
    current++;
} 

GraphAsMatrix::AllEdgesIter::AllEdgesIter(GraphAsMatrix& owner, int row):
    owner(owner),
    row(row),
    col(-1)
{
    next();
}

void GraphAsMatrix::AllEdgesIter::next() {
    do {
        if (++col >= owner.number_of_vertices()) return;
    } while (owner.adjacencyMatrix[row][col] == nullptr); 
}

Edge& GraphAsMatrix::AllEdgesIter::operator*() {
    return *(owner.adjacencyMatrix[row][col]);
}

void GraphAsMatrix::AllEdgesIter::operator++() {
    next();
}

bool GraphAsMatrix::AllEdgesIter::is_done() {
    return col >= owner.number_of_vertices();
}

GraphAsMatrix::EmanEdgesIter::EmanEdgesIter(GraphAsMatrix& owner, int row):
    owner(owner), 
    row(row), 
    col(-1) 
{
    next();
}

void GraphAsMatrix::EmanEdgesIter::next() {
    do {
        if (++col >= owner.number_of_vertices()) return;
    } while (owner.adjacencyMatrix[row][col] == nullptr);   
}

bool GraphAsMatrix::EmanEdgesIter::is_done() {
    return col >= owner.number_of_vertices();
}

Edge& GraphAsMatrix::EmanEdgesIter::operator*() {
    return *(owner.adjacencyMatrix[row][col]);
}

void GraphAsMatrix::EmanEdgesIter::operator++() {
    next();
}

GraphAsMatrix::InciEdgesIter::InciEdgesIter(GraphAsMatrix& owner, int col):
    owner(owner), 
    row(-1), 
    col(col)
{
    next();
}

void GraphAsMatrix::InciEdgesIter::next() {
    do {
        if (++row >= owner.number_of_vertices()) return;
    } while (owner.adjacencyMatrix[row][col] == nullptr);   
}

bool GraphAsMatrix::InciEdgesIter::is_done() {
    return row >= owner.number_of_vertices();
}

Edge& GraphAsMatrix::InciEdgesIter::operator*() {
    return *(owner.adjacencyMatrix[row][col]);
}

void GraphAsMatrix::InciEdgesIter::operator++() {
    next();
}

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

void GraphAsMatrix::DFS_visitor(Visitor* visitor, Vertex* v) {
    std::vector<bool> visited(this->number_of_vertices(), false);
    DFS_visitor(visitor, v, visited);
}

void GraphAsMatrix::DFS_visitor(Visitor* visitor, Vertex *v, std::vector<bool>& visited) {
    visitor->visit(v);
    visited[v->get_number()] = true;
    for (GraphAsMatrix::EmanEdgesIter& it = this->eman_edges_iter(v->get_number()); 
        !it.is_done(); ++it) {
            Vertex* vertex = (*it).mate(v);
        if (!visited[vertex->get_number()]) {
            DFS_visitor(visitor, vertex, visited);
        }
    }  
}

bool GraphAsMatrix::is_connected() {
    if (!_isDirected) {
        Vertex* vertex = this->select_vertex(0);
        Visitor* visitor = new Visitor();
        DFS_visitor(visitor, vertex);
        unsigned int vertNum = visitor->count();
        delete visitor;
        return vertNum == _numberOfVertices;
    }
    unsigned int vertNum;
    for (unsigned int i = 0; i < _numberOfVertices; i++) {
        Vertex* vertex = this->select_vertex(i);
        Visitor* visitor = new Visitor();
        DFS_visitor(visitor, vertex);
        vertNum = visitor->count();
        delete visitor;
        if (vertNum != _numberOfVertices) return false;
    }
    return true;
}

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
            DFS1(vertex, visited, parent);
        }
    }
}

void GraphAsMatrix::DFS1(Vertex* v, std::vector<bool>& visited, std::vector<int>& parent) {
    visited[v->get_number()] = true;
    for (GraphAsMatrix::EmanEdgesIter& it = this->eman_edges_iter(v->get_number()); 
        !it.is_done(); ++it) {
            Vertex* vertex = (*it).mate(v);
        if (!visited[vertex->get_number()]) {
            parent[vertex->get_number()] = v->get_number();
            std::cout << vertex->get_number() << "\'s parent is " << parent[vertex->get_number()] << std::endl;
            DFS1(vertex, visited, parent);
        }
    }
}

