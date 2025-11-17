#include "graph.h"
#include "../stack/stack.h"

struct TarjanContext {
    Graph* g_tarjan;
    int *components;
    Stack* path; // for strong connected components
    int counter_exploration;
    int counter_complete;
    int *exploration;
    int *complete;
};

void free_tarjan_context(struct TarjanContext *tc) {
    // keep on memor: g_tarjan + componentes
    free(tc->exploration);
    free(tc->complete);
    stack_free(tc->path);
    free(tc);
}

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

int update_components(struct TarjanContext *tc, EdgeType edge_type, int u, int v) {
    if (edge_type == TREE) {
        int tcu = tc->components[u];
        int tcv = tc->components[v];
        return tcu < tcv? tcu: tcv;
    } else if (stack_has(tc->path, v)) {
        int tcu = tc->components[u];
        int exv = tc->exploration[v];
        return tcu < exv? tcu: exv;
    }
    return tc->components[u];
}


static void graph_dfst(
    Graph *g,
    int node,
    struct TarjanContext *tc
) {
    tc->exploration[node] = ++tc->counter_exploration;
    tc->components[node] = tc->exploration[node];
    stack_push(tc->path, node);
    Set* neighbors_set = graph_get_neighbors(g, node);
    Iterator* set_it = set_iterator(neighbors_set);

    while (!iterator_done(set_it)) {
        int neighbor = *(int*) iterator_next(set_it);
        EdgeType edge_type = tarjan_classify_edge(tc, node, neighbor);
        if (!graph_has_edge(tc->g_tarjan, node, neighbor)) {
            graph_add_edge_with_weight(tc->g_tarjan, node, neighbor, edge_type);
        }

        if (edge_type == TREE) {
            graph_dfst(g, neighbor, tc);
        }

        tc->components[node] = update_components(tc, edge_type, node, neighbor);
    }

    // pop elements for components visited in a cycle
    if (tc->components[node] == tc->exploration[node]) {
        while (stack_pop(tc->path) != node);
    }
    set_free(neighbors_set);
    iterator_free(set_it);

    tc->complete[node] = ++tc->counter_complete;
}

struct TarjanContext* graph_tarjan_explore(Graph *g) {
    struct TarjanContext *tc = (struct TarjanContext*) malloc(sizeof(struct TarjanContext));
    int max_node_id = graph_max_node_id(g);
    int n = max_node_id + 1;
    int *exploration = (int*) malloc(n * sizeof(int));
    int *complete = (int*) malloc(n * sizeof(int));
    int *components= (int*) malloc(n * sizeof(int));

    // initialize arrays
    for (int i = 0; i < n; i++) {
        exploration[i] = 0;
        complete[i] = 0;
        components[i] = -1;
    }

    tc->g_tarjan = graph_tarjan_create(graph_is_directed(g));
    tc->counter_complete = 0;
    tc->counter_exploration = 0;
    tc->exploration = exploration;
    tc->complete = complete;
    tc->components = components;
    tc->path = stack_create();

    // dfs over each node
    Iterator *nodes = graph_nodes_iterator(g);
    while (!iterator_done(nodes)) {
        int node = *(int*) iterator_next(nodes);
        if (tc->exploration[node] == 0) {
            graph_dfst(g, node, tc);
        }

    }
    iterator_free(nodes);
    return tc;
}

Graph* graph_tarjan(Graph *g) {
    struct TarjanContext *tc= graph_tarjan_explore(g);
    Graph* g_tarjan = tc->g_tarjan;
    free(tc->components);
    free_tarjan_context(tc);
    return g_tarjan;
}

int* graph_strong_components(Graph *g) {
    struct TarjanContext *tc= graph_tarjan_explore(g);
    int* components = tc->components;
    graph_free(tc->g_tarjan);
    free_tarjan_context(tc);
    return components;
}
