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
#include <assert.h>
#include "sort.h"

// HACK: macro rules
#define N 8
#define TEST(ALGORITHM)                         \
    int *v = random_vector(N);                  \
    printf("== Testing for %s: ", #ALGORITHM);  \
    print_vector(v, N);                         \
    ALGORITHM(v, N);                            \
    printf("Finished: ");                       \
    print_vector(v, N);                         \
    assert(check_sorted(v, N));                 \
    free(v)

void test_bubblesort(void) {
    TEST(bubblesort);
}

void test_insertionsort(void) {
    TEST(insertionsort);

}

void test_quicksort(void) {
    TEST(quicksort);

}

void test_mergesort(void) {
    TEST(mergesort);

}

void test_heapsort(void) {
    TEST(heapsort);

}

void test_radixsort(void) {
    TEST(radixsort);
}

void test_selectionsort(void) {
    TEST(selectionsort);
}

int main(void) {
    test_bubblesort();
    test_insertionsort();
    test_selectionsort();
    test_quicksort();
    test_mergesort();
    test_heapsort();
    test_radixsort();
    return 0;
}
