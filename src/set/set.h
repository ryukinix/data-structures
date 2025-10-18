/**
 * ================================================
 *
 *         Copyrigset 2025 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: ITA
 *
 * ===============================================
 */

#ifndef SET_H
#define SET_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @brief A basic implementation of a Set.
 *
 * This implementation uses a hash table to store the elements, which allows
 * for efficient insertion, deletion, and membership testing.
 */
typedef struct Set Set;

/**
 * @brief Create a new set instance
 * @return pointer to the newly created set
 */
Set* set_create();

/**
 * @brief Create a new set instance with elements
 * @param set_size number of elements in initialization
 * @return pointer to the newly created set
 */
Set* set_init(int set_size, ...);

/**
 * @brief Create a set as copy of another
 * @param set to copy
 * @return pointer to the newly created set
 */
Set* set_copy(Set *set);

/**
 * @brief Put a value associated to a key
 * @param set pointer
 * @param element integer to add in the set
 */
void set_add(Set *set, int element);

/**
 * @brief Check if set A is a subset of set B
 * @param set_a set A
 * @param set_b set B
   */
bool set_subset(Set *set_a, Set *set_b);

/**
 * @brief Intersection of set A and B
 * @param set_a set A
 * @param set_b set B
   */
Set* set_intersection(Set *set_a, Set *set_b);

/**
 * @brief Union of set A and B
 * @param set_a set A
 * @param set_b set B
   */
Set* set_union(Set *set_a, Set *set_b);

/**
 * @brief Difference of set A and B
 * @param set_a set A
 * @param set_b set B
   */
Set* set_difference(Set *set_a, Set *set_b);

/**
 * @brief Check if set A and B are equals
 * @param set_a set A
 * @param set_b set B
 * @return boolean if set A and B are equals
   */
bool set_equal(Set *set_a, Set *set_b);

/**
 * @brief Remove a element
 * @param set pointer
 * @param element integer used to remove
  */
void set_remove(Set *set, int element);

/**
 * @brief Get a value in the set
 * @param set pointer
 * @param element integer used to check if exists in the set
   */
bool set_contains(Set *set, int element);

/**
 * @brief Print all elements of the set
 * @param set pointer
 */
void set_print(Set *set);

/**
 * @brief Free memory of set and its contents
 * @param set pointer
 */
void set_free(Set *set);

#endif /* SET_H */
