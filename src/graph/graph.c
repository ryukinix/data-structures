#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "../hash-table/hash-table-gen.h"

#define GRAPH_DEFAULT_N_BUCKETS 128

struct Graph {
    HashTableGen *adj;
};

Graph* graph_create() {
    Graph *g = malloc(sizeof(Graph));
    if (!g) {
        return NULL;
    }
    g->adj = hash_table_gen_create(GRAPH_DEFAULT_N_BUCKETS);
    if (!g->adj) {
        free(g);
        return NULL;
    }
    return g;
}

void graph_add_node(Graph *g, int node) {
    bool exists;
    hash_table_gen_get(g->adj, node, &exists);
    if (!exists) {
        Set *s = set_create();
        hash_table_gen_put(g->adj, node, s);
    }
}

void graph_add_edge(Graph *g, int u, int v) {
    graph_add_node(g, u);
    graph_add_node(g, v);
    Set *set_u = hash_table_gen_get(g->adj, u, NULL);
    set_add(set_u, v);
}

void graph_remove_edge(Graph *g, int u, int v) {
    bool u_exists, v_exists;
    Set *set_u = hash_table_gen_get(g->adj, u, &u_exists);
    hash_table_gen_get(g->adj, v, &v_exists);

    if (u_exists && v_exists) {
        set_remove(set_u, v);
    }
}

void graph_remove_node(Graph *g, int node) {
    bool exists;
    Set *adj_node = hash_table_gen_get(g->adj, node, &exists);
    if (exists) {
        set_free(adj_node);
        hash_table_gen_remove(g->adj, node);
    }

    ListGen *nodes = hash_table_gen_keys(g->adj);
    ListGen *current = nodes;
    while(current) {
        int u = (int)(long)current->data;
        Set *s = hash_table_gen_get(g->adj, u, NULL);
        set_remove(s, node);
        current = current->next;
    }
    list_gen_free(nodes);
}

bool graph_has_edge(Graph *g, int u, int v) {
    bool exists;
    Set *set_u = hash_table_gen_get(g->adj, u, &exists);
    if (!exists) {
        return false;
    }
    return set_contains(set_u, v);
}

Set* graph_get_neighbors(Graph *g, int node) {
    bool exists;
    Set *neighbors = hash_table_gen_get(g->adj, node, &exists);
    if (!exists) {
        return set_create();
    }
    return set_copy(neighbors);
}

void graph_print(Graph *g) {
    ListGen *nodes = hash_table_gen_keys(g->adj);
    ListGen *current = nodes;
    while(current) {
        int u = (int)(long)current->data;
        printf("%d -> ", u);
        Set *s = hash_table_gen_get(g->adj, u, NULL);
        set_print(s);
        current = current->next;
    }
    list_gen_free(nodes);
}


void graph_free(Graph *g) {
    hash_table_gen_free(g->adj, (void (*)(void*))set_free);
    free(g);
}
