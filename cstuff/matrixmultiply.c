#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Program to take in elements of a matrix in a DDA and display the product
 */

int MAX = RAND_MAX;
void reset_matrix(int a[][MAX], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
}

void accept_matrix(int a[][MAX], int n, char* name) {
    int i, j;
    printf("\nEnter elements of %s:\n", name);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%s[%d][%d]: ", name, i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void fill_matrix(int a[][MAX], int n, char* name) {
    int i, j;
    printf("\nFilling elements of %s:\n", name);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = rand();
        }
    }
}

void display_matrix(int a[][MAX], int n, char* name) {
    int i, j;
    printf("\nElements of %s are:\n", name);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%s[%d][%d] - %d\t", name, i + 1, j + 1, a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j, k, n;
    double s;
    int a[MAX][MAX];
    int b[MAX][MAX];
    int product[MAX][MAX];
    printf("Enter the number of rows/columns (<= %d)\n", MAX);
    printf("n: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("Please enter proper values next time!\n");
        exit(1);
    }
    fill_matrix(a, n, "a");
    fill_matrix(b, n, "b");
    display_matrix(a, n, "a");
    display_matrix(b, n, "b");
    reset_matrix(product, n);
    s = omp_get_wtime();
#pragma omp parallel for private(i, j, k) shared(a, b, product)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                product[i][j] += a[k][j] * b[j][k];
            }
        }
    }
    s = omp_get_wtime() - s;
    printf("Parallel execution time = %f\n", s);

    reset_matrix(product, n);
    s = omp_get_wtime();
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                product[i][j] += a[k][j] * b[j][k];
            }
        }
    }
    s = omp_get_wtime() - s;
    printf("Serial execution time = %f\n", s);

    display_matrix(product, n, "product");
}
