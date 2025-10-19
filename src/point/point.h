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

#ifndef POINT_H
#define POINT_H

/**
 * @brief struct Point as 2D space pointer.
 */
struct Point {
    float x; /**< x horizontal point on 2D plane */
    float y; /**< y vertical point on 2D plane */
};


/**
 * @brief Represents a point in a 2D plane.
 */
typedef struct Point Point;

/**
 * @brief create a new Point and set x an y
 *
 * @return the address of the allocated point
 * @ingroup DataStructureMethods
 */
Point* point_create(float x, float y);

/**
 * @brief free memory for the Point p
 * @param p Point to be free
 * @ingroup DataStructureMethods
 */
void point_free(Point *p);

/**
 * @brief Set the values of p.x and p.y
 * @ingroup DataStructureMethods
 */
void point_set(Point *p, float x, float y);

/**
 * @brief Get the values of p.x and p.y through the pointers *x and *y
 * @ingroup DataStructureMethods
 */
void point_get(Point *p, float *x, float *y);

/**
 * @brief Get the y value
 * @ingroup DataStructureMethods
 */
float point_get_y(Point *p);

/**
 * @brief Get the x value
 * @ingroup DataStructureMethods
 */
float point_get_x(Point *p);

/**
 * @brief Copy point origin to destination
 * @ingroup DataStructureMethods
 */
void point_copy(Point *origin, Point *destination);

/**
 * @brief calculate the euclidean distance between two points
 *
 * @return the distance of *px and *py as a float number
 * @ingroup DataStructureMethods
 */
float point_distance(Point *px, Point *py);

#endif
