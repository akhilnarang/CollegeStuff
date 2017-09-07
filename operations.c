#include<stdio.h>

/**
 * Program to accept 2 numbers and print the output of various mathematical operations performed on them
 */

void main(){
    // Declaration of variables
    int num1, num2, sum, difference, product, quotient;
    // Prompting users and accepting values
    printf("Enter 2 numbers\n");
    printf("num1: ");
    scanf("%d", &num1);
    printf("num2: ");
    scanf("%d", &num2);
    // Adding the numbers
    sum=num1+num2;
    // Subtracting the numbers
    difference=num1-num2;
    // Multiplying the numbers
    product=num1*num2;
    // Dividing the numbers
    quotient=num1/num2;
    // Displaying the output
    printf("Sum of %d and %d is %d\n", num1, num2, sum);
    printf("Difference between %d and %d is %d\n", num1, num2, difference);
    printf("Product of %d and %d is %d\n", num1, num2, product);
    printf("Quotient of %d and %d is %d\n", num1, num2, quotient);
}
