#include <stdio.h>

/**
 * Menu driven program to display fibonaci series upto a user provided limit
 */

void main() {
    // Prompting the user
    printf("\nEnter 1 for limit to number of elements, 2 for actual limit: ");
    // Declaring some variables
    int m, n, i = 3;
    int a = 0, b = 1, c = a + b;
    // Accepting input from the user
    scanf("%d", &m);
    switch (m) {  // switch-case structure for the input given by the user
        case 1: {
            // Prompting the user
            printf(
                "\nEnter the limit you want for fibonacci series(at least "
                "3): ");
            // Accepting input
            scanf("%d", &n);
            printf("\n");
            if (n < 3) {  // Don't do anything if the user can't follow simple
                          // instructions
                printf("Please listen to instructions!");
            } else {  // Print the series!
                printf("Number\t1:\t%d\nNumber\t2:\t%d\n", a, b);
                for (; i <= n; i++, c = a + b, a = b, b = c) {
                    printf("Number\t%d:\t%d\n", i, c);
                }
            }
            printf("\n");
            break;
        }
        case 2: {
            // Prompting the user
            printf(
                "\nEnter the limit you want for fibonacci series(greater than "
                "1): ");
            // Accepting input
            scanf("%d", &n);
            printf("\n");
            if (n < 2) {  // Don't do anything if the user can't follow simple
                          // instructions
                printf("Please listen to instructions!");
            } else {  // Print the series!
                printf("Number\t1:\t%d\nNumber\t2:\t%d\n", a, b);
                for (; c <= n; i++, c = a + b, a = b, b = c) {
                    printf("Number\t%d:\t%d\n", i, c);
                }
            }
            printf("\n");
            break;
        }
    }
}
