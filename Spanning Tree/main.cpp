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
    while (!itInci.is_done()) {
        (*itInci).print_vertex();
        ++itInci;
    }
    delete &itInci;
    std::cout << std::endl;
    delete graph;
}

void test_DFS(int size, bool isDirected) {
    std::string str = isDirected ? "Directed" : "Undirected";
    std::cout << str << " graph" << std::endl;
    GraphAsMatrix* graph = new GraphAsMatrix(size, isDirected);
    graph->add_edge(0, 1);
    graph->add_edge(1, 2);
    graph->add_edge(2, 3);
    graph->add_edge(3, 4);
    graph->add_edge(3, 7);
    graph->add_edge(4, 5);
    graph->add_edge(5, 9);
    graph->add_edge(9, 9);
    graph->add_edge(6, 8);
    graph->add_edge(8, 6);
    graph->DFS(graph->select_vertex(0));
    graph->add_edge(0, 8);
    graph->DFS(graph->select_vertex(0));
    delete graph;
}

void test_Connectivity() {
    GraphAsMatrix* graph = new GraphAsMatrix(10, false);
    graph->add_edge(0, 1);
    graph->add_edge(1, 2);
    graph->add_edge(2, 3);
    graph->add_edge(3, 4);
    graph->add_edge(3, 7);
    graph->add_edge(4, 5);
    graph->add_edge(5, 9);
    graph->add_edge(9, 9);
    graph->add_edge(6, 8);
    graph->add_edge(8, 6);
    // graph->add_edge(0, 8);
    std::cout << "connectivity: " << graph->is_connected() << std::endl;
    graph->add_edge(0, 8);
    std::cout << "connectivity: " << graph->is_connected() << std::endl;
    delete graph;
    std::cout << "\n******************************" << std::endl;
}

void test_Strong_Connectivity() {
    GraphAsMatrix* dGraph = new GraphAsMatrix(10, true);
    dGraph->add_edge(0, 1);
    dGraph->add_edge(1, 2);
    dGraph->add_edge(2, 3);
    dGraph->add_edge(3, 4);
    dGraph->add_edge(3, 7);
    dGraph->add_edge(4, 5);
    dGraph->add_edge(5, 9);
    dGraph->add_edge(9, 9);
    dGraph->add_edge(6, 8);
    dGraph->add_edge(8, 6);
    dGraph->add_edge(0, 8);
    dGraph->add_edge(6, 0);
    dGraph->add_edge(9, 0);
    std::cout << "strong connectivity: " << dGraph->is_connected() << std::endl;
    dGraph->add_edge(7, 0);
    std::cout << "strong connectivity: " << dGraph->is_connected() << std::endl;
    delete dGraph;
}

int main() {
    std::cout << "******************************" << std::endl;
    std::cout << "             DFS" << std::endl;
    std::cout << "******************************" << std::endl;
    
    
    test_DFS(10, false);
    std::cout << "\n******************************" << std::endl;
    
    test_DFS(10, true);
    std::cout << "\n******************************" << std::endl;

    test_Connectivity();
    test_Strong_Connectivity();


    std::cout << "\n\n******************************" << std::endl;
    std::cout << "        Spanning tree" << std::endl;
    std::cout << "******************************" << std::endl;
    GraphAsMatrix* tGraph = new GraphAsMatrix(10, false);
    tGraph->add_edge(0, 1);
    tGraph->add_edge(1, 2);
    tGraph->add_edge(2, 3);
    tGraph->add_edge(3, 4);
    tGraph->add_edge(3, 7);
    tGraph->add_edge(4, 5);
    tGraph->add_edge(5, 9);
    tGraph->add_edge(9, 9);
    tGraph->add_edge(6, 8);
    tGraph->add_edge(8, 6);
    tGraph->add_edge(0, 8);
    tGraph->DFS_spanning_tree(tGraph->select_vertex(0));
    std::cout << "\n*********************\n";
    tGraph->add_edge(3, 9);
    tGraph->add_edge(5, 7);
    tGraph->add_edge(9, 8);
    tGraph->DFS_spanning_tree(tGraph->select_vertex(0));
    return 0;
}
