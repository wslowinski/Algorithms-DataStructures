#include "GraphAsMatrix.h"
#include <iostream>

void test_Edge(GraphAsMatrix* graph, int u, int v) {
    Edge* e = graph->select_edge(u, v);
    int v0No = e->v0()->get_number();
    int v1No = e->v1()->get_number();
    std::cout << v0No << std::endl;
    std::cout << v1No << std::endl;
    std::cout << e->mate(e->v0())->get_number() << std::endl;
    std::cout << e->mate(e->v1())->get_number() << std::endl;
    e->set_weight(v0No + v1No);
    std::cout << e->get_weight() << std::endl;
    std::cout << std::endl;
    delete e;
}

void test_AllEdgesIter(GraphAsMatrix* graph, int row) {
    GraphAsMatrix::AllEdgesIter& itEdge = graph->edges_iter(row);
    while (!itEdge .is_done()) {
        (*itEdge).print_vertex();
        ++itEdge;
    }
    delete &itEdge;
}

void test_Graph(int size, bool isDirected) {
    GraphAsMatrix* graph = new GraphAsMatrix(size, isDirected);
    std::cout << graph->number_of_vertices() << std::endl;
    std::cout << graph->number_of_edges() << std::endl;
    std::cout << std::endl;
    
    Vertex* v = graph->select_vertex(2);
    int vNumber = v->get_number();
    std::cout << vNumber << std::endl;
    v->set_weight(vNumber * vNumber);
    std::cout << v->get_weight() << std::endl;
    std::cout << std::endl;

    graph->add_edge(1, 2);
    graph->add_edge(1, 2);
    graph->add_edge(2, 3);
    graph->add_edge(3, 4);
    graph->add_edge(9, 9);

    std::cout << std::endl;
    
    std::cout << graph->number_of_vertices() << std::endl;
    std::cout << graph->number_of_edges() << std::endl;
    std::cout << graph->is_edge(1, 1) << std::endl;
    std::cout << graph->is_edge(1, 2) << std::endl;
    std::cout << graph->is_edge(2, 1) << std::endl;
    std::cout << std::endl;

    std::cout << "*** AllVerticesIter ***" << std::endl;
    GraphAsMatrix::AllVerticesIter& it = graph->vertices_iter();
    while (!it.is_done()) {
        std::cout << "No: " << (*it).get_number() 
            << ", W: " << (*it).get_weight() << std::endl;
        ++it;
    }
    delete &it;
    std::cout << std::endl;

    graph->add_edge(3, 5);
    graph->add_edge(8, 3);
    graph->add_edge(5, 2);

    std::cout << "*** AllEdgesIter ***" << std::endl;
    for (unsigned int i = 0; i < graph->number_of_vertices(); i++) {
        test_AllEdgesIter(graph, i);
    }
    std::cout << std::endl;

    std::cout << "*** EmanEdgesIter ***" << std::endl;
    GraphAsMatrix::EmanEdgesIter& itEman = graph->eman_edges_iter(3);
    while (!itEman .is_done()) {
        (*itEman).print_vertex();
        ++itEman;
    }
    delete &itEman;
    std::cout << std::endl;

    std::cout << "*** InciEdgesIter ***" << std::endl;
    GraphAsMatrix::InciEdgesIter& itInci = graph->inci_edges_iter(2);
    while (!itInci .is_done()) {
        (*itInci).print_vertex();
        ++itInci;
    }
    delete &itInci;
    std::cout << std::endl;
    delete graph;
}

int main() {
    std::cout << "Directed graph" << std::endl;
    test_Graph(10, true);
    std::cout << "Undirected graph" << std::endl;
    test_Graph(10, false);
    return 0;
}
