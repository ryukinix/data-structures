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

#include "sort.h"
#include <stdio.h>

void quicksort(Type *v, int n) {
    static int k = 0;
    if (n <= 1) {
        return;
    }

    const int pivot = 0;
    int x = v[pivot];
    int left = pivot + 1;
    int right = n - 1;

    while (1) {
        while(left < n && v[left] <= x) left++;
        while(v[right] > x) right--;
        if (left < right) {
            debug("%d: swap: v[%d]=%d <-> v[%d]=%d \n", k, left, v[left], right, v[right]);
            swap(v + left, v + right);
            left++;
            right--;
        } else {
            break;
        }
    }
    debug("%d: swap: v[%d]=%d <-> v[%d]=%d \n", k, left, v[right], right, v[right]);
    swap(v + pivot, v + right);
    debug("%d: pivt: v[%d]=%d\n", k, right, v[right]); k++;
    debug("%d: left:  ", k);
    debug_print_vector(v, right);
    debug("%d: right: ", k);
    debug_print_vector(v + left, n - left);
    quicksort(v + left, n - left);
    quicksort(v, right);
}
