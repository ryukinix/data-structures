#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash-table-gen.h"

struct HashTableGen {
    size_t size;
    size_t n_buckets;
    ListGen **buckets;
};

static unsigned int hash_int(int key, size_t n_buckets) {
    if (key < 0) {
        key = -key;
    }
    return (unsigned int)(key % n_buckets);
}

HashTableGen* hash_table_gen_create(size_t n_buckets) {
    HashTableGen *ht = (HashTableGen*) malloc(sizeof(HashTableGen));
    if (!ht) return NULL;

    ht->n_buckets = n_buckets;
    ht->size = 0;
    ht->buckets = (ListGen**) calloc(n_buckets, sizeof(ListGen*));
    if (!ht->buckets) {
        free(ht);
        return NULL;
    }
    return ht;
}

bool hash_table_gen_empty(HashTableGen *ht) {
    if (!ht) {
        return true;
    }

    return ht->size == 0;

}

void hash_table_gen_put(HashTableGen *ht, int key, void *data) {
    unsigned int index = hash_int(key, ht->n_buckets);

    ListGen *found = list_gen_search_by_key(ht->buckets[index], key);

    if (found != NULL) {
        found->data = data;
    } else {
        ht->buckets[index] = list_gen_insert_with_key(ht->buckets[index], key, data);
        ht->size++;
    }
}

void hash_table_gen_remove(HashTableGen *ht, int key) {
    bool exists;
    hash_table_gen_get(ht, key, &exists);
    if (!exists) {
        return;
    }
    unsigned int index = hash_int(key, ht->n_buckets);
    ht->buckets[index] = list_gen_remove_by_key(ht->buckets[index], key);
    ht->size--;
}

void* hash_table_gen_get(HashTableGen *ht, int key, bool *exists) {
    unsigned int index = hash_int(key, ht->n_buckets);
    ListGen *l = ht->buckets[index];
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
    return NULL;
}

size_t hash_table_gen_size(HashTableGen *ht) {
    return ht->size;
}

List* hash_table_gen_keys(HashTableGen *ht) {
    List *keys = list_create();
    for (size_t i = 0; i < ht->n_buckets; i++) {
        ListGen *head = ht->buckets[i];
        if (!list_gen_empty(head)) {
            do {
                keys = list_insert(keys, head->key);
                head = head->next;
            } while (head);
        }
    }
    return keys;
}


void hash_table_gen_free(HashTableGen *ht, void (*free_data)(void *)) {
    for (size_t i = 0; i < ht->n_buckets; i++) {
        if(free_data) {
            ListGen *l = ht->buckets[i];
            while(l) {
                free_data(l->data);
                l = l->next;
            }
        }
        list_gen_free(ht->buckets[i]);
    }
    free(ht->buckets);
    free(ht);
}
