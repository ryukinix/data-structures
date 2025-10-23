#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdbool.h>
#include <stdlib.h>
#include "../utils/check_alloc.h"

typedef struct Iterator {
    void  *container;
    void  *begin;
    void* (*get)(struct Iterator*);  /* get current inner container data pointer */
    void* (*next)(struct Iterator*); /* get current data and move container pointer to next */
    void  (*free)(struct Iterator*);           /* (optional) free object  */
    bool  (*done)(struct Iterator*); /* (optional) check logic if iterator is done */
} Iterator;

static inline Iterator* iterator_create(
    void  *container,
    void* (*get)(Iterator*),
    void* (*next)(Iterator*),
    void  (*free)(Iterator*),
    bool  (*done)(Iterator*)
) {
    Iterator* it = malloc(sizeof(Iterator));
    check_alloc(it);
    it->container = container;
    it->begin = container;
    it->get = get;
    it->next = next;
    it->free = free;
    it->done = done;
    return it;
}

static inline bool iterator_done(Iterator* it) {
    if (it->container == NULL) {
        return true;
    }
    return it->done != NULL && it->done(it);
}

static inline void* iterator_next(Iterator* it) {
    // if have a get function
    if (it->get != NULL) {
        void *current = it->get(it);
        void *next = it->next(it);
        it->container = next;
        return current;
    } else {
        // only calculate next and return directly
        return it->next(it);
    }

}

static inline void iterator_free(Iterator *it) {
    if (it->free != NULL) {
        it->free(it);
    } else {
        free(it);
    }
}

#endif
