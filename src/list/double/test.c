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
#include "../../console/console.h"
#include "list-double.h"

int main(void) {
    ListDouble *l = list_double_create();
    l = list_double_insert(l, 10);
    l = list_double_insert(l, 13);
    l = list_double_insert(l, 25);
    l = list_double_insert(l, 29);
    l = list_double_insert(l, 40);
    l = list_double_remove(l, 40);
    list_double_println(l);
    list_double_free(l);

#ifdef _WIN32
    pause();
#endif

    return 0;
}
