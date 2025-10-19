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

#ifndef LIST_CIRCULAR_H
#define LIST_CIRCULAR_H
/**
 * @brief A node in a circular singly linked list.
 *
 * Each node contains an integer data field and a pointer to the next node in
 * the list. In a circular list, the `next` pointer of the last node points
 * back to the first node.
 */
struct ListCircular {
    int data;
    struct ListCircular *next;
};

/**
 * @brief A circular singly linked list.
 *
 * A `ListCircular` is a pointer to the first node in the list. An empty list
 * is represented by a null pointer.
 */
typedef struct ListCircular ListCircular;

#define EMPTY_LIST_CIRCULAR (ListCircular*) 0

/**
 * @brief Creates an empty circular list.
 *
 * @return A null pointer, representing an empty list.
 * @ingroup DataStructureMethods
 */
ListCircular* list_circular_create(void);

/**
 * @brief Checks if a circular list is empty.
 *
 * @param l The list to check.
 * @return 1 if the list is empty, 0 otherwise.
 * @ingroup DataStructureMethods
 */
int list_circular_empty(ListCircular *l);

/**
 * @brief Inserts a new element at the beginning of a circular list.
 *
 * @param l The list to insert into.
 * @param data The data to insert.
 * @return The updated list.
 * @ingroup DataStructureMethods
 */
ListCircular* list_circular_insert(ListCircular *l, int data);

/**
 * @brief Removes an element from a circular list.
 *
 * @param l The list to remove from.
 * @param data The data to remove.
 * @return The updated list.
 * @ingroup DataStructureMethods
 */
ListCircular* list_circular_remove(ListCircular *l, int data);

/**
 * @brief Searches for an element in a circular list.
 *
 * @param l The list to search in.
 * @param data The data to search for.
 * @return A pointer to the node containing the data, or a null pointer if the
 * data is not found.
 * @ingroup DataStructureMethods
 */
ListCircular* list_circular_search(ListCircular *l, int data);

/**
 * @brief Prints the elements of a circular list to the console, followed by a
 * newline character.
 *
 * @param l The list to print.
 * @ingroup DataStructureMethods
 */
void list_circular_print(ListCircular *l);

/**
 * @brief Prints the elements of a circular list to the console, followed by a
 * newline character.
 *
 * @param l The list to print.
 * @ingroup DataStructureMethods
 */
void list_circular_println(ListCircular *l);


/**
 * @brief Frees the memory allocated for a circular list.
 *
 * @param l The list to free.
 * @ingroup DataStructureMethods
 */
void list_circular_free(ListCircular *l);

/*********/
/* UTILS */
/*********/

/**
 * @brief Creates a new node for a circular list.
 *
 * @param data The data to store in the new node.
 * @return A pointer to the new node.
 * @ingroup DataStructureMethods
 */
ListCircular* list_circular__new_node(int data);

#endif
