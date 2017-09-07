#include <stdio.h>

/**
 * Program to print an inputted character (for no real reason)
 */

int main() {
    printf("Enter stuff: ");
    char c;
    while ( (c=getchar()) != EOF ) {
        printf ("The inputted character is: ");
        putchar(c);
        printf ("\n");
    }
}
