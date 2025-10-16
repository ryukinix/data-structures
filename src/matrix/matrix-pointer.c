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

#include <stdlib.h>
#include <assert.h>
#include "matrix.h"
#include "../utils/check_alloc.h"

struct matrix {
    int lines;
    int columns;
    float **v;
};

Matrix* matrix_create(int m, int n) {
    Matrix *matrix = (Matrix *) malloc(sizeof(Matrix));
    check_alloc(matrix);
    matrix->lines = m;
    matrix->columns = n;

    matrix->v = (float**) malloc(sizeof(float*) * matrix->lines);
    check_alloc(matrix->v);

    for(int i = 0; i < matrix->lines; i++) {
        matrix->v[i] = (float*) calloc(matrix->columns, sizeof(float));
        check_alloc(matrix->v[i]);
    }

    return matrix;
}

void matrix_free(Matrix* matrix) {
    int lines = matrix->lines;
    for(int i = 0; i < lines; i++) {
        free(matrix->v[i]);
    }
    free(matrix->v);
    free(matrix);
}

float matrix_get(Matrix *matrix, int i, int j) {
    assert(i >= 0 && i < matrix->lines);
    assert(j >= 0 && j < matrix->columns);

    return matrix->v[i][j];
}

void matrix_set(Matrix *matrix, int i, int j, float v) {
    assert(i >= 0 && i < matrix->lines);
    assert(j >= 0 && j < matrix->columns);

    matrix->v[i][j] = v;
}


int matrix_lines(Matrix *matrix) {
    return matrix->lines;
}


int matrix_columns(Matrix *matrix) {
    return matrix->columns;
}
