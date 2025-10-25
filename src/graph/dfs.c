#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "../stack/stack.h"
#include "../list/single/list.h"

typedef struct GraphIteratorContext {
    Graph* graph;
    Iterator* nodes;
    Stack* stack;
    Set* visited;
    List* path;
} GraphIteratorContext;

static void graph_visit_if_necessary(GraphIteratorContext* it_context, int node) {
    if (!set_contains(it_context->visited, node)) {
        set_add(it_context->visited, node);
        stack_push(it_context->stack, node);
    }
}

bool graph_dfs_done(Iterator* it) {
    GraphIteratorContext* it_context = (GraphIteratorContext*) it->container;
    bool stack_is_empty = stack_empty(it_context->stack);
    if (!graph_is_directed(it_context->graph)) {
        return stack_is_empty;
    }

    // ensure visite all nodes
    while (stack_empty(it_context->stack) && !iterator_done(it_context->nodes)) {
        int node = *(int*)iterator_next(it_context->nodes);
        graph_visit_if_necessary(it_context, node);
    }

    return stack_empty(it_context->stack);
}

void graph_dfs_free(Iterator* it) {
    GraphIteratorContext* it_context = (GraphIteratorContext*) it->container;
    stack_free(it_context->stack);
    set_free(it_context->visited);
    list_free(it_context->path);
    iterator_free(it_context->nodes);
    free(it->container);
    free(it);
}

void* graph_dfs_next(Iterator* it) {
    GraphIteratorContext* it_context = (GraphIteratorContext*) it->container;
    int current_node = stack_pop(it_context->stack);

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

Iterator* graph_dfs(Graph* g, int start_node) {
    // 1. Create a stack for the nodes to visit and a set for visited nodes.
    Stack* q = stack_create();
    Set* visited = set_create();
    List* path = list_create();

    // 2. Add the starting node to the stack and the visited set.
    stack_push(q, start_node);
    set_add(visited, start_node);

    GraphIteratorContext* it_context = malloc(sizeof(GraphIteratorContext));
    it_context->graph = g;
    it_context->nodes = graph_nodes_iterator(g);
    it_context->visited = visited;
    it_context->stack = q;
    it_context->path = path;

    return iterator_create(
        it_context,
        graph_dfs_next,
        graph_dfs_free,
        graph_dfs_done
    );
}
