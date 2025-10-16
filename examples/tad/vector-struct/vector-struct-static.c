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
#include "student.h"

#define MAX 3
#define STUDENT_EMPTY -1 /**< used to identify if struct block is empty */

void init(Student students[MAX]) {
    for(int i = 0; i < MAX; i++) {
        students[i].ira = STUDENT_EMPTY;
    }
}

void print_student(int i, Student students[MAX]) {
    assert(i >= 0 || i < MAX);
    if (students[i].ira != STUDENT_EMPTY) {
        student_print(students + i);
    }
}

void print_students(Student students[MAX]) {
    for(int i = 0; i < MAX; i++) {
        print_student(i, students);
    }
}

void update_student(int i, Student students[MAX]) {
    assert(i >= 0 || i < MAX);
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

void update_students(Student students[MAX]) {
    for(int i = 0; i < MAX; i++) {
        update_student(i, students);
    }
}

int main(void) {
    Student students[MAX];
    init(students);
    update_students(students);
    print_students(students);
    return 0;
}
