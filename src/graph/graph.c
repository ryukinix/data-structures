#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "../hash-table/hash-table-gen.h"

#define GRAPH_DEFAULT_N_BUCKETS 128

struct Graph {
    HashTableGen *adj;
    bool directed; // true by default
    bool weighted; // false by default
    bool tarjan;   // false by default
};

Graph* graph_create() {
    Graph *g = (Graph*) malloc(sizeof(Graph));
    if (!g) {
        return NULL;
    }
    g->adj = hash_table_gen_create(GRAPH_DEFAULT_N_BUCKETS);
    g->directed = true;
    g->weighted = false;
    g->tarjan = false;
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

Graph* graph_tarjan_create(bool directed) {
    Graph *g = graph_create();
    g->directed = directed;
    g->weighted = true;
    g->tarjan = true;
    return g;
}

static void graph_nodes_iterator_free(Iterator *it) {
    list_free((List*)it->begin);
    free(it);
}

Iterator* graph_nodes_iterator(Graph *g) {
    List *nodes = hash_table_gen_keys(g->adj);
    list_sort(&nodes);
    Iterator *iterator = list_iterator_data(nodes);
    iterator->free = &graph_nodes_iterator_free;
    return iterator;
}

List* graph_edges(Graph *g) {
    Iterator *nodes = graph_nodes_iterator(g);
    List *edges = list_create();
    while (!iterator_done(nodes)) {
        int node = *(int*) iterator_next(nodes);

        Set* neighbors = graph_get_neighbors(g, node);
        Iterator* set_it = set_iterator(neighbors);

        while (!iterator_done(set_it)) {
            int neighbor = *(int*) iterator_next(set_it);

            edges = list_insert_with_key(edges, node, neighbor);
        }
        set_free(neighbors);
        iterator_free(set_it);
    }
    iterator_free(nodes);
    return edges;
}

int graph_edges_count(Graph *g) {
    Iterator *nodes = graph_nodes_iterator(g);
    int n_edges = 0;
    while (!iterator_done(nodes)) {
        int node = *(int*) iterator_next(nodes);
        Set* neighbors = graph_get_neighbors(g, node);
        n_edges += set_size(neighbors);
        set_free(neighbors);
    }
    iterator_free(nodes);
    return n_edges;
}

// compare edges in descending order
int _compare_edge_weight(const void *a, const void *b) {
    int x = *((const int*)a + 2);
    int y = *((const int*)b + 2);
    if (x < y) {
        return 1;
    } else if (x > y) {
        return -1;
    } else {
        return 0;
    }
}

// return a list of edges ordered in ascending order
List* graph_edges_ordered(Graph *g) {
    int edges_count = graph_edges_count(g);
    int edges_by_weight[edges_count][3];
    List *edges = graph_edges(g);
    Iterator *it = list_iterator(edges);
    int rows = 0;
    while (!iterator_done(it)) {
        List *edge = (List*) iterator_next(it);
        int u = edge->key;
        int v = edge->data;
        int w = graph_get_edge_weight(g, u, v);
        edges_by_weight[rows][0] = u;
        edges_by_weight[rows][1] = v;
        edges_by_weight[rows][2] = w;
        rows++;
    }
    iterator_free(it);
    list_free(edges);

    qsort(edges_by_weight, edges_count, sizeof(int) * 3, _compare_edge_weight);
    List *edges_ordered = list_create();
    for (int i = 0; i < edges_count; i++) {
        int u = edges_by_weight[i][0];
        int v = edges_by_weight[i][1];
        edges_ordered = list_insert_with_key(edges_ordered, u, v);
    }

    return edges_ordered;
}


List* graph_remove_duplicated_edges(List* edges) {
    List *node = edges;
    while (node != NULL) {
        int u = node->key;
        int v = node->data;
        edges = list_remove_by_key_data(edges, v, u);
        node = node->next;
    }
    return edges;
}

int graph_edges_sum(Graph *g) {
    int s = 0;
    List *edges = graph_edges(g);

    if (!g->directed) {
        edges = graph_remove_duplicated_edges(edges);
    }

    Iterator *it = list_iterator(edges);
    while (!iterator_done(it)) {
        List *node = (List*) iterator_next(it);
        int u = node->key;
        int v = node->data;
        s += graph_get_edge_weight(g, u, v);
    }
    list_free(edges);
    iterator_free(it);
    return s;
}

size_t graph_size(Graph *g) {
    return hash_table_gen_size(g->adj);
}

int graph_max_node_id(Graph *g) {
    Iterator *it = graph_nodes_iterator(g);
    int max_node_id = iterator_max_int(it);
    iterator_free(it);
    return max_node_id;
}

bool graph_is_directed(Graph *g) {
    return g->directed;
}

bool graph_is_weighted(Graph *g) {
    return g->weighted;
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
    Set *set_u = (Set*) hash_table_gen_get(g->adj, u, NULL);
    set_add_with_value(set_u, v, weight);
    g->weighted = true;

    if (!g->directed) {
        Set *set_v = (Set*) hash_table_gen_get(g->adj, v, NULL);
        set_add_with_value(set_v, u, weight);
    }
}

void graph_add_edge(Graph *g, int u, int v) {
    graph_add_node(g, u);
    graph_add_node(g, v);
    Set *set_u = (Set*) hash_table_gen_get(g->adj, u, NULL);
    set_add(set_u, v);

    if (!g->directed) {
        Set *set_v = (Set*) hash_table_gen_get(g->adj, v, NULL);
        set_add(set_v, u);
    }
}

void graph__remove_edge(Graph *g, int u, int v) {
    bool u_exists, v_exists;
    Set *set_u = (Set*) hash_table_gen_get(g->adj, u, &u_exists);
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
    Set *adj_node = (Set*) hash_table_gen_get(g->adj, node, &exists);
    if (exists) {
        set_free(adj_node);
        hash_table_gen_remove(g->adj, node);
    }

    List *nodes = hash_table_gen_keys(g->adj);
    Iterator *it = list_iterator_data(nodes);
    while(!iterator_done(it)) {
        int u = *(int*)iterator_next(it);
        Set *s = (Set*) hash_table_gen_get(g->adj, u, NULL);
        set_remove(s, node);
    }
    list_free(nodes);
    iterator_free(it);
}

bool graph_has_edge(Graph *g, int u, int v) {
    bool exists;
    Set *set_u = (Set*) hash_table_gen_get(g->adj, u, &exists);
    if (!exists) {
        return false;
    }
    return set_contains(set_u, v);
}

bool graph_has_node(Graph *g, int u) {
    bool exists;
    hash_table_gen_get(g->adj, u, &exists);
    return exists;
}

Set* graph_get_neighbors(Graph *g, int node) {
    bool exists;
    Set *neighbors = (Set*) hash_table_gen_get(g->adj, node, &exists);
    if (!exists) {
        return set_create();
    }
    return set_copy(neighbors);
}

int graph_get_edge_weight(Graph *g, int u, int v) {
    bool exists;
    Set *set_u = (Set*) hash_table_gen_get(g->adj, u, &exists);
    if (!exists) {
        return -1;
    }
    if (!set_contains(set_u, v)) {
        return -1;
    }
    return set_get_value(set_u, v);
}

void graph_print(Graph *g) {
    Iterator *it = graph_nodes_iterator(g);
    while(!iterator_done(it)) {
        int u = *(int*)iterator_next(it);
        printf("%d: ", u);
        Set *neighbors = (Set*) hash_table_gen_get(g->adj, u, NULL);
        if (g->tarjan) {
            Iterator *neighbors_it = set_iterator_items(neighbors);
            printf("{");
            while (!iterator_done(neighbors_it)) {
                List *list = (List*) iterator_next(neighbors_it);
                printf("%d:%s", list->key, graph_edge_type_name((EdgeType)list->data));
                if (!iterator_done(neighbors_it)) {
                    printf(", ");
                }
            }
            printf("}\n");
            iterator_free(neighbors_it);
        } else if (g->weighted) {
            set_print_items(neighbors);
        } else {
            set_print(neighbors);
        }
    }
    iterator_free(it);
}


void graph_free(Graph *g) {
    hash_table_gen_free(g->adj, (void (*)(void*))set_free);
    free(g);
}

void graph_export_to_dot(Graph *g, const char* filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file %s for writing\n", filename);
        return;
    }

    fprintf(fp, "%s G {\n", g->directed ? "digraph" : "graph");

    List *nodes = hash_table_gen_keys(g->adj);
    List *current_node = nodes;
    while(current_node) {
        int u = (int)(long)current_node->data;
        fprintf(fp, "    %d;\n", u); // Declare nodes
        current_node = current_node->next;
    }
    list_free(nodes);


    nodes = hash_table_gen_keys(g->adj);
    current_node = nodes;
    while (current_node) {
        int u = (int)(long)current_node->data;
        Set *neighbors = (Set*) hash_table_gen_get(g->adj, u, NULL);
        Iterator *it = set_iterator(neighbors);
        while (!iterator_done(it)) {
            int v = *(int*)iterator_next(it);
            if (g->directed || u < v) { // Avoid duplicate edges in undirected graphs
                fprintf(fp, "    %d %s %d", u, g->directed ? "->" : "--", v);
                if (g->tarjan) {
                    int edge_type = set_get_value(neighbors, v);
                    fprintf(fp, " [label=\"%s\"]", graph_edge_type_name((EdgeType)edge_type));
                } else if (g->weighted) {
                    int weight = set_get_value(neighbors, v);
                    fprintf(fp, " [label=\"%d\"]", weight);
                }
                fprintf(fp, ";\n");
            }
        }
        iterator_free(it);
        current_node = current_node->next;
    }
    list_free(nodes);

    fprintf(fp, "}\n");
    fclose(fp);
}


bool graph_is_dag(Graph* g) {
    return g->directed && graph_acyclical(g);
}
