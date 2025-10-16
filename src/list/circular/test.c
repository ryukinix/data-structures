/**
 * ================================================
 *
 *         Copyright 2017-2025 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC
 *
 * ===============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "list-circular.h"
#include "../../console/console.h"

int main(void) {
    ListCircular* l = list_circular_create();
    l = list_circular_insert(l,10);
    list_circular_println(l);
    l = list_circular_insert(l,13);
    list_circular_println(l);
    l = list_circular_insert(l,25);
    list_circular_println(l);
    l = list_circular_insert(l,29);
    list_circular_println(l);
    l = list_circular_insert(l,40);
    list_circular_println(l);
    list_circular_println(list_circular_search(l, 29));
    l = list_circular_remove(l,10);
    list_circular_println(l);
    l = list_circular_remove(l,13);
    list_circular_println(l);
    l = list_circular_remove(l,25);
    list_circular_println(l);
    l = list_circular_remove(l,29);
    list_circular_println(l);
    l = list_circular_remove(l,40);
    list_circular_println(l);
    list_circular_free(l);

#ifdef _WIN32
    pause();
#endif

    return 0;
}
