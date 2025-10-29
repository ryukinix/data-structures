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

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "pqueue.h"

void test_max_pqueue(void) {
    printf("--- Testing Max Priority Queue ---\n");
    PQueue *pq = pqueue_create(MAX_PQUEUE);

    pqueue_insert(pq, 0, 34);
    pqueue_insert(pq, 1, 11);
    pqueue_insert(pq, 2, 45);
    pqueue_insert(pq, 3, 78);
    pqueue_insert(pq, 4, 92);
    pqueue_insert(pq, 5, 66);

    printf("Initial PQueue: ");
    pqueue_println(pq);

    PQueueNode top = pqueue_top(pq);
    printf("Top priority: (%d, %d)\n", top.key, top.value);
    PQueueNode extracted = pqueue_extract(pq);
    printf("Extracted: (%d, %d)\n", extracted.key, extracted.value);
    printf("PQueue after extract: ");
    pqueue_println(pq);

    top = pqueue_top(pq);
    printf("Top priority: (%d, %d)\n", top.key, top.value);
    extracted = pqueue_extract(pq);
    printf("Extracted: (%d, %d)\n", extracted.key, extracted.value);
    printf("PQueue after extract: ");
    pqueue_println(pq);

    pqueue_change_key(pq, 2, 200);
    printf("Changed key-2 element to 200 priority\n");
    printf("PQueue after change_key: ");
    pqueue_println(pq);
    top = pqueue_top(pq);
    printf("Element of top priority: (%d, %d)\n", top.key, top.value);

    pqueue_free(pq);
    printf("--- End Max Priority Queue Test ---\n\n");
}

void test_min_pqueue(void) {
    printf("--- Testing Min Priority Queue ---\n");
    PQueue *pq = pqueue_create(MIN_PQUEUE);

    printf("Inserting (0, 10)...\n");
    pqueue_insert(pq, 0, 10);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 1);
    assert(pqueue_top(pq).value == 10);

    printf("Inserting (1, 20)...\n");
    pqueue_insert(pq, 1, 20);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 2);
    assert(pqueue_top(pq).value == 10);

    printf("Inserting (2, 5)...\n");
    pqueue_insert(pq, 2, 5);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 3);
    assert(pqueue_top(pq).value == 5);

    printf("Inserting (3, 25)...\n");
    pqueue_insert(pq, 3, 25);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 4);
    assert(pqueue_top(pq).value == 5);

    printf("Inserting (4, 15)...\n");
    pqueue_insert(pq, 4, 15);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 5);
    assert(pqueue_top(pq).value == 5);

    printf("Size: %d\n", pqueue_size(pq));
    printf("Min: %d\n", pqueue_top(pq).value);

    printf("Extracting min...\n");
    assert(pqueue_extract(pq).value == 5);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 4);
    assert(pqueue_top(pq).value == 10);

    printf("Extracting min...\n");
    assert(pqueue_extract(pq).value == 10);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 3);
    assert(pqueue_top(pq).value == 15);

    printf("Extracting min...\n");
    assert(pqueue_extract(pq).value == 15);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 2);
    assert(pqueue_top(pq).value == 20);

    printf("Extracting min...\n");
    assert(pqueue_extract(pq).value == 20);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 1);
    assert(pqueue_top(pq).value == 25);

    printf("Extracting min...\n");
    assert(pqueue_extract(pq).value == 25);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_is_empty(pq));

    pqueue_free(pq);
    printf("--- End Min Priority Queue Test ---\n\n");
}

void test_pqueue_growth(void) {
    printf("--- Testing PQueue Growth ---\n");
    PQueue *pq = pqueue_create(MIN_PQUEUE);
    int initial_capacity = pq->capacity;
    printf("Initial capacity: %d\n", initial_capacity);

    for (int i = 0; i < initial_capacity + 5; i++) {
        pqueue_insert(pq, i, i);
    }

    printf("PQueue after inserting %d elements: ", pqueue_size(pq));
    pqueue_println(pq);
    assert(pq->size == initial_capacity + 5);
    assert(pq->capacity == initial_capacity + PQUEUE_GROWTH_FACTOR);
    printf("Final capacity: %d\n", pq->capacity);

    pqueue_free(pq);
    printf("--- End PQueue Growth Test ---\n\n");
}


int main(void) {
    test_max_pqueue();
    test_min_pqueue();
    test_pqueue_growth();
    return 0;
}

