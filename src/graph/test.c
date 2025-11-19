#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <linux/limits.h>
#include <string.h>
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
    List *path_expected = list_init(6, 4, 1, 2, 3, 5, 6);
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
    List *path_expected = list_init(6, 6, 1, 3, 2, 5, 4);
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

void test_graph_acyclical() {
    puts("== Graph acyclical tests");
    Graph *g = graph_create();

    graph_add_edge(g, 1, 2);
    graph_add_edge(g, 2, 3);
    graph_add_edge(g, 3, 4);

    printf("This graph doesn't have cycles:\n");
    graph_print(g);

    assert(graph_acyclical(g) == true);

    printf("But this have one cycle after introducing edge (3, 1):\n");
    graph_add_edge(g, 3, 1);
    graph_print(g);

    assert(graph_acyclical(g) == false);

    graph_free(g);
}

void test_graph_tarjan() {
    puts("== Graph edge classification through tarjan ");

    Graph *g = graph_create();

    printf("input graph: \n");
    graph_add_edge(g, 1, 2);
    graph_add_edge(g, 2, 3);
    graph_add_edge(g, 3, 4);
    graph_add_edge(g, 3, 1);

    graph_print(g);

    printf("tarjan graph: \n");
    Graph *g_tarjan = graph_tarjan(g);
    graph_print(g_tarjan);

    assert(graph_get_edge_weight(g_tarjan, 1, 2) == TREE);
    assert(graph_get_edge_weight(g_tarjan, 2, 3) == TREE);
    assert(graph_get_edge_weight(g_tarjan, 3, 4) == TREE);
    assert(graph_get_edge_weight(g_tarjan, 3, 1) == BACK);

    graph_free(g_tarjan);
    graph_free(g);
}

void test_graph_edges_ordered() {
    Graph* g = graph_create();
    graph_add_edge_with_weight(g, 2, 4, 15);
    graph_add_edge_with_weight(g, 1, 6, 14);
    graph_add_edge_with_weight(g, 2, 3, 10);
    graph_add_edge_with_weight(g, 1, 2, 7);
    graph_add_edge_with_weight(g, 1, 3, 9);
    printf(":: graph");
    graph_print(g);


    List *expected = list_create();
    expected = list_append_with_key(expected, 1, 2);
    expected = list_append_with_key(expected, 1, 3);
    expected = list_append_with_key(expected, 2, 3);
    expected = list_append_with_key(expected, 1, 6);
    expected = list_append_with_key(expected, 2, 4);

    List *edges_ordered = graph_edges_ordered(g);
    printf("Edges ordered: "); list_println(edges_ordered);
    printf("Edges expected: "); list_println(expected);
    assert(list_equal(edges_ordered, expected));

    graph_free(g);
    list_free(expected);
    list_free(edges_ordered);
}

void test_graph_strong_components() {
    puts("== Graph strong components ");

    Graph *g = graph_create();

    printf(":: input graph: \n");
    graph_add_edge(g, 1, 2);
    graph_add_edge(g, 1, 3);
    graph_add_edge(g, 2, 3);
    graph_add_edge(g, 3, 4);
    graph_add_edge(g, 4, 1);
    graph_add_edge(g, 5, 1);

    graph_print(g);

    printf(":: strong components: \n");

    int *components = graph_strong_components(g);
    int n = graph_max_node_id(g) + 1;
    for (int u = 0; u < n; u++) {
        if (components[u] >= 0) {
            printf("%d -> %d\n", u, components[u]);
        }
    }

    // expected: two components {1, 2, 3, 4} and {5}
    assert(components[1] == components[2]);
    assert(components[2] == components[3]);
    assert(components[3] == components[4]);
    assert(components[3] == components[4]);
    assert(components[1] != components[5]);

    free(components);
    graph_free(g);
}

void test_graph_export() {
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    const char *g1_fname = "test_graph.dot";
    const char *g2_fname = "test_graph_undirected.dot";
    const char *g3_fname = "test_graph_tarjan.dot";
    const char *g4_fname = "test_graph_undirected_tarjan.dot";

    puts("== Testing graph export");
    Graph *g = graph_create();
    graph_add_edge_with_weight(g, 1, 2, 10);
    graph_add_edge_with_weight(g, 1, 3, 20);
    graph_add_edge(g, 2, 3);
    graph_add_edge_with_weight(g, 3, 4, 30);
    graph_add_edge(g, 4, 1);
    graph_add_edge(g, 5, 1);

    graph_export_to_dot(g, g1_fname);
    printf("saved: %s/%s\n", cwd, g1_fname);

    Graph *g2 = graph_undirected_create();
    graph_add_edge_with_weight(g2, 1, 2, 10);
    graph_add_edge_with_weight(g2, 1, 3, 20);
    graph_add_edge(g2, 2, 3);
    graph_add_edge_with_weight(g2, 3, 4, 30);

    graph_export_to_dot(g2, g2_fname);
    printf("saved: %s/%s\n", cwd, g2_fname);
    Graph* g3 = graph_tarjan(g);
    graph_export_to_dot(g3, g3_fname);
    printf("saved: %s/%s\n", cwd, g3_fname);

    Graph* g4 = graph_tarjan(g2);
    graph_export_to_dot(g4, g4_fname);
    printf("saved: %s/%s\n", cwd, g3_fname);

    graph_free(g);
    graph_free(g2);
    graph_free(g3);
    graph_free(g4);
}

void test_graph_topological_sort() {
    puts("== Graph topological sort test");
    Graph *g = graph_create();

    graph_add_edge(g, 5, 1);
    graph_add_edge(g, 1, 2);
    graph_add_edge(g, 1, 3);
    graph_add_edge(g, 2, 3);
    graph_add_edge(g, 3, 4);

    List* nodes = graph_topological_sort(g);
    List* expected = list_init(5, 5, 1, 2, 3, 4);

    printf("Graph: \n");
    graph_print(g);

    printf("Topological sort: ");
    list_println(nodes);
    printf("Expected: ");
    list_println(expected);

    assert(list_equal(nodes, expected));
    graph_free(g);
    list_free(nodes);
    list_free(expected);
}

void test_graph_dijkstra(bool extra_tests) {
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    puts("== Dijkstra test");
    Graph* g = graph_create();
    graph_add_edge_with_weight(g, 1, 2, 7);
    graph_add_edge_with_weight(g, 1, 3, 9);
    graph_add_edge_with_weight(g, 1, 6, 14);
    graph_add_edge_with_weight(g, 2, 3, 10);
    graph_add_edge_with_weight(g, 2, 4, 15);
    graph_add_edge_with_weight(g, 3, 4, 11);
    graph_add_edge_with_weight(g, 3, 6, 2);
    graph_add_edge_with_weight(g, 4, 5, 6);
    graph_add_edge_with_weight(g, 5, 6, 9);

    printf("Original graph:\n");
    graph_print(g);

    int source = 1;
    Graph* dijkstra_result = graph_dijkstra(g, source);
    printf("\nDijkstra result (source=%d):\n", source);
    graph_print(dijkstra_result);

    if (extra_tests) {
        graph_export_to_dot(g, "test_graph_dijkstra_input.dot");
        printf("saved input: %s/test_graph_dijkstra_input.dot\n", cwd);
        graph_export_to_dot(dijkstra_result, "test_graph_dijkstra_output.dot");
        printf("saved output: %s/test_graph_dijkstra_output.dot\n", cwd);
    }


    assert(graph_has_edge(dijkstra_result, 1, 2));
    assert(graph_get_edge_weight(dijkstra_result, 1, 2) == 7);
    assert(graph_has_edge(dijkstra_result, 1, 3));
    assert(graph_get_edge_weight(dijkstra_result, 1, 3) == 9);
    assert(graph_has_edge(dijkstra_result, 3, 6));
    assert(graph_get_edge_weight(dijkstra_result, 3, 6) == 11);
    assert(graph_has_edge(dijkstra_result, 3, 4));
    assert(graph_get_edge_weight(dijkstra_result, 3, 4) == 20);
    assert(graph_has_edge(dijkstra_result, 4, 5));
    assert(graph_get_edge_weight(dijkstra_result, 4, 5) == 26);
    assert(graph_size(dijkstra_result) == 6);

    List* expected_shortest_path = list_init(4, 1, 3, 4, 5);
    List* shortest_path = graph_shortest_path(g, 1, 5);
    printf("Shortest path from 1 -> 5: "); list_println(shortest_path);
    printf("Expected path from 1 -> 5: "); list_println(expected_shortest_path);
    assert(list_equal(shortest_path, expected_shortest_path));

    int minimum_distance = graph_minimum_distance(g, 1, 5);
    printf("Minimum distance from 1 -> 5: %d\n", minimum_distance);
    assert(minimum_distance == 26);

    list_free(expected_shortest_path);
    list_free(shortest_path);
    graph_free(g);
    graph_free(dijkstra_result);
}

void test_graph_kruskal() {
    puts("== Graph kruskal test");
    Graph *g = graph_create();
    graph_add_edge_with_weight(g, 1, 2, 10);
    graph_add_edge_with_weight(g, 1, 3, 20);
    graph_add_edge_with_weight(g, 2, 3, 5);
    graph_add_edge_with_weight(g, 3, 4, 30);
    graph_add_edge_with_weight(g, 4, 1, 9);
    graph_add_edge_with_weight(g, 5, 1, 7);

    printf(":: input graph\n");
    graph_print(g);

    printf(":: kruskal tree\n");
    Graph *g_kruskal = graph_kruskal(g);
    graph_print(g_kruskal);

    graph_free(g);
    graph_free(g_kruskal);
}


bool should_run_extra_tests(int argc, char *argv[]) {
    // Iterate through the command-line arguments starting from argv[1]
    // (argv[0] is the program name)
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--extra-tests") == 0) {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    int extra_tests = should_run_extra_tests(argc, argv);
    test_graph_directed();
    test_graph_undirected();
    test_bfs();
    test_dfs();
    test_graph_acyclical();
    test_graph_tarjan();
    test_graph_strong_components();
    test_graph_topological_sort();
    test_graph_dijkstra(extra_tests);
    test_graph_edges_ordered();
    test_graph_kruskal();
    if (should_run_extra_tests(argc, argv)) {
        test_graph_export();
    }

    printf("\nAll graph tests passed!\n");
    return 0;
}
