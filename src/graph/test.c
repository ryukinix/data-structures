#include <stdio.h>
#include <assert.h>
#include "graph.h"

void test_bfs() {
    printf("\n--- Testing BFS ---\n");
    Graph* g = graph_create();

    // Add nodes
    for (int i = 1; i <= 6; i++) {
        graph_add_node(g, i);
    }

    // Add edges
    graph_add_edge(g, 1, 2);
    graph_add_edge(g, 1, 3);
    graph_add_edge(g, 2, 4);
    graph_add_edge(g, 2, 5);
    graph_add_edge(g, 3, 6);

    printf("Graph created:\n");
    graph_print(g);
    printf("\n");

    Iterator *it = graph_bfs(g, 1);
    while (!iterator_done(it)) {
        int node = *(int*) iterator_next(it);
        printf("BFS: %d\n", node);
    }

    iterator_free(it);
    graph_free(g);
    printf("\n--- BFS Test Finished ---\n");
}


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

    test_bfs();

    return 0;
}
