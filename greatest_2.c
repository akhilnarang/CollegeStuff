#include <stdio.h>

/**
 * Program to display the greatest among 2 numbers
 */

int main () {
    // Variables declaration
    int a,b;
    // Prompting user to enter numbers
    printf("Please enter values for 2 numbers\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    // Checking which number is greater and printing 
    if (a>b) {
        printf("a (%d) is greater than b (%d).\n", a, b);
    } else if (b>a) {
        printf("b (%d) is greater than a (%d).\n", b, a);
    } else {
        printf("a (%d) is equal to b (%d).\n", a, b);
    }
}
