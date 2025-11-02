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

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "search.h"

struct test_case {
    const char *text;
    const char *pattern;
    const int expected;

};

struct test_case tests[] = {
    {
        .text = "a search pattern algorithm",
        .pattern = "a search",
        .expected = 0,
    },
    {
        .text = "a search pattern algorithm",
        .pattern = "ttern",
        .expected = 11
    },
    {
        .text = "a search pattern algorithm",
        .pattern = "rithm",
        .expected = 21
    },
    {
        .text = "a search pattern algorithm",
        .pattern = "machine",
        .expected = -1
    },
    {
        .text = "xxxabababaaba",
        .pattern = "abaaba",
        .expected = 7
    },
    {
        .text = "ratara tatata xxx",
        .pattern = "tata",
        .expected = 7
    },
};

int n_tests = sizeof(tests) / sizeof(struct test_case);
int answer, i;

#define TEST(ALGORITHM)                                \
    printf("== Testing for %s: ", #ALGORITHM);         \
    for (i = 0; i < n_tests; i++) { \
        printf("\n   Input: text='%s'; \t pattern='%s'\n", tests[i].text, tests[i].pattern); \
        answer = ALGORITHM((char*) tests[i].text, (char*)tests[i].pattern);   \
        printf("   Result: answer=%d; expected=%d\n", answer, tests[i].expected); \
        assert(answer == tests[i].expected); \
    };


int main(void) {
    TEST(search_naive);
    TEST(search_kmp);
    TEST(search_bm);
    TEST(search_kr);
    return 0;
}
