/**
 * Copyright 2017-2025 Manoel Vilela
 *
 * Referências da Aula_0 e Aula_1.
 */

// Nós temos duas maneiras de lidar com matrizes
// e alocação dinâmica.

// Uma matriz pode ser representada como um conjunto de n
// ponteiros aninhados, a maneira que eu acho mais óbvia.

// int **v;
// int n, m;
// a[0] -> [0 1 2 3 4 ... m]
// a[1] -> [0 1 2 3 4 ... m]
// ...
// a[n - 1] -> [0 1 2 3 4 ... m]

// Ou alocando a memória de forma contínua como um vetor
// e usando regras de "fatiamento" pra fazer uma abstração
// de uma matrix em cima de um vetor.
// Onde cada passo para o próximo do vetor é do tamanho
// da coluna definida. Isso são maneiras completamente diferentes
// de abstrair uma matriz na memória e tem implicações no uso
// tanto quanto na performance.

/*
 * TODO: Dar um jeito nessa replicação cancerígena por causa das assinaturas
 *       diferentes das funções do tipo vector e pointer.
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../src/utils/check_alloc.h"


// aloca uma matrix como um vetor contínuo
// @return: um ponteiro simples
int* alloc_vector_matrix(int n, int m) {
    int *matrix;
    matrix = (int *) malloc(sizeof(int) * n * m);
    check_alloc(matrix);
    return matrix;
}

// aloca uma matrix como uma coleção de vetores contínuos
// @return: ponteiro de ponteiro :: double pointer
int** alloc_pointer_matrix(int n, int m) {
    int **matrix;

    matrix = (int **) malloc(n * sizeof(int*)); // coleção de ponteiros de ponteiros;
    check_alloc(matrix);
    for(int i = 0; i < n; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * m);
        check_alloc(matrix[i]);
    }

    return matrix;
}

// preenche uma matriz do tipo pointer
void fill_matrix_pointer(int **matrix, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            matrix[i][j] = i * m + j;
        }
    }
}

// preenche uma matriz do tipo vetor contínuo
void fill_matrix_vector(int *matrix, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            matrix[i * m + j] = i * m + j;
        }
    }
}


// repete o character `c` `n` vezes e quebra a linha
void repeat_printf(char c, int n) {
    while(n--) {
        printf("%c", c);
    }
    puts("");
}

// imprime uma matrix do tipo vector (alocado como ponteiro simples)
void print_matrix_vector(int *matrix, int n, int m) {
    printf("=> Matriz alocada como vetor\n");
    int width = ceil(log10(n*m));
    int column_length = (width + 1)*m + 3;
    repeat_printf('-', column_length);
    for(int i = 0; i < n; i++) {
        printf("| ");
        for(int j = 0; j < m; j++) {
            printf("%*d ", width, matrix[i*m +j]);
        }
        printf("|\n");
    }
    repeat_printf('-', column_length);
}

// imprime uma matrix do tipo pointer (alocado como double pointer)
void print_matrix_pointer(int **matrix, int n, int m) {
    printf("=> Matriz alocada como ponteiro de ponteiro\n");
    int width = ceil(log10(n*m));
    int column_length = (width + 1)*m + 3;
    repeat_printf('-', column_length);
    for(int i = 0; i < n; i++) {
        printf("| ");
        for(int j = 0; j < m; j++) {
            printf("%*d ", width, matrix[i][j]);
        }
        printf("|\n");
    }
    repeat_printf('-', column_length);
}

// desalocação de um vetor dinâmico simples, encarado como matriz nesse problema
void free_matrix_vector(int *matrix) {
    free(matrix);
}

// desaloca uma matriz definida como um vetor de ponteiros
void free_matrix_pointer(int **matrix, int length) {
    for(int i = 0; i < length; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main(void) {
    int *matrix_vector = NULL;
    int **matrix_pointer = NULL;

    int n, m;
    printf("Digite o tamanho da matrix (n m): ");
    scanf("%d %d", &n, &m);

    // alocação dinâmica para ambas matrizes
    matrix_vector = alloc_vector_matrix(n, m);
    matrix_pointer = alloc_pointer_matrix(n, m);

    // preencher as matrizes
    fill_matrix_vector(matrix_vector, n, m);
    fill_matrix_pointer(matrix_pointer, n, m);

    // printing all this shit
    print_matrix_vector(matrix_vector, n, m);
    print_matrix_pointer(matrix_pointer, n, m);

    // desalocação de memória
    free_matrix_vector(matrix_vector);
    free_matrix_pointer(matrix_pointer, n);
    matrix_vector = NULL;
    matrix_pointer = NULL;

    return 0;

}
