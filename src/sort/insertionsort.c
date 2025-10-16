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

void insertionsort(Type *v, int n) {
    for (int i = 1; i < n; i++) {
        for(int j = i; j > 0 && v[j-1] > v[j]; j--) {
            swap(v + j, v + j - 1);
        }
     }
}
