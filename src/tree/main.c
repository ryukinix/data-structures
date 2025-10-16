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
#include <string.h>
#include "avl/avl.h"
#include "ascii-tree/ascii-tree.h"
#include "../console/console.h"

/**
 * @description
 * A simple program to see what happens on AVL
 * interactively inserting and removing new elements
 */

void help() {
	printf("usage: [insert(i) num | remove(r) num | infix | posfix | prefix | print(p) | clear | help | exit]\n");
}

int main(void) {
    AVLTree *root = avl_create();
    int number;
    char command[50];
    help();
    while (1) {
        printf(">>> ");
        int tokens = scanf("%s", command);

        if (tokens < 1) { // EOF emit
            exit(0);
        }

        if (strcmp(command, "insert") == 0 || strcmp(command, "i") == 0) {
            scanf(" %d", &number);
            root = avl_insert(root, number);
        } else if (strcmp(command, "remove") == 0  || strcmp(command, "r") == 0) {
            scanf(" %d", &number);
            root = avl_remove(root, number);
        } else if (strcmp(command, "infix") == 0) {
            avl_infix(root);
        } else if (strcmp(command, "posfix") == 0) {
            avl_posfix(root);
        } else if (strcmp(command, "prefix") == 0) {
            avl_prefix(root);
        } else if (strcmp(command, "print") == 0 || strcmp(command, "p") == 0) {
            print_ascii_tree(root);
        } else if (strcmp(command, "clear") == 0) {
            clear();

        } else if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0) {
            exit(0);
        } else {
        	help();
		}
    }

}
