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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <time.h>
#include "sort.h"
#include "../utils/check_alloc.h"

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
    srand(time(NULL));
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

void debug(const char *format, ...) {
#ifdef DEBUG
    va_list args;
    va_start(args, format);

    // Print the prefix
    printf("[debug] ");

    // Print the formatted string
    vprintf(format, args);

    va_end(args);
#else
    (void)format;
#endif
}

void debug_print_vector(Type *v, int n) {
#ifdef DEBUG
    print_vector(v, n);
#else
    (void)v, (void)n;
#endif
}
