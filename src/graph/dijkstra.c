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
#include "pqueue/pqueue.h"
#include "iterator/iterator.h"
#include "utils/check_alloc.h"

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
