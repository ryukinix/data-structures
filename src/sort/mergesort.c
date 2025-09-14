/**
 * ================================================
 *
 *         Copyright 2017-2025 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC-ITA
 *
 * ===============================================
 */

#include "sort.h"

/**
 * @description Merges two partitions in sorted way
 *     /p v is a array of elements
 *     /p l is a index-0 based of the left partition
 *     /p m is the point to cut the array
 *     /p r is a index-0 based of the right partition
 *
 * @example
 *     First subarray is v[l..m]
 *     Second subarray is v[m+1..r]
 */
void merge(Type v[], int l, int m, int r) {
    int i = l;
    int j = l;
    int k = m + 1;
    int n = r - l + 1;

    Type aux[n];
    // merge ordered elements
    while (j <= m && k <= r) {
        if (v[j] < v[k]) {
            aux[i++ - l] = v[j++];
        }
        else {
            aux[i++ - l] = v[k++];
        }
    }

    // copy lasting elements from each side
    while (j <= m) {
        aux[i++ - l] = v[j++];
    }
    while (k <= r) {
        aux[i++ - l] = v[k++];
    }

    // copy from aux to v
    for (int x = l; x <= r; x++) {
        v[x] = aux[x - l];
    }
}



/* Auxiliar function to break in partitions recursively */
void partition(Type v[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        partition(v, l, m);
        partition(v, m+1, r);
        merge(v, l, m, r);

    }
}

// iterative version of partition algorithm
void partition_iter(Type v[], int start, int end) {
    int block_size = 1;
    while (block_size <= end) {
        int block_pointer = start;
        while ((block_pointer + block_size) <= end) {
            int right = block_pointer - 1 + 2 * block_size;
            if (right > end) {
                right = end;
            }
            int middle = block_pointer + block_size - 1;
            merge(v, block_pointer, middle, right);
            block_pointer += 2 * block_size;
        }
        block_size *= 2;
    }
}


void mergesort(Type *v, int n) {
    partition_iter(v, 0, n - 1);
}
