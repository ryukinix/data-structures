/**
 * ============================================================================
 *
 *                      Copyright 2017 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC
 *
 * ============================================================================
 */

#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix Matrix;

/**
 * @brief Create a new matrix
 * @param m means number of lines
 * @param n means number of columns
 * @return the address of the created matrix
 */
Matrix* matrix_create(int m, int n);


/**
 * @brief Free memory of the matrix
 * @param matrix the matrix pointer itself
 */
void matrix_free(Matrix* matrix);


/**
 * @brieaf Get a value on position (i,j) of the matrix
 * @param the matrix pointer
 * @param i the line index
 * @param j the column index
 * @return the value on (i,j) as float
 */
float matrix_get(Matrix *matrix, int i, int j);


/**
 * @brief Set a value on position(i,j) of the matrix
 * @param matrix the matrix pointer
 * @param i the line index
 * @param j the column index
 * @param v the value the set on (i,j)
 */
void matrix_set(Matrix *matrix, int i, int j, float v);


/**
 * @brief Get the number of lines of the matrix
 * @param matrix the matrix pointer
 * @return the number of lines
 */
int matrix_lines (Matrix *matrix);


/**
 * @brief Get the number of columns of the matrix
 * @param matrix the matrix pointer
 * @return the number of columns
 */
int matrix_columns(Matrix *matrix);


/**
 * @brief Get the max value on the matrix
 * @param matrix the matrix pointer
 * @return the max value
 */
float matrix_max(Matrix *matrix);

#endif
