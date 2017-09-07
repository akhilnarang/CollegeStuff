#include <stdio.h>

/**
 * Menu driven program to display fibonaci series upto a user provided limit
 */

void main()
{
    printf("\nEnter 1 for limit to number of elements, 2 for actual limit: ");
    int m, n, i=3;
    int a=0,b=1,c=a+b;
    scanf("%d", &m);
    switch (m) {
        case 1: {
            printf("\nEnter the limit you want for fibonacci series(at least 3): ");
            scanf("%d", &n);
            printf("\n");
            if (n<3) {
                printf("Please listen to instructions!");
            } else {
                printf("Number\t1:\t%d\nNumber\t2:\t%d\n", a, b);
                for(;i<=n;i++,c=a+b,a=b,b=c) {
                    printf("Number\t%d:\t%d\n", i, c);
                }
            }
            printf("\n");
            break;
        } case 2: {
            printf("\nEnter the limit you want for fibonacci series(greater than 1): ");
            scanf("%d", &n);
            printf("\n");
            if (n<2) {
                printf("Please listen to instructions!");
            } else {
                printf("Number\t1:\t%d\nNumber\t2:\t%d\n", a, b);
                for(;c<=n;i++,c=a+b,a=b,b=c) {
                    printf("Number\t%d:\t%d\n", i, c);
                }
            }
            printf("\n");
            break;
        }
    }
}
