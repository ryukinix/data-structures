#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash-table.h"

struct HashTable {
    size_t size;    // size of buckets
    size_t items;   // number of pairs key->data inside of hash table
    List **buckets; // hash-indexed buckets to set pairs on int
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
    ht->items = 0;
    ht->buckets = calloc(size, sizeof(List*));
    if (!ht->buckets) {
        free(ht);
        return NULL;
    }
    return ht;
}

bool hash_table_empty(HashTable *ht) {
    if (!ht) {
        return true;
    }

    return ht->items == 0;

}

HashTable* hash_table_copy(HashTable *ht) {
    HashTable *ht_copy = hash_table_create(ht->size);
    ht_copy->items = ht->items;
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
        ht->items++;
    }
}

void hash_table_remove(HashTable *ht, int key) {
    bool exists;
    hash_table_get(ht, key, &exists);
    if (!exists) {
        return;
    }
    unsigned int index = hash_int(key, ht->size);
    ht->buckets[index] = list_remove_by_key(ht->buckets[index], key);
    ht->items--;
}

int hash_table_get(HashTable *ht, int key, bool *exists) {
    unsigned int index = hash_int(key, ht->size);
    List *l = ht->buckets[index];
    while (l) {
        if (l->key == key) {
            if (exists != NULL) {
                *exists = true;
            }
            return l->data;
        }
        l = l->next;
    }
    if (exists != NULL) {
        *exists = false;
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

size_t hash_table_items(HashTable *ht) {
    return ht->items;
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

List* hash_table_keys(HashTable *ht) {
    List *keys = list_create();
    for (size_t i = 0; i < ht->size; i++) {
        List *head = ht->buckets[i];
        if (!list_empty(head)) {
            do {
                keys = list_insert(keys, head->key);
                head = head->next;
            } while (head);
        }
    }
    return keys;
}


void hash_table_print_keys(HashTable *ht) {
    List *keys = hash_table_keys(ht);
    list_println_reverse(keys);
}


void hash_table_free(HashTable *ht) {
    for (size_t i = 0; i < ht->size; i++) {
        list_free(ht->buckets[i]);
    }
    free(ht->buckets);
    free(ht);
}
