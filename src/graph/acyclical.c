#include "graph.h"
#include "../stack/stack.h"

struct CycleContext {
    Stack* cycle_path;
    int counter_exploration;
    int counter_complete;
    int *exploration;
    int *complete;
};

// detect if graph has cycles
static bool graph_dfsa(
    Graph *g,
    int node,
    struct CycleContext *sc
) {
    sc->exploration[node] = ++sc->counter_exploration;
    stack_push(sc->cycle_path, node);

    bool has_cycles = false;
    Set* neighbors_set = graph_get_neighbors(g, node);
    Iterator* set_it = set_iterator(neighbors_set);

    while (!iterator_done(set_it)) {
        int neighbor = *(int*) iterator_next(set_it);
        if (sc->exploration[neighbor] == 0) {
            has_cycles = graph_dfsa(
                g,
                neighbor,
                sc
            );
        } else if (sc->exploration[neighbor] < sc->exploration[node] && sc->complete[neighbor] == 0) {
            has_cycles = true;
        }

        if (has_cycles) {
            break;
        }
    }
    set_free(neighbors_set);
    iterator_free(set_it);
    if (has_cycles) {
        return true;
    }

    stack_pop(sc->cycle_path);
    sc->complete[node] = ++sc->counter_complete;
    return false;
}


bool graph_acyclical(Graph *g) {
    struct CycleContext sc;
    int exploration[graph_size(g)];
    int complete[graph_size(g)];
    Stack* cycle_path = stack_create();

    sc.cycle_path = cycle_path;
    sc.counter_complete = 0;
    sc.counter_exploration = 0;
    sc.exploration = exploration;
    sc.complete = complete;

    Iterator *nodes;

    // initialize
    nodes = graph_nodes_iterator(g);
    while (!iterator_done(nodes)) {
        int node = *(int*) iterator_next(nodes);
        exploration[node] = 0;
        complete[node] = 0;
    }
    iterator_free(nodes);

    // dfs over each node
    nodes = graph_nodes_iterator(g);
    bool has_cycles = false;
    while (!iterator_done(nodes)) {
        int node = *(int*) iterator_next(nodes);
        has_cycles = graph_dfsa(
            g,
            node,
            &sc
        );
        if (has_cycles) {
            //printf("Cycle: "); stack_println(cycle_path);
            break;
        }

    }
    stack_free(cycle_path);
    iterator_free(nodes);
    return !has_cycles;
}
