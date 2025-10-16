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

#include <stdlib.h>
#include <assert.h>
#include "matrix.h"
#include "../utils/check_alloc.h"

struct matrix {
    int lines;
    int columns;
    float *v;
};

Matrix* matrix_create(int m, int n) {
    Matrix *matrix = (Matrix *) malloc(sizeof(Matrix));
    matrix->lines = m;
    matrix->columns = n;

    matrix->v = (float*) malloc(sizeof(float) * m * n);
    check_alloc(matrix->v);

    return matrix;
}

void matrix_free(Matrix* matrix) {
    free(matrix->v);
    free(matrix);
}

float matrix_get(Matrix *matrix, int i, int j) {
    assert(i >= 0 && i < matrix->lines);
    assert(j >= 0 && j < matrix->columns);

    return matrix->v[i*matrix->columns + j];
}

void matrix_set(Matrix *matrix, int i, int j, float v) {
    assert(i >= 0 && i < matrix->lines);
    assert(j >= 0 && j < matrix->columns);

    matrix->v[i*matrix->columns + j] = v;
}


int matrix_lines(Matrix *matrix) {
    return matrix->lines;
}


int matrix_columns(Matrix *matrix) {
    return matrix->columns;
}
