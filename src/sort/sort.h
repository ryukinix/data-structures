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

#ifndef SORT_H
#define SORT_H

#ifndef Type
#define Type int
#endif
#ifndef TypeFormat
#define TypeFormat "%d"
#endif

/**********************/
/* SORTING ALGORITHMS */
/**********************/

/**
 * @brief Sorts an array of integers in ascending order using the bubble sort
 * algorithm.
 *
 * @param v The array to sort.
 * @param n The number of elements in the array.
 * @ingroup SortingAlgorithms
 */
void bubblesort(Type *v, int n);

/**
 * @brief Sorts an array of integers in ascending order using the insertion sort
 * algorithm.
 *
 * @param v The array to sort.
 * @param n The number of elements in the array.
 * @ingroup SortingAlgorithms
 */
void insertionsort(Type *v, int n);

/**
 * @brief Sorts an array of integers in ascending order using the merge sort
 * algorithm.
 *
 * @param v The array to sort.
 * @param n The number of elements in the array.
 * @ingroup SortingAlgorithms
 */
void mergesort(Type *v, int n);

/**
 * @brief Sorts an array of integers in ascending order using the quicksort
 * algorithm.
 *
 * @param v The array to sort.
 * @param n The number of elements in the array.
 * @ingroup SortingAlgorithms
 */
void quicksort(Type *v, int n);

/**
 * @brief Sorts an array of integers in ascending order using the heapsort
 * algorithm.
 *
 * @param v The array to sort.
 * @param n The number of elements in the array.
 * @ingroup SortingAlgorithms
 */
void heapsort(Type *v, int n);

/**
 * @brief Sorts an array of integers in ascending order using the radix sort
 * algorithm.
 *
 * @param v The array to sort.
 * @param n The number of elements in the array.
 * @ingroup SortingAlgorithms
 */
void radixsort(Type *v, int n);

/**
 * @brief Sorts an array of integers in ascending order using the selection sort
 * algorithm.
 *
 * @param v The array to sort.
 * @param n The number of elements in the array.
 * @ingroup SortingAlgorithms
 */
void selectionsort(Type *v, int n);

/*********/
/* UTILS */
/*********/


/**
 * @brief Prints the elements of an array to the console.
 *
 * @param v The array to print.
 * @param n The number of elements in the array.
 */
void print_vector(Type *v, int n);


/**
 * @brief Swaps the values of two integers.
 *
 * @param e1 A pointer to the first integer.
 * @param e2 A pointer to the second integer.
 */
void swap(Type *e1, Type *e2);

/**
 * @brief Checks if an array is sorted in ascending order.
 *
 * @param v The array to check.
 * @param n The number of elements in the array.
 * @return 1 if the array is sorted, 0 otherwise.
 */
int check_sorted(Type *v, int n);

/**
 * @brief Creates an array of random integers.
 *
 * @param n The number of elements in the array.
 * @return A pointer to the new array.
 */
Type* random_vector(int n);

/**
 * @brief Prints the elements of an array to the console if the DEBUG symbol is
 * defined.
 *
 * @param v The array to print.
 * @param n The number of elements in the array.
 */
void debug_print_vector(Type *v, int n);

/**
 * @brief Prints a debug message to the console if the DEBUG symbol is defined.
 *
 * @param format The format string for the message.
 * @param ... The arguments for the format string.
 */
void debug(const char *format, ...);

#endif
