/**
 * Copyright 2017-2025 Manoel Vilela
 * UFC
 */


#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

/**
 * @brief A structure to represent a circle
 */
typedef struct {
    Point center; /**< center of the circle as 2D point */
    float r;      /**< radius length of the circle */
} Circle;

int point_inside(Circle *c, Point *p);
Circle new_circle(Point center, float r);
Circle read_circle();

#endif
