/**
 * ================================================
 *
 *         Copyright 2017 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC
 *
 * ===============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "search.h"


char *text = "a search pattern algorithm";
const char *pattern = "ttern";
int expected = 11;
int answer;

#define TEST(ALGORITHM)                                \
    printf("== Testing for %s: ", #ALGORITHM);         \
    printf("\n-- Input: text='%s' ; pattern='%s'\n", text, pattern);     \
    answer = ALGORITHM(text, pattern);                  \
    printf("-- Result: answer=%d; expected=%d\n", answer, expected);    \
    assert(answer == expected);

int main(void) {
    TEST(search_naive);
    return 0;
}
