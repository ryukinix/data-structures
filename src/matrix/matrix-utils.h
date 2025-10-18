/**
 * ============================================================================
 *
 *                      Copyright 2017-2025 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC
 *
 * ============================================================================
 */

#ifndef MATRIX_PRINT_H
#define MATRIX_PRINT_H
#include "matrix.h"

/**
 * @brief Prints the elements of a matrix to the console in a formatted way.
 *
 * @param matrix The matrix to print.
 */
void matrix_print(Matrix *matrix);


/**
 * @brief Finds the maximum value in a matrix.
 *
 * @param matrix The matrix to search.
 * @return The maximum value in the matrix.
 */
float matrix_max(Matrix *matrix);

#endif
