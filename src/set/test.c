#include <stdio.h>
#include <assert.h>
#include "set.h"

void test_set_contains() {
    printf("\n== test set_contains\n\n");
    Set *set = set_init(5, 1, 2, 3, 3, 4);
    printf("set: ");
    set_print(set);
    printf("Check if set contains 3\n");
    assert(set_contains(set, 3) == true);

    set_free(set);
}


void test_set_remove() {
    printf("\n== test set_remove\n\n");
    Set *set = set_init(5, 1, 2, 3, 3, 4);
    printf("set: ");
    set_print(set);
    printf("remove 2 from set\nset: ");
    set_remove(set, 2);
    set_print(set);
    assert(set_contains(set, 2) == false);

    set_free(set);
}


void test_set_equal() {
    printf("\n== test set_equal\n\n");
    Set *set_a = set_init(5, 1, 2, 3, 3, 4);
    Set *set_b = set_init(5, 3, 2, 1, 3, 4);
    printf("set_a: ");
    set_print(set_a);
    printf("set_b: ");
    set_print(set_b);
    assert(set_equal(set_a, set_b) == true);

    printf("Remove 4 from set_b. They should not be equal anymore.\nset_b: ");
    set_remove(set_b, 4);
    set_print(set_b);
    assert(set_equal(set_a, set_b) == false);
    set_free(set_a); set_free(set_b);

}


void test_set_intersection() {
    printf("\n== test set_intersection\n\n");
    Set *set_a = set_init(1, 1);
    Set *set_b = set_init(5, 3, 2, 1, 3, 4);
    printf("set_a: ");
    set_print(set_a);
    printf("set_b: ");
    set_print(set_b);
    Set *set_c = set_intersection(set_a, set_b);
    printf("set_intersection: ");
    set_print(set_c);
    assert(set_equal(set_c, set_a) == true);
    set_free(set_a); set_free(set_b); set_free(set_c);
}


void test_set_union() {
    printf("\n== test set_union\n\n");
    Set *set_a = set_init(1, 6);
    Set *set_b = set_init(5, 1, 2, 3, 4, 5);
    Set *set_expected = set_init(6, 1, 2, 3, 4, 5, 6);
    printf("set_a: ");
    set_print(set_a);
    printf("set_b: ");
    set_print(set_b);
    Set *set_c = set_union(set_a, set_b);
    printf("set_union: ");
    set_print(set_c);
    assert(set_equal(set_c, set_expected) == true);
    set_free(set_a); set_free(set_b); set_free(set_c); set_free(set_expected);
}


void test_set_difference() {
    printf("\n== test set_difference\n\n");
    Set *set_a = set_init(4, 0, 1, 2, 3);
    Set *set_b = set_init(5, 1, 2, 3, 4, 5);
    Set *set_expected = set_init(1, 0);
    printf("set_a: ");
    set_print(set_a);
    printf("set_b: ");
    set_print(set_b);
    Set *set_c = set_difference(set_a, set_b);
    printf("set_difference: ");
    set_print(set_c);
    assert(set_equal(set_c, set_expected) == true);
    set_free(set_a); set_free(set_b); set_free(set_c); set_free(set_expected);
}


void test_set_copy() {
    printf("\n== test set_copy\n\n");
    Set *set = set_init(4, 0, 1, 2, 3);
    Set *set_copied = set_copy(set);

    assert(set_equal(set, set_copied) == true);

    printf("Modify the copy should not affect the original. Insert 5.\n");
    set_add(set_copied, 5);
    printf("set: ");
    set_print(set);
    printf("set_copied: ");
    set_print(set_copied);
    assert(set_equal(set, set_copied) == false);
    set_free(set); set_free(set_copied);
}


int main(void) {
    printf("== Tests over Set data stucture");
    test_set_contains();
    test_set_remove();
    test_set_equal();
    test_set_copy();
    test_set_intersection();
    test_set_union();
    test_set_difference();
    return 0;
}
