#include<stdio.h>

/**
 * Program to calculate factorial of a number calling a function recursively
 */
 
// function that computes the factorial of a number by calling itself
int factorial(int n)
{
    if (n==1) {
        return 1; // Exit out once we're down to 1
    } else {
        return(n*factorial(n-1)); // Call the function recursively
    }
}

void main()
{
    // Prompting the user
    printf("\nEnter a positive integer n: ");
    // Decalaring integer variable
    int n;
    // Accepting input
    scanf("%d", &n);
    if (n<1) { // Don't calculate if the user can't listen
        printf("\nPlease follow instructions!\n");
    } else {
        // Call factorial() and print the value
        printf("\nFactorial of %d is %d!\n", n, factorial(n));
    }       
}
