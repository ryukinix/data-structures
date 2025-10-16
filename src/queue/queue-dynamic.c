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

#include <stdlib.h>
#include <stdio.h>
#include "../list/single/list.h"
#include "../utils/check_alloc.h"
#include "queue.h"

struct queue {
    List* start;
    List* end;
};


Queue* queue_create(void) {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    check_alloc(q);
    q->start = list_create();
    q->end = list_create();
    return q;
}


int queue_empty(Queue *q) {
    return list_empty(q->start);
}


void queue_insert(Queue *q, int data) {
    List* l = list__new_node(data);
    if(queue_empty(q)) {
        q->start = l;
    } else {
        q->end->next = l;
    }

    q->end = l;
}


int queue_remove(Queue *q) {
    if(queue_empty(q)) {
        printf("Exception: trying get element from empty queue!\n");
    }
    int head = list_pop_head(&q->start);

    if(queue_empty(q)) {
        q->end = EMPTY_LIST;
    }

    return head;
}


void queue_print(Queue *q) {
    printf("<QUEUE: ");
    list_print(q->start);
    printf(">");
}


void queue_println(Queue *q) {
    queue_print(q);
    printf("\n");
}


void queue_free(Queue *q) {
    list_free(q->start);
    free(q);
}


void queue_reverse(Queue *q) {
    q->end = q->start;
    list_reverse(&q->start);
}


int queue__list_greater_than(List *l, int n) {
    if (list_empty(l)) {
        return 0;
    } else if (list_head(l) > n) {
        return 1 + queue__list_greater_than(list_tail(l), n);
    } else {
        return 0 + queue__list_greater_than(list_tail(l), n);
    }
}

int queue_greater_than(Queue *q, int n) {
    return queue__list_greater_than(q->start, n);
}


// additional recursive count of odds for list
int queue__list_odds(List* l) {
    if (list_empty(l)) {
        return 0;
    } else if ((list_head(l) & 1) == 0) {
        return 1 + queue__list_odds(list_tail(l));
    } else {
        return 0 + queue__list_odds(list_tail(l));
    }
}


int queue_evens(Queue *q) {
    return queue__list_odds(q->start);
}
