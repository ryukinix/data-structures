#include "graph.h"
#include "../set/set-disjoint.h"

Graph* graph_kruskal(Graph *g) {
    Graph *g_kruskal = graph_undirected_create();
    DisjointSet *components = set_disjoint_create(graph_max_node_id(g) + 1);
    List *edges = graph_edges_ordered(g);
    Iterator *it = list_iterator(edges);

    while (!iterator_done(it)) {
        List *edge = (List*) iterator_next(it);
        int u = edge->key;
        int v = edge->data;
        if (set_disjoint_find(components, u) != set_disjoint_find(components, v)) {
            graph_add_edge_with_weight(g_kruskal, u, v, graph_get_edge_weight(g, u, v));
            set_disjoint_union(components, u, v);
        }
    }

    set_disjoint_free(components);
    iterator_free(it);
    list_free(edges);
    return g_kruskal;
}
