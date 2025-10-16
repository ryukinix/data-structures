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
 * @brief pretty print matrix
 * @param matrix the matrix itself
 */
void matrix_print(Matrix *matrix);


/**
 * @brief Get the max value on the matrix
 * @param matrix the matrix pointer
 * @return the max value
 */
float matrix_max(Matrix *matrix);

#endif
