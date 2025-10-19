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

#ifndef QUEUE_H
#define QUEUE_H

/**
 * @brief A queue data structure.
 */
typedef struct queue Queue;

#define EMPTY_QUEUE (Queue*) 0
#ifndef QUEUE_STATIC_MAX
#define QUEUE_STATIC_MAX 1000000
#endif

/**
 * @brief Creates an empty queue.
 *
 * @return A pointer to the new queue.
 * @ingroup DataStructureMethods
 */
Queue* queue_create(void);

/**
 * @brief Checks if a queue is empty.
 *
 * @param q The queue to check.
 * @return 1 if the queue is empty, 0 otherwise.
 * @ingroup DataStructureMethods
 */
int queue_empty(Queue *q);

/**
 * @brief Inserts an element at the back of a queue.
 *
 * @param q The queue to insert into.
 * @param data The data to insert.
 * @ingroup DataStructureMethods
 */
void queue_insert(Queue *q, int data);

/**
 * @brief Removes and returns the element at the front of a queue.
 *
 * @param q The queue to remove from.
 * @return The element at the front of the queue.
 * @ingroup DataStructureMethods
 */
int queue_remove(Queue *q);

/**
 * @brief Prints the elements of a queue to the console.
 *
 * @param q The queue to print.
 * @ingroup DataStructureMethods
 */
void queue_print(Queue *q);

/**
 * @brief Prints the elements of a queue to the console, followed by a newline
 * character.
 *
 * @param q The queue to print.
 * @ingroup DataStructureMethods
 */
void queue_println(Queue *q);

/**
 * @brief Frees the memory allocated for a queue.
 *
 * @param q The queue to free.
 * @ingroup DataStructureMethods
 */
void queue_free(Queue *q);

/**
 * @brief Reverses the elements of a queue.
 *
 * @param q The queue to reverse.
 * @ingroup DataStructureMethods
 */
void queue_reverse(Queue *q);

/**
 * @brief Counts the number of elements in a queue that are greater than a given
 * value.
 *
 * @param q The queue to search.
 * @param n The value to compare against.
 * @return The number of elements greater than n.
 * @ingroup DataStructureMethods
 */
int queue_greater_than(Queue *q, int n);

/**
 * @brief Counts the number of even elements in a queue.
 *
 * @param q The queue to search.
 * @return The number of even elements.
 * @ingroup DataStructureMethods
 */
int queue_evens(Queue *q);


#endif
