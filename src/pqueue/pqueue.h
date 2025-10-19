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
 * @brief A priority queue implementation using a binary heap.
 */
struct PQueue {
    int heap[PQUEUE_SIZE]; /**< inner heap for weights */
    int size;              /**< the current size of PQueue */
};


/**
 * @brief A priority queue.
 */
typedef struct PQueue PQueue;

/**
 * @brief Creates an empty priority queue.
 *
 * @return A pointer to the new priority queue.
 * @ingroup DataStructureMethods
 */
PQueue* pqueue_create();

/**
 * @brief Inserts an element into the priority queue.
 *
 * @param pq The priority queue to insert into.
 * @param x The element to insert.
 * @ingroup DataStructureMethods
 */
void pqueue_insert(PQueue *pq, int x);

/**
 * @brief Extracts the maximum element from the priority queue.
 *
 * @param pq The priority queue to extract from.
 * @return The maximum element.
 * @ingroup DataStructureMethods
 */
int pqueue_extract_max(PQueue *pq);

/**
 * @brief Increases the key of an element in the priority queue.
 *
 * @param pq The priority queue.
 * @param k The index of the element to increase.
 * @param v The new value of the element.
 * @ingroup DataStructureMethods
 */
void pqueue_increase_keys(PQueue *pq, int k, int v);

/**
 * @brief Returns the maximum element in the priority queue without extracting it.
 *
 * @param pq The priority queue.
 * @return The maximum element.
 * @ingroup DataStructureMethods
 */
int pqueue_maximum(PQueue *pq);

/**
 * @brief Frees the memory allocated for a priority queue.
 *
 * @param pq The priority queue to free.
 * @ingroup DataStructureMethods
 */
void pqueue_free(PQueue *pq);

/**
 * @brief Prints the elements of a priority queue to the console.
 *
 * @param pq The priority queue to print.
 * @ingroup DataStructureMethods
 */
void pqueue_print(PQueue *pq);

/**
 * @brief Prints the elements of a priority queue to the console, followed by a
 * newline character.
 *
 * @param pq The priority queue to print.
 * @ingroup DataStructureMethods
 */
void pqueue_println(PQueue *pq);

#endif
