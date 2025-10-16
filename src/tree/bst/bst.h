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

#ifndef BST_H
#define BST_H

/**
 * @description
 * This module define a Abstract Data Type
 * for the structure Binary Search Tree.
 */

// definition of BinaryTree and struct node.
#include "../binary-tree.h"

/* Binary Search Tree DataType Definition */
typedef struct BinaryNode BSTree;

#ifndef Type
#define Type BINARY_NODE_TYPE
#endif

#define BST_EMPTY (BSTree*) 0

/* Função que cria um nó de uma Árvore */
BSTree* bst_create_node(BSTree* left, BSTree* right, Type value);

/* Função que cria uma Árvore Binária de Busca Vazia. */
BSTree* bst_create(void);

/* Testa se uma Árvore Binária é vazia. */
int bst_empty(BSTree *t);

/* Função que determina se um caractere pertence à Árvore. */
int bst_exists(BSTree *t, Type c);

/* Função que busca a sub-árvore que contém um inteiro. */
BSTree* bst_search(BSTree *t,Type c);

/* Função que imprime os elementos de uma Árvore. */
void bst_print(BSTree *t);

/* Função que retorna a altura de uma Árvore. */
int bst_height(BSTree *t);

/* Função que insere um inteiro em uma Árvore. */
BSTree* bst_insert(BSTree *t, Type c);

/* Função que remove um inteiro em uma Árvore. */
BSTree* bst_remove(BSTree *t, Type c);

/* Libera o espaço alocado para uma Árvore. */
void bst_free(BSTree *t);

/* Imprime a árvore linearmente em pós-ordem */
void bst_posfix(BSTree *t);

/* Imprime a árvore linearmente em pré-ordem */
void bst_prefix(BSTree *t);

/* Imprime a árvore linearmente de forma simétrica */
void bst_infix(BSTree *t);

/* Count the number of nodes */
int bst_nodes(BSTree *t);

/* Return the number of leafs which are prime numbers */
int bst_leafs_primes(BSTree *t);

/* Return the number of nodes that has two children */
int bst_two_children(BSTree *t);

/* Return the number of nodes which have equal branch heights*/
int bst_nodes_equal_height(BSTree *t);

/* Compare if t1 and t2 are equal by traversal tree search */
int bst_equals(BSTree *t1, BSTree *t2);

#endif
