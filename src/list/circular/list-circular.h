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
 * @brief A List circular data structure.
 * The last *next pointer points to the first.
 */
struct ListCircular {
    int data;
    struct ListCircular *next;
};


/** List circular alias */
typedef struct ListCircular ListCircular;

#define EMPTY_LIST_CIRCULAR (ListCircular*) 0

/** Create a new empty list */
ListCircular* list_circular_create(void);

/** Verify if the list is empty */
int list_circular_empty(ListCircular *l);

/** Insert a new element on the begin of the list */
ListCircular* list_circular_insert(ListCircular *l, int data);

/** Remove a element \p data, if exists, on the list */
ListCircular* list_circular_remove(ListCircular *l, int data);

/** Search for a node which has a \p data field */
ListCircular* list_circular_search(ListCircular *l, int data);

/** Print a circular list (without newline) */
void list_circular_print(ListCircular *l);

/** Print a circular list (with newline) */
void list_circular_println(ListCircular *l);


/** Free the memory allocated by list */
void list_circular_free(ListCircular *l);

/*********/
/* UTILS */
/*********/

ListCircular* list_circular__new_node(int data);

#endif
