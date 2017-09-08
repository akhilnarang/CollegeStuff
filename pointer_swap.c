#include <stdio.h>

/**
 * Program to accept and swap 2 integers using pointers
 */

// Method to swap 2 numbers using pointers
void swap(int *a, int *b)
{
    // Swapping a and b
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}

void main()
{
    // Declaring variables
    int a, b;
    // Prompting user and accepting 2 integers a and b
    printf("Enter 2 numbers.\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("\n");
    // Printing values before swap
    printf("Value of a is %d.\n", a);
    printf("Value of b is %d.\n", b);
    printf("\nSwapping!\n\n");
    // swap() function call
    swap(&a, &b);
    // Printing values after swap
    printf("Value of a is %d.\n", a);
    printf("Value of b is %d.\n", b);
}
