#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdbool.h>
#include <stdlib.h>
#include "../utils/check_alloc.h"

typedef struct Iterator {
    void *container;
    bool (*done)(struct Iterator*);
    void* (*get_next)(struct Iterator*);
} Iterator;

static Iterator* iterator_create(
    void *container,
    bool (*done)(Iterator*),
    void* (*get_next)(Iterator*)
) {
    Iterator* it = malloc(sizeof(Iterator));
    check_alloc(it);
    it->container = container;
    it->done = done;
    it->get_next = get_next;
    return it;
}

static bool iterator_done(Iterator* it) {
    if (it->container != NULL || it->get_next(it)) {
        return false;
    }
    return true;
}

static void* iterator_get_next(Iterator* it) {
    void *next = it->get_next(it);
    it->container = next;
    return next;
}

static void iterator_free(Iterator *it) {
    free(it);
}

#endif
