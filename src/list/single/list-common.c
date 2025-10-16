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

/**
 * @brief common functions between list-iter and list-rec
 */

#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include "list.h"
#include "../../utils/check_alloc.h"

List* list_create(void) {
    return NULL;
}

int list_empty(List *l) {
    return l == EMPTY_LIST;
}

// util function
List* list__new_node(int data) {
    List* l = (List *) malloc(sizeof(List));
    check_alloc(l);
    l->data = data;
    l->next = list_create();
    return l;
}


List* list_insert(List *l, int data) {
    List* head = list__new_node(data);

    if (list_empty(l)) {
        l = head;
    } else {
        head->next = l;
        l = head;
    }
    return l;
}

List* list_init(int size_list,...) {
    List *l = list_create();
    va_list args;

    va_start(args, size_list);
    for(int i = 0; i < size_list; i++) {
        l = list_append(l, va_arg(args, int));
    }

    va_end(args);
    return l;
}


// check if a given number is perfect or not
int list__is_perfect_number(int n) {
    int sum_divisors = 1;

    for(int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            sum_divisors += i + n/i;
        }
    }
    return sum_divisors == n;

}


int list_head(List *l) {
    return l->data;
}


List* list_tail(List *l) {
    return l->next;
}


int list_pop_head(List** l) {
    if (!list_empty(*l)) {
        int head = (*l)->data;
        List* head_pointer = *l;
        *l = (*l)->next;
        free(head_pointer);
        return head;
    } else {
        printf("Exception: pop head on empty list\n");
        exit(1);
    }
}
