#ifndef SET_DISJOINT_H
#define SET_DISJOINT_H

/**
 * @brief A disjoint-set data structure.
 * @see https://en.wikipedia.org/wiki/Disjoint-set_data_structure
 */
typedef struct DisjointSet DisjointSet;

/**
 * @brief Creates a new disjoint-set data structure with n elements.
 *
 * @param[in] n The number of elements.
 * @return A pointer to the new disjoint-set.
 */
DisjointSet *set_disjoint_create(int n);

/**
 * @brief Free a disjoint-set data structure.
 *
 * @param[in,out] ds A pointer to a pointer to the disjoint-set.
 */
void set_disjoint_free(DisjointSet *ds);

/**
 * @brief Finds the representative of the set containing element i.
 *
 * @param[in] ds The disjoint-set.
 * @param[in] i The element to find.
 * @return The representative of the set containing i.
 */
int set_disjoint_find(DisjointSet *ds, int i);

/**
 * @brief Merges the sets containing elements i and j.
 *
 * @param[in,out] ds The disjoint-set.
 * @param[in] i The first element.
 * @param[in] j The second element.
 */
void set_disjoint_union(DisjointSet *ds, int i, int j);

#endif /* SET_DISJOINT_H */
