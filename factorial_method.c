#include<stdio.h>
#include<stdlib.h>

/**
 * Program to calculate factorial of a number calling a function recursively
 */
 
// function that computes the factorial of a number by calling itself
int factorial(int n)
{
    return n==1?n:n*factorial(n-1); // Call the function recursively
}

void main()
{
    // Prompting the user
    printf("\nEnter a positive integer n: ");
    // Decalaring integer variable
    int n;
    // Accepting input
    scanf("%d", &n);
    if (n<1) { // Exit on invalid input!
        printf("\nPlease follow instructions!\n");
        exit(1);
    }
    // Call factorial() and print the value
    printf("\nFactorial of %d is %d!\n", n, factorial(n));
}

/*EXECUTION
fpllab@fpllab-OptiPlex-9020:~/Desktop/Akhil$ gcc ./factorial_method.c
fpllab@fpllab-OptiPlex-9020:~/Desktop/Akhil$ ./a.out

Enter a positive integer n: 5

Factorial of 5 is 120!
*/
