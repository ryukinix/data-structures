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

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stddef.h>
#include <stdbool.h>
#include "../list/single/list.h"

/** Public type definition for HashTable */
typedef struct HashTable HashTable;

/**
 * @brief Create a new hash table instance
 * @param size number of buckets in the hash table
 * @return pointer to the newly created hash table
 */
HashTable* hash_table_create(size_t size);

/**
 * @brief Put a value associated to a key
 * @param ht hash table pointer
 * @param key integer key used to determine the bucket
 * @param value integer value to store
 */
void hash_table_put(HashTable *ht, int key, int value);

/**
 * @brief Remove a specific value associated with a given key
 * @param ht hash table pointer
 * @param key integer key used to locate the bucket
  */
void hash_table_remove(HashTable *ht, int key);

/**
 * @brief Get a value in the hash table
 * @param ht hash table pointer
 * @param key integer key used to locate the bucket
 * @param pointer of the value integer key used to locate the bucket; null if not found
  */
int hash_table_get(HashTable *ht, int key, bool *ok);

/**
 * @brief Print all buckets of the hash table (one list per line)
 * @param ht hash table pointer
 */
void hash_table_print(HashTable *ht);

/**
 * @brief Print items of the hash table
 * @param ht hash table pointer
 */
void hash_table_print_items(HashTable *ht);

/**
 * @brief Print keys of the hash table
 * @param ht hash table pointer
 */
void hash_table_print_keys(HashTable *ht);

/**
 * @brief Free memory of hash table and its contents
 * @param ht hash table pointer
 */
void hash_table_free(HashTable *ht);

#endif /* HASH_TABLE_H */
