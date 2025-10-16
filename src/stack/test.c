/**
 * ================================================
 *
 *         Copyright 2017 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC
 *
 * ===============================================
 */

#include <stdio.h>
#include "stack.h"
#include "../console/console.h"

int main(void) {
    Stack* p1 = stack_create();
    stack_push(p1,10);
    stack_push(p1,20);
    stack_push(p1,25);
    stack_push(p1,30);
    printf("Stack: ");
    stack_println(p1);
    int a = stack_pop(p1);
    printf("Pop: %d\n", a);
    printf("Top element: %d\n", stack_top(p1));
    printf("Odds count %d\n", stack_odds(p1));
    stack_free(p1);

#ifdef _WIN32
    pause();
#endif
    return 0;
}
