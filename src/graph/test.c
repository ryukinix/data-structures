#include <stdio.h>
#include <assert.h>
#include "graph.h"

int main() {
    Graph *g = graph_create();

    graph_add_edge(g, 1, 2);
    graph_add_edge(g, 1, 3);
    graph_add_edge(g, 2, 3);
    graph_add_edge(g, 3, 4);

    assert(graph_has_edge(g, 1, 2));
    assert(graph_has_edge(g, 1, 3));
    assert(graph_has_edge(g, 2, 3));
    assert(graph_has_edge(g, 3, 4));
    assert(!graph_has_edge(g, 4, 1));

    printf("Graph before removing edge (1, 2):\n");
    graph_print(g);

    graph_remove_edge(g, 1, 2);
    assert(!graph_has_edge(g, 1, 2));

    printf("\nGraph after removing edge (1, 2):\n");
    graph_print(g);

    graph_remove_node(g, 3);
    assert(!graph_has_edge(g, 1, 3));
    assert(!graph_has_edge(g, 2, 3));

    printf("\nGraph after removing node 3:\n");
    graph_print(g);

    graph_free(g);

    printf("\nAll graph tests passed!\n");

    return 0;
}
