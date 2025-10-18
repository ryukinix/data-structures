#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash-table.h"

struct HashTable {
    size_t size;
    List **buckets;
};

static unsigned int hash_int(int key, size_t size) {
    if (key < 0) {
        key = -key;
    }
    return (unsigned int)(key % size);
}

HashTable* hash_table_create(size_t size) {
    HashTable *ht = malloc(sizeof(HashTable));
    if (!ht) return NULL;

    ht->size = size;
    ht->buckets = calloc(size, sizeof(List*));
    if (!ht->buckets) {
        free(ht);
        return NULL;
    }
    return ht;
}

HashTable* hash_table_copy(HashTable *ht) {
    HashTable *ht_copy = hash_table_create(ht->size);

    for (size_t i = 0; i < ht_copy->size; i++) {
        ht_copy->buckets[i] = list_copy(ht->buckets[i]);
    }
    return ht_copy;
}

void hash_table_put(HashTable *ht, int key, int value) {
    unsigned int index = hash_int(key, ht->size);

    List *found = list_search_by_key(ht->buckets[index], key);

    if (found != NULL) {
        found->data = value;
    } else {
        ht->buckets[index] = list_insert_with_key(ht->buckets[index], key, value);
    }
}

void hash_table_remove(HashTable *ht, int key) {
    unsigned int index = hash_int(key, ht->size);
    ht->buckets[index] = list_remove_by_key(ht->buckets[index], key);
}

int hash_table_get(HashTable *ht, int key, bool *ok) {
    unsigned int index = hash_int(key, ht->size);
    List *l = ht->buckets[index];
    while (l) {
        if (l->key == key) {
            if (ok != NULL) {
                *ok = true;
            }
            return l->data;
        }
        l = l->next;
    }
    if (ok != NULL) {
        *ok = false;
    }
    return -1;
}

void hash_table_print(HashTable *ht) {
    for (size_t i = 0; i < ht->size; i++) {
        if (!list_empty(ht->buckets[i])) {
            printf("[%zu]: ", i);
            list_println(ht->buckets[i]);
        }
    }
}

void hash_table_print_items(HashTable *ht) {
    printf("{");
    for (size_t i = 0; i < ht->size; i++) {
        List *head = ht->buckets[i];
        if (!list_empty(head)) {
            do {
                printf("%d->%d", head->key, head->data);
                head = head->next;
                if (!((ht->size - 1) == i && !head)) {
                    printf(", ");
                }
            } while (head);
        }
    }
    printf("}\n");
}

void hash_table_print_keys(HashTable *ht) {
    printf("{");
    for (size_t i = 0; i < ht->size; i++) {
        List *head = ht->buckets[i];
        if (!list_empty(head)) {
            do {
                printf("%d", head->key);
                head = head->next;
                if (!((ht->size - 1) == i && !head)) {
                    printf(", ");
                }
            } while (head);
        }
    }
    printf("}\n");
}

void hash_table_free(HashTable *ht) {
    for (size_t i = 0; i < ht->size; i++) {
        list_free(ht->buckets[i]);
    }
    free(ht->buckets);
    free(ht);
}
