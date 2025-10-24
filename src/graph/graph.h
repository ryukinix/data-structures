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

/**
 * @brief Creates a new graph.
 * @return A pointer to the new graph.
 * @ingroup DataStructureMethods
 */
Graph* graph_create();

/**
 * @brief Adds a node to the graph.
 * @param g The graph.
 * @param node The node to be added.
 * @ingroup DataStructureMethods
 */
void graph_add_node(Graph *g, int node);

/**
 * @brief Adds an edge to the graph.
 * @param g The graph.
 * @param u The source node.
 * @param v The destination node.
 * @ingroup DataStructureMethods
 */
void graph_add_edge(Graph *g, int u, int v);

/**
 * @brief Removes an edge from the graph.
 * @param g The graph.
 * @param u The source node.
 * @param v The destination node.
 * @ingroup DataStructureMethods
 */
void graph_remove_edge(Graph *g, int u, int v);

/**
 * @brief Removes a node from the graph.
 * @param g The graph.
 * @param node The node to be removed.
 * @ingroup DataStructureMethods
 */
void graph_remove_node(Graph *g, int node);

/**
 * @brief Checks if an edge exists in the graph.
 * @param g The graph.
 * @param u The source node.
 * @param v The destination node.
 * @return True if the edge exists, false otherwise.
 * @ingroup DataStructureMethods
 */
bool graph_has_edge(Graph *g, int u, int v);

/**
 * @brief Gets the neighbors of a node.
 * @param g The graph.
 * @param node The node.
 * @return A set containing the neighbors of the node.
 * @ingroup DataStructureMethods
 */
Set* graph_get_neighbors(Graph *g, int node);

/**
 * @brief Frees the memory allocated for the graph.
 * @param g The graph.
 * @ingroup DataStructureMethods
 */
void graph_free(Graph *g);

/**
 * @brief Prints the graph.
 * @param g The graph.
 * @ingroup DataStructureMethods
 */
void graph_print(Graph *g);

/**
 * @brief Performs a Breadth-First Search on a graph.
 * @param g The graph to traverse.
 * @param start_node The node to start the traversal from.
 */
Iterator* graph_bfs(Graph *g, int start_node);

/**
 * @brief Performs a Depth-First Search on a graph.
 * @param g The graph to traverse.
 * @param start_node The node to start the traversal from.
 */
Iterator* graph_dfs(Graph *g, int start_node);

#endif /* GRAPH_H */
