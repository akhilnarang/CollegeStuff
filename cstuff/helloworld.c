#include <omp.h>
#include <stdio.h>

/**
 * Hello World
 */

int main() {
#pragma omp parallel for
    for (int i = 0; i < 12; i++) {
        printf("Hello World from %d!\n", omp_get_thread_num());
    }
    return 0;
}