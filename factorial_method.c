#include<stdio.h>

/**
  * Program to calculate factorial of a number calling a function recursively
  */

int factorial(int n) {
    if (n==1) {
        return 1;
    } else {
        return(n*factorial(n-1));
    }
}

main() {
    printf("\nEnter a positive integer n: ");
    int n;
    scanf("%d", &n);
    if (n<1) {
        printf("\nPlease follow instructions!\n");
    } else {
        printf("\nFactorial of %d is %d!\n", n, factorial(n));
    }
}
