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
#include "avl.h"
#include "../ascii-tree/ascii-tree.h"

#define N 5

void naive_tests() {
    printf("== [AVL] Manoel Naive Tests\n");
    AVLTree* t = avl_create();
    int array[N] = {10, 20, 5, 80, 50};
    int heights[N] = {0, 1, 1, 2, 2};
    // insertion
    for(int i = 0; i < N; i++) {
        printf("Insert: %d\n", array[i]);
        t = avl_insert(t, array[i]);
        print_ascii_tree(t);
        int h = avl_height(t);
        int h_expected = heights[i];
        if (h != h_expected) {
            printf(":: expected height=%d, got %d\n", h_expected, h);
            exit(1);

        }
    }

    // infix, posfix, prefix
    printf("== Notations\n");
    printf("Infix: ");
    avl_infix(t);
    printf("Prefix: ");
    avl_prefix(t);
    printf("Posfix: ");
    avl_posfix(t);
    printf("Nodes: %d\n", avl_nodes(t));

    // remove
    for(int i = 0; i < N; i++) {
        printf("Remove: %d\n", array[i]);
        t = avl_remove(t, array[i]);
        print_ascii_tree(t);
    }

    avl_free(t);
}

void jarbas_tests() {
    printf("== Jarbas Tests\n");
    AVLTree *t = avl_create();
    t = avl_insert(t, 3);
    t = avl_insert(t, 5);
    t = avl_insert(t, 2);
    t = avl_insert(t, 4);
    t = avl_insert(t, 7);
    t = avl_insert(t, 0);
    t = avl_insert(t, 4);
    printf("Tree (t):\n");
    print_ascii_tree(t);
    printf("Height of the tree: %d\n", avl_height(t));
    printf("Number of prime leafs: %d\n", avl_leafs_primes(t));
    printf("Number of nodes with two children: %d\n", avl_two_children(t));
    printf("Nodes with equal height: %d\n", avl_nodes_equal_height(t));

    AVLTree *r = avl_create();

    r = avl_insert(r, 9);
    r = avl_insert(r, 10);
    r = avl_insert(r, 11);
    printf("Tree (r):\n");
    print_ascii_tree(r);

    printf("Infix tree (t): ");
    avl_infix(t);
    printf("Infix tree (r): ");
    avl_infix(r);

    printf("Equal trees? Answer: %d.", avl_equals(t, r));
    printf("\n");
    avl_free(t);
    avl_free(r);

}


int main(void) {
    naive_tests();
    jarbas_tests();
    return 0;
}
