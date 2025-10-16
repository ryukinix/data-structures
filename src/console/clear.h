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

#ifndef CLEAR_H
#define CLEAR_H

#ifdef _WIN32
static inline void clear() {
    system("cls");
}
#else
static inline void clear() {
    printf("\033[1;1H\033[2J");
}
#endif

#endif
