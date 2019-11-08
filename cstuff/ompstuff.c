#include <omp.h>
#include <stdio.h>

int main() {
    int a = 1, b = 2, c = 3;
    int result, thread_id;
    int result1, result2, result3, result4;
#pragma omp parallel
    {
        thread_id = omp_get_thread_num();
        printf("Thread %d!\n", thread_id);
        switch (thread_id) {
            case 0:
            case 1:
                result1 = a * a;
                printf("r1 %d\n", result1);
                break;
            case 2:
            case 3:
                result2 = b * b;
                printf("r2 %d\n", result2);
                break;
            case 4:
            case 5:
                result3 = 2 * a * b;
                printf("r3 %d\n", result3);
                break;
            case 6:
            case 7:
                result4 = 4 * a * b;
                printf("r4 %d\n", result4);
                break;
            default:
                break;
        }
    }
    printf("%d\n", result1);
    printf("%d\n", result2);
    printf("%d\n", result3);
    printf("%d\n", result4);
    result = result1 + result2 + result3 - result4;
    printf("a: %d\nb: %d\nc: %d\nresult: %d\n", a, b, c, result);
}