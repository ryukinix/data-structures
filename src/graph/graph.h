/**
 * ================================================
 *
 *         Copyright 2025 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: ITA
 *
 * ===============================================
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include "../set/set.h"

typedef struct Graph Graph;

Graph* graph_create();
void graph_add_node(Graph *g, int node);
void graph_add_edge(Graph *g, int u, int v);
void graph_remove_edge(Graph *g, int u, int v);
void graph_remove_node(Graph *g, int node);
bool graph_has_edge(Graph *g, int u, int v);
Set* graph_get_neighbors(Graph *g, int node);
void graph_free(Graph *g);
void graph_print(Graph *g);

#endif /* GRAPH_H */
