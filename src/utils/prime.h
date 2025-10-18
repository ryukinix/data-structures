#ifndef PRIME_H
#define PRIME_H

#include <stdbool.h>
#include <math.h>

/**
 * @brief Checks if a given integer is a prime number.
 *
 * This function implements a basic primality test. It handles special cases
 * for 0, 1, and 2, and then iterates through odd numbers up to the square root
 * of the input to check for divisibility.
 *
 * @param n The integer to check for primality.
 * @return `true` if `n` is prime, `false` otherwise.
 */
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

/**
 * @brief Finds the next prime number greater than a given integer.
 *
 * This function iteratively checks integers starting from `q + 1` until it
 * finds the first prime number using the `is_prime` function.
 *
 * @param q The integer to start searching from (exclusive).
 * @return The smallest prime number greater than `q`.
 */
static inline int next_prime(int q) {
    int i = q + 1;
    while (!is_prime(i)) i++;
    return i;
}

#endif
