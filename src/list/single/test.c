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

/**
 * @brief Simple tests for the abstract data type list
 */


#include "list.h"
#include "console/console.h"
#include <stdio.h>

void test_basic_functions(void) {
    puts("== test basic functions: insert_ord, print, free and remove");
    List *l = list_create();
    printf("Ordered insert: 3, 1, 9, 0\n");
    l = list_insert_ord(l, 3);
    l = list_insert_ord(l, 1);
    l = list_insert_ord(l, 9);
    l = list_insert_ord(l, 0);
    list_println(l);
    printf("Search for sub-list with head 3\n");
    List* s = list_search(l, 3);
    list_println(s);

    printf("Remove 3\n");
    l = list_remove(l, 3);
    list_println(l);

    list_free(l);
    l = EMPTY_LIST;

}

void test_list_init(void) {
    puts("== test list_init() variadic");
    List *l = list_init(4,1,2,3,4);
    list_println(l);
    list_free(l);
    l = EMPTY_LIST;
}

void test_list_last(void) {
    puts("== test list_last()");
    List *l = list_init(3, 1, 2, 3);
    list_println(l);
    printf("Last: %d\n", list_last(l));
    list_free(l);
    l = EMPTY_LIST;
}

void test_list_head(void) {
    puts("== test list_head()");
    List *l = list_init(3, 1, 2, 3);
    list_println(l);
    printf("Head: %d\n", list_head(l));
    list_free(l);
    l = EMPTY_LIST;
}

void test_list_tail(void) {
    puts("== test list_tail()");
    List *l = list_init(3, 1, 2, 3);
    list_println(l);
    printf("Tail: ");
    list_println(list_tail(l));
    list_free(l);
    l = EMPTY_LIST;
}

void test_list_pop_head(void) {
    puts("== test list_pop_head");
    List *l = list_init(3, 1, 2, 3);
    list_println(l);
    printf("Head popped: %d\n", list_pop_head(&l));
    printf("List updated: ");
    list_println(l);
    list_free(l);
    l = EMPTY_LIST;
}

void test_list_pop_last(void) {
    puts("== test list_pop_last()");
    List *l = list_init(3, 1, 2, 3);
    list_println(l);
    printf("Last popped: %d\n", list_pop_last(&l));
    printf("List updated: ");
    list_println(l);
    list_free(l);
    l = EMPTY_LIST;
}

void test_list_equal(void) {
    puts("== test list_list_equal()");
    List *l = list_init(3, 1, 2, 3);
    List *s = list_init(3, 1, 2, 3);
    List *z = list_init(2, 0, 1);
    list_print(l);
    printf(" == ");
    list_print(s);
    printf(" => %s\n", list_equal(l, s)? "true" : "false");
    list_print(s);
    printf(" == ");
    list_print(z);
    printf(" => %s\n", list_equal(s, z)? "true" : "false");

    list_free(l);
    list_free(s);
    list_free(z);
    l = EMPTY_LIST;
    s = EMPTY_LIST;
    z = EMPTY_LIST;
}

void test_list_perfect(void) {
    puts("== test list_perfect");
    List *l = list_init(3, 6, 12, 28);
    list_print(l);
    printf(" has %d perfect numbers\n", list_perfect(l));
    list_free(l);
    l = EMPTY_LIST;
}

void test_list_length(void) {
    puts("== test list_length");
    List *l = list_init(3, 1, 2, 3);
    list_print(l);
    printf(" has length %d\n", list_length(l));
    list_free(l);
    l = EMPTY_LIST;
}

void test_list_less_than(void) {
    puts("== test list_less_than");
    List *l = list_init(5, 1, 2, 3, 4, 5);
    int n = 3;
    list_print(l);
    printf(" %d nodes are lesser than %d\n", list_less_than(l, n), n);
    list_free(l);
    l = EMPTY_LIST;
}

void test_list_sum(void) {
    puts("== test list_sum");
    List *l = list_init(5, 1, 2, 3, 4, 5);
    list_print(l);
    printf(" the sum of nodes: %d\n", list_sum(l));
    list_free(l);
    l = EMPTY_LIST;
}


void test_list_concat(void) {
    puts("== test list_concat");
    List *l = list_init(3, 1, 2, 3);
    List *s = list_init(2, 4, 5);
    List *sl = list_concat(s, l);
    List *ls = list_concat(l, s);
    List *l_empty = list_concat(l, EMPTY_LIST);
    List *empty_s = list_concat(EMPTY_LIST, s);

    // l + s => ls
    list_print(l);
    printf(" + ");
    list_print(s);
    printf(" => ");
    list_println(ls);

    // s + l => sl
    list_print(s);
    printf(" + ");
    list_print(l);
    printf(" => ");
    list_println(sl);

    // [] + s => s
    list_print(EMPTY_LIST);
    printf(" + ");
    list_print(s);
    printf(" => ");
    list_println(empty_s);

    // l + [] => l
    list_print(l);
    printf(" + ");
    list_print(EMPTY_LIST);
    printf(" => ");
    list_println(l_empty);

    list_free(l);
    list_free(s);
    list_free(ls);
    list_free(sl);
    list_free(l_empty);
    list_free(empty_s);

}

void test_list_reverse(void) {
    puts("== test list_reverse()");
    List *l = list_init(5, 1, 2, 3, 4, 5);
    list_print(l);
    list_reverse(&l);
    printf(" => ");
    list_println(l);
    list_free(l);
    l = EMPTY_LIST;
}

int main(void) {
    test_basic_functions();
    test_list_init();
    test_list_last();
    test_list_head();
    test_list_tail();
    test_list_pop_head();
    test_list_pop_last();
    test_list_equal();
    test_list_perfect();
    test_list_length();
    test_list_less_than();
    test_list_sum();
    test_list_concat();
    test_list_reverse();
#ifdef _WIN32
    pause();
#endif
    return 0;
}
