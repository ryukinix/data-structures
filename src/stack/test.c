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
    Iterator* it = stack_iterator(p1);
    printf("Iterating in the rest of the values: \n");
    int k = 1;
    while (!iterator_done(it)) {
        int n = *(int*) iterator_next(it);
        printf("stack[%d] = %d\n", k++, n);
    }
    iterator_free(it);
    stack_free(p1);

#ifdef _WIN32
    pause();
#endif
    return 0;
}
