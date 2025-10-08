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

#include "search.h"
#include <string.h>


int search_naive(char* text, const char* pattern) {
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

void kmp_init_failure_function(int *f, int m, const char* pattern) {
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

int search_kmp(char *text, const char* pattern) {
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
