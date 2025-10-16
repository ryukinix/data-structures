/*
 * ============================================================================
 *
 *                      Copyright 2017 Manoel Vilela
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
 * @brief remove all the garbage from stdin
 */
static inline void flush_stdin() {
    char c;
    ungetc('\n', stdin); // ensure that stdin is dirty
    while(((c = getchar()) != '\n') && (c != EOF));
}

/**
 * @brief Cross-platform pause: works on windows and linux
 */
static inline void pause() {
    printf("Press enter to continue...");
    flush_stdin();
    getchar();
}

#endif
