#include <stdio.h>
#include "graph.h"
#include "../queue/queue.h"
#include "../list/single/list.h"

void graph_bfs(Graph* g, int start_node) {
    // 1. Create a queue for the nodes to visit and a set for visited nodes.
    Queue* q = queue_create();
    Set* visited = set_create();

    // 2. Add the starting node to the queue and the visited set.
    queue_insert(q, start_node);
    set_add(visited, start_node);

    printf("Starting BFS from node %d\n", start_node);

    // 3. Loop while there are nodes in the queue.
    while (!queue_empty(q)) {
        // 4. Dequeue a node to visit.
        int current_node = queue_remove(q);
        printf("Visiting node: %d\n", current_node);

        // 5. Get the neighbors of the current node.
        Set* neighbors_set = graph_get_neighbors(g, current_node);
        Iterator* it = set_iterator(neighbors_set); // Helper function
        // 6. Iterate over the neighbors.
        while (!iterator_done(it)) {
            int neighbor = *(int*)it->next(it);
            // 7. If the neighbor has not been visited, add it to the queue and visited set.
            if (!set_contains(visited, neighbor)) {
                set_add(visited, neighbor);
                queue_insert(q, neighbor);
            }
        }

        // 8. Free the memory used for the neighbors list and set.
        iterator_free(it);
        set_free(neighbors_set);
    }

    // 9. Free the queue and visited set.
    queue_free(q);
    set_free(visited);
}
