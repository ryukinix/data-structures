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

#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

#define EMPTY_QUEUE (Queue*) 0
#ifndef QUEUE_STATIC_MAX
#define QUEUE_STATIC_MAX 1000000
#endif

/**
 * @brief Create a new queue
 */
Queue* queue_create(void);

/**
 * @brief Check if the queueis empty
 */
int queue_empty(Queue *q);

/**
 * @brief Insert a new elemet on the queue
 */
void queue_insert(Queue *q, int data);

/**
 * @brief Remove and return the first element on the queue
 */
int queue_remove(Queue *q);

/**
 * @brief Print the queue (wthout newline)
 */
void queue_print(Queue *q);

/**
 * @brief Print the queue (wth a newline)
 */
void queue_println(Queue *q);

/**
 * @brief Free memory of thequeue structure
 */
void queue_free(Queue *q);

/**
 * @brief Reverse the elemens of the queue
 */
void queue_reverse(Queue *q);

/**
 * @brief Count the number o elements greater than \p n
 */
int queue_greater_than(Queue *q, int n);

/**
 * @brief Count the number o even elements on Queue
 */
int queue_evens(Queue *q);


#endif
