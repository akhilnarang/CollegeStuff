#include <stdio.h>

/**
 * Program to print the word of a given digit
 */

void main() {
    printf("Enter a digit between 0-9: ");  // Prompting the user
    int n;
    scanf("%d", &n);  // Accepting input
    int m = n;
    while (m > 0) {
        n = m % 10;
        m = m / 10;
        switch ((int)n) {  // Printing the result after checking
            case 0:
                printf("Zero ");
                break;
            case 1:
                printf("One ");
                break;
            case 2:
                printf("Two ");
                break;
            case 3:
                printf("Three ");
                break;
            case 4:
                printf("Four ");
                break;
            case 5:
                printf("Five ");
                break;
            case 6:
                printf("Six ");
                break;
            case 7:
                printf("Seven ");
                break;
            case 8:
                printf("Eight ");
                break;
            case 9:
                printf("Nine ");
                break;
        }
    }
    printf("\n");
}
