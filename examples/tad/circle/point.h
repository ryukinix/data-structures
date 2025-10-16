/**
 * Copyright 2017-2025 Manoel Vilela
 * UFC
 */

#ifndef POINT_H
#define POINT_H

/**
 * @brief simple implementation of a two dimensional vector of plane
 */
typedef struct {
    float x; /**< a real number (abscissa)*/
    float y; /**< y another real number (coordenante) */
} Point;

float distance(Point *px, Point *py);
Point new_point(float x, float y);
Point read_point();

#endif
