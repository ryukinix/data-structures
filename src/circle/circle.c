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
#include "circle.h"
#include "../utils/check_alloc.h"

Circle* circle_create(Point *center, float radius) {
    Circle* c = (Circle *) malloc(sizeof(Circle));
    check_alloc(c);
    c->center = center;
    c->radius = radius;
    return c;
}

void circle_free(Circle *c) {
    free(c->center);
    free(c);
}

void circle_set_center(Circle *c, Point *center) {
    c->center = center;
}

void circle_set_radius(Circle *c, float radius) {
    c->radius = radius;
}

void circle_set(Circle *c, Point *center, float radius) {
    circle_set_center(c, center);
    circle_set_radius(c, radius);
}


float circle_get_radius(Circle *c) {
    return c->radius;
}

Point* circle_get_center(Circle *c) {
    return c->center;
}

void circle_get(Circle *c, Point *center, float *radius) {
    *radius = c->radius;
    point_copy(c->center, center);
}

int circle_point_inside(Circle *c, Point *point) {
    float distance_from_center = point_distance(c->center, point);
    return (distance_from_center < c->radius);
}
