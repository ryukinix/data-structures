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

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "utils/check_alloc.h"

struct queue {
    int size;
    int start;
    int v[QUEUE_STATIC_MAX];
};


Queue* queue_create(void) {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    check_alloc(q);
    q->size = 0;
    q->start = 0;
    return q;
}


int queue_empty(Queue *q) {
    return q->size == 0;
}


void queue_insert(Queue *q, int data) {
    int end;
    if (q->size == QUEUE_STATIC_MAX) {
        printf("Exception: Insert on full queue! size=%d\n", q->size);
        exit(EXIT_FAILURE);
    }
    end = (q->start + q->size) % QUEUE_STATIC_MAX;
    q->v[end] = data;
    q->size++;
}


int queue_remove(Queue *q) {
    int data;
    if(queue_empty(q)) {
        printf("Exception: remove on empty queue!\n");
        exit(EXIT_FAILURE);
    }
    data = q->v[q->start];
    q->start = (q->start + 1) % QUEUE_STATIC_MAX;
    q->size--;
    return data;

}


void queue_print(Queue *q) {
    printf("<QUEUE: [");
    for(int i = 0; i < q->size; i++) {
        int k = (q->start+i) % QUEUE_STATIC_MAX;
        printf("%d", q->v[k]);
        if (i + 1 < q->size) {
            printf(", ");
        }
    }
    printf("]>");
}


void queue_println(Queue *q) {
    queue_print(q);
    printf("\n");
}


void queue_free(Queue *q) {
    free(q);
}

void queue__swap_values(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void queue_reverse(Queue *q) {
    // get the index of the last element
    int end = (q->start + q->size) % QUEUE_STATIC_MAX - 1;
    for(int i = 0; i < q->size/2; i++) {
        int k_start = (q->start+i) % QUEUE_STATIC_MAX;
        int k_end = (end - i) % QUEUE_STATIC_MAX;
        queue__swap_values(q->v + k_start, q->v + k_end);
    }
}


int queue_greater_than(Queue *q, int n) {
    int count = 0;
    for(int i = 0; i < q->size; i++) {
        int k = (q->start+i) % QUEUE_STATIC_MAX;
        int elem = q->v[k];
        if (elem > n) {
            count++;
        }
    }
    return count;
}


int queue_evens(Queue *q) {
    int count = 0;
    for(int i = 0; i < q->size; i++) {
        int k = (q->start+i) % QUEUE_STATIC_MAX;
        int elem = q->v[k];
        if (elem % 2 == 0) {
            count++;
        }
    }
    return count;
}
