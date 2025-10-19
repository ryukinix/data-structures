/**
 * ================================================
 *
 *         Copyright 2025 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: ITA
 *
 * ===============================================
 */

#ifndef LIST_GEN_H
#define LIST_GEN_H
#include <stdbool.h>
#include <stddef.h>

typedef struct ListGen ListGen;

struct ListGen {
    int key;
    void *data;
    ListGen *next;
};

ListGen* list_gen_create();
ListGen* list_gen_copy(ListGen *l);
bool list_gen_empty(ListGen *l);
ListGen* list_gen_insert(ListGen *l, void *data);
ListGen* list_gen_insert_with_key(ListGen *l, int key, void *data);
ListGen* list_gen_search(ListGen *l, void *data);
ListGen* list_gen_search_by_key(ListGen *l, int key);
ListGen* list_gen_remove(ListGen *l, void *data);
ListGen* list_gen_remove_by_key(ListGen *l, int key);
void list_gen_free(ListGen *l);
void list_gen_println(ListGen *l);
ListGen* list_gen_concat(ListGen *l1, ListGen *l2);
void list_gen_println_reverse(ListGen *l);

#endif