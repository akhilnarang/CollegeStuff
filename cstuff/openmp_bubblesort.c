#include <omp.h>
#include <stdio.h>

int main() {
    int a = 2;
    int b = 3;

    int n[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    double s = omp_get_wtime();
    for (int i = 0; i < 5; i++) {
        #pragma omp parallel for
        for (int j = 0; j < 9; j+=2) {
            //printf("We are at i=%d|j=%d|thread=%d\n", i, j, omp_get_thread_num());
            if (n[j] > n[j+1]) {
                int temp = n[j];
                n[j] = n[j+1];
                n[j+1] = temp;
            }
        }
        #pragma omp parallel for
        for (int k = 1; k < 8; k+=2) {
            //printf("We are at i=%d|k=%d|thread=%d\n", i, k, omp_get_thread_num());
            if (n[k] > n[k+1]) {
                int temp = n[k];
                n[k] = n[k+1];
                n[k+1] = temp;
            }

        }
    }
    s = omp_get_wtime() - s;
    printf("%f\n", s);
    for (int i = 0; i < 9; i++) {
        printf("n[%d] = %d\n", i, n[i]);
    }

    return 0;
}