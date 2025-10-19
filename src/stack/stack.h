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

/**
 * @brief A stack data structure.
 */
typedef struct stack Stack;

/**
 * @brief Creates an empty stack.
 *
 * @return A pointer to the new stack.
 * @ingroup DataStructureMethods
 */
Stack* stack_create(void);

/**
 * @brief Checks if a stack is empty.
 *
 * @param s The stack to check.
 * @return 1 if the stack is empty, 0 otherwise.
 * @ingroup DataStructureMethods
 */
int stack_empty(Stack* s);

/**
 * @brief Pushes an element onto the top of a stack.
 *
 * @param s The stack to push onto.
 * @param data The data to push.
 * @ingroup DataStructureMethods
 */
void stack_push(Stack* s, int data);

/**
 * @brief Pops an element from the top of a stack.
 *
 * @param s The stack to pop from.
 * @return The popped element.
 * @ingroup DataStructureMethods
 */
int stack_pop(Stack* s);

/**
 * @brief Prints the elements of a stack to the console.
 *
 * @param s The stack to print.
 * @ingroup DataStructureMethods
 */
void stack_print(Stack* s);

/**
 * @brief Prints the elements of a stack to the console, followed by a newline
 * character.
 *
 * @param s The stack to print.
 * @ingroup DataStructureMethods
 */
void stack_println(Stack* s);

/**
 * @brief Frees the memory allocated for a stack.
 *
 * @param s The stack to free.
 * @ingroup DataStructureMethods
 */
void stack_free(Stack* s);

// additional functions

/**
 * @brief Returns the element at the top of a stack without removing it.
 *
 * @param s The stack to peek at.
 * @return The element at the top of the stack.
 * @ingroup DataStructureMethods
 */
int stack_top(Stack* s);

/**
 * @brief Counts the number of odd elements in a stack.
 *
 * @param s The stack to search.
 * @return The number of odd elements.
 * @ingroup DataStructureMethods
 */
int stack_odds(Stack* s);

#endif
