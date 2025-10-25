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
#include "../list/single/list.h"

typedef struct HashTableGen HashTableGen;

/**
 * @brief Creates a new generic hash table.
 * @param n_buckets The number of buckets.
 * @return A pointer to the new hash table.
 * @ingroup DataStructureMethods
 */
HashTableGen* hash_table_gen_create(size_t n_buckets);

/**
 * @brief Checks if the hash table is empty.
 * @param ht The hash table.
 * @return True if the hash table is empty, false otherwise.
 * @ingroup DataStructureMethods
 */
bool hash_table_gen_empty(HashTableGen *ht);

/**
 * @brief Creates a copy of the hash table.
 * @param ht The hash table.
 * @return A pointer to the new hash table.
 * @ingroup DataStructureMethods
 */
HashTableGen* hash_table_gen_copy(HashTableGen *ht);

/**
 * @brief Inserts a key-value pair into the hash table.
 * @param ht The hash table.
 * @param key The key.
 * @param data The data.
 * @ingroup DataStructureMethods
 */
void hash_table_gen_put(HashTableGen *ht, int key, void *data);

/**
 * @brief Removes a key-value pair from the hash table.
 * @param ht The hash table.
 * @param key The key.
 * @ingroup DataStructureMethods
 */
void hash_table_gen_remove(HashTableGen *ht, int key);

/**
 * @brief Gets the value associated with a key.
 * @param ht The hash table.
 * @param key The key.
 * @param exists A pointer to a boolean that will be set to true if the key exists, false otherwise.
 * @return The value associated with the key.
 * @ingroup DataStructureMethods
 */
void* hash_table_gen_get(HashTableGen *ht, int key, bool *exists);

/**
 * @brief Gets the size of the hash table.
 * @param ht The hash table.
 * @return The size of the hash table.
 * @ingroup DataStructureMethods
 */
size_t hash_table_gen_size(HashTableGen *ht);

/**
 * @brief Prints the hash table.
 * @param ht The hash table.
 * @ingroup DataStructureMethods
 */
void hash_table_gen_print(HashTableGen *ht);

/**
 * @brief Gets the keys of the hash table.
 * @param ht The hash table.
 * @return A list of the keys.
 * @ingroup DataStructureMethods
 */
List* hash_table_gen_keys(HashTableGen *ht);

/**
 * @brief Frees the memory allocated for the hash table.
 * @param ht The hash table.
 * @param free_data A function to free the data.
 * @ingroup DataStructureMethods
 */
void hash_table_gen_free(HashTableGen *ht, void (*free_data)(void *));

#endif /* HASH_TABLE_GEN_H */
