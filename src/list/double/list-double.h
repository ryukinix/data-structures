/**
 * ================================================
 *
 *         Copyright 2017-2025 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC
 *
 * ===============================================
 */

#ifndef LIST_DOUBLE_H
#define LIST_DOUBLE_H

/**
 * @brief A node in a doubly linked list.
 *
 * Each node contains an integer data field, a pointer to the next node in the
 * list, and a pointer to the previous node in the list.
 */
struct ListDouble {
    int data;
    struct ListDouble *next;
    struct ListDouble *prev;
};

/**
 * @brief A doubly linked list.
 *
 * A `ListDouble` is a pointer to the first node in the list. An empty list is
 * represented by a null pointer.
 */
typedef struct ListDouble ListDouble;

#define EMPTY_LIST_DOUBLE (ListDouble*) 0


/**
 * @brief Creates an empty doubly linked list.
 *
 * @return A null pointer, representing an empty list.
 */
ListDouble* list_double_create(void);

/**
 * @brief Checks if a doubly linked list is empty.
 *
 * @param l The list to check.
 * @return 1 if the list is empty, 0 otherwise.
 */
int list_double_empty(ListDouble *l);

/**
 * @brief Inserts a new element at the beginning of a doubly linked list.
 *
 * @param l The list to insert into.
 * @param data The data to insert.
 * @return The updated list.
 */
ListDouble* list_double_insert(ListDouble *l, int data);

/**
 * @brief Removes an element from a doubly linked list.
 *
 * @param l The list to remove from.
 * @param data The data to remove.
 * @return The updated list.
 */
ListDouble* list_double_remove(ListDouble *l, int data);

/**
 * @brief Searches for an element in a doubly linked list.
 *
 * @param l The list to search in.
 * @param data The data to search for.
 * @return A pointer to the node containing the data, or a null pointer if the
 * data is not found.
 */
ListDouble* list_double_search(ListDouble *l, int data);

/**
 * @brief Prints the elements of a doubly linked list to the console.
 *
 * @param l The list to print.
 */
void list_double_print(ListDouble *l);

/**
 * @brief Prints the elements of a doubly linked list to the console, followed by a
 * newline character.
 *
 * @param l The list to print.
 */
void list_double_println(ListDouble *l);

/**
 * @brief Frees the memory allocated for a doubly linked list.
 *
 * @param l The list to free.
 */
void list_double_free(ListDouble *l);

/*********/
/* UTILS */
/*********/

/**
 * @brief Creates a new node for a doubly linked list.
 *
 * @param data The data to store in the new node.
 * @return A pointer to the new node.
 */
ListDouble* list_double__new_node(int data);

#endif
