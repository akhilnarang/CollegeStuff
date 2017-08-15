#include <stdio.h>

/**
 * Program to display the greatest among 3 numbers
 */

int main () {
    // Declaration of variables
    int a,b,c;
    // Prompting user to enter numbers
    printf("Please enter values for 3 numbers\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);

    // Checking greatest of the numbers and printing accordingly
    if (a>b && a>c) {
        printf("a (%d) is greater than b (%d) and c (%d).\n", a, b, c);
    } else if (b>a && b>c) {
        printf("b (%d) is greater than a (%d) and c (%d).\n", b, a, c);
    } else if (c>a && c>b) {
        printf("c (%d) is greater than a (%d) and b (%d).\n", c, a, b);
    } else {
        printf("a (%d) is equal to b (%d) and c (%d).\n", a, b, c);
    }
}
