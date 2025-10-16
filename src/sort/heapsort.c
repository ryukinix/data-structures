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

#include "sort.h"

void heapify(Type v[], int n, int i) {
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
    // need swaps
    if (largest != i) {
        swap(v+i, v+largest); // current and largest
        heapify(v, n, largest); // apply recursively
    }
}

void heapsort(Type *v, int n) {
    // build heap
    for(int i = n/ 2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }
    for (int i = n -1; i >= 0; i--) {
        swap(v, v + i);
        heapify(v, i, 0);
    }
}
