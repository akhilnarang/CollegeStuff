#include <stdio.h>

/**
 * Program to display fibonaci series upto a user provided limit
 */

void main()
{
    printf("\nEnter the limit you want for fibonacci series(at least 3): ");
    int i=3;
    int n;
    scanf("%d", &n);
    printf("\n");
    if (n<3) {
        printf("Please listen to instructions!");
    } else {
        int a=0,b=1,c=a+b;
        printf("Number\t1:\t%d\nNumber\t2:\t%d\n", a, b);
        for(;i<=n;i++,c=a+b,a=b,b=c) {
            printf("Number\t%d:\t%d\n", i, c);
        }
    }
    printf("\n");
}
