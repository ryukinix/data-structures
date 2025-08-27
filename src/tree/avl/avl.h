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

#ifndef AVLT_H
#define AVLT_H

/**
 * @description
 * This module define a Abstract Data Type
 * for the structure Binary Search Tree.
 */

// definition of BinaryTree and struct node.


/* Binary Search Tree DataType Definition */
#include "tree/avl/binary-tree.h"
typedef struct BinaryNode AVLTree;
#ifndef Type
#define Type BINARY_NODE_TYPE
#endif

#define AVLT_EMPTY (AVLTree*) 0

/* Função que cria um nó de uma Árvore */
AVLTree* avl_create_node(Type value);

/* Função que cria uma Árvore Binária de Busca Vazia. */
AVLTree* avl_create(void);

/* Testa se uma Árvore Binária é vazia. */
int avl_empty(AVLTree *t);

/* Função que determina se um caractere pertence à Árvore. */
int avl_exists(AVLTree *t, Type c);

/* Função que busca a sub-árvore que contém um inteiro. */
AVLTree* avl_search(AVLTree *t,Type c);

/* Função que imprime os elementos de uma Árvore. */
void avl_print(AVLTree *t);

/* Função que retorna a altura de uma Árvore. */
int avl_height(AVLTree *t);

/* Função que insere um inteiro em uma Árvore. */
AVLTree* avl_insert(AVLTree *t, Type c);

/* Função que remove um inteiro em uma Árvore. */
AVLTree* avl_remove(AVLTree *t, Type c);

/* Libera o espaço alocado para uma Árvore. */
void avl_free(AVLTree *t);

/* Imprime a árvore linearmente em pós-ordem */
void avl_posfix(AVLTree *t);

/* Imprime a árvore linearmente em pré-ordem */
void avl_prefix(AVLTree *t);

/* Imprime a árvore linearmente de forma simétrica */
void avl_infix(AVLTree *t);

/* Count the number of nodes */
int avl_nodes(AVLTree *t);

/* Return the number of leafs which are prime numbers */
int avl_leafs_primes(AVLTree *t);

/* Return the number of nodes that has two children */
int avl_two_children(AVLTree *t);

/* Return the number of nodes which have equal branch heights*/
int avl_nodes_equal_height(AVLTree *t);

/* Compare if t1 and t2 are equal by traversal tree search */
int avl_equals(AVLTree *t1, AVLTree *t2);

#endif
