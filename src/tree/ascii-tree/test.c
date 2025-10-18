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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../bst/bst.h"
#include "ascii-tree.h"

int main() {
    // A sample use of these functions.  Start with the empty tree
    // insert some stuff into it, and then delete it
    BSTree *root = bst_create();

    printf("\nAfter inserting value 10..\n");
    root = bst_insert(root, 10);
    print_ascii_tree(root);

    printf("\nAfter inserting value 5..\n");
    root = bst_insert(root, 5);
    print_ascii_tree(root);

    printf("\nAfter inserting value 15..\n");
    root = bst_insert(root, 15);
    print_ascii_tree(root);

    printf("\nAfter inserting elements 9, 13..\n");
    root = bst_insert(root, 9);
    root = bst_insert(root, 13);
    print_ascii_tree(root);

    printf("\nAfter inserting elements 2, 6, 12, 14, ..\n");
    root = bst_insert(root, 2);
    root = bst_insert(root, 6);
    root = bst_insert(root, 12);
    root = bst_insert(root, 14);
    print_ascii_tree(root);

    printf("\n\nAfter deleting a node (14) with no child..\n");
    root = bst_remove(root, 14);
    print_ascii_tree(root);

    printf("\n\nAfter deleting a node (13) with left child..\n");
    root = bst_remove(root, 13);
    print_ascii_tree(root);

    printf("\n\nAfter deleting a node (5) with left and right children..\n");
    root = bst_remove (root, 5);
    print_ascii_tree(root);

    printf("\n\nAfter deleting a node (tree_root, 10 node) with left and right "
           "children..\n");
    root = bst_remove (root, 10);
    print_ascii_tree(root);
    bst_free(root);
}
