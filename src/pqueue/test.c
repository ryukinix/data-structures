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

#include "pqueue.h"
#include <stdio.h>

void jarbas_test(void) {
    PQueue *pq = pqueue_create();

    pqueue_insert(pq, 34);
    pqueue_insert(pq, 11);
    pqueue_insert(pq, 45);
    pqueue_insert(pq, 78);
    pqueue_insert(pq, 92);
    pqueue_insert(pq, 66);

    printf("PQueue: ");
    pqueue_println(pq);

    printf("Priority: %d\n", pqueue_maximum(pq));
    int a = pqueue_extract_max(pq);
    printf("PQueue: ");
    pqueue_println(pq);
    printf("Priorities: %d (extracted) and next %d\n", a, pqueue_maximum(pq));
    a = pqueue_extract_max(pq);
    printf("PQueue: ");
    pqueue_println(pq);
    printf("Priorities: %d (extracted) and %d\n", a, pqueue_maximum(pq));
    pqueue_increase_keys(pq, 2, 200);
    printf("Increase index-2 element to 200 priority\n");
    printf("Element of max priority: %d\n", pqueue_maximum(pq));
    printf("PQueue: ");
    pqueue_println(pq);
}

int main(void) {
    jarbas_test();
    return 0;
}
