/*
 * ============================================================================
 *
 *                      Copyright 2017-2025 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC
 *
 * ============================================================================
**/

#ifndef PAUSE_H
#define PAUSE_H

#include <stdio.h>

/**
 * @brief Clears the standard input buffer.
 *
 * This function reads and discards all characters from the standard input
 * buffer until a newline character or the end-of-file is reached.
 */
static inline void flush_stdin() {
    char c;
    ungetc('\n', stdin); // ensure that stdin is dirty
    while(((c = getchar()) != '\n') && (c != EOF));
}

/**
 * @brief Pauses the program execution until the user presses Enter.
 *
 * This function prints a message to the console and waits for the user to
 * press the Enter key.
 */
static inline void pause() {
    printf("Press enter to continue...");
    flush_stdin();
    getchar();
}

#endif
