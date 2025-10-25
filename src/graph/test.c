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

    Iterator *it = graph_bfs(g, 4);
    List *path = list_from_iterator(it);
    iterator_free(it);
    printf("BFS Path: ");
    list_println(path);
    List *path_expected = list_init(6, 4, 1, 3, 2, 6, 5);
    printf("BFS Expected: ");
    list_println(path_expected);

    assert(list_equal(path, path_expected));

    list_free(path); list_free(path_expected);
    graph_free(g);
    printf("\n--- BFS Test Finished ---\n");
}

void test_dfs() {
    printf("\n--- Testing DFS ---\n");
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

    Iterator *it = graph_dfs(g, 6);
    List *path = list_from_iterator(it);
    iterator_free(it);
    printf("DFS Path: ");
    list_println(path);
    List *path_expected = list_init(6, 6, 1, 2, 4, 5, 3, 1);
    printf("DFS Expected: ");
    list_println(path_expected);

    assert(list_equal(path, path_expected));

    list_free(path); list_free(path_expected);
    graph_free(g);
    printf("\n--- DFS Test Finished ---\n");
}

void test_graph_directed() {
    puts("== Graph directed tests");
    Graph *g = graph_create();

    graph_add_edge(g, 1, 2);
    graph_add_edge(g, 1, 3);
    graph_add_edge(g, 2, 3);
    graph_add_edge(g, 3, 4);
    graph_add_edge_with_weight(g, 3, 4, 2);

    assert(graph_has_edge(g, 1, 2));
    assert(graph_has_edge(g, 1, 3));
    assert(graph_has_edge(g, 2, 3));
    assert(graph_has_edge(g, 3, 4));
    assert(!graph_has_edge(g, 4, 3));
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
}

void test_graph_undirected() {
    puts("== Graph undirected tests");
    Graph *g = graph_undirected_create();

    graph_add_edge(g, 1, 2);
    graph_add_edge(g, 1, 3);
    graph_add_edge(g, 2, 3);
    graph_add_edge(g, 3, 4);

    assert(graph_has_edge(g, 1, 2));
    assert(graph_has_edge(g, 2, 1));
    assert(graph_has_edge(g, 1, 3));
    assert(graph_has_edge(g, 3, 1));
    assert(graph_has_edge(g, 4, 3));
    assert(!graph_has_edge(g, 4, 1));

    printf("Graph before removing edge (1, 2):\n");
    graph_print(g);

    graph_remove_edge(g, 1, 2);
    assert(!graph_has_edge(g, 1, 2));
    assert(!graph_has_edge(g, 2, 1));

    printf("\nGraph after removing edge (1, 2):\n");
    graph_print(g);

    graph_remove_node(g, 3);
    assert(!graph_has_edge(g, 1, 3));
    assert(!graph_has_edge(g, 2, 3));

    printf("\nGraph after removing node 3:\n");
    graph_print(g);

    graph_free(g);
}

int main() {
    test_graph_directed();
    test_graph_undirected();
    test_bfs();
    test_dfs();

    printf("\nAll graph tests passed!\n");
    return 0;
}
