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

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#ifndef BINARY_NODE_TYPE
#define BINARY_NODE_TYPE int
#endif
#ifndef BINARY_NODE_FORMAT
#define BINARY_NODE_FORMAT "%d"
#endif

struct BinaryNode {
    BINARY_NODE_TYPE value;
    int height;
    struct BinaryNode* left;
    struct BinaryNode* right;
};

typedef struct BinaryNode BinaryTree;

#endif
