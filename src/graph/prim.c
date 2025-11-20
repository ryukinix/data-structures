#include "graph.h"
#include "../utils/pair_hash.h"
#include "../pqueue/pqueue.h"

void update_heap(Graph* g, PQueue* pq, Set* visited, int start) {
    Set* neighbors = graph_get_neighbors(g, start);
    Iterator *it = set_iterator_items(neighbors);
    while (!iterator_done(it)) {
        List *neighbor_weight = (List*) iterator_next(it);
        if (!set_contains(visited, neighbor_weight->key)) {
            int k = pair_hash(start, neighbor_weight->key);
            int w = neighbor_weight->data;
            pqueue_insert(pq, k, w);
        }
    }
    set_free(neighbors);
    iterator_free(it);
}

// WARNING: this implementation only return the Minimum Spanning Tree
// of conected component from <start> node. If some node is
// unreachable from <start> will be not included in the final tree.
Graph* graph_prim(Graph *g, int start) {
    Graph* g_prim = graph_create();
    Set* visited = set_create();
    PQueue *pq = pqueue_create(MIN_PQUEUE);
    update_heap(g, pq, visited, start);
    set_add(visited, start);

    while (!pqueue_is_empty(pq)) {
        PQueueNode node = pqueue_extract(pq);
        int u = unpair_hash_x(node.key);
        int v = unpair_hash_y(node.key);
        int w = node.value;
        if (set_contains(visited, v)) {
            continue;
        }
        graph_add_edge_with_weight(g_prim, u, v, w);
        set_add(visited, v);
        update_heap(g, pq, visited, v);
    }

    return g_prim;
}
