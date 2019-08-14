#include <stdio.h>

/**
 * Program to check and display whether given number is a prime number or not
 */

void main() {
    printf("Enter a number: ");
    int n, c = 0, i;
    scanf("%d", &n);
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            c++;
        }
    }
    if (n == 0 || n == 1 || c != 0) {
        printf("%d is not a prime number!\n", n);
    } else {
        printf("%d is a prime number!\n", n);
    }
}
