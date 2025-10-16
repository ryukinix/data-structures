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
#include "../../utils/check_alloc.h"
#include "../../utils/prime.h"


// New auxiliary methods

static inline int max(int a, int b) {
    return a > b ? a : b;
}

static int height(AVLTree* node) {
    return node ? node->height : -1;
}

AVLTree* avl_create_node(Type value) {
    AVLTree* node = malloc(sizeof(AVLTree));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;
}

static void update_height(AVLTree* node) {
    node->height = max(height(node->left), height(node->right)) + 1;
}

static int get_balance(AVLTree* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

static AVLTree* rotate_right(AVLTree* y) {
    AVLTree* x = y->left;
    AVLTree* T2 = x->right;
    x->right = y;
    y->left = T2;
    update_height(y);
    update_height(x);
    return x;
}

static AVLTree* rotate_left(AVLTree* x) {
    AVLTree* y = x->right;
    AVLTree* T2 = y->left;
    y->left = x;
    x->right = T2;
    update_height(x);
    update_height(y);
    return y;
}


static AVLTree* min_value_node(AVLTree* node) {
    AVLTree* current = node;
    while (current->left)
        current = current->left;
    return current;
}


AVLTree* avl_create(void) {
    return AVLT_EMPTY;
}

int avl_empty(AVLTree *t) {
    return t == AVLT_EMPTY;
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
        return max(1 + avl_height(t->left), 1 + avl_height(t->right));
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

AVLTree* avl_insert(AVLTree* node, int value) {
    if (!node)
        return avl_create_node(value);

    if (value < node->value)
        node->left = avl_insert(node->left, value);
    else if (value > node->value)
        node->right = avl_insert(node->right, value);
    else
        return node; // No duplicates

    update_height(node);

    int balance = get_balance(node);

    // Left Left Case
    if (balance > 1 && value < node->left->value)
        return rotate_right(node);

    // Right Right Case
    if (balance < -1 && value > node->right->value)
        return rotate_left(node);

    // Left Right Case
    if (balance > 1 && value > node->left->value) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->value) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

AVLTree* avl_remove(AVLTree* root, int value) {
    if (!root)
        return root;

    if (value < root->value)
        root->left = avl_remove(root->left, value);
    else if (value > root->value)
        root->right = avl_remove(root->right, value);
    else {
        // node with only one child or no child
        if (!root->left || !root->right) {
            AVLTree* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }
        // node with two children: get inorder successor
        AVLTree* temp = min_value_node(root->right);
        root->value = temp->value;
        root->right = avl_remove(root->right, temp->value);
    }

    update_height(root);

    int balance = get_balance(root);

    // Left Left Case
    if (balance > 1 && get_balance(root->left) >= 0)
        return rotate_right(root);

    // Left Right Case
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    // Right Right Case
    if (balance < -1 && get_balance(root->right) <= 0)
        return rotate_left(root);

    // Right Left Case
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
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

int avl_is_leaf(AVLTree *t) {
    return t != NULL && t->left == NULL && t->right == NULL;
}


int avl_leafs_primes(AVLTree *t) {
    if (!avl_empty(t)) {
        if (avl_is_leaf(t)) {
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
