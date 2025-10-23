#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdbool.h>
#include <stdlib.h>
#include "../utils/check_alloc.h"

typedef struct Iterator {
    void  *container;
    void* (*get)(struct Iterator*);  /* get current inner container data pointer */
    void* (*next)(struct Iterator*); /* get current data and move container pointer to next */
} Iterator;

static inline Iterator* iterator_create(
    void  *container,
    void* (*get)(Iterator*),
    void* (*next)(Iterator*)
) {
    Iterator* it = malloc(sizeof(Iterator));
    check_alloc(it);
    it->container = container;
    it->get = get;
    it->next = next;
    return it;
}

static inline bool iterator_done(Iterator* it) {
    if (it->container == NULL) {
        return true;
    }
    return false;
}

static inline void* iterator_next(Iterator* it) {
    void *current = it->get(it);
    void *next = it->next(it);
    it->container = next;
    return current;
}

static inline void iterator_free(Iterator *it) {
    free(it);
}

#endif
