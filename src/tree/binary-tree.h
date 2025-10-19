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

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#ifndef BINARY_NODE_TYPE
#define BINARY_NODE_TYPE int
#endif
#ifndef BINARY_NODE_FORMAT
#define BINARY_NODE_FORMAT "%d"
#endif

/**
 * @brief A node in a binary tree.
 *
 * Each node contains a value and pointers to its left and right children.
 */
struct BinaryNode {
    BINARY_NODE_TYPE value;
    struct BinaryNode* left;
    struct BinaryNode* right;
};

/**
 * @brief A binary tree.
 *
 * A `BinaryTree` is a pointer to the root node of the tree.
 */
typedef struct BinaryNode BinaryTree;

#endif
