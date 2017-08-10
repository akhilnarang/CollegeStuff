#include<stdio.h>

main() {
    // Declaration of variables
    int num1, num2, sum;
    // Prompting users and accepting values
    printf("Enter 2 numbers\n");
    printf("num1: ");
    scanf("%d", &num1);
    printf("num2: ");
    scanf("%d", &num2);
    // Adding the numbers
    sum=num1+num2;
    // Displaying the output
    printf("Sum of %d and %d is %d\n", num1, num2, sum);
}
