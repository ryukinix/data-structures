#include "graph.h"
#include "../stack/stack.h"

struct TarjanContext {
    Graph* g_tarjan;
    int counter_exploration;
    int counter_complete;
    int *exploration;
    int *complete;
};

EdgeType tarjan_classify_edge(struct TarjanContext *tc, int parent, int u) {
    if (tc->exploration[u] == 0) {
        return TREE;
    } else if (tc->exploration[u] > tc->exploration[parent]) {
        return FORWARD;
    } else if (tc->complete[u] > 0) {
        return CROSS;
    } else {
        return BACK;
    }
}

// detect if graph has cycles
static void graph_dfsj(
    Graph *g,
    int node,
    struct TarjanContext *tc
) {
    tc->exploration[node] = ++tc->counter_exploration;

    Set* neighbors_set = graph_get_neighbors(g, node);
    Iterator* set_it = set_iterator(neighbors_set);

    while (!iterator_done(set_it)) {
        int neighbor = *(int*) iterator_next(set_it);
        EdgeType edge_type = tarjan_classify_edge(tc, node, neighbor);
        if (!graph_has_edge(tc->g_tarjan, node, neighbor)) {
            graph_add_edge_with_weight(tc->g_tarjan, node, neighbor, edge_type);
        }

        if (edge_type == TREE) {
            graph_dfsj(g, neighbor, tc);
        }
    }
    set_free(neighbors_set);
    iterator_free(set_it);

    tc->complete[node] = ++tc->counter_complete;
}


Graph* graph_tarjan(Graph *g) {
    struct TarjanContext tc;
    int exploration[graph_size(g)];
    int complete[graph_size(g)];

    tc.g_tarjan = graph_tarjan_create(graph_is_directed(g));
    tc.counter_complete = 0;
    tc.counter_exploration = 0;
    tc.exploration = exploration;
    tc.complete = complete;

    Iterator *nodes;

    // initialize
    nodes = graph_nodes_iterator(g);
    while (!iterator_done(nodes)) {
        int node = *(int*) iterator_next(nodes);
        exploration[node] = 0;
        complete[node] = 0;
    }
    iterator_free(nodes);

    // dfs over each node
    nodes = graph_nodes_iterator(g);
    while (!iterator_done(nodes)) {
        int node = *(int*) iterator_next(nodes);
        if (tc.exploration[node] == 0) {
            graph_dfsj(g, node, &tc);
        }

    }
    iterator_free(nodes);
    return tc.g_tarjan;
}
