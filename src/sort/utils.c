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
#include <stdbool.h>
#include <time.h>
#include "sort.h"
#include "utils/check_alloc.h"

void print_vector(Type *v, int n) {
    printf("[");
    for(int i = 0; i < n; i++) {
        printf(TypeFormat, v[i]);
        if (i + 1 < n) {
            printf(", ");
        }
    }
    printf("]\n");
}

Type* random_vector(int n) {
    Type* v = (Type*) malloc(sizeof(Type) * n);
    check_alloc(v);
    srand(time((void*) v));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % n;

#ifdef UNIQUE_RANDOM_NUMBERS
        // ensure the numbers are unique
        for (int j = 0; j < i; j++) {
            if (v[i] == v[j]) {
                i--;
                break;
            }
        }
#endif
    }
    return v;
}

// check if array v is sorted, O(n)
int check_sorted(Type *v, int n) {
    int i;

    for (i = 0; i < n - 1 ; i++) {
        if (v[i] > v[i + 1]) {
            return false;
        }
    }
    return true;
}

void swap(Type *e1, Type *e2) {
    Type temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}
