/**
 * ================================================
 *
 *         Copyright 2025 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: ITA
 *
 * ===============================================
 */

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#include "search.h"

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define ALPHABET 128

int search_naive(char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}

void kmp_init_failure_function(int *f, int m, const char *pattern) {
    f[0] = 0;
    int i = 1, j = 0;
    while (i < m) {
        if (pattern[i] == pattern[j]) {
            f[i++] = ++j;
        } else if (j == 0) {
            f[i++] = 0;
        } else {
            j = f[j - 1];
        }
    }
}

int search_kmp(char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int f[m];
    kmp_init_failure_function(f, m, pattern);

    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            if (j == (m - 1)) {
                return i - j;
            } else {
                i++;
                j++;
            }
        } else {
            if (j != 0) {
                j = f[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1;
}

void bm_init_l(int *l, int m, const char* pattern) {
    for (int k = 0; k < ALPHABET; k++) {
        l[k] = -1;
    }
    for (int i = 0; i < m; i++) {
        l[(int)pattern[i]] = i;
    }

}

int search_bm(char *text, const char *pattern) {
    int l[ALPHABET];
    int n = strlen(text);
    int m = strlen(pattern);

    bm_init_l(l, m, pattern);
    int i = m - 1;
    int j = m - 1;
    do {
        if (text[i] == pattern[j]) {
            if (j == 0) {
                return i;
            } else {
                i--;
                j--;
            }
        } else {
            int x = l[(int)text[i]];
            i += m - min(j, 1 + x);
            j = m - 1;
        }

    } while (i < n);

    return -1;

}

int is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int q = 2; q < sqrt(n) + 1; q++) {
        if (n % q == 0) {
            return false;
        }
    }

    return true;
}

int next_prime(int q) {
    int i = q + 1;
    while (!is_prime(i)) i++;
    return i;
}

int check_substring(char *text, const char *pattern) {
    int m = strlen(pattern);
    return strncmp(text, pattern, m) == 0;
}

int pow_mod(int x, int n, int m) {
    // (x ^ n) % m

    // Initialize result as 1 (since anything power 0 is 1)
    int res = 1;

    // n times to multiply x with itself
    for(int i = 1; i <= n; i++) {

        // Multiplying res with x
        // and taking modulo to avoid overflow
        res = (res * x) % m;
    }

    return res;
}


int search_kr(char *text, const char *pattern) {
    int d = ALPHABET;
    int n = strlen(text);
    int m = strlen(pattern);
    int q = next_prime(m * 1000);
    int h = pow_mod(d, m - 1, q);

    int p = 0;
    int t = 0;

    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    printf("[debug] d=%d, q=%d, h=%d, p=%d, t=%d\n", d, q, h, p, t);

    for (int s = 0; s <= (n - m); s++) {
        if (p == t) {
            printf("[debug] match! p=%d t=%d s=%d\n", p, t, s);
            if (check_substring(text + s, pattern)) {
                return s;
            }
        }
        if (s < (n - m)) {
            // FIXME: this hashing update function is not correct!
            t = (d * (t - text[s] * h) + text[s + m]) % q;
        }
    }
    return -1;
}
