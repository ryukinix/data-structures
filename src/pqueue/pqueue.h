/**
 * ================================================
 *
 *         Copyright 2017-2025 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC
 *
 * ================================================
 */

#ifndef PQUEUE_H
#define PQUEUE_H

#ifndef PQUEUE_SIZE
#define PQUEUE_SIZE 10
#endif

#include <stdbool.h>

/**
 * @brief A node in the priority queue.
 */
typedef struct PQueueNode {
    int key;
    int value; // priority
} PQueueNode;


#define HEAP_EMPTY_NODE (PQueueNode){-1, -1}

/**
 * @brief Enum for priority queue type (min or max).
 */
typedef enum PQueueType {
    MIN_PQUEUE,
    MAX_PQUEUE
} PQueueType;

/**
 * @brief A priority queue implementation using a binary heap.
 */
struct PQueue {
    PQueueNode heap[PQUEUE_SIZE]; /**< inner heap for nodes */
    int size;              /**< the current size of PQueue */
    PQueueType type;       /**< type of the priority queue (min or max) */
};


/**
 * @brief A priority queue.
 */
typedef struct PQueue PQueue;

/**
 * @brief Creates an empty priority queue.
 *
 * @param type The type of priority queue (MIN_PQUEUE or MAX_PQUEUE).
 * @return A pointer to the new priority queue.
 * @ingroup DataStructureMethods
 */
PQueue* pqueue_create(PQueueType type);

/**
 * @brief Inserts an element into the priority queue.
 *
 * @param pq The priority queue to insert into.
 * @param key The key of the element to insert.
 * @param value The value (priority) of the element to insert.
 * @ingroup DataStructureMethods
 */
void pqueue_insert(PQueue *pq, int key, int value);

/**
 * @brief Extracts the top element (max for MAX_PQUEUE, min for MIN_PQUEUE) from the priority queue.
 *
 * @param pq The priority queue to extract from.
 * @return The top element (a PQueueNode).
 * @ingroup DataStructureMethods
 */
PQueueNode pqueue_extract(PQueue *pq);

/**
 * @brief Changes the priority of an element in the priority queue.
 *
 * @param pq The priority queue.
 * @param key The key of the element to change.
 * @param value The new priority of the element.
 * @ingroup DataStructureMethods
 */
void pqueue_change_key(PQueue *pq, int key, int value);

/**
 * @brief Returns the top element (max for MAX_PQUEUE, min for MIN_PQUEUE) in the priority queue without extracting it.
 *
 * @param pq The priority queue.
 * @return The top element (a PQueueNode).
 * @ingroup DataStructureMethods
 */
PQueueNode pqueue_top(PQueue *pq);

/**
 * @brief Returns the number of elements in the priority queue.
 *
 * @param pq The priority queue.
 * @return The number of elements.
 * @ingroup DataStructureMethods
 */
int pqueue_size(PQueue *pq);

/**
 * @brief Checks if the priority queue is empty.
 *
 * @param pq The priority queue.
 * @return True if the priority queue is empty, false otherwise.
 * @ingroup DataStructureMethods
 */
bool pqueue_is_empty(PQueue *pq);

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
