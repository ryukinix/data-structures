#include <stdlib.h>
#include "graph.h"
#include "../stack/stack.h"

struct CycleContext {
    int counter_exploration;
    int counter_complete;
    bool has_cycles;
    int *exploration;
    int *complete;
    Stack* cycle_path;
    Stack* topological_sort;
};

// detect if graph has cycles and save the topological sort
static void graph_dfsa(
    Graph *g,
    int node,
    struct CycleContext *cc
) {
    cc->exploration[node] = ++cc->counter_exploration;
    stack_push(cc->cycle_path, node);

    Set* neighbors_set = graph_get_neighbors(g, node);
    Iterator* set_it = set_iterator(neighbors_set);

    while (!iterator_done(set_it)) {
        int neighbor = *(int*) iterator_next(set_it);
        if (cc->exploration[neighbor] == 0) {
            graph_dfsa(g, neighbor, cc);
        } else if (cc->exploration[neighbor] < cc->exploration[node] && cc->complete[neighbor] == 0) {
            cc->has_cycles = true;
        }
        if (cc->has_cycles) {
            break;
        }
    }
    set_free(neighbors_set);
    iterator_free(set_it);
    // early stop
    if (cc->has_cycles) {
        return;
    }

    stack_push(cc->topological_sort, node);
    stack_pop(cc->cycle_path);
    cc->complete[node] = ++cc->counter_complete;
}

struct CycleContext* cycle_context_create(Graph *g) {
    struct CycleContext *cc = malloc(sizeof(struct CycleContext));
    int max_nodes = graph_max_node_id(g) + 1;

    cc->topological_sort = stack_create();
    cc->cycle_path = stack_create();
    cc->exploration = malloc(max_nodes * sizeof(int));
    cc->complete = malloc(max_nodes * sizeof(int));
    cc->counter_complete = 0;
    cc->counter_exploration = 0;
    cc->has_cycles = false;

    // initialize arrays
    for (int i = 0; i < max_nodes; i++) {
        cc->exploration[i] = 0;
        cc->complete[i] = 0;
    }

    return cc;
}

void cycle_context_free(struct CycleContext *cc) {
    free(cc->exploration);
    free(cc->complete);
    stack_free(cc->topological_sort);
    stack_free(cc->cycle_path);
    free(cc);
}

static struct CycleContext* graph_check_cycles(Graph *g) {
    struct CycleContext *cc = cycle_context_create(g);

    // dfs over each node
    Iterator *nodes = graph_nodes_iterator(g);
    while (!iterator_done(nodes)) {
        int node = *(int*) iterator_next(nodes);

        if (cc->exploration[node] == 0) {
            graph_dfsa(
                g,
                node,
                cc
            );
        }

        if (cc->has_cycles) {
            //printf("Cycle: "); stack_println(cc->cycle_path);
            break;
        }

    }
    iterator_free(nodes);
    return cc;
}

bool graph_acyclical(Graph *g) {
    struct CycleContext *cc = graph_check_cycles(g);
    bool has_cycles = cc->has_cycles;
    cycle_context_free(cc);
    return !has_cycles;
}

List* graph_topological_sort(Graph *g) {
    struct CycleContext *cc = graph_check_cycles(g);
    if (cc->has_cycles) {
        cycle_context_free(cc);
        return NULL;
    }
    Iterator *it = stack_iterator(cc->topological_sort);
    List *list = list_from_iterator(it);
    iterator_free(it);
    cycle_context_free(cc);
    return list;
}
