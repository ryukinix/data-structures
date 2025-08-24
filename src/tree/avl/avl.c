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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "avl.h"
#include "utils/check_alloc.h"

#define MAX(a, b) a > b? a : b


AVLTree* avl_create(void) {
    return AVLT_EMPTY;
}

int avl_empty(AVLTree *t) {
    return t == AVLT_EMPTY;
}

AVLTree* avl_create_node(AVLTree* left, AVLTree* right, Type value) {
    AVLTree* node = (AVLTree*) malloc(sizeof(AVLTree));
    check_alloc(node);
    node->left = left;
    node->right = right;
    node->value = value;
    return node;
}

int avl_exists(AVLTree *t, Type c) {
    return avl_search(t, c) != AVLT_EMPTY;
}

AVLTree* avl_search(AVLTree *t, Type c) {
    if (!avl_empty(t)) {
        if (c < t->value) {
            return avl_search(t->left, c);
        } else if (c > t->value) {
            return avl_search(t->right, c);
        } else {
            return t;
        }
    }
    return AVLT_EMPTY;
}


int avl_height(AVLTree *t) {
    if (!avl_empty(t)) {
        return MAX(1 + avl_height(t->left), 1 + avl_height(t->right));
    }
    return -1;
}

int avl_nodes(AVLTree *t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + avl_nodes(t->left) + avl_nodes(t->right);
    }
}

AVLTree* avl_insert(AVLTree *t, Type c) {
    if (avl_empty(t)) {
        t = avl_create_node(NULL, NULL, c);
    } else if (c < t->value) {
        t->left = avl_insert(t->left, c);
    } else if (c > t->value) {
        t->right = avl_insert(t->right, c);
    }
    return t;
}

AVLTree* avl_remove(AVLTree *t, Type c) {
    if (!avl_empty(t)) {
        if (c < t->value) {
            t->left = avl_remove(t->left, c);
        } else if (c > t->value) {
            t->right = avl_remove(t->right, c);
        } else {
            AVLTree* r;
            if (avl_empty(t->left)) {
                r = t; t = t->right;
                free(r);
            } else if (avl_empty(t->right)) {
                r = t; t = t->left;
                free(r);
            } else {
                // remoção por suavlituição
                // do elemento mais a direita da subárvore esquerda
                r = t->left;
                while (!avl_empty(r->right)) {
                    r = r->right;
                }
                t->value = r->value;
                r->value = c;
                t->left = avl_remove(t->left, c);
            }
        }
    }
    return t;
}

void avl_free(AVLTree *t) {
    if(!avl_empty(t)) {
        avl_free(t->left);
        avl_free(t->right);
        free(t);
    }
}

/**********/
/* OUTPUT */
/**********/

void avl_print_aux(AVLTree *t, int deep, char prefix) {
    if (!avl_empty(t)) {
        printf("| %*c(%c) %d\n", deep*4, ' ', prefix,  t->value);
        deep++;
        avl_print_aux(t->left, deep, 'L');
        avl_print_aux(t->right, deep, 'R');
    }
}

void avl_print(AVLTree *t) {
    if (!avl_empty(t)) {
        printf("== TREE\n");
        avl_print_aux(t, 1, '.');
    } else {
        printf("Empty tree.\n");
    }
}


void avl_posfix_aux(AVLTree *t) {
    if (!avl_empty(t)) {
        avl_posfix_aux(t->left);
        avl_posfix_aux(t->right);
        printf(" (%d) ", t->value);
    }
}

void avl_posfix(AVLTree *t) {
    printf("[");
    avl_posfix_aux(t);
    printf("]\n");
}

void avl_prefix_aux(AVLTree *t) {
    if (!avl_empty(t)) {
        printf(" (%d) ", t->value);
        avl_prefix_aux(t->left);
        avl_prefix_aux(t->right);
    }
}

void avl_prefix(AVLTree *t) {
    printf("[");
    avl_prefix_aux(t);
    printf("]\n");
}

void avl_infix_aux(AVLTree *t) {
    if (!avl_empty(t)) {
        avl_infix_aux(t->left);
        printf(" (%d) ", t->value);
        avl_infix_aux(t->right);
    }
}

void avl_infix(AVLTree *t) {
    printf("[");
    avl_infix_aux(t);
    printf("]\n");
}

/*********************************/
/*    Jarbas - Assignment 2     */
/*********************************/

// a)

int is_leaf(AVLTree *t) {
    return t != NULL && t->left == NULL && t->right == NULL;
}

// Worst: O(sqrt(n))
int is_prime(int n) {
    if (n == 2) {
        return true;
    } else if (n <= 1 || n % 2 == 0) {
        return false;
    }

    for (int k = 3; k <= floor(sqrt(n)); k += 2) {
        if (n % k == 0) {
            return false;
        }
    }

    return true;
}

int avl_leafs_primes(AVLTree *t) {
    if (!avl_empty(t)) {
        if (is_leaf(t)) {
            return is_prime(t->value);
        } else {
            return avl_leafs_primes(t->left) + avl_leafs_primes(t->right);
        }
    }
    return 0;
}


// b)

int avl_two_children(AVLTree *t) {
    if (!avl_empty(t)) {
        return (t->left != NULL && t->right != NULL) \
            + avl_two_children(t->left)              \
            + avl_two_children(t->right);
    }
    return 0;
}

// c)

int avl_nodes_equal_height(AVLTree *t) {
    if (!avl_empty(t)) {
        return (avl_height(t->left) == avl_height(t->right))    \
            + avl_nodes_equal_height(t->left)                   \
            + avl_nodes_equal_height(t->right);
    }
    return 0;
}


// d)

int avl_equals(AVLTree *t1, AVLTree *t2) {
    if (avl_empty(t1) != avl_empty(t2)) {
        return false;
    } else if (avl_empty(t1) && avl_empty(t2)) {
        return true;
    } else {
        return t1->value == t2->value               \
            && avl_equals(t1->left, t2->left)       \
            && avl_equals(t1->right, t2->right);
    }
}
