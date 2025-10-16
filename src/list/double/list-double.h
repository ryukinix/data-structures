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
 * @brief Linked List with double pointers.
 */
struct ListDouble {
    int data;
    struct ListDouble *next;
    struct ListDouble *prev;
};

typedef struct ListDouble ListDouble;

#define EMPTY_LIST_DOUBLE (ListDouble*) 0


/** Create a new empty list */
ListDouble* list_double_create(void);

/** Verify if the list is empty */
int list_double_empty(ListDouble *l);

/** Insert a new element on the begin of the list */
ListDouble* list_double_insert(ListDouble *l, int data);

/** Remove a element \p data, if exists, on the list */
ListDouble* list_double_remove(ListDouble *l, int data);

/** Return a given node which have the \p data field */
ListDouble* list_double_search(ListDouble *l, int data);

/** Print a double list (without newline) */
void list_double_print(ListDouble *l);

/** Print a double list (with newline) */
void list_double_println(ListDouble *l);

/** Free the memory allocated by list */
void list_double_free(ListDouble *l);

/*********/
/* UTILS */
/*********/

ListDouble* list_double__new_node(int data);

#endif
