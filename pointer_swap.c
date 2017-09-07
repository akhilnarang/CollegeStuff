#include <stdio.h>

void swap(int *a, int *b)
{
    int c=*a;
    *a=*b;
    *b=c;    
}

void main()
{
    printf("Enter 2 numbers.\n");
    int a, b;
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("\nValue of a is %d.\nValue of b is %d.\n", a, b);
    printf("\n\nSwapping values!\n\n");
    swap(&a, &b);
    printf("\nValue of a is %d.\nValue of b is %d.\n", a, b);
}

