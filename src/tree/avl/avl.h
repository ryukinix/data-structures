/**
 * ================================================
 *
 *         Copyright 2017-2025 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC
 *
 * ===============================================
 */

#ifndef AVLT_H
#define AVLT_H

/**
 * @brief
 * This module define a Abstract Data Type
 * for the structure Binary Search Tree.
 */


/* Binary Search Tree DataType Definition */
#include "binary-tree.h"

/**
 * @brief A node in an AVL tree.
 *
 * Each node contains a value, pointers to its left and right children, and its
 * height.
 */
typedef struct BinaryNode AVLTree;
#ifndef Type
#define Type BINARY_NODE_TYPE
#endif

#define AVLT_EMPTY (AVLTree*) 0

/**
 * @brief Creates a new AVL tree node.
 *
 * @param value The value to store in the node.
 * @return A pointer to the new node.
 * @ingroup DataStructureMethods
 */
AVLTree* avl_create_node(Type value);

/**
 * @brief Creates an empty AVL tree.
 *
 * @return A null pointer, representing an empty tree.
 * @ingroup DataStructureMethods
 */
AVLTree* avl_create(void);

/**
 * @brief Checks if an AVL tree is empty.
 *
 * @param t The tree to check.
 * @return 1 if the tree is empty, 0 otherwise.
 * @ingroup DataStructureMethods
 */
int avl_empty(AVLTree *t);

/**
 * @brief Checks if a value exists in an AVL tree.
 *
 * @param t The tree to search in.
 * @param c The value to search for.
 * @return 1 if the value exists, 0 otherwise.
 * @ingroup DataStructureMethods
 */
int avl_exists(AVLTree *t, Type c);

/**
 * @brief Searches for a value in an AVL tree.
 *
 * @param t The tree to search in.
 * @param c The value to search for.
 * @return A pointer to the node containing the value, or a null pointer if the
 * value is not found.
 * @ingroup DataStructureMethods
 */
AVLTree* avl_search(AVLTree *t,Type c);

/**
 * @brief Prints the elements of an AVL tree in in-order traversal.
 *
 * @param t The tree to print.
 * @ingroup DataStructureMethods
 */
void avl_print(AVLTree *t);

/**
 * @brief Returns the height of an AVL tree.
 *
 * @param t The tree.
 * @return The height of the tree.
 * @ingroup DataStructureMethods
 */
int avl_height(AVLTree *t);

/**
 * @brief Inserts a value into an AVL tree.
 *
 * @param t The tree to insert into.
 * @param c The value to insert.
 * @return The updated tree.
 * @ingroup DataStructureMethods
 */
AVLTree* avl_insert(AVLTree *t, Type c);

/**
 * @brief Removes a value from an AVL tree.
 *
 * @param t The tree to remove from.
 * @param c The value to remove.
 * @return The updated tree.
 * @ingroup DataStructureMethods
 */
AVLTree* avl_remove(AVLTree *t, Type c);

/**
 * @brief Frees the memory allocated for an AVL tree.
 *
 * @param t The tree to free.
 * @ingroup DataStructureMethods
 */
void avl_free(AVLTree *t);

/**
 * @brief Prints the elements of an AVL tree in post-order traversal.
 *
 * @param t The tree to print.
 * @ingroup DataStructureMethods
 */
void avl_posfix(AVLTree *t);

/**
 * @brief Prints the elements of an AVL tree in pre-order traversal.
 *
 * @param t The tree to print.
 * @ingroup DataStructureMethods
 */
void avl_prefix(AVLTree *t);

/**
 * @brief Prints the elements of an AVL tree in in-order traversal.
 *
 * @param t The tree to print.
 * @ingroup DataStructureMethods
 */
void avl_infix(AVLTree *t);

/**
 * @brief Counts the number of nodes in an AVL tree.
 *
 * @param t The tree.
 * @return The number of nodes.
 * @ingroup DataStructureMethods
 */
int avl_nodes(AVLTree *t);

/**
 * @brief Counts the number of leaf nodes in an AVL tree that are prime numbers.
 *
 * @param t The tree.
 * @return The number of prime leaf nodes.
 * @ingroup DataStructureMethods
 */
int avl_leafs_primes(AVLTree *t);

/**
 * @brief Counts the number of nodes in an AVL tree that have two children.
 *
 * @param t The tree.
 * @return The number of nodes with two children.
 * @ingroup DataStructureMethods
 */
int avl_two_children(AVLTree *t);

/**
 * @brief Counts the number of nodes in an AVL tree that have equal branch
 * heights.
 *
 * @param t The tree.
 * @return The number of nodes with equal branch heights.
 * @ingroup DataStructureMethods
 */
int avl_nodes_equal_height(AVLTree *t);

/**
 * @brief Compares two AVL trees for equality.
 *
 * @param t1 The first tree.
 * @param t2 The second tree.
 * @return 1 if the trees are equal, 0 otherwise.
 * @ingroup DataStructureMethods
 */
int avl_equals(AVLTree *t1, AVLTree *t2);

#endif
