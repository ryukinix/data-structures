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

#include <stdio.h>
#include "point/point.h"
#include "circle/circle.h"
#include "matrix/matrix.h"
#include "matrix/matrix-utils.h"

void test_matrix(void) {
    puts(":: Testing matrix ADT");
    Matrix *matrix = matrix_create(4, 9);
    for(int i = 0; i < matrix_lines(matrix); i++) {
        for(int j = 0; j < matrix_columns(matrix); j++) {
            matrix_set(matrix, i, j, i*matrix_columns(matrix) + j);
        }
    }
    matrix_print(matrix);
    matrix_free(matrix);
}

void test_circle_and_point() {
    puts(":: Testing point & circle ADT");
    Circle *circle = circle_create(point_create(4, 6), 7);
    Point *external = point_create(100, 200);
    Point *internal = point_create(4, 5);

    if (circle_point_inside(circle, internal)) {
        puts("Ok.");
    } else {
        puts("Fails.");
    }

    if (!circle_point_inside(circle, external)) {
        puts("Ok.");
    } else {
        puts("Fails.");
    }

    circle_free(circle);
    point_free(external);
    point_free(internal);
}

int main(void) {
    test_circle_and_point();
    test_matrix();
    return 0;
}
