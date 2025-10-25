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
#include "../list/single/list.h"
#include "../iterator/iterator.h"

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
 * @ingroup DataStructureMethods
 */
Set* set_create();

/**
 * @brief Create a new set instance with elements
 * @param set_size number of elements in initialization
 * @return pointer to the newly created set
 * @ingroup DataStructureMethods
 */
Set* set_init(int set_size, ...);

/**
 * @brief Create a set as copy of another
 * @param set to copy
 * @return pointer to the newly created set
 * @ingroup DataStructureMethods
 */
Set* set_copy(Set *set);

/**
 * @brief Put a value associated to a key
 * @param set pointer
 * @param element integer to add in the set
 * @ingroup DataStructureMethods
 */
void set_add(Set *set, int element);

/**
 * @brief Add an element to the set with a custom value.
 * @param set pointer
 * @param element integer to add in the set
 * @param value integer value associated with the element
 * @ingroup DataStructureMethods
 */
void set_add_with_value(Set *set, int element, int value);

/**
 * @brief Get the value of an element in the set.
 * @param set pointer
 * @param element integer to get the value from
 * @return the value of the element, or 0 if the element is not in the set
 * @ingroup DataStructureMethods
 */
int set_get_value(Set *set, int element);

/**
 * @brief Check if set A is a subset of set B
 * @param set_a set A
 * @param set_b set B
 * @ingroup DataStructureMethods
   */
bool set_subset(Set *set_a, Set *set_b);

/**
 * @brief Intersection of set A and B
 * @param set_a set A
 * @param set_b set B
 * @ingroup DataStructureMethods
   */
Set* set_intersection(Set *set_a, Set *set_b);

/**
 * @brief Union of set A and B
 * @param set_a set A
 * @param set_b set B
 * @ingroup DataStructureMethods
   */
Set* set_union(Set *set_a, Set *set_b);

/**
 * @brief Difference of set A and B
 * @param set_a set A
 * @param set_b set B
 * @ingroup DataStructureMethods
   */
Set* set_difference(Set *set_a, Set *set_b);

/**
 * @brief Check if set A and B are equals
 * @param set_a set A
 * @param set_b set B
 * @return boolean if set A and B are equals
 * @ingroup DataStructureMethods
   */
bool set_equal(Set *set_a, Set *set_b);

/**
 * @brief Remove a element
 * @param set pointer
 * @param element integer used to remove
 * @ingroup DataStructureMethods
  */
void set_remove(Set *set, int element);

/**
 * @brief Get a value in the set
 * @param set pointer
 * @param element integer used to check if exists in the set
 * @ingroup DataStructureMethods
   */
bool set_contains(Set *set, int element);

/**
 * @brief Print all elements of the set
 * @param set pointer
 * @ingroup DataStructureMethods
 */
void set_print(Set *set);

/**
 * @brief Free memory of set and its contents
 * @param set pointer
 * @ingroup DataStructureMethods
 */
void set_free(Set *set);

/**
 * @brief Creates an iterator for the set.
 *
 * @param s The set to iterate over.
 * @return A pointer to the new iterator.
 */
Iterator* set_iterator(Set *s);


/**
 * @brief Creates a set from an iterator.
 *
 * @param s The iterator to create the set from.
 * @return A pointer to the new set.
 */
Set* set_from_iterator(Iterator *s);

#endif /* SET_H */
