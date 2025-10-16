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
#include <stdlib.h>
#include "list-double.h"
#include "../../utils/check_alloc.h"


ListDouble* list_double__new_node(int data) {
    ListDouble* node = (ListDouble*) malloc(sizeof(ListDouble));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}


ListDouble* list_double_create(void) {
    return EMPTY_LIST_DOUBLE;
}

int list_double_empty(ListDouble *l) {
    return l == EMPTY_LIST_DOUBLE;
}

ListDouble* list_double_insert(ListDouble *l, int data) {
    ListDouble* node = list_double__new_node(data);
    if(list_double_empty(l)) {
        l = node;
    } else {
        node->next = l;
        l->prev = node;
        l = node;
    }

    return l;
}

ListDouble* list_double_search(ListDouble *l, int data) {
    for(ListDouble *lx = l; !list_double_empty(lx); lx = lx->next) {
        if(lx->data == data) {
            return lx;
        }
    }
    return EMPTY_LIST_DOUBLE;
}

ListDouble* list_double_remove(ListDouble *l, int data) {
    ListDouble* lx = list_double_search(l, data);
    if(!list_double_empty(lx)) { // a node was found
        if (!list_double_empty(lx->next)) {
            lx->next->prev = lx->prev;
        }
        if (!list_double_empty(lx->prev)) {
            lx->prev->next = lx->next;
        }
        if (lx == l) {
            l = lx->next;
        }
        free(lx);
    }

    return l;
}

void list_double_print(ListDouble *l) {
    printf("[");
    for(ListDouble *lx = l; !list_double_empty(lx); lx = lx->next) {
        printf("%d", lx->data);
        if(!list_double_empty(lx->next)) {
            printf(", ");
        }
    }
    printf("]");
}

void list_double_println(ListDouble *l) {
    list_double_print(l);
    printf("\n");
}

void list_double_free(ListDouble *l) {
    if(!list_double_empty(l)) {
        list_double_free(l->next);
        free(l);
    }
}
