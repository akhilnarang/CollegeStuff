#include <stdio.h>

int main() {
    printf("Enter stuff: ");
    char c;
    while ( (c=getchar()) != EOF ) {
        printf ("The inputted character is: ");
        putchar(c);
        printf ("\n");
    }
}
