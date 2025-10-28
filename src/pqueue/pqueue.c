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
#include <stdbool.h>

int pqueue_size(PQueue *pq) {
    return pq->size;
}

bool pqueue_is_empty(PQueue *pq) {
    return pq->size == 0;
}

void swap_values(int *e1, int *e2) {
    int temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

int parent(int i) {
    return (i - 1) / 2; // Corrected for 0-indexed array
}

int left(int i) {
    return 2 * i + 1; // Corrected for 0-indexed array
}

int right(int i) {
    return 2 * i + 2; // Corrected for 0-indexed array
}

// Max-heapify function
void max_heapify(PQueue *pq, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < pq->size && pq->heap[l] > pq->heap[largest]) {
        largest = l;
    }

    if (r < pq->size && pq->heap[r] > pq->heap[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap_values(&pq->heap[i], &pq->heap[largest]);
        max_heapify(pq, largest);
    }
}

// Min-heapify function
void min_heapify(PQueue *pq, int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < pq->size && pq->heap[l] < pq->heap[smallest]) {
        smallest = l;
    }

    if (r < pq->size && pq->heap[r] < pq->heap[smallest]) {
        smallest = r;
    }

    if (smallest != i) {
        swap_values(&pq->heap[i], &pq->heap[smallest]);
        min_heapify(pq, smallest);
    }
}


PQueue* pqueue_create(PQueueType type) {
    PQueue* pq = (PQueue*) malloc(sizeof(PQueue));
    if (pq == NULL) {
        perror("Failed to allocate memory for PQueue");
        exit(EXIT_FAILURE);
    }
    pq->size = 0;
    pq->type = type;
    return pq;
}

void pqueue_insert(PQueue *pq, int x) {
    if (pq->size == PQUEUE_SIZE) {
        printf("Heap overflow!\n");
        exit(EXIT_FAILURE);
    }
    pq->size++;
    int i = pq->size - 1;
    pq->heap[i] = x; // Temporarily insert at the end

    if (pq->type == MAX_PQUEUE) {
        // Bubble up for max-heap
        while (i > 0 && pq->heap[parent(i)] < pq->heap[i]) {
            swap_values(&pq->heap[i], &pq->heap[parent(i)]);
            i = parent(i);
        }
    } else { // MIN_PQUEUE
        // Bubble up for min-heap
        while (i > 0 && pq->heap[parent(i)] > pq->heap[i]) {
            swap_values(&pq->heap[i], &pq->heap[parent(i)]);
            i = parent(i);
        }
    }
}

int pqueue_top(PQueue *pq) {
    if (pq->size < 1) {
        printf("Heap underflow!\n");
        exit(EXIT_FAILURE);
    }
    return pq->heap[0];
}

int pqueue_extract(PQueue *pq) {
    if (pq->size < 1) {
        printf("Heap underflow!\n");
        exit(EXIT_FAILURE);
    }
    int top_val = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    if (pq->type == MAX_PQUEUE) {
        max_heapify(pq, 0);
    }
    else { // MIN_PQUEUE
        min_heapify(pq, 0);
    }
    return top_val;
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

void pqueue_change_key(PQueue *pq, int k, int v) {
    if (k < 0 || k >= pq->size) {
        printf("Index out of bounds!\n");
        exit(EXIT_FAILURE);
    }

    int old_val = pq->heap[k];
    pq->heap[k] = v;

    if (pq->type == MAX_PQUEUE) {
        if (v < old_val) {
            // If new value is smaller, need to heapify down
            max_heapify(pq, k);
        } else {
            // If new value is larger, need to bubble up
            while (k > 0 && pq->heap[parent(k)] < pq->heap[k]) {
                swap_values(&pq->heap[k], &pq->heap[parent(k)]);
                k = parent(k);
            }
        }
    } else { // MIN_PQUEUE
        if (v > old_val) {
            // If new value is larger, need to heapify down
            min_heapify(pq, k);
        } else {
            // If new value is smaller, need to bubble up
            while (k > 0 && pq->heap[parent(k)] > pq->heap[k]) {
                swap_values(&pq->heap[k], &pq->heap[parent(k)]);
                k = parent(k);
            }
        }
    }
}

void pqueue_free(PQueue *pq) {
    free(pq);
}
