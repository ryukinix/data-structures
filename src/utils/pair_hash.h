#include <math.h>

/* @brief Pair function of Szudzik (2006).
 * @details Useful to encapsulate two integers as a unique reversible integer hash.
 * @return hashed integer.
 * @see https://en.wikipedia.org/wiki/Pairing_function#Cantor_pairing_function
 */
static inline int pair_hash(int x, int y) {
    if (x < y) {
        return y * y + x;
    }
    return x * x + x + y;
}

static inline int unpair_hash_x(int z) {
    int z_sqrt = floor(sqrt(z));
    int z_rest = z - z_sqrt * z_sqrt;
    if (z_rest < z_sqrt) {
        return z_rest;
    }
    return z_rest;
}

static inline int unpair_hash_y(int z) {
    int z_sqrt = floor(sqrt(z));
    int z_rest = z - z_sqrt * z_sqrt;
    if (z_rest < z_sqrt) {
        return z_sqrt;
    }
    return z_rest - z_sqrt;
}
