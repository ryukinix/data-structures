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

#ifndef STACK_H
#define STACK_H

#define STACK_STATIC_MAX 10

typedef struct stack Stack;

/** Create a new stack */
Stack* stack_create(void);

/** Verify is stack is empty */
int stack_empty(Stack* s);

/** Push a new element on top of stack */
void stack_push(Stack* s, int data);

/** Pop a element from top of stack */
int stack_pop(Stack* s);

/** Print the elements of stack without a newline */
void stack_print(Stack* s);

/** Print the elements of stack with a newline on the end */
void stack_println(Stack* s);

/** Free memory of the stack structure */
void stack_free(Stack* s);

// additional functions

/** Get the element of top without removing */
int stack_top(Stack* s);

/** Count the elements which is odd */
int stack_odds(Stack* s);

#endif
