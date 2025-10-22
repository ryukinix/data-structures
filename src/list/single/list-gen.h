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

/**
 * @brief Creates a new generic list.
 * @return A pointer to the new list.
 * @ingroup DataStructureMethods
 */
ListGen* list_gen_create();

/**
 * @brief Creates a copy of the list.
 * @param l The list.
 * @return A pointer to the new list.
 * @ingroup DataStructureMethods
 */
ListGen* list_gen_copy(ListGen *l);

/**
 * @brief Checks if the list is empty.
 * @param l The list.
 * @return True if the list is empty, false otherwise.
 * @ingroup DataStructureMethods
 */
bool list_gen_empty(ListGen *l);

/**
 * @brief Inserts data into the list.
 * @param l The list.
 * @param data The data.
 * @return A pointer to the new list.
 * @ingroup DataStructureMethods
 */
ListGen* list_gen_insert(ListGen *l, void *data);

/**
 * @brief Inserts data with a key into the list.
 * @param l The list.
 * @param key The key.
 * @param data The data.
 * @return A pointer to the new list.
 * @ingroup DataStructureMethods
 */
ListGen* list_gen_insert_with_key(ListGen *l, int key, void *data);

/**
 * @brief Searches for data in the list.
 * @param l The list.
 * @param data The data.
 * @return A pointer to the list node containing the data, or NULL if not found.
 * @ingroup DataStructureMethods
 */
ListGen* list_gen_search(ListGen *l, void *data);

/**
 * @brief Searches for a key in the list.
 * @param l The list.
 * @param key The key.
 * @return A pointer to the list node containing the key, or NULL if not found.
 * @ingroup DataStructureMethods
 */
ListGen* list_gen_search_by_key(ListGen *l, int key);

/**
 * @brief Removes data from the list.
 * @param l The list.
 * @param data The data.
 * @return A pointer to the new list.
 * @ingroup DataStructureMethods
 */
ListGen* list_gen_remove(ListGen *l, void *data);

/**
 * @brief Removes a key from the list.
 * @param l The list.
 * @param key The key.
 * @return A pointer to the new list.
 * @ingroup DataStructureMethods
 */
ListGen* list_gen_remove_by_key(ListGen *l, int key);

/**
 * @brief Frees the memory allocated for the list.
 * @param l The list.
 * @ingroup DataStructureMethods
 */
void list_gen_free(ListGen *l);

/**
 * @brief Prints the list.
 * @param l The list.
 * @ingroup DataStructureMethods
 */
void list_gen_println(ListGen *l);

/**
 * @brief Concatenates two lists.
 * @param l1 The first list.
 * @param l2 The second list.
 * @return A pointer to the new list.
 * @ingroup DataStructureMethods
 */
ListGen* list_gen_concat(ListGen *l1, ListGen *l2);

/**
 * @brief Prints the list in reverse order.
 * @param l The list.
 * @ingroup DataStructureMethods
 */
void list_gen_println_reverse(ListGen *l);

#endif