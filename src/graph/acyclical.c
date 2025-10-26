#include <stdlib.h>
#include "graph.h"
#include "../stack/stack.h"

struct CycleContext {
    Stack* cycle_path;
    Stack* topological_sort;
    int counter_exploration;
    int counter_complete;
    int *exploration;
    int *complete;
    bool has_cycles;
};

// detect if graph has cycles
static void graph_dfsa(
    Graph *g,
    int node,
    struct CycleContext *sc
) {
    sc->exploration[node] = ++sc->counter_exploration;
    stack_push(sc->cycle_path, node);

    Set* neighbors_set = graph_get_neighbors(g, node);
    Iterator* set_it = set_iterator(neighbors_set);

    while (!iterator_done(set_it)) {
        int neighbor = *(int*) iterator_next(set_it);
        if (sc->exploration[neighbor] == 0) {
            graph_dfsa(g, neighbor, sc);
        } else if (sc->exploration[neighbor] < sc->exploration[node] && sc->complete[neighbor] == 0) {
            sc->has_cycles = true;
        }
        if (sc->has_cycles) {
            break;
        }
    }
    set_free(neighbors_set);
    iterator_free(set_it);
    // early stop
    if (sc->has_cycles) {
        return;
    }

    stack_push(sc->topological_sort, node);
    stack_pop(sc->cycle_path);
    sc->complete[node] = ++sc->counter_complete;
}

struct CycleConext* cycle_context_create(Graph *g) {
    struct CycleContext *sc = malloc(sizeof(struct CycleContext));

    sc->topological_sort = stack_create();
    sc->cycle_path = stack_create();
    sc->counter_complete = 0;
    sc->counter_exploration = 0;
    sc->exploration = malloc(graph_size(g) * sizeof(int));
    sc->complete = malloc(graph_size(g) * sizeof(int));
    sc->has_cycles = false;

    return sc;
}

void cycle_context_free(struct CycleContext *sc) {
    free(sc->exploration);
    free(sc->complete);
    stack_free(sc->topological_sort);
    stack_free(sc->cycle_path);
    free(sc);
}

static struct CycleContext* graph_check_cycles(Graph *g) {
    struct CycleContext *sc = cycle_context_create(g);
    Iterator *nodes;

    // initialize
    nodes = graph_nodes_iterator(g);
    while (!iterator_done(nodes)) {
        int node = *(int*) iterator_next(nodes);
        sc->exploration[node] = 0;
        sc->complete[node] = 0;
    }
    iterator_free(nodes);

    // dfs over each node
    nodes = graph_nodes_iterator(g);
    while (!iterator_done(nodes)) {
        int node = *(int*) iterator_next(nodes);

        if (sc->exploration[node] == 0) {
            graph_dfsa(
                g,
                node,
                sc
            );
        }

        if (sc->has_cycles) {
            //printf("Cycle: "); stack_println(sc->cycle_path);
            break;
        }

    }
    return sc;
}

bool graph_acyclical(Graph *g) {
    struct CycleContext *sc = graph_check_cycles(g);
    bool has_cycles = sc->has_cycles;
    cycle_context_free(sc);
    return !has_cycles;
}

List* graph_topological_sort(Graph *g) {
    struct CycleContext *sc = graph_check_cycles(g);
    if (sc->has_cycles) {
        cycle_context_free(sc);
        return NULL;
    }
    Iterator *it = stack_iterator(sc->topological_sort);
    List *list = list_from_iterator(it);
    iterator_free(it);
    cycle_context_free(sc);
    return list;
}
