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

void swap_nodes(PQueueNode *n1, PQueueNode *n2) {
    PQueueNode temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int parent(int i) {
    return i / 2;
}

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

// Max-heapify function
void max_heapify(PQueue *pq, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < pq->size && pq->heap[l].value > pq->heap[largest].value) {
        largest = l;
    }

    if (r < pq->size && pq->heap[r].value > pq->heap[largest].value) {
        largest = r;
    }

    if (largest != i) {
        swap_nodes(&pq->heap[i], &pq->heap[largest]);
        max_heapify(pq, largest);
    }
}

// Min-heapify function
void min_heapify(PQueue *pq, int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < pq->size && pq->heap[l].value < pq->heap[smallest].value) {
        smallest = l;
    }

    if (r < pq->size && pq->heap[r].value < pq->heap[smallest].value) {
        smallest = r;
    }

    if (smallest != i) {
        swap_nodes(&pq->heap[i], &pq->heap[smallest]);
        min_heapify(pq, smallest);
    }
}


PQueue* pqueue_create(PQueueType type) {
    PQueue* pq = (PQueue*) malloc(sizeof(PQueue));
    if (pq == NULL) {
        perror("Failed to allocate memory for PQueue");
        exit(EXIT_FAILURE);
    }
    pq->heap = (PQueueNode*) malloc(PQUEUE_SIZE * sizeof(PQueueNode));
    if (pq->heap == NULL) {
        perror("Failed to allocate memory for PQueue heap");
        free(pq);
        exit(EXIT_FAILURE);
    }
    pq->size = 0;
    pq->capacity = PQUEUE_SIZE;
    pq->type = type;
    return pq;
}

void pqueue_insert(PQueue *pq, int key, int value) {
    if (pq->size == pq->capacity) {
        pq->capacity += PQUEUE_GROWTH_FACTOR;
        pq->heap = (PQueueNode*) realloc(pq->heap, pq->capacity * sizeof(PQueueNode));
        if (pq->heap == NULL) {
            perror("Failed to reallocate memory for PQueue heap");
            exit(EXIT_FAILURE);
        }
    }
    pq->size++;
    int i = pq->size - 1;
    pq->heap[i] = (PQueueNode){key, value};

    if (pq->type == MAX_PQUEUE) {
        // Bubble up for max-heap
        while (i > 0 && pq->heap[parent(i)].value < pq->heap[i].value) {
            swap_nodes(&pq->heap[i], &pq->heap[parent(i)]);
            i = parent(i);
        }
    } else { // MIN_PQUEUE
        // Bubble up for min-heap
        while (i > 0 && pq->heap[parent(i)].value > pq->heap[i].value) {
            swap_nodes(&pq->heap[i], &pq->heap[parent(i)]);
            i = parent(i);
        }
    }
}

PQueueNode pqueue_top(PQueue *pq) {
    if (pq->size < 1) {
        printf("Heap underflow!\n");
        return HEAP_EMPTY_NODE;
    }
    return pq->heap[0];
}

PQueueNode pqueue_extract(PQueue *pq) {
    if (pq->size < 1) {
        printf("Heap underflow!\n");
        return HEAP_EMPTY_NODE;
    }
    PQueueNode top_node = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    if (pq->type == MAX_PQUEUE) {
        max_heapify(pq, 0);
    }
    else { // MIN_PQUEUE
        min_heapify(pq, 0);
    }
    return top_node;
}

void pqueue_print(PQueue *pq) {
    printf("<PQUEUE(size=%d, capacity=%d): [", pq->size, pq->capacity);
    for (int i = 0; i < pq->size; i++) {
        printf("(%d, %d)", pq->heap[i].key, pq->heap[i].value);
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

int find_key_index(PQueue *pq, int key) {
    for (int i = 0; i < pq->size; i++) {
        if (pq->heap[i].key == key) {
            return i;
        }
    }
    return -1;
}

void pqueue_update_key(PQueue *pq, int key, int value) {
    int k = find_key_index(pq, key);
    if (k == -1) {
        printf("Key not found!\n");
        return;
    }

    int old_value = pq->heap[k].value;
    pq->heap[k].value = value;

    if (pq->type == MAX_PQUEUE) {
        if (value < old_value) {
            // If new value is smaller, need to heapify down
            max_heapify(pq, k);
        } else {
            // If new value is larger, need to bubble up
            while (k > 0 && pq->heap[parent(k)].value < pq->heap[k].value) {
                swap_nodes(&pq->heap[k], &pq->heap[parent(k)]);
                k = parent(k);
            }
        }
    } else { // MIN_PQUEUE
        if (value > old_value) {
            // If new value is larger, need to heapify down
            min_heapify(pq, k);
        } else {
            // If new value is smaller, need to bubble up
            while (k > 0 && pq->heap[parent(k)].value > pq->heap[k].value) {
                swap_nodes(&pq->heap[k], &pq->heap[parent(k)]);
                k = parent(k);
            }
        }
    }
}

void pqueue_free(PQueue *pq) {
    free(pq->heap);
    free(pq);
}


struct PQueueIterator {
    PQueue* pq;
    int index;
};


void* pqueue_iterator_next_node(Iterator *it) {
    struct PQueueIterator *pq_it = (struct PQueueIterator*) it->container;
    int i = pq_it->index++;
    return &pq_it->pq->heap[i];
}


void* pqueue_iterator_next_key(Iterator *it) {
    struct PQueueNode* node = (struct PQueueNode*) pqueue_iterator_next_node(it);
    return &node->key;
}


bool pqueue_iterator_done(Iterator *it) {
    struct PQueueIterator *pq_it = (struct PQueueIterator*) it->container;
    return pq_it->index == pq_it->pq->size;
}


void pqueue_iterator_free(Iterator *it) {
    free(it->container);
    free(it);
}


Iterator* pqueue_iterator(PQueue *pq) {
    struct PQueueIterator *pq_it = malloc(sizeof(struct PQueueIterator));
    check_alloc(pq_it);
    pq_it->pq = pq;
    pq_it->index = 0;
    return iterator_create(
        pq_it,
        pqueue_iterator_next_node,
        pqueue_iterator_free,
        pqueue_iterator_done
    );
}


Iterator* pqueue_iterator_keys(PQueue *pq) {
    struct PQueueIterator *pq_it = malloc(sizeof(struct PQueueIterator));
    check_alloc(pq_it);
    pq_it->pq = pq;
    pq_it->index = 0;
    return iterator_create(
        pq_it,
        pqueue_iterator_next_key,
        pqueue_iterator_free,
        pqueue_iterator_done
    );
}
