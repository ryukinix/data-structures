#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "../hash-table/hash-table-gen.h"

#define GRAPH_DEFAULT_N_BUCKETS 128

struct Graph {
    HashTableGen *adj;
    bool directed; // true by default
};

Graph* graph_create() {
    Graph *g = malloc(sizeof(Graph));
    if (!g) {
        return NULL;
    }
    g->adj = hash_table_gen_create(GRAPH_DEFAULT_N_BUCKETS);
    g->directed = true;
    if (!g->adj) {
        free(g);
        return NULL;
    }
    return g;
}

Graph* graph_undirected_create() {
    Graph *g = graph_create();
    g->directed = false;
    return g;
}

bool graph_is_directed(Graph* g) {
    return g->directed;
}

void graph_add_node(Graph *g, int node) {
    bool exists;
    hash_table_gen_get(g->adj, node, &exists);
    if (!exists) {
        Set *s = set_create();
        hash_table_gen_put(g->adj, node, s);
    }
}

void graph_add_edge_with_weight(Graph *g, int u, int v, int weight) {
    graph_add_node(g, u);
    graph_add_node(g, v);
    Set *set_u = hash_table_gen_get(g->adj, u, NULL);
    set_add_with_value(set_u, v, weight);

    if (!g->directed) {
        Set *set_v = hash_table_gen_get(g->adj, v, NULL);
        set_add_with_value(set_v, u, weight);
    }
}

void graph_add_edge(Graph *g, int u, int v) {
    graph_add_edge_with_weight(g, u, v, 1);
}

void graph__remove_edge(Graph *g, int u, int v) {
    bool u_exists, v_exists;
    Set *set_u = hash_table_gen_get(g->adj, u, &u_exists);
    hash_table_gen_get(g->adj, v, &v_exists);

    if (u_exists && v_exists) {
        set_remove(set_u, v);
    }
}

void graph_remove_edge(Graph *g, int u, int v) {
    graph__remove_edge(g, u, v);
    if (!g->directed) {
        graph__remove_edge(g, v, u);
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

int graph_get_edge_weight(Graph *g, int u, int v) {
    bool exists;
    Set *set_u = hash_table_gen_get(g->adj, u, &exists);
    if (!exists) {
        return -1;
    }
    if (!set_contains(set_u, v)) {
        return -1;
    }
    return set_get_value(set_u, v);
}

void graph_print(Graph *g) {
    ListGen *nodes = hash_table_gen_keys(g->adj);
    ListGen *current_node = nodes;
    while(current_node) {
        int u = (int)(long)current_node->data;
        printf("%d -> { ", u);
        Set *neighbors = hash_table_gen_get(g->adj, u, NULL);
        Iterator *it = set_iterator(neighbors);
        while(!iterator_done(it)) {
            int v = *(int*)iterator_next(it);
            int weight = set_get_value(neighbors, v);
            printf("(%d, w: %d)", v, weight);
            if(!iterator_done(it)) {
                printf(", ");
            }
        }
        iterator_free(it);
        printf(" }\n");
        current_node = current_node->next;
    }
    list_gen_free(nodes);
}


void graph_free(Graph *g) {
    hash_table_gen_free(g->adj, (void (*)(void*))set_free);
    free(g);
}