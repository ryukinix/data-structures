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

#ifndef LIST_H
#define LIST_H

/**
 * @brief A node in a singly linked list.
 *
 * Each node contains an integer key, an integer data field, and a pointer to
 * the next node in the list.
 */
struct ListNode {
    int key; // optional field, introduced because hash tables
    int data;
    struct ListNode *next;
};

/**
 * @brief A singly linked list.
 *
 * A `List` is a pointer to the first node in the list. An empty list is
 * represented by a null pointer.
 */
typedef struct ListNode List;

#define EMPTY_LIST (List*) 0

                         /******************/
                         /* PUBLIC METHODS */
                         /******************/

/**
 * @brief create a new list instance
 */
List* list_create(void);

/**
 * @brief Insert a new element on the beginning of the list
 * @param l List to insert \p data on
 * @param data integer value to insert on
 * @return the updated list
 */
List* list_insert(List *l, int data);

/**
 * @brief Insert a new element on the beginning of the list
 * @param l List to insert \p data and \p key on
 * @param data integer value to insert on
 * @param key integer value to insert on
 * @return the updated list
 */
List* list_insert_with_key(List *l, int key, int data);

/**
 * @brief Insert a new element on the end of the list
 * @param l List to insert \p data on
 * @param data integer value to insert on
 * @return the updated list
 */
List* list_append(List *l, int data);

/**
 * @brief Insert a new element on the end of the list with key
 * @param l List to insert \p data on with \p key
 * @param data integer value to insert on
 * @param key integer value to insert on
 * @return the updated list
 */
List* list_append_with_key(List *l, int key, int data);

/**
 * @brief Insert a new node on the end of the list
 * @param l List to insert \p data on
 * @param node to insert on
 * @return the updated list
 */
List* list_append_node(List *l, struct ListNode *node);

/**
 * @brief Ordered insert of a new element in the list
 * @param l List to insert \p data on
 * @param data integer value to insert on
 * @return the updated list
 */
List* list_insert_ord(List *l, int data);

/**
 * @brief Search on the list by data and return the node which contains it
 * @param l List to insert \p data on
 * @param data integer value to search on
 * @return the node to return it
 */
List* list_search(List *l, int data);

/**
 * @brief Search on the list by key and return the node which contains it
 * @param l List to search \p key
 * @param key integer value to search
 * @return the node to return it
 */
List* list_search_by_key(List *l, int key);

/**
 * @brief Print the list without a new line
 * @param l the list to print
 */
void list_print(List *l);


/**
 * @brief Print the list with a new line
 * @param l the list to print
 */
void list_println(List *l);

/**
 * @brief Print the list reversed without a new line
 * @param l the list to print
 */
void list_print_reverse(List *l);


/**
 * @brief Print the list reversed with a new line
 * @param l the list to print
 */
void list_println_reverse(List *l);


/**
 * @brief Remove specific element from List
 * @param l List to remove \p data on
 * @param data integer value to remove
 * @return new list without the node which contains \p data
 */
List* list_remove(List *l, int data);

/**
 * @brief Remove specific element from List by a key
 * @param l List to remove with \p key
 * @param key integer value to remove
 * @return new list without the node which contains \p key
 */
List* list_remove_by_key(List *l, int key);

/**
 * @brief Free memory of List and its nodes
 */
void list_free(List *l);

/**
 * @brief Verify if the list is empty
 * @return 1 if empty and 0 if is not
 */
int list_empty(List *l);


/**
 * @brief Check if two lists are equal
 */
int list_equal(List* l_x, List* l_y);


                       /**********************/
                       /* ADDITIONAL METHODS */
                       /**********************/


/**
 * @brief Return the count of perfect numbers on list
 */
int list_perfect(List *l);

/**
 * @brief Return the length of the list
 */
int list_length(List *l);

/**
 * @brief Return the number of numbers less \p n
 */
int list_less_than(List *l, int n);

/**
 * @brief Return the sum of numbers on the list
 */
int list_sum(List *l);

/**
 * @brief Create a copy of the list l
 */
List* list_copy(List *l);

/**
 * @brief Return a concatenation of the two lists as a new list
 */
List* list_concat(List *l_x, List* l_y);


                          /****************/
                          /* UTIL METHODS */
                          /****************/


/**
 * @brief Create a list based on its variadic arguments
 * @param size_list number of paramaters passed to the function
 */
List* list_init(int size_list, ...);

/**
 * @brief Get the data from last element
 */
int list_last(List *l);

/**
 * @brief Get the data from the first element
 */
int list_head(List *l);

/**
 * @brief Get the tail of the list
 */
List* list_tail(List *l);

/**
 * @brief Get and pop the head of the list
 */
int list_pop_head(List** l);

/**
 * @brief Get and pop the last element of the list
 */
int list_pop_last(List** l);

/**
 * @brief Reverse a list (no creating a new)
 * WARNING: side-effects
 */
void list_reverse(List** l);

                        /*******************/
                        /* PRIVATE METHODS */
                        /*******************/

/**
 * @brief Check if a given number is perfect
 */
int list__is_perfect_number(int n);

/**
 * @brief Create a new node for the list
 */
List* list__new_node(int data);

#endif
