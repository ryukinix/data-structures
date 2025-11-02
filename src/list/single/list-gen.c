#include <stdio.h>
#include <stdlib.h>
#include "list-gen.h"

ListGen* list_gen_create() {
    return NULL;
}

bool list_gen_empty(ListGen *l) {
    return l == NULL;
}

ListGen* list_gen_insert(ListGen *l, void *data) {
    ListGen *newNode = (ListGen*) malloc(sizeof(ListGen));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = data;
    newNode->next = l;
    return newNode;
}

ListGen* list_gen_insert_with_key(ListGen *l, int key, void *data) {
    ListGen *newNode = (ListGen*) malloc(sizeof(ListGen));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->key = key;
    newNode->data = data;
    newNode->next = l;
    return newNode;
}

ListGen* list_gen_remove(ListGen *l, void *data) {
    ListGen *current = l;
    ListGen *prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return l;
    }

    if (prev == NULL) {
        l = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    return l;
}

ListGen* list_gen_remove_by_key(ListGen *l, int key) {
    ListGen *current = l;
    ListGen *prev = NULL;
    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return l;
    }

    if (prev == NULL) {
        l = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    return l;
}


ListGen* list_gen_search(ListGen *l, void *data) {
    ListGen *current = l;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

ListGen* list_gen_search_by_key(ListGen *l, int key) {
    ListGen *current = l;
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


void list_gen_free(ListGen *l) {
    ListGen *current = l;
    while (current != NULL) {
        ListGen *next = current->next;
        free(current);
        current = next;
    }
}

ListGen* list_gen_copy(ListGen *l) {
    if (l == NULL) {
        return NULL;
    }

    ListGen *new_list = list_gen_create();
    ListGen *current = l;
    ListGen *new_current = NULL;

    while(current != NULL) {
        ListGen *new_node = (ListGen*) malloc(sizeof(ListGen));
        if (new_node == NULL) {
            exit(1);
        }
        new_node->key = current->key;
        new_node->data = current->data;
        new_node->next = NULL;

        if (new_list == NULL) {
            new_list = new_node;
            new_current = new_list;
        } else {
            new_current->next = new_node;
            new_current = new_node;
        }

        current = current->next;
    }

    return new_list;
}

ListGen* list_gen_concat(ListGen *l1, ListGen *l2) {
    if (l1 == NULL) {
        return l2;
    }

    ListGen *current = l1;
    while(current->next != NULL) {
        current = current->next;
    }

    current->next = l2;
    return l1;
}
