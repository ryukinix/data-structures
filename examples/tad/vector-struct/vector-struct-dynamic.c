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

#define STUDENT_EMPTY -1

void init(Student *students, int n) {
    for(int i = 0; i < n; i++) {
        students[i].ira = STUDENT_EMPTY;
    }
}

void print_student(int i, Student *students, int n) {
    assert(i >= 0 || i < n);
    if (students[i].ira != STUDENT_EMPTY) {
        student_print(students + i);
    }
}

void print_students(Student *students, int n) {
    for(int i = 0; i < n; i++) {
        print_student(i, students, n);
    }
}

void update_student(int i, Student *students, int n) {
    assert(i >= 0 || i < n);
    float ira = -1;
    printf("Name: ");
    scanf(" %[^\n]", students[i].name);
    while (1) {
        printf("Ira: ");
        scanf("%f", &ira);
        if (ira < 0 || ira > 100) {
            printf("[ErrorValue] Ira value must be on interval [0, 100].\n");
        } else {
            break;
        }
    }
    students[i].ira = ira;
}

void update_students(Student *students, int n) {
    for(int i = 0; i < n; i++) {
        update_student(i, students, n);
    }
}

int main(void) {
    Student *students = NULL;
    int n; // number of students
    printf("Number of Students: ");
    scanf("%d", &n);

    // memory alloc
    students = (Student *) malloc(sizeof(Student)*n);
    check_alloc(students);

    // main program
    init(students, n);
    update_students(students, n);
    print_students(students, n);

    // free memory
    free(students);
    students = NULL;

    return 0;
}
