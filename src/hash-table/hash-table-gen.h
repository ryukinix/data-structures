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

#ifndef HASH_TABLE_GEN_H
#define HASH_TABLE_GEN_H

#include <stddef.h>
#include <stdbool.h>
#include "../list/single/list-gen.h"

typedef struct HashTableGen HashTableGen;

HashTableGen* hash_table_gen_create(size_t n_buckets);
bool hash_table_gen_empty(HashTableGen *ht);
HashTableGen* hash_table_gen_copy(HashTableGen *ht);
void hash_table_gen_put(HashTableGen *ht, int key, void *data);
void hash_table_gen_remove(HashTableGen *ht, int key);
void* hash_table_gen_get(HashTableGen *ht, int key, bool *exists);
size_t hash_table_gen_size(HashTableGen *ht);
void hash_table_gen_print(HashTableGen *ht);
ListGen* hash_table_gen_keys(HashTableGen *ht);
void hash_table_gen_free(HashTableGen *ht, void (*free_data)(void *));

#endif /* HASH_TABLE_GEN_H */
