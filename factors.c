#include <stdio.h>

/**
 * Program to print the factors of a number
 */

void main(){
    printf("Enter a number(greater than 2): ");
    int n,i;
    scanf("%d", &n);
    for(i=2;i<n;i++) {
        if (n%i==0) {
            printf("%d is a factor of %d!\n", i, n);
        }
    }
}
