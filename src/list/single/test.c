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

/**
 * @brief Simple tests for the abstract data type list
 */


#include <stdio.h>
#include <assert.h>
#include "list.h"
#include "../../console/console.h"

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

void test_jarbas(void) {
    printf("\n\n== TEST ADDED FOR JARBAS CHECKING ==\n");
    List* l1 = list_create();
    l1 = list_insert(l1, 6);
    l1 = list_insert(l1, 13);
    l1 = list_insert(l1, 25);
    l1 = list_insert(l1, 28);
    l1 = list_insert(l1, 40);
    l1 = list_remove(l1, 10);
    printf("List: ");
    list_println(l1);
    printf("Reversed: ");
    list_println_reverse(l1);

    printf("Nodes with data lesser than 23: %d\n", list_less_than(l1,23));
    printf("The length of the list is: %d\n", list_length(l1));
    printf("Sum of values of nodes: %d\n", list_sum(l1));
    printf("Num of nodes with perfect numbers: %d\n", list_perfect(l1));

    List* l2 = list_create();
    l2 = list_insert(l2, 90);
    l2 = list_insert(l2, 130);

    List* l3 = list_concat(l1, l2);
    list_println(l3);

    list_free(l1);
    list_free(l2);
    list_free(l3);

}

void test_list_iterator() {
    puts("== list iterator should produce the same list");
    List *l = list_init(3, 1, 2, 3);
    printf("list input: ");
    list_println(l);

    Iterator *it = list_iterator_data(l);
    List *l_from_iterator = list_from_iterator(it);
    printf("list iterator: ");
    list_println(l_from_iterator);

    assert(list_equal(l, l_from_iterator));

    iterator_free(it);
    list_free(l);
    list_free(l_from_iterator);
}

void test_list_sort() {
    puts("== list sort should produce the a ordered list");
    List *l = list_init(4, 1, 0, 2, 3);
    List *l_expected = list_init(4, 0, 1, 2, 3);
    printf("list input: ");
    list_println(l);
    printf("list expected after sort: ");
    list_println(l_expected);

    list_sort(&l);
    assert(list_equal(l, l_expected));

    list_free(l);
    list_free(l_expected);
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
    test_jarbas();
    test_list_iterator();
    test_list_sort();
#ifdef _WIN32
    pause();
#endif
    return 0;
}
