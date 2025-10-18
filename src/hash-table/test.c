#include <stdio.h>
#include <assert.h>
#include "hash-table.h"


void test_hash_table_remove(HashTable *ht, int key) {
    printf("\n== After removing key=%d:\n", key);
    hash_table_remove(ht, key);
    hash_table_print(ht);


    bool ok;
    hash_table_get(ht, key, &ok);
    assert(ok == false);

}

void test_hash_table_get(HashTable *ht, int key, int expected) {
    int value = hash_table_get(ht, key, NULL);
    assert(value == expected);
}

void test_hash_table_insert_with_update(HashTable *ht, int key) {
    hash_table_put(ht, key, 10);
    hash_table_put(ht, key, 20);
    printf("\n== Inserting 10 and 20 values with key=%d:\n", key);
    hash_table_print(ht);
    printf("items: ");
    hash_table_print_items(ht);
    printf("keys: ");
    hash_table_print_keys(ht);
}

void test_hash_table_copy(HashTable *ht) {
    HashTable *ht_copy = hash_table_copy(ht);

    printf("== Hash Table Copy, modify key=1 from 10 to 20\n");
    hash_table_put(ht, 1, 10);
    hash_table_put(ht_copy, 1, 20);
    printf("\nOriginal: \n");
    hash_table_print(ht);
    printf("Copy: \n");
    hash_table_print(ht_copy);

    assert(hash_table_get(ht, 1, NULL) != hash_table_get(ht_copy, 1, NULL));

    hash_table_free(ht_copy);
}


HashTable* hash_table_setup() {
    HashTable *ht = hash_table_create(10);

    hash_table_put(ht, 1, 111);
    hash_table_put(ht, 10, 110);
    hash_table_put(ht, 11, 112);
    hash_table_put(ht, 9, 999);
    hash_table_put(ht, 2, 300);

    printf("== Hash Table:\n");
    printf("number of items: %lu\n", hash_table_size(ht));
    hash_table_print(ht);

    return ht;
}

void test_hash_table_empty() {
    HashTable *ht = hash_table_create(5);
    assert(hash_table_empty(ht) == true);
    hash_table_put(ht, 1, 1);
    assert(hash_table_empty(ht) == false);
    hash_table_remove(ht, 1);
    assert(hash_table_empty(ht) == true);
    hash_table_free(ht);
}

int main(void) {

    HashTable *ht = hash_table_setup();
    test_hash_table_get(ht, 9, 999);
    test_hash_table_remove(ht, 10);
    test_hash_table_remove(ht, 1);
    test_hash_table_insert_with_update(ht, 0);
    test_hash_table_copy(ht);
    test_hash_table_empty();


    hash_table_free(ht);
    return 0;
}
