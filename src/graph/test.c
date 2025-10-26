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
    test_graph_directed();
    test_graph_undirected();
    test_bfs();
    test_dfs();
    test_graph_acyclical();
    test_graph_tarjan();
    if (should_run_extra_tests(argc, argv)) {
        test_graph_export();
    }

    printf("\nAll graph tests passed!\n");
    return 0;
}
