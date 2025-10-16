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

#include "list-circular.h"
#include <stdlib.h>
#include <stdio.h>

ListCircular* list_circular__new_node(int data) {
    ListCircular* node = (ListCircular*) malloc(sizeof(ListCircular));
    node->data = data;
    node->next = NULL;
    return node;
}

ListCircular* list_circular_create(void) {
    return EMPTY_LIST_CIRCULAR;
}

int list_circular_empty(ListCircular *l) {
    return l == EMPTY_LIST_CIRCULAR;
}

ListCircular* list_circular_insert(ListCircular *l, int data) {
    ListCircular* node = list_circular__new_node(data);
    if (list_circular_empty(l)) {
        node->next = node;
    } else {
        node->next = l->next;
        l->next = node;
    }

    return node;
}

ListCircular* list_circular_search(ListCircular *l, int data) {
    ListCircular* head = l;
    do {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    } while(l != head);
    return EMPTY_LIST_CIRCULAR;
}

ListCircular* list_circular_remove(ListCircular *l, int data) {
    if(!list_circular_empty(l)) {
        ListCircular **head = &l;
        do {
            if ((*head)->data == data) {
                ListCircular *temp = *head;
                if(*head != (*head)->next) {
                    *head = (*head)->next;
                } else {
                    *head = NULL;
                }
                free(temp);
                break;
            }
            head = &(*head)->next;
        } while(l != *head);
    }
    return l;
}


void list_circular_print(ListCircular *l) {
    printf("[");
    if(!list_circular_empty(l)) {
        ListCircular* head = l;
        do {
            printf("%d, ", head->data);
            head = head->next;
        } while(l != head);
        printf("...");
    }
    printf("]");

}

void list_circular_println(ListCircular *l) {
    list_circular_print(l);
    printf("\n");
}

void list_circular_free(ListCircular *l) {
    if (!list_circular_empty(l)) {
        ListCircular* head = l;
        do  {
            ListCircular* next = head->next;
            free(head);
            head = next;
        } while(head != l);
    }
}
