#include <stdio.h>

/**
 * Program to print the factors of a number
 */

void main()
{
    // Prompting the user
    printf("Enter a number(greater than 2): ");
    // Declaring variables
    int n,i;
    // Accepting input
    scanf("%d", &n);
    // Iterate over i till the number
    for(i=2;i<n;i++) {
        if (n%i==0) {
            // If the remainder is 0, i is a factor
            printf("%d is a factor of %d!\n", i, n);
        }
    }
}
