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

#ifndef MATRIX_H
#define MATRIX_H

/**
 * @brief A 2D matrix of floating-point numbers.
 *
 * The matrix is stored in row-major order.
 */
typedef struct matrix Matrix;

/**
 * @brief Create a new matrix
 * @param m means number of lines
 * @param n means number of columns
 * @return the address of the created matrix
 * @ingroup DataStructureMethods
 */
Matrix* matrix_create(int m, int n);


/**
 * @brief Free memory of the matrix
 * @param matrix the matrix pointer itself
 * @ingroup DataStructureMethods
 */
void matrix_free(Matrix* matrix);


/**
 * @brief Get a value on position (i,j) of the matrix
 * @param matrix the matrix pointer
 * @param i the line index
 * @param j the column index
 * @return the value on (i,j) as float
 * @ingroup DataStructureMethods
 */
float matrix_get(Matrix *matrix, int i, int j);


/**
 * @brief Set a value on position(i,j) of the matrix
 * @param matrix the matrix pointer
 * @param i the line index
 * @param j the column index
 * @param v the value the set on (i,j)
 * @ingroup DataStructureMethods
 */
void matrix_set(Matrix *matrix, int i, int j, float v);


/**
 * @brief Get the number of lines of the matrix
 * @param matrix the matrix pointer
 * @return the number of lines
 * @ingroup DataStructureMethods
 */
int matrix_lines (Matrix *matrix);


/**
 * @brief Get the number of columns of the matrix
 * @param matrix the matrix pointer
 * @return the number of columns
 * @ingroup DataStructureMethods
 */
int matrix_columns(Matrix *matrix);


#endif
