#include "GraphAsMatrix.h"
#include <iostream>

int main() {
    int n, x, i = 0;
    std::cin >> n;
    GraphAsMatrix* graph = new GraphAsMatrix(n, true);
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        graph->add_edge(i, x-1);
    }
    std::cout << graph->number_of_money_box(new Visitor()) << std::endl;
    delete graph;
    return 0;
}