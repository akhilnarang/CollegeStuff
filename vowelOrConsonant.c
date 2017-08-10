#include<stdio.h>

/**
 * Program to check whether given input is a vowel or a consonant
 */

main() {
    // Declaration of variables
    char c, n;
    // Prompting users to input
    printf("\nEnter a letter: ");
    scanf("%c",&c);

    // Converting to uppercase if its lowercase for simplicity
    if ((int)c>90) {
        n=(int)c-32;
    } else {
        n=c;
    }
    
    // Check for an invalid input
    if ((int)n<65 || (int)n>90) {
        printf("\nA letter please, not other characters!\n");
    } else {
        // Check whether its a vowel or not
        switch (n) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                printf("%c is a vowel!\n", c);
                break;
            default:
                printf("%c is a consonant!\n", c);
        }
    }
}