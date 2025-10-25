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
        HashTableGen *s = hash_table_gen_create(GRAPH_DEFAULT_N_BUCKETS);
        hash_table_gen_put(g->adj, node, s);
    }
}

void graph__add_weighted_edge(Graph *g, int u, int v, int weight) {
    graph_add_node(g, u);
    graph_add_node(g, v);
    HashTableGen *neighbors = hash_table_gen_get(g->adj, u, NULL);
    hash_table_gen_put(neighbors, v, (void*)(long)weight);
}

void graph_add_edge_with_weight(Graph *g, int u, int v, int weight) {
    graph__add_weighted_edge(g, u, v, weight);
    if (!g->directed) {
        graph__add_weighted_edge(g, v, u, weight);
    }
}

void graph_add_edge(Graph *g, int u, int v) {
    graph_add_edge_with_weight(g, u, v, 1);
}

void graph__remove_edge(Graph *g, int u, int v) {
    bool u_exists;
    HashTableGen *set_u = hash_table_gen_get(g->adj, u, &u_exists);

    if (u_exists) {
        hash_table_gen_remove(set_u, v);
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
    HashTableGen *adj_node = hash_table_gen_get(g->adj, node, &exists);
    if (exists) {
        hash_table_gen_free(adj_node, NULL); // we don't need a freer for the weights
        hash_table_gen_remove(g->adj, node);
    }

    ListGen *nodes = hash_table_gen_keys(g->adj);
    ListGen *current = nodes;
    while(current) {
        int u = (int)(long)current->data;
        HashTableGen *s = hash_table_gen_get(g->adj, u, NULL);
        hash_table_gen_remove(s, node);
        current = current->next;
    }
    list_gen_free(nodes);
}

bool graph_has_edge(Graph *g, int u, int v) {
    bool u_exists, v_exists;
    HashTableGen *neighbors_u = hash_table_gen_get(g->adj, u, &u_exists);
    if (!u_exists) {
        return false;
    }
    hash_table_gen_get(neighbors_u, v, &v_exists);
    return v_exists;
}

Set* graph_get_neighbors(Graph *g, int node) {
    bool exists;
    HashTableGen *neighbors = hash_table_gen_get(g->adj, node, &exists);
    if (!exists) {
        return set_create();
    }
    ListGen *nodes = hash_table_gen_keys(neighbors);
    Set *s = set_create();
    ListGen *current = nodes;
    while(current) {
        set_add(s, (int)(long)current->data);
        current = current->next;
    }
    list_gen_free(nodes);
    return s;
}

void graph_print(Graph *g) {
    ListGen *nodes = hash_table_gen_keys(g->adj);
    ListGen *current_node = nodes;
    while(current_node) {
        int u = (int)(long)current_node->data;
        printf("%d -> { ", u);
        HashTableGen *neighbors = hash_table_gen_get(g->adj, u, NULL);
        ListGen *neighbor_keys = hash_table_gen_keys(neighbors);
        ListGen *current_neighbor = neighbor_keys;
        while(current_neighbor) {
            int v = (int)(long)current_neighbor->data;
            int weight = (int)(long)hash_table_gen_get(neighbors, v, NULL);
            printf("(%d, w: %d)", v, weight);
            if(current_neighbor->next) {
                printf(", ");
            }
            current_neighbor = current_neighbor->next;
        }
        printf(" }\n");
        list_gen_free(neighbor_keys);
        current_node = current_node->next;
    }
    list_gen_free(nodes);
}


void free_inner_hash_table(void* ht) {
    hash_table_gen_free((HashTableGen*)ht, NULL);
}

void graph_free(Graph *g) {
    hash_table_gen_free(g->adj, free_inner_hash_table);
    free(g);
}

int graph_get_edge_weight(Graph *g, int u, int v) {
    bool u_exists, v_exists;
    HashTableGen *neighbors_u = hash_table_gen_get(g->adj, u, &u_exists);
    if (!u_exists) {
        return -1; // Or some other error indicator
    }
    void* weight_ptr = hash_table_gen_get(neighbors_u, v, &v_exists);
    if (!v_exists) {
        return -1; // Or some other error indicator
    }
    return (int)(long)weight_ptr;
}
