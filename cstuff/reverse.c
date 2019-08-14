#include <stdio.h>

/**
 * Program to display the reverse of an inputted number
 */

void main() {
    printf("Enter a number to be reversed: ");
    int n;
    scanf("%d", &n);
    int rev = 0, m = n;
    while (m > 0) {
        int t = m % 10;
        rev = rev * 10 + t;
        m /= 10;
    }
    printf("The reverse of %d is %d.\n", n, rev);
}
