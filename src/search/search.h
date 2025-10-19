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

/**
 * @brief Finds the first occurrence of a pattern in a text using the naive
 * string searching algorithm.
 *
 * @param text The text to search in.
 * @param pattern The pattern to search for.
 * @return The index of the first occurrence of the pattern in the text, or -1
 * if the pattern is not found.
 * @ingroup SearchAlgorithms
 */
int search_naive(char *text, const char *pattern);

/**
 * @brief Finds the first occurrence of a pattern in a text using the
 * Knuth-Morris-Pratt (KMP) algorithm.
 *
 * @param text The text to search in.
 * @param pattern The pattern to search for.
 * @return The index of the first occurrence of the pattern in the text, or -1
 * if the pattern is not found.
 * @ingroup SearchAlgorithms
 */
int search_kmp(char *text, const char *pattern);

/**
 * @brief Finds the first occurrence of a pattern in a text using the
 * Boyer-Moore string searching algorithm.
 *
 * @param text The text to search in.
 * @param pattern The pattern to search for.
 * @return The index of the first occurrence of the pattern in the text, or -1
 * if the pattern is not found.
 * @ingroup SearchAlgorithms
 */
int search_bm(char *text, const char *pattern);

/**
 * @brief Finds the first occurrence of a pattern in a text using the
 * Karp-Rabin algorithm.
 *
 * @param text The text to search in.
 * @param pattern The pattern to search for.
 * @return The index of the first occurrence of the pattern in the text, or -1
 * if the pattern is not found.
 * @ingroup SearchAlgorithms
 */
int search_kr(char *text, const char *pattern);


#endif
