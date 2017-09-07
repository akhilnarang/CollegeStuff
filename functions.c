#include <stdio.h>

/**
 * Program to define and call a couple of methods to perform some mathematical
 * operations
 */

// Function that returns the sum of 2 integers
int add(int a, int b) {
    return a+b;
}

// Function that returns the difference between 2 integers
int subtract(int a, int b) {
    return a-b;
}

// Function that returns the product of 2 numbers
int multiply(int a, int b) {
    return a*b;
}

// Function that returns the quotient of 2 numbers
int divide(int a, int b) {
    return a/b;
}

void main(){
    // Prompting the user for input
    printf("\nEnter 2 integers!\n");
    int a, b;
    // Accepting input
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    // Calling the functions and calling input
    printf("\nSum of %d and %d is %d", a, b, add(a, b));
    printf("\nDifference between %d and %d is %d", a, b, subtract(a, b));
    printf("\nProduct of %d and %d is %d", a, b, multiply(a, b));
    // Checking for division by 0
    if (!b) {
        printf("\nCannot perform division by 0!");
    } else {
        printf("\nQuotient of %d and %d is %d", a, b, divide(a, b));
    }
    printf("\n");
}
