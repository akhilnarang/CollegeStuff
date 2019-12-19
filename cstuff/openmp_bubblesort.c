#include <omp.h>
#include <stdio.h>

int main() {
    unsigned long long int i, j, k, size, temp;
    printf("Enter size of array!\n");
    printf("size: ");
    scanf("%llu", &size);
    unsigned long long int n[size];
    unsigned long long int a, b;

#pragma omp for
    for (i = 0; i < size; i++) {
        n[i] = size - i;
    }

    double s = omp_get_wtime();
    for (i = 0; i < size; i++) {
#pragma omp parallel for
        for (j = 0; j < size - 1; j += 2) {
            // printf("We are at i=%llu|j=%llu|thread=%d\n", i, j,
            //        omp_get_thread_num());
            if (n[j] > n[j + 1]) {
                temp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = temp;
            }
        }
#pragma omp parallel for
        for (k = 1; k < size - 1; k += 2) {
            // printf("We are at i=%llu|k=%llu|thread=%d\n", i, k,
            //        omp_get_thread_num());
            if (n[k] > n[k + 1]) {
                temp = n[k];
                n[k] = n[k + 1];
                n[k + 1] = temp;
            }
        }
    }
    s = omp_get_wtime() - s;
    printf("Parallel execution time for size %llu: %f\n", size, s);
    // for (unsigned long long int i = 0; i < size; i++) {
    //     printf("n[%llu] = %llu\n", i, n[i]);
    // }

#pragma omp for
    for (i = 0; i < size; i++) {
        n[i] = size - i;
    }

    s = omp_get_wtime();
    for (unsigned long long int i = 0; i < size; i++) {
        for (unsigned long long int j = 0; j < size - i - 1; j++) {
            if (n[j] > n[j + 1]) {
                // swap
                temp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = temp;
            }
        }
    }
    s = omp_get_wtime() - s;
    printf("Serial execution time for size %llu: %f\n", size, s);
    return 0;
}