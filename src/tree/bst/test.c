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
#include "bst.h"
#include "../ascii-tree/ascii-tree.h"

#define N 5

void naive_tests() {
    printf("== [BST] Manoel Naive Tests\n");
    BSTree* t = bst_create();
    int array[N] = {10, 20, 5, 80, 50};

    // insertion
    for(int i = 0; i < N; i++) {
        printf("Insert: %d\n", array[i]);
        t = bst_insert(t, array[i]);
        print_ascii_tree(t);
    }

    // infix, posfix, prefix
    printf("== Notations\n");
    printf("Infix: ");
    bst_infix(t);
    printf("Prefix: ");
    bst_prefix(t);
    printf("Posfix: ");
    bst_posfix(t);
    printf("Nodes: %d\n", bst_nodes(t));

    // remove
    for(int i = 0; i < N; i++) {
        printf("Remove: %d\n", array[i]);
        t = bst_remove(t, array[i]);
        print_ascii_tree(t);
    }

    bst_free(t);
}

void jarbas_tests() {
    printf("== Jarbas Tests\n");
    BSTree *t = bst_create();
    t = bst_insert(t, 3);
    t = bst_insert(t, 5);
    t = bst_insert(t, 2);
    t = bst_insert(t, 4);
    t = bst_insert(t, 7);
    t = bst_insert(t, 0);
    t = bst_insert(t, 4);
    printf("Tree (t):\n");
    print_ascii_tree(t);
    printf("Height of the tree: %d\n", bst_height(t));
    printf("Number of prime leafs: %d\n", bst_leafs_primes(t));
    printf("Number of nodes with two children: %d\n", bst_two_children(t));
    printf("Nodes with equal height: %d\n", bst_nodes_equal_height(t));

    BSTree *r = bst_create();

    r = bst_insert(r, 9);
    r = bst_insert(r, 10);
    r = bst_insert(r, 11);
    printf("Tree (r):\n");
    print_ascii_tree(r);

    printf("Infix tree (t): ");
    bst_infix(t);
    printf("Infix tree (r): ");
    bst_infix(r);

    printf("Equal trees? Answer: %d.", bst_equals(t, r));

    bst_free(t);
    bst_free(r);

}


int main(void) {
    naive_tests();
    jarbas_tests();
    return 0;
}
