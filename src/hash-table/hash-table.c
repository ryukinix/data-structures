#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash-table.h"
#include "../utils/check_alloc.h"

struct HashTable {
    size_t size;   // number of pairs key->data inside of hash table
    size_t n_buckets;    // size of buckets
    List **buckets; // hash-indexed buckets to set pairs on int
};

static unsigned int hash_int(int key, size_t n_buckets) {
    if (key < 0) {
        key = -key;
    }
    return (unsigned int)(key % n_buckets);
}

HashTable* hash_table_create(size_t n_buckets) {
    HashTable *ht = malloc(sizeof(HashTable));
    check_alloc(ht);

    ht->n_buckets = n_buckets;
    ht->size = 0;
    ht->buckets = calloc(n_buckets, sizeof(List*));
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

    return ht->size == 0;

}

HashTable* hash_table_copy(HashTable *ht) {
    HashTable *ht_copy = hash_table_create(ht->n_buckets);
    ht_copy->size = ht->size;
    for (size_t i = 0; i < ht_copy->n_buckets; i++) {
        ht_copy->buckets[i] = list_copy(ht->buckets[i]);
    }
    return ht_copy;
}

void hash_table_put(HashTable *ht, int key, int value) {
    unsigned int index = hash_int(key, ht->n_buckets);

    List *found = list_search_by_key(ht->buckets[index], key);

    if (found != NULL) {
        found->data = value;
    } else {
        ht->buckets[index] = list_insert_with_key(ht->buckets[index], key, value);
        ht->size++;
    }
}

void hash_table_remove(HashTable *ht, int key) {
    bool exists;
    hash_table_get(ht, key, &exists);
    if (!exists) {
        return;
    }
    unsigned int index = hash_int(key, ht->n_buckets);
    ht->buckets[index] = list_remove_by_key(ht->buckets[index], key);
    ht->size--;
}

int hash_table_get(HashTable *ht, int key, bool *exists) {
    unsigned int index = hash_int(key, ht->n_buckets);
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
    for (size_t i = 0; i < ht->n_buckets; i++) {
        if (!list_empty(ht->buckets[i])) {
            printf("[%zu]: ", i);
            list_println(ht->buckets[i]);
        }
    }
}

size_t hash_table_size(HashTable *ht) {
    return ht->size;
}

void hash_table_print_items(HashTable *ht) {
    printf("{");
    for (size_t i = 0; i < ht->n_buckets; i++) {
        List *head = ht->buckets[i];
        if (!list_empty(head)) {
            do {
                printf("%d->%d", head->key, head->data);
                head = head->next;
                if (!((ht->n_buckets - 1) == i && !head)) {
                    printf(", ");
                }
            } while (head);
        }
    }
    printf("}\n");
}

List* hash_table_keys(HashTable *ht) {
    List *keys = list_create();
    for (size_t i = 0; i < ht->n_buckets; i++) {
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

List* hash_table_values(HashTable *ht) {
    List *keys = list_create();
    for (size_t i = 0; i < ht->n_buckets; i++) {
        List *head = ht->buckets[i];
        if (!list_empty(head)) {
            do {
                keys = list_insert(keys, head->data);
                head = head->next;
            } while (head);
        }
    }
    return keys;
}


void hash_table_print_keys(HashTable *ht) {
    List *keys = hash_table_keys(ht);
    list_println_reverse(keys);
    list_free(keys);
}


void hash_table_free(HashTable *ht) {
    for (size_t i = 0; i < ht->n_buckets; i++) {
        list_free(ht->buckets[i]);
    }
    free(ht->buckets);
    free(ht);
}

static void hash_table_iterator_free(Iterator *it) {
    list_free(it->begin);
    free(it);
}

Iterator* hash_table_iterator_keys(HashTable *ht) {
    // NOTE: values of list from produced hash_table_keys are produced
    // on field list->data, and not list->keys
    Iterator *it = list_iterator_data(hash_table_keys(ht));
    it->free = &hash_table_iterator_free;
    return it;
}

Iterator* hash_table_iterator_values(HashTable *ht) {
    Iterator *it = list_iterator_data(hash_table_values(ht));
    it->free = &hash_table_iterator_free;
    return it;
}
