#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include "../hash-table/hash-table.h"
#include "../utils/check_alloc.h"
#include "set.h"

#define SET_DEFAULT_HASH_MAP_SIZE 128
#define SET_DEFAULT_HASH_MAP_VALUE 1

struct Set {
    HashTable *memory;
};


Set* set_create() {
    Set *set = malloc(sizeof(Set));
    check_alloc(set);
    set->memory = hash_table_create(SET_DEFAULT_HASH_MAP_SIZE);
    return set;
}

Set* set_copy(Set *set) {
    Set *set_new = set_create();
    hash_table_free(set_new->memory);
    set_new->memory = hash_table_copy(set->memory);
    return set_new;
}


void set_add(Set *set, int element) {
    hash_table_put(set->memory, element, SET_DEFAULT_HASH_MAP_VALUE);
}


Set* set_init(int set_size,...) {
    Set *s = set_create();
    va_list args;

    va_start(args, set_size);
    for(int i = 0; i < set_size; i++) {
        set_add(s, va_arg(args, int));
    }

    va_end(args);
    return s;
}

bool set_subset(Set *set_a, Set *set_b) {
    List* keys_begin = hash_table_keys(set_a->memory);
    List* keys = keys_begin;
    bool checking = true;
    while (!list_empty(keys)) {
        bool exists;
        int element = keys->data;
        hash_table_get(set_b->memory, element, &exists);
        if (!exists) {
            checking = false;
            break;
        }
        keys = keys->next;
    }
    list_free(keys_begin);
    return checking;
}


bool set_equal(Set *set_a, Set *set_b) {
    if (hash_table_size(set_a->memory) != hash_table_size(set_b->memory)) {
        return false;
    }
    return set_subset(set_a, set_b);
}


Set* set_intersection(Set *set_a, Set *set_b) {
    Set* set_new = set_create();
    List* keys_begin = hash_table_keys(set_a->memory);
    List* keys = keys_begin;
    while (!list_empty(keys)) {
        bool exists;
        int element = keys->data;
        hash_table_get(set_b->memory, element, &exists);
        if (exists) {
            set_add(set_new, element);
        }
        keys = keys->next;
    }
    list_free(keys_begin);
    return set_new;
}


Set* set_union(Set *set_a, Set *set_b) {
    List* keys_a = hash_table_keys(set_a->memory);
    List* keys_b = hash_table_keys(set_b->memory);
    List* keys_begin = list_concat(keys_a, keys_b);
    List* keys = keys_begin;
    Set* set_new = set_create();
    while (!list_empty(keys)) {
        set_add(set_new, keys->data);
        keys = keys->next;
    }
    list_free(keys_a);
    list_free(keys_b);
    list_free(keys_begin);
    return set_new;
}


Set* set_difference(Set *set_a, Set *set_b) {
    Set* set_new = set_create();
    List* keys_begin = hash_table_keys(set_a->memory);
    List* keys = keys_begin;
    while (!list_empty(keys)) {
        bool exists;
        int element = keys->data;
        hash_table_get(set_b->memory, element, &exists);
        keys = keys->next;
        if (exists) {
            continue;
        }
        set_add(set_new, element);
    }
    list_free(keys_begin);
    return set_new;
}


void set_remove(Set *set, int element) {
    hash_table_remove(set->memory, element);
}


bool set_contains(Set *set, int element) {
    bool exists;
    hash_table_get(set->memory, element, &exists);
    return exists;
}


void set_print(Set *set) {
    hash_table_print_keys(set->memory);
}


void set_free(Set *set) {
    hash_table_free(set->memory);
    free(set);
}
