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

#ifndef BST_H
#define BST_H

/**
 * @brief
 * This module define a Abstract Data Type
 * for the structure Binary Search Tree.
 */

// definition of BinaryTree and struct node.
#include "../binary-tree.h"

/**
 * @brief A node in a Binary Search Tree (BST).
 *
 * Each node contains a value and pointers to its left and right children.
 */
typedef struct BinaryNode BSTree;

#ifndef Type
#define Type BINARY_NODE_TYPE
#endif

#define BST_EMPTY (BSTree*) 0

/**
 * @brief Creates a new BST node.
 *
 * @param left A pointer to the left child.
 * @param right A pointer to the right child.
 * @param value The value to store in the node.
 * @return A pointer to the new node.
 * @ingroup DataStructureMethods
 */
BSTree* bst_create_node(BSTree* left, BSTree* right, Type value);

/**
 * @brief Creates an empty BST.
 *
 * @return A null pointer, representing an empty tree.
 * @ingroup DataStructureMethods
 */
BSTree* bst_create(void);

/**
 * @brief Checks if a BST is empty.
 *
 * @param t The tree to check.
 * @return 1 if the tree is empty, 0 otherwise.
 * @ingroup DataStructureMethods
 */
int bst_empty(BSTree *t);

/**
 * @brief Checks if a value exists in a BST.
 *
 * @param t The tree to search in.
 * @param c The value to search for.
 * @return 1 if the value exists, 0 otherwise.
 * @ingroup DataStructureMethods
 */
int bst_exists(BSTree *t, Type c);

/**
 * @brief Searches for a value in a BST.
 *
 * @param t The tree to search in.
 * @param c The value to search for.
 * @return A pointer to the node containing the value, or a null pointer if the
 * value is not found.
 * @ingroup DataStructureMethods
 */
BSTree* bst_search(BSTree *t,Type c);

/**
 * @brief Prints the elements of a BST in in-order traversal.
 *
 * @param t The tree to print.
 * @ingroup DataStructureMethods
 */
void bst_print(BSTree *t);

/**
 * @brief Returns the height of a BST.
 *
 * @param t The tree.
 * @return The height of the tree.
 * @ingroup DataStructureMethods
 */
int bst_height(BSTree *t);

/**
 * @brief Inserts a value into a BST.
 *
 * @param t The tree to insert into.
 * @param c The value to insert.
 * @return The updated tree.
 * @ingroup DataStructureMethods
 */
BSTree* bst_insert(BSTree *t, Type c);

/**
 * @brief Removes a value from a BST.
 *
 * @param t The tree to remove from.
 * @param c The value to remove.
 * @return The updated tree.
 * @ingroup DataStructureMethods
 */
BSTree* bst_remove(BSTree *t, Type c);

/**
 * @brief Frees the memory allocated for a BST.
 *
 * @param t The tree to free.
 * @ingroup DataStructureMethods
 */
void bst_free(BSTree *t);

/**
 * @brief Prints the elements of a BST in post-order traversal.
 *
 * @param t The tree to print.
 * @ingroup DataStructureMethods
 */
void bst_posfix(BSTree *t);

/**
 * @brief Prints the elements of a BST in pre-order traversal.
 *
 * @param t The tree to print.
 * @ingroup DataStructureMethods
 */
void bst_prefix(BSTree *t);

/**
 * @brief Prints the elements of a BST in in-order traversal.
 *
 * @param t The tree to print.
 * @ingroup DataStructureMethods
 */
void bst_infix(BSTree *t);

/**
 * @brief Counts the number of nodes in a BST.
 *
 * @param t The tree.
 * @return The number of nodes.
 * @ingroup DataStructureMethods
 */
int bst_nodes(BSTree *t);

/**
 * @brief Counts the number of leaf nodes in a BST that are prime numbers.
 *
 * @param t The tree.
 * @return The number of prime leaf nodes.
 * @ingroup DataStructureMethods
 */
int bst_leafs_primes(BSTree *t);

/**
 * @brief Counts the number of nodes in a BST that have two children.
 *
 * @param t The tree.
 * @return The number of nodes with two children.
 * @ingroup DataStructureMethods
 */
int bst_two_children(BSTree *t);

/**
 * @brief Counts the number of nodes in a BST that have equal branch heights.
 *
 * @param t The tree.
 * @return The number of nodes with equal branch heights.
 * @ingroup DataStructureMethods
 */
int bst_nodes_equal_height(BSTree *t);

/**
 * @brief Compares two BSTs for equality.
 *
 * @param t1 The first tree.
 * @param t2 The second tree.
 * @return 1 if the trees are equal, 0 otherwise.
 * @ingroup DataStructureMethods
 */
int bst_equals(BSTree *t1, BSTree *t2);

#endif
