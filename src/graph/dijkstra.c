/**
 * ===============================================
 *
 *         Copyright 2025 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: ITA
 *
 * ===============================================
 */

#include <limits.h>
#include "graph.h"
#include "../pqueue/pqueue.h"
#include "../stack/stack.h"
#include "../iterator/iterator.h"

#define DIJKSTRA_INFINITY INT_MAX

Graph* graph_dijkstra(Graph* g, int source) {
    int n = graph_max_node_id(g) + 1;
    int dist[n];
    int prev[n];

    for (int i = 0; i < n; i++) {
        dist[i] = DIJKSTRA_INFINITY;
        prev[i] = -1;
    }

    dist[source] = 0;

    PQueue *pq = pqueue_create(MIN_PQUEUE);
    pqueue_insert(pq, source, 0);

    while (!pqueue_is_empty(pq)) {
        PQueueNode u_node = pqueue_extract(pq);
        int u = u_node.key;

        Set *neighbors = graph_get_neighbors(g, u);
        Iterator *it = set_iterator(neighbors);

        while (!iterator_done(it)) {
            int v = *(int*) iterator_next(it);
            int weight = graph_get_edge_weight(g, u, v);
            if (dist[u] != DIJKSTRA_INFINITY && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pqueue_update_key(pq, v, dist[v]);
            }
        }
        iterator_free(it);
        set_free(neighbors);
    }

    Graph *g_new = graph_create();
    for (int i = 0; i < n; i++) {
        if (prev[i] != -1) {
            graph_add_node(g_new, i);
            graph_add_node(g_new, prev[i]);
            graph_add_edge_with_weight(g_new, prev[i], i, dist[i]);
        }
    }

    pqueue_free(pq);

    return g_new;
}

List* graph_shortest_path(Graph* g, int source, int destination) {
    Graph* g_dijkstra = graph_dijkstra(g, source);

    Stack* dfs = stack_create();
    // tracing parents of the path
    HashTable* prev = hash_table_create(graph_size(g_dijkstra));
    Set* visited = set_create();

    stack_push(dfs, source);
    while (!stack_empty(dfs)) {
        int node = stack_pop(dfs);
        set_add(visited, node);

        Set *neighbors = graph_get_neighbors(g_dijkstra, node);
        Iterator *it = set_iterator(neighbors);

        while (!iterator_done(it)) {
            int neighbor = *(int*) iterator_next(it);
            hash_table_put(prev, neighbor, node);
            if (!set_contains(visited, neighbor)) {
                stack_push(dfs, neighbor);
            }
        }
        set_free(neighbors);
        iterator_free(it);
    }
    stack_free(dfs);
    set_free(visited);
    graph_free(g_dijkstra);

    int visiting_node = destination;
    List* path = list_init(1, destination);
    while (visiting_node != source) {
        bool exists;
        int parent = hash_table_get(prev, visiting_node, &exists);
        if (!exists) {
            path = NULL;
            break;
        }
        path = list_insert(path, parent);
        visiting_node = parent;
    }
    hash_table_free(prev);

    return path;
}

int graph_minimum_distance(Graph* g, int source, int destination) {
    Graph* g_dijkstra = graph_dijkstra(g, source);
    List* edges = graph_edges(g_dijkstra);
    Iterator* it = list_iterator(edges);

    int distance = -1;
    while (!iterator_done(it)) {
        struct ListNode* edge = (struct ListNode*) iterator_next(it);

        if (edge->data == destination) {
            distance = graph_get_edge_weight(g_dijkstra, edge->key, edge->data);
            break;
        }
    }

    list_free(edges);
    iterator_free(it);
    graph_free(g_dijkstra);


    return distance;
}
