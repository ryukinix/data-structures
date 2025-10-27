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

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE

void test_max_pqueue(void) {
    printf("--- Testing Max Priority Queue ---\n");
    PQueue *pq = pqueue_create(MAX_PQUEUE);

    pqueue_insert(pq, 34);
    pqueue_insert(pq, 11);
    pqueue_insert(pq, 45);
    pqueue_insert(pq, 78);
    pqueue_insert(pq, 92);
    pqueue_insert(pq, 66);

    printf("Initial PQueue: ");
    pqueue_println(pq);

    printf("Top priority: %d\n", pqueue_top(pq));
    int extracted = pqueue_extract(pq);
    printf("Extracted: %d\n", extracted);
    printf("PQueue after extract: ");
    pqueue_println(pq);

    printf("Top priority: %d\n", pqueue_top(pq));
    extracted = pqueue_extract(pq);
    printf("Extracted: %d\n", extracted);
    printf("PQueue after extract: ");
    pqueue_println(pq);

    pqueue_change_key(pq, 2, 200);
    printf("Changed index-2 element to 200 priority\n");
    printf("PQueue after change_key: ");
    pqueue_println(pq);
    printf("Element of top priority: %d\n", pqueue_top(pq));

    pqueue_free(pq);
    printf("--- End Max Priority Queue Test ---\n\n");
}

void test_min_pqueue(void) {
    printf("--- Testing Min Priority Queue ---\n");
    PQueue *pq = pqueue_create(MIN_PQUEUE);

    printf("Inserting 10...\n");
    pqueue_insert(pq, 10);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 1);
    assert(pqueue_top(pq) == 10);

    printf("Inserting 20...\n");
    pqueue_insert(pq, 20);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 2);
    assert(pqueue_top(pq) == 10);

    printf("Inserting 5...\n");
    pqueue_insert(pq, 5);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 3);
    assert(pqueue_top(pq) == 5);

    printf("Inserting 25...\n");
    pqueue_insert(pq, 25);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 4);
    assert(pqueue_top(pq) == 5);

    printf("Inserting 15...\n");
    pqueue_insert(pq, 15);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 5);
    assert(pqueue_top(pq) == 5);

    printf("Size: %d\n", pqueue_size(pq));
    printf("Min: %d\n", pqueue_top(pq));

    printf("Extracting min...\n");
    assert(pqueue_extract(pq) == 5);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 4);
    assert(pqueue_top(pq) == 10);

    printf("Extracting min...\n");
    assert(pqueue_extract(pq) == 10);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 3);
    assert(pqueue_top(pq) == 15);

    printf("Extracting min...\n");
    assert(pqueue_extract(pq) == 15);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 2);
    assert(pqueue_top(pq) == 20);

    printf("Extracting min...\n");
    assert(pqueue_extract(pq) == 20);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_size(pq) == 1);
    assert(pqueue_top(pq) == 25);

    printf("Extracting min...\n");
    assert(pqueue_extract(pq) == 25);
    printf("PQueue: "); pqueue_println(pq);
    assert(pqueue_is_empty(pq));

    pqueue_free(pq);
    printf("--- End Min Priority Queue Test ---\n\n");
}


int main(void) {
    test_max_pqueue();
    test_min_pqueue();
    return EXIT_SUCCESS;
}
