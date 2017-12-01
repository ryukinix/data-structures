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

#ifndef SORT_H
#define SORT_H

#ifndef Type
#define Type int
#endif
#ifndef TypeFormat
#define TypeFormat "%d"
#endif
#include <stdbool.h>

/**********************/
/* SORTING ALGORITHMS */
/**********************/

/* Apply BubbleSort Algorithm on the v */
void bubblesort(Type *v, int n);

/* Apply the InsertionSort Algorithm on the v */
void insertionsort(Type *v, int n);

/* Apply the MergeSort Algorithm on the v */
void mergesort(Type *v, int n);

/* Apply the QuickSort Algorithm on the v */
void quicksort(Type *v, int n);

/* Apply the HeapSort Algorithm on the v */
void heapsort(Type *v, int n);

/*********/
/* UTILS */
/*********/


/* Print the v in a pretty format */
void print_vector(Type *v, int n);

/* Swap the values between e1 and e2 */
void swap(Type *e1, Type *e2);

/* Check if the vector v is sorted */
bool check_sorted(Type *v, int n);

/* Return a random_vector with n values */
Type* random_vector(int n);

#endif
