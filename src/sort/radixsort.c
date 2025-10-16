/**
 * ================================================
 *
 *         Copyright 2025 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: ITA
 *
 * ===============================================
 */

#define BASE 10

#include <math.h>
#include <stdio.h>

#include "../queue/queue.h"
#include "sort.h"


void init_queues(Queue* q[BASE]) {
    for (int i = 0; i < BASE; i++) {
        q[i] = queue_create();
    }
}

int digits(int k) {
    return floor(log10(k)) + 1;
}

int max_digits(Type *v, int n) {
    int max_value = digits(v[0]);
    for (int i = 1; i < n; i++) {
        int value = digits(v[i]);
        if (value > max_value) {
            max_value = value;
        }
    }
    return max_value;
}


void radixsort(Type *v, int n) {
    Queue* q[BASE];
    init_queues(q);
    int d = max_digits(v, n);

    for (int i = 0, factor = 1; i < d; factor *= BASE, i++) {
        for (int j = 0; j < n; j++) {
            Queue* digit_queue = q[(v[j] / factor) % BASE];
            queue_insert(digit_queue, v[j]);
        }

        for (int j = 0, k = 0; j < BASE; j++) {
            while (!queue_empty(q[j])) {
              v[k++] = queue_remove(q[j]);
            }
       }

    }
}
