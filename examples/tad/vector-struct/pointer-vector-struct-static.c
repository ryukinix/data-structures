/**
 * ============================================================================
 *
 *                      Copyright 2017-2025 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC
 *
 * ============================================================================
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "student.h"
#include "utils/check_alloc.h"

#define MAX 2

void init(Student **students) {
    for(int i = 0; i < MAX; i++) {
        students[i] = NULL;
    }
}

void print_student(int i, Student **students) {
    assert(i >= 0 || i < MAX);
    if (students[i] != NULL) {
        student_print(students[i]);
    }
}

void print_students(Student **students) {
    for(int i = 0; i < MAX; i++) {
        print_student(i, students);
    }
}

void update_student(int i, Student **students) {
    assert(i >= 0 || i < MAX);
    float ira = -1;
    if (students[i] == NULL) {
        students[i] = student_new();
        check_alloc(students[i]);
    }

    printf("Name: ");
    scanf(" %[^\n]", students[i]->name);
    while (1) {
        printf("Ira: ");
        scanf(" %f", &ira);
        if (ira < 0 || ira > 100) {
            printf("[ErrorValue] Ira value must be on interval [0, 100].\n");
        } else {
            break;
        }
    }
    students[i]->ira = ira;
}

void update_students(Student **students) {
    for(int i = 0; i < MAX; i++) {
        update_student(i, students);
    }
}

void delete_student(int i, Student **students) {
    assert(i >= 0 || i < MAX);
    if (students[i] != NULL) {
        free(students[i]);
    }
}


void free_students(Student **students) {
    for(int i = 0; i < MAX; i++) {
        delete_student(i, students);
    }
}

int main(void) {
    Student *students[MAX]; // vector of struct pointers

    // main program
    init(students);
    update_students(students);
    print_students(students);

    // free memory
    free_students(students);

    return 0;
}
