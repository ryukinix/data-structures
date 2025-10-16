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

/**
 * @brief List methods defined recursively
 */


#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "../../utils/check_alloc.h"


// auxiliar print recursively list (without squared brackets)
void list__aux_print(List *l) {
    if(!list_empty(l)) {
        printf("%d", l->data);
        if (!list_empty(l->next)) {
            printf(", ");
        }
        list__aux_print(l->next);
    }
}

// the is_init param is used to signalize if is the first funcall
// to print correctly without a comma on the last element (which is the first)
void list__aux_print_reverse(List *l, int is_init) {
    if(!list_empty(l)) {
        list__aux_print_reverse(l->next, 0);
        printf("%d", l->data);
        if (!is_init) {
            printf(", ");
        }
    }
}

void list_print(List *l) {
    printf("[");
    list__aux_print(l);
    printf("]");
}

void list_println(List *l) {
    list_print(l);
    printf("\n");
}

void list_print_reverse(List *l) {
    printf("[");
    list__aux_print_reverse(l, 1);
    printf("]");
}

void list_println_reverse(List *l) {
    list_print_reverse(l);
    printf("\n");
}

List* list_append(List *l, int data) {
    if (list_empty(l)) {
        l = list__new_node(data);
    } else {
        l->next = list_append(l->next, data);
    }

    return l;
}


List* list_insert_ord(List *l, int data) {
    if(list_empty(l) || data <= l->data) {
        l = list_insert(l, data);
    } else {
        l->next = list_insert_ord(l->next, data);
    }
    return l;
}


List* list_search(List *l, int data) {
    if(!list_empty(l)) {
        if (l->data != data) {
            l = list_search(l->next, data);
        }
    }
    return l;
}


List* list_remove(List *l, int data) {
    if (!list_empty(l)) {
        if (l->data == data) {
            List* next = l->next;
            free(l);
            l = next;
        } else {
            l->next = list_remove(l->next, data);
        }
    }
    return l;
}

void list_free(List *l) {
    if (!list_empty(l)) {
        list_free(l->next);
        free(l);
    }
}


int list_last(List *l) {
    if (!list_empty(l) && list_empty(l->next)) {
        return l->data;
    } else if (!list_empty(l)) {
        return list_last(l->next);
    } else {
        printf("Exception: trying get last on empty list\n");
        exit(1);
    }
}


int list_pop_last(List** l) {
    if (!list_empty(*l) && list_empty((*l)->next)) {
        return list_pop_head(l);
    } else if (!list_empty(*l)) {
        return list_pop_last(&(*l)->next);
    } else {
        printf("Exception: pop last on empty list\n");
        exit(1);
    }
}

int list_equal(List* l_x, List* l_y) {
    if (list_empty(l_x) && list_empty(l_y)) {
        return true;
    } else if (list_empty(l_x) || list_empty(l_y)) {
        return false;
    } else {
        return l_x->data==l_y->data && list_equal(l_x->next, l_y->next);
    }
}


int list_perfect(List *l) {
    if (list_empty(l)) {
        return 0;
    } else if (list__is_perfect_number(list_head(l))) {
        return 1 + list_perfect(list_tail(l));
    } else {
        return 0 + list_perfect(list_tail(l));
    }
}

int list_length(List *l) {
    if (list_empty(l)) {
        return 0;
    } else {
        return 1 + list_length(list_tail(l));
    }
}


int list_less_than(List *l, int n) {
    if (list_empty(l)) {
        return 0;
    } else if (list_head(l) < n) {
        return 1 + list_less_than(list_tail(l), n);
    } else {
        return 0 + list_less_than(list_tail(l), n);
    }
}


int list_sum(List *l) {
    if (list_empty(l)) {
        return 0;
    } else {
        return list_head(l) + list_sum(list_tail(l));
    }
}


/** create a copy of l */
List* list_copy(List *l) {
    List* copy = list_create();

    if (!list_empty(l)) {
        copy = list_insert(copy, list_head(l));
        copy->next = list_copy(list_tail(l));
    }

    return copy;
}

/* Concatenation l_y into l_x :: Side-effect: modify l_x */
List* list__aux_concat(List *l_x, List *l_y) {
    if (list_empty(l_y)) {
        return l_x;
    } else if (list_empty(l_x)) {
        return l_y;
    } else {
        l_x->next = list__aux_concat(list_tail(l_x), l_y);
        return l_x;
    }
}


List* list_concat(List *l_x, List* l_y) {
    List* copy_lx = list_copy(l_x);
    List* copy_ly = list_copy(l_y);
    return list__aux_concat(copy_lx, copy_ly);
}


void list_reverse(List** l) {
    if (list_empty(*l) || list_empty((*l)->next)) {
        return;
    }

    List* first = *l;
    List* tail = first->next;

    // reverse the tail recursively
    list_reverse(&tail);
    first->next->next = first;
    first->next = NULL;

    *l = tail;
}
