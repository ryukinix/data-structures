/**
 * ================================================
 *
 *         Copyright 2017 Manoel Vilela
 *
 *         Author: Manoel Vilela
 *        Contact: manoel_vilela@engineer.com
 *   Organization: UFC
 *
 * ===============================================
 */


#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <string.h>

#define SIZES 5
#define EXPERIMENTS 5

const int sizes[] = {1E2, 1E3, 1E4, 1E5, 1E6};
static double benchmark[SIZES][EXPERIMENTS+1];


// HACK: Macro for expanding testing by name of algorithm (ALGO)
#define BENCHMARK_ALGORITHM(ALGO)                                       \
    printf("== Testing algorithm: %s\n", #ALGO);                        \
    for (int i = 0; i < SIZES; i++) {                                   \
        int n = sizes[i];                                               \
        benchmark[i][0] = n;                                            \
        for (int j = 1; j < EXPERIMENTS+1; j++) {                       \
            int *v = random_vector(n);                                  \
            clock_t start = clock();                                    \
            ALGO(v, n);                                                 \
            clock_t end = clock();                                      \
            assert(check_sorted(v, n));                                 \
            benchmark[i][j] = (double)1000*(end-start)/CLOCKS_PER_SEC;  \
            free(v);                                                    \
        }                                                               \
        printf("%d/%d :: %d elements\n", i+1, SIZES,  sizes[i]);        \
    }                                                                   \
    save_csv(#ALGO);                                                    \

// save a csv file based on the name of algorithm like 'quicksort'
void save_csv(char *algorithm) {
    char filename[80];
    sprintf(filename, "%s.csv", algorithm);
    FILE *fp = fopen(filename,"w");

    fprintf(fp,"Elements;");
    for(int i = 0; i < EXPERIMENTS; i++) {
        fprintf(fp, "Time_%d(ms);", (i+1));
    }
    fprintf(fp, "\n");

    for(int i = 0; i < SIZES; i++){
        fprintf(fp, "%d;", (int)benchmark[i][0]);
        for(int j = 1; j < EXPERIMENTS+1; j++) {
            fprintf(fp,"%.3lf;", benchmark[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
	printf("Saved at: %s\n", filename);
}


int main(void) {
    BENCHMARK_ALGORITHM(quicksort);
    BENCHMARK_ALGORITHM(heapsort);
    BENCHMARK_ALGORITHM(mergesort);
    BENCHMARK_ALGORITHM(insertionsort);
    BENCHMARK_ALGORITHM(bubblesort);
    BENCHMARK_ALGORITHM(radixsort);
    return 0;
}
