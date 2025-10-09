/**
 * ================================================
 *
 *         Copyright 2025 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: ITA
 *
 * ===============================================
 */

#ifndef SEARCH_H
#define SEARCH_H


/**********************/
/* SEARCH ALGORITHMS */
/**********************/

/* Use brute force search to find substring on text:
   worst case: O(n * m)
 */
int search_naive(char *text, const char *pattern);

/* Use KMP algorithm to search substring on text:
   worst case: O(n)
 */
int search_kmp(char *text, const char *pattern);

/* Use Boyer-Moore algorithm to search substring on text:
   avg case: Omega(n/m)
   worst case: O(n * m)
 */
int search_bm(char *text, const char *pattern);

/* Use Karp-Rabin algorithm to search substring on text:
   avg case: Omega(n)
   worst case: O(n * m)
 */
int search_kr(char *text, const char *pattern);


#endif
