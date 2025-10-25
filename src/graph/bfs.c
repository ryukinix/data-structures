#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "../queue/queue.h"
#include "../list/single/list.h"

typedef struct GraphIteratorContext {
    Graph* graph;
    Iterator* nodes;
    Queue* queue;
    Set* visited;
    List* path;
} GraphIteratorContext;


void graph_visit_if_necessary(GraphIteratorContext* it_context, int node) {
    if (!set_contains(it_context->visited, node)) {
        set_add(it_context->visited, node);
        queue_insert(it_context->queue, node);
    }
}

bool graph_bfs_done(Iterator* it) {
    GraphIteratorContext* it_context = (GraphIteratorContext*) it->container;
    bool queue_is_empty = queue_empty(it_context->queue);
    if (!graph_is_directed(it_context->graph)) {
        return queue_is_empty;
    }

    // ensure visite all nodes
    while (queue_empty(it_context->queue) && !iterator_done(it_context->nodes)) {
        int node = *(int*)iterator_next(it_context->nodes);
        graph_visit_if_necessary(it_context, node);
    }

    return queue_empty(it_context->queue);
}

void graph_bfs_free(Iterator* it) {
    GraphIteratorContext* it_context = (GraphIteratorContext*) it->container;
    queue_free(it_context->queue);
    set_free(it_context->visited);
    list_free(it_context->path);
    iterator_free(it_context->nodes);
    free(it->container);
    free(it);
}

void* graph_bfs_next(Iterator* it) {
    GraphIteratorContext* it_context = (GraphIteratorContext*) it->container;
    int current_node = queue_remove(it_context->queue);

    // Save in a internal list: why? I need to return a pointer of the data
    it_context->path = list_insert(it_context->path, current_node);

    // Get the neighbors of the current node.
    Set* neighbors_set = graph_get_neighbors(it_context->graph, current_node);
    Iterator* set_it = set_iterator(neighbors_set); // Helper function
    // Iterate over the neighbors.
    while (!iterator_done(set_it)) {
        int neighbor = *(int*)iterator_next(set_it);
        graph_visit_if_necessary(it_context, neighbor);
    }

    iterator_free(set_it);
    set_free(neighbors_set);

    return &it_context->path->data;
}

Iterator* graph_bfs(Graph* g, int start_node) {
    // 1. Create a queue for the nodes to visit and a set for visited nodes.
    Queue* q = queue_create();
    Set* visited = set_create();

    // 2. Add the starting node to the queue and the visited set.
    queue_insert(q, start_node);
    set_add(visited, start_node);

    GraphIteratorContext* it_context = malloc(sizeof(GraphIteratorContext));
    it_context->graph = g;
    it_context->nodes = graph_nodes_iterator(g);
    it_context->visited = visited;
    it_context->queue = q;
    it_context->path = list_create();

    return iterator_create(
        it_context,
        graph_bfs_next,
        graph_bfs_free,
        graph_bfs_done
    );
}
