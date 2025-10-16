#ifndef PRIME_H
#define PRIME_H

#include <stdbool.h>
#include <math.h>

// Worst: O(sqrt(n))
static inline int is_prime(int n) {
    if (n == 2) {
        return true;
    } else if (n <= 1 || n % 2 == 0) {
        return false;
    }

    for (int k = 3; k <= floor(sqrt(n)); k += 2) {
        if (n % k == 0) {
            return false;
        }
    }

    return true;
}

static inline int next_prime(int q) {
    int i = q + 1;
    while (!is_prime(i)) i++;
    return i;
}

#endif
