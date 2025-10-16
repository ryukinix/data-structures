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

#ifndef CIRCLE_H
#define CIRCLE_H

#include "../point/point.h"

/**
 * @brief define a Circle structure
 * Has the fields hidden by struct circle
 * as (Point* center) and (float radius)
 */
struct Circle {
    Point* center; /**< the center point of circle */
    float radius; /**< the radius size of the circle */
};


typedef struct Circle Circle;

/**
 * @brief allocate a new circle on memory based on its parameters
 * @param center_pointint is the center point of the circle
 * @param radius is the radius of the circle
 * @return the address of the allocated circle
 */
Circle* circle_create(Point *center, float radius);


/**
 * @brief free memory allocated by the circle c
 * @param c a pointer to Circle structure
 */
void circle_free(Circle *c);

/**
 * @brief Set the circle center
 */
void circle_set_center(Circle *c, Point *center);

/**
 * @brief Set the circle radius
 */
void circle_set_radius(Circle *c, float center);

/**
 * @brief Set the values of center and radius of structure
 */
void circle_set(Circle *c, Point *center, float radius);


/**
 * @brief Get the radius of circle c
 */
float circle_get_radius(Circle *c);

/**
 * @brief Get the center of circle c
 * @param [in] c the circle to get the /p center
 */
Point* circle_get_center(Circle *c);

/**
 * @brief Get the its internal attributes through the pointers passed
 * @param [in] c the desired circle as pointer
 * @param [out] center the point pointer to save the center of \p c
 * @param [out] radius the radius to save the radius of \p c
 */
void circle_get(Circle *c, Point *center, float *radius);

/**
 * @brief Check if the pointer /p point is inside of the circle
 * @param c is the circle to check
 * @param point is the point to check if is inside the /p c
 * @return 1 if inside of the circle, otherwise 0
 */
int circle_point_inside(Circle *c, Point *point);

#endif
