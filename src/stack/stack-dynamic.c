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

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "../utils/check_alloc.h"
#include "../list/single/list.h"

struct stack {
    List* list;
};

Stack* stack_create(void) {
    Stack *s = (Stack*) malloc(sizeof(Stack));
    check_alloc(s);

    s->list = list_create();
    return s;
}

int stack_empty(Stack* s) {
    return list_empty(s->list);
}

void stack_push(Stack *s, int data) {
    s->list = list_insert(s->list, data);
}

int stack_pop(Stack *s) {
    return list_pop_head(&s->list);
}

void stack_print(Stack* s) {
    printf("<STACK: ");
    list_print(s->list);
    printf(">");
}

void stack_println(Stack* s) {
    stack_print(s);
    printf("\n");
}

void stack_free(Stack* s) {
    list_free(s->list);
    s->list = NULL;
    free(s);
}

int stack_top(Stack *s) {
    return list_head(s->list);
}

int stack__list_odds(List* l) {
    if (list_empty(l)) {
        return 0;
    } else if (list_head(l) & 1) {
        return 1 + stack__list_odds(list_tail(l));
    } else {
        return 0 + stack__list_odds(list_tail(l));
    }
}

int stack_odds(Stack *s) {
    return stack__list_odds(s->list);
}
