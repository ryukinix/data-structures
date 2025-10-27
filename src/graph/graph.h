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

typedef enum edgeType {
    TREE,
    CROSS,
    FORWARD,
    BACK,
} EdgeType;

static inline const char* graph_edge_type_name(EdgeType edge_type) {
    switch (edge_type) {
    case TREE: return "TREE";
    case CROSS: return "CROSS";
    case FORWARD: return "FORWARD";
    case BACK: return "BACK";
    }
    return "?";
}


/**
 * @brief Creates a new directed graph.
 * @return A pointer to the new graph.
 * @ingroup DataStructureMethods
 */
Graph* graph_create();

/**
 * @brief Creates a new undirected graph.
 * @return A pointer to the new graph.
 * @ingroup DataStructureMethods
 */
Graph* graph_undirected_create();

/**
 * @brief Creates a new tarjan graph.
 * @param directed flag if graph should be directed or not.
 * @return A pointer to the new graph.
 * @ingroup DataStructureMethods
 */
Graph* graph_tarjan_create(bool directed);

/**
 * @brief Get the number of nodes.
 * @return number of nodes on the graph.
 * @ingroup DataStructureMethods
 */
size_t graph_size(Graph *g);

/**
 * @brief Check if graph is weighted.
 * @return true if is weighted, false otherwise.
 * @ingroup DataStructureMethods
 */
bool graph_is_directed(Graph *g);

/**
 * @brief Check if graph is weighted.
 * @return true if is weighted, false otherwise.
 * @ingroup DataStructureMethods
 */
bool graph_is_weighted(Graph *g);

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
 * @brief Adds a weighted edge to the graph.
 * @param g The graph.
 * @param u The source node.
 * @param v The destination node.
 * @param weight The weight of the edge.
 * @ingroup DataStructureMethods
 */
void graph_add_edge_with_weight(Graph *g, int u, int v, int weight);


/**
 * @brief Gets the weight of an edge.
 * @param g The graph.
 * @param u The source node.
 * @param v The destination node.
 * @return The weight of the edge, or -1 if the edge does not exist.
 * @ingroup DataStructureMethods
 */
int graph_get_edge_weight(Graph *g, int u, int v);


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
 * @brief Exports the graph to a DOT file for visualization with Graphviz.
 * @param g The graph.
 * @param filename The name of the output DOT file.
 * @ingroup DataStructureMethods
 */
void graph_export_to_dot(Graph *g, const char* filename);

/**
 * @brief Performs a Breadth-First Search on a graph.
 * @param g The graph to traverse.
 * @param start_node The node to start the traversal from.
 * @return A node iterator
 * @ingroup DataStructureMethods
 */
Iterator* graph_bfs(Graph *g, int start_node);

/**
 * @brief Performs a Depth-First Search on a graph.
 * @param g The graph to traverse.
 * @param start_node The node to start the traversal from.
 * @return A node iterator
 * @ingroup DataStructureMethods
 */
Iterator* graph_dfs(Graph *g, int start_node);

/**
 * @brief Iterate over nodes of the graph.
 * @param g The graph to traverse.
 * @ingroup DataStructureMethods
 */
Iterator* graph_nodes_iterator(Graph *g);

/**
 * @brief Get the maximum node id on the graph.
 * @return maximum node id on the graph.
 * @ingroup DataStructureMethods
 */
int graph_max_node_id(Graph *g);

/**
 * @brief Check if graph has cycles.
 * @param g The graph to traverse.
 * @return true if has any cycle, false otherwise.
 * @ingroup DataStructureMethods
 */
bool graph_acyclical(Graph *g);

/**
 * @brief Check if graph can be classified as Directed Acyclical Graph.
 * @param g The graph to traverse.
 * @return true if is directed and acyclical , false otherwise.
 * @ingroup DataStructureMethods
 */
bool graph_is_dag(Graph *g);

/**
 * @brief Create a new graph with tarjan arc classification as weight of the edges.
 * @param g The graph to traverse.
 * @return new graph.
 * @ingroup DataStructureMethods
 */
Graph* graph_tarjan(Graph *g);

/**
 * This method is defined in acyclical.c because it inherits part of the acyclical code.
 *
 * @brief Creat a list with the nodes in topological sort.
 * @param g The graph to traverse.
 * @return a list with the nodes that represents the topological sort. Return NULL if graph cannot be sort.
 * @ingroup DataStructureMethods
 */
List* graph_topological_sort(Graph *g);

#endif /* GRAPH_H */
