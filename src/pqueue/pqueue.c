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
#include <stdlib.h>
#include <stdio.h>

void swap_values(int *e1, int *e2) {
    int temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

int parent(int i) {
    return i / 2;
}

int left(int i) {
    return i * 2;
}

int right(int i) {
    return i * 2 + 1;
}


void heapify_vector(int v[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*(i + 1);

    // verify if left node is greater
    // than largest
    if (l < n && v[l] > v[largest]) {
        largest = l;
    }

    // verify if the right node is greater
    // than largest
    if (r < n && v[r] > v[largest]) {
        largest = r;
    }

    // if current node is not the largest
    // need swap_valuess
    if (largest != i) {
        swap_values(v+i, v+largest); // current and largest
        heapify_vector(v, n, largest); // apply recursively
    }
}

PQueue* pqueue_create() {
    PQueue* pq = (PQueue*) malloc(sizeof(PQueue));
    pq->size = 0;
    return pq;
}

void pqueue_insert(PQueue *pq, int x) {
    pq->size++;
    pq->heap[pq->size-1] = HEAP_EMPTY_CELL;
    pqueue_increase_keys(pq, pq->size-1, x);
}

int pqueue_maximum(PQueue *pq) {
    return pq->heap[0];
}

int pqueue_extract_max(PQueue *pq) {
    if (pq->size < 1) {
        printf("Heap underflow!");
        exit(1);
    }
    int max = pqueue_maximum(pq);
    pq->heap[0] = pq->heap[pq->size-1];
    pq->size--;
    heapify_vector(pq->heap, pq->size, 0);
    return max;

}

void pqueue_print(PQueue *pq) {
    printf("<PQUEUE: [");
    for (int i = 0; i < pq->size; i++) {
        printf("%d", pq->heap[i]);
        if (i + 1 < pq->size) {
            printf(", ");
        }
    }
    printf("]>");
}

void pqueue_println(PQueue *pq) {
    pqueue_print(pq);
    printf("\n");
}

void pqueue_increase_keys(PQueue *pq, int k, int v) {
    if (v < pq->heap[k]) {
        printf("New weight %d is lesser than %d (current)", v, pq->heap[k]);
        exit(1);
    }
    pq->heap[k] = v;
    while(k > 0 && pq->heap[parent(k)] < pq->heap[k]) {
        swap_values(pq->heap+k, pq->heap+parent(k));
        k = parent(k);
    }
}

void pqueue_free(PQueue *pq) {
    free(pq);
}
