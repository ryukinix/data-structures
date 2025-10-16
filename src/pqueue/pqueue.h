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

#ifndef PQUEUE_H
#ifndef PQUEUE_SIZE
#define PQUEUE_SIZE 10
#endif

#define HEAP_EMPTY_CELL -1

/**
 * @brief Priority Queue Data Structure.
 * Like a normal queue about push/pop logic,
 *  but each individual now heave a weight. A inner
 * heap implementation it's provided.
 */
struct PQueue {
    int heap[PQUEUE_SIZE]; /**< inner heap for weights */
    int size;              /**< the current size of PQueue */
};


typedef struct PQueue PQueue;

PQueue* pqueue_create();

void pqueue_insert(PQueue *pq, int x);

int pqueue_extract_max(PQueue *pq);

void pqueue_increase_keys(PQueue *pq, int k, int v);

int pqueue_maximum(PQueue *pq);

void pqueue_free(PQueue *pq);

void pqueue_print(PQueue *pq);

void pqueue_println(PQueue *pq);

#endif
