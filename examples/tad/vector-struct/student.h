/**
 * ============================================================================
 *
 *                      Copyright 2017 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC
 *
 * ============================================================================
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>


#define STUDENT_MAX_NAME 81

/**
 * @brief just a struct to represent a Student
 */
typedef struct {
    char name[STUDENT_MAX_NAME]; /**< name of the student */
    float ira; /**< student individual academic coefficient */
} Student;


void char_repeat(int n, char c) {
    for(int i = 0; i < n; i++) {
        printf("%c", c);
    }
    printf("\n");
}

void student_print(Student *student) {
    char_repeat(STUDENT_MAX_NAME, '=');
    printf("Name: %s\n", student->name);
    printf("IRA: %.3f\n", student->ira);
}

Student* student_new() {
    return (Student *) malloc(sizeof(Student));
}

#endif
