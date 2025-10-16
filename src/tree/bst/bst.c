/**
 * ================================================
 *
 *         Copyright 2017 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC
 *
 * ===============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "bst.h"
#include "../../utils/check_alloc.h"
#include "../../utils/prime.h"

#define MAX(a, b) a > b? a : b


BSTree* bst_create(void) {
    return BST_EMPTY;
}

int bst_empty(BSTree *t) {
    return t == BST_EMPTY;
}

BSTree* bst_create_node(BSTree* left, BSTree* right, Type value) {
    BSTree* node = (BSTree*) malloc(sizeof(BSTree));
    check_alloc(node);
    node->left = left;
    node->right = right;
    node->value = value;
    return node;
}

int bst_exists(BSTree *t, Type c) {
    return bst_search(t, c) != BST_EMPTY;
}

BSTree* bst_search(BSTree *t, Type c) {
    if (!bst_empty(t)) {
        if (c < t->value) {
            return bst_search(t->left, c);
        } else if (c > t->value) {
            return bst_search(t->right, c);
        } else {
            return t;
        }
    }
    return BST_EMPTY;
}


int bst_height(BSTree *t) {
    if (!bst_empty(t)) {
        return MAX(1 + bst_height(t->left), 1 + bst_height(t->right));
    }
    return -1;
}

int bst_nodes(BSTree *t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + bst_nodes(t->left) + bst_nodes(t->right);
    }
}

BSTree* bst_insert(BSTree *t, Type c) {
    if (bst_empty(t)) {
        t = bst_create_node(NULL, NULL, c);
    } else if (c < t->value) {
        t->left = bst_insert(t->left, c);
    } else if (c > t->value) {
        t->right = bst_insert(t->right, c);
    }
    return t;
}

BSTree* bst_remove(BSTree *t, Type c) {
    if (!bst_empty(t)) {
        if (c < t->value) {
            t->left = bst_remove(t->left, c);
        } else if (c > t->value) {
            t->right = bst_remove(t->right, c);
        } else {
            BSTree* r;
            if (bst_empty(t->left)) {
                r = t; t = t->right;
                free(r);
            } else if (bst_empty(t->right)) {
                r = t; t = t->left;
                free(r);
            } else {
                // remoção por substituição
                // do elemento mais a direita da subárvore esquerda
                r = t->left;
                while (!bst_empty(r->right)) {
                    r = r->right;
                }
                t->value = r->value;
                r->value = c;
                t->left = bst_remove(t->left, c);
            }
        }
    }
    return t;
}

void bst_free(BSTree *t) {
    if(!bst_empty(t)) {
        bst_free(t->left);
        bst_free(t->right);
        free(t);
    }
}

/**********/
/* OUTPUT */
/**********/

void bst_print_aux(BSTree *t, int deep, char prefix) {
    if (!bst_empty(t)) {
        printf("| %*c(%c) %d\n", deep*4, ' ', prefix,  t->value);
        deep++;
        bst_print_aux(t->left, deep, 'L');
        bst_print_aux(t->right, deep, 'R');
    }
}

void bst_print(BSTree *t) {
    if (!bst_empty(t)) {
        printf("== TREE\n");
        bst_print_aux(t, 1, '.');
    } else {
        printf("Empty tree.\n");
    }
}


void bst_posfix_aux(BSTree *t) {
    if (!bst_empty(t)) {
        bst_posfix_aux(t->left);
        bst_posfix_aux(t->right);
        printf(" (%d) ", t->value);
    }
}

void bst_posfix(BSTree *t) {
    printf("[");
    bst_posfix_aux(t);
    printf("]\n");
}

void bst_prefix_aux(BSTree *t) {
    if (!bst_empty(t)) {
        printf(" (%d) ", t->value);
        bst_prefix_aux(t->left);
        bst_prefix_aux(t->right);
    }
}

void bst_prefix(BSTree *t) {
    printf("[");
    bst_prefix_aux(t);
    printf("]\n");
}

void bst_infix_aux(BSTree *t) {
    if (!bst_empty(t)) {
        bst_infix_aux(t->left);
        printf(" (%d) ", t->value);
        bst_infix_aux(t->right);
    }
}

void bst_infix(BSTree *t) {
    printf("[");
    bst_infix_aux(t);
    printf("]\n");
}

/*********************************/
/*    Jarbas - Assignment 2     */
/*********************************/

// a)

int bst_is_leaf(BSTree *t) {
    return t != NULL && t->left == NULL && t->right == NULL;
}

int bst_leafs_primes(BSTree *t) {
    if (!bst_empty(t)) {
        if (bst_is_leaf(t)) {
            return is_prime(t->value);
        } else {
            return bst_leafs_primes(t->left) + bst_leafs_primes(t->right);
        }
    }
    return 0;
}


// b)

int bst_two_children(BSTree *t) {
    if (!bst_empty(t)) {
        return (t->left != NULL && t->right != NULL) \
            + bst_two_children(t->left)              \
            + bst_two_children(t->right);
    }
    return 0;
}

// c)

int bst_nodes_equal_height(BSTree *t) {
    if (!bst_empty(t)) {
        return (bst_height(t->left) == bst_height(t->right))    \
            + bst_nodes_equal_height(t->left)                   \
            + bst_nodes_equal_height(t->right);
    }
    return 0;
}


// d)

int bst_equals(BSTree *t1, BSTree *t2) {
    if (bst_empty(t1) != bst_empty(t2)) {
        return false;
    } else if (bst_empty(t1) && bst_empty(t2)) {
        return true;
    } else {
        return t1->value == t2->value               \
            && bst_equals(t1->left, t2->left)       \
            && bst_equals(t1->right, t2->right);
    }
}
