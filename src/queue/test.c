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

#include <stdio.h>
#include "queue.h"
#include "../console/console.h"

int main(void) {
    Queue* q = queue_create();
    queue_insert(q, 1);
    queue_insert(q, 2);
    queue_insert(q, 3);
    queue_insert(q, 4);
    queue_insert(q, 5);
    printf("Queue: ");
    queue_println(q);
    printf("Reversed: ");
    queue_reverse(q);
    queue_println(q);
    printf("Removed: %d\n", queue_remove(q));
    printf("Updated: ");
    queue_println(q);
    printf("Elements on queue greater than 2: %d\n", queue_greater_than(q, 2));
    printf("Even elements on queue: %d\n", queue_evens(q));
    queue_free(q);

#ifdef _WIN32
    pause();
#endif
    return 0;
}
