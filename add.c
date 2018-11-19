#include <stdio.h>

/**
 * Program to find and print the sum of 2 inputted numbers
 */

int main() {
    int m, n, sum;
    printf("Enter 2 numbers:\n");
    printf("m: ");
    scanf("%d", &m);
    printf("n: ");
    scanf("%d", &n);
    sum = m + n;
    printf("The sum of %d and %d is %d.\n", m, n, sum);
}
