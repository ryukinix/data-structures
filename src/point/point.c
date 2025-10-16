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
#include <math.h>
#include "point.h"
#include "../utils/check_alloc.h"


Point* point_create(float x, float y) {
    Point* p = (Point *) malloc(sizeof(Point));
    check_alloc(p);
    p->x = x;
    p->y = y;
    return p;
}

void point_free(Point *p) {
    free(p);
}


void point_set(Point *p, float x, float y) {
    p->x = x;
    p->y = y;
}


void point_get(Point *p, float *x, float *y) {
    *x = p->x;
    *y = p->y;
}

float point_get_x(Point *p) {
    return p->x;
}

float point_get_y(Point *p) {
    return p->y;
}

void point_copy(Point *origin, Point *destination) {
    destination->x = origin->x;
    destination->y = origin->y;
}

float point_distance(Point *px, Point *py) {
    return sqrt(pow(px->x - py->x, 2)
              + pow(px->y - py->y, 2));
}
