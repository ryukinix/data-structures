/**
 * Copyright 2017-2025 Manoel Vilela
 * UFC
 */

#include <stdio.h>
#include "point.h"
#include "circle.h"
#include "console/console.h"

int main(void) {
    Circle c = read_circle();
    puts(":: Reading a additional point");
    Point p = read_point();

    if (point_inside(&c, &p)) {
        puts("Point inside of the circle!");
    } else {
        puts("Point outside of the circle!");
    }

    pause();

    return 0;
}
