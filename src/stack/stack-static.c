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
#include "stack.h"
#include "../utils/check_alloc.h"

struct stack {
    int n;
    int v[STACK_STATIC_MAX];
};

Stack* stack_create(void) {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    check_alloc(s);
    s->n = 0;
    return s;
}

int stack_empty(Stack* s) {
    return s->n == 0;
}

void stack_push(Stack* s, int data) {
    s->v[s->n++] = data;
}

int stack_pop(Stack* s) {
    return s->v[--s->n];
}

void stack_print(Stack* s) {
    printf("<STACK: [");
    for(int i = 0; i < s->n; i++) {
        printf("%d", s->v[i]);
        if (i + 1 < s->n) {
            printf(", ");
        }
    }
    printf("]>");
}

bool stack_has(Stack *s, int data) {
    for (int i = 0; i < s->n; i++) {
        if (s->v[i] == data) {
            return true;
        }
    }
    return false;
}

void stack_println(Stack* s) {
    stack_print(s);
    printf("\n");
}

void stack_free(Stack* s) {
    s->n = 0;
    free(s);
}

int stack_top(Stack* s) {
    return s->v[s->n-1];
}

int stack_odds(Stack* s) {
    int count = 0;
    for(int i = 0; i < s->n; i++ ) {
        if (s->v[i] & 1) {
            count++;
        }
    }
    return count;
}
