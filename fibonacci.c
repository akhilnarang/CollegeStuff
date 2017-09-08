#include <stdio.h>

/**
 * Program to display fibonaci series upto a user provided limit
 */
 
void main()
{
    // Prompting the user
    printf("\nEnter the limit you want for fibonacci series(at least 3): ");
    // Declaring variables
    int i=3;
    int n;
    // Accepting input
    scanf("%d", &n);
    printf("\n");
    if (n<3) { // Don't do anything if the user can't follow simple instructions
        printf("Please listen to instructions!");
    } else {
        // Print the series!
        int a=0,b=1,c=a+b;
        printf("Number\t1:\t%d\nNumber\t2:\t%d\n", a, b);
        for(;i<=n;i++,c=a+b,a=b,b=c) {
            printf("Number\t%d:\t%d\n", i, c);
        }
    }
    printf("\n");
}
