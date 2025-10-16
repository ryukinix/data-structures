/**
 * ============================================================================
 *
 *                      Copyright 2017 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC
 *
 * ============================================================================
 */

#ifndef CHECK_ALLOC_H
#define CHECK_ALLOC_H

#include <stdio.h>
#include <stdlib.h>

// wondering why the `static` here?
// the inline is just to expand as macro instead to define a function
// here is the reason:
// https://stackoverflow.com/questions/9428433/small-functions-defined-in-header-files-inline-or-static
// basically is to avoid multiple definitions problem when this unit is included
// in several sources and later is linked together.
// yes, in this case the include guard is not enough.
// but this is bad?


static inline void check_alloc(void *p) {
    if (p == NULL) {
        puts("Memory allocation error.");
        exit(EXIT_FAILURE);
    }
}


#endif
