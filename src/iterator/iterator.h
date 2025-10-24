#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdbool.h>
#include <stdlib.h>
#include "../utils/check_alloc.h"

/**
 * @brief A generic iterator struct.
 *
 * This struct provides a generic interface for iterating over a container.
 */
typedef struct Iterator {
    void  *container;
    void  *begin;
    void* (*next)(struct Iterator*); /**< get current data and move container pointer to next */
    void  (*free)(struct Iterator*);  /**< (optional) free object  */
    bool  (*done)(struct Iterator*); /**< (optional) check logic if iterator is done */
} Iterator;

/**
 * @brief Creates a new iterator.
 *
 * @param container The container to iterate over.
 * @param next A function pointer to move to the next element and get the data.
 * @param free A function pointer to free the iterator.
 * @param done A function pointer to check if the iteration is done.
 * @return A pointer to the new iterator.
 */
static inline Iterator* iterator_create(
    void  *container,
    void* (*next)(Iterator*),
    void  (*free)(Iterator*),
    bool  (*done)(Iterator*)
) {
    Iterator* it = malloc(sizeof(Iterator));
    check_alloc(it);
    it->container = container;
    it->begin = container;
    it->next = next;
    it->free = free;
    it->done = done;
    return it;
}

/**
 * @brief Checks if the iteration is done.
 *
 * @param it The iterator.
 * @return True if the iteration is done, false otherwise.
 */
static inline bool iterator_done(Iterator* it) {
    if (it->done != NULL) {
        return it->done(it);
    }
    return it->container == NULL;
}

/**
 * @brief Gets the next element in the container.
 *
 * @param it The iterator.
 * @return A pointer to the next element.
 */
static inline void* iterator_next(Iterator* it) {
    return it->next(it);
}

/**
 * @brief Frees the iterator.
 *
 * @param it The iterator.
 */
static inline void iterator_free(Iterator *it) {
    if (it->free != NULL) {
        it->free(it);
    } else {
        free(it);
    }
}

#endif
