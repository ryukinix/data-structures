/**
 * Copyright 2017-2025 Manoel Vilela
 * UFC
 */

#include <stdio.h>
#include "circle.h"
#include "point.h"

/**
 * @brief check if the external point `p` is inside of circle `c`
 *
 * To this be true, the distance of the point from the center
 * should be lesser than the size of radius.
 *
 * @param c a pointer to Circle structure
 * @param p a pointer to a Point to check if inside of the Circle
 */
int point_inside(Circle *c, Point *p) {
    float d = distance(&c->center, p);
    return (d < c->r);
}

/**
 * @brief create a new Circle structure based on its parameters
 *
 * @param center a Point structure which represents the center of the circle
 * @param r the radio of the circle;
 */
Circle new_circle(Point center, float r) {
    Circle c;
    c.center = center;
    c.r = r;
    return c;
}


/**
 * @brief read a new Circle from stdin
 *
 * @return a new circle structure
 */
Circle read_circle() {
    float r;
    Point center;
    printf(":: Reading a circle\n");
    puts("=> Circle.center");
    center = read_point();
    puts("=> Circle.r");
    printf("Type the size of radius: ");
    scanf("%f", &r);

    return new_circle(center, r);
}
