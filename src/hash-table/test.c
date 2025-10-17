#include <stdio.h>
#include <assert.h>
#include "hash-table.h"


void test_hash_table_remove(HashTable *ht, int key) {
    printf("\nAfter removing key=%d:\n", key);
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

int main(void) {
    HashTable *ht = hash_table_create(10);

    hash_table_put(ht, 1, 111);
    hash_table_put(ht, 10, 110);
    hash_table_put(ht, 11, 112);
    hash_table_put(ht, 9, 999);
    hash_table_put(ht, 2, 300);

    printf("== Hash Table:\n");
    hash_table_print(ht);
    test_hash_table_get(ht, 9, 999);
    test_hash_table_remove(ht, 10);
    test_hash_table_remove(ht, 1);



    hash_table_free(ht);
    return 0;
}
