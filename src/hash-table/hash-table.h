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

/**
 * @brief A basic implementation of a hash table.
 *
 * This implementation uses a separate chaining strategy to handle collisions.
 * The hash table is composed of an array of buckets, where each bucket is a
 * linked list of key-value pairs.
 */
typedef struct HashTable HashTable;

/**
 * @brief Create a new hash table instance
 * @param n_buckets number of buckets in the hash table
 * @return pointer to the newly created hash table
 */
HashTable* hash_table_create(size_t n_buckets);

/**
 * @brief Check if hash table is empty
 * @param ht hash table pointer
 * @return true if empty, false otherwise
 */
bool hash_table_empty(HashTable *ht);

/**
 * @brief Create a hash table as copy of another
 * @param ht hash table to copy
 * @return pointer to the newly created hash table
 */
HashTable* hash_table_copy(HashTable *ht);

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
 * @param exists bool pointer, set true if found false otherwise; null pointer does nothing
  */
int hash_table_get(HashTable *ht, int key, bool *exists);


/**
 * @brief Get the number of elements in the hash table
 * @param ht hash table pointer
 * @return the number of elements inside of the hash table
 */
size_t hash_table_size(HashTable *ht);


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
 * @brief Build a list with the hash table keys
 * @param ht hash table pointer
 */
List* hash_table_keys(HashTable *ht);

/**
 * @brief Free memory of hash table and its contents
 * @param ht hash table pointer
 */
void hash_table_free(HashTable *ht);

#endif /* HASH_TABLE_H */
