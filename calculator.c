#include <stdio.h>

/** 
 * Menu driven C program for a simple arithmetic calculator
*/

main() {
    // Declaration of variables
    int a,b;
    char c;
    // Prompting and accepting values
    printf("\n\t\tBASIC CALCULATOR\n");
    printf("\nEnter 2 numbers a and b!\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("Choose operation c:\n\t+ for addition,\n\t- for subtraction,\n\t* f"); 
    printf("or multiplication,\n\t/ for division, and\n\t%% for remainder\n");
    printf("c: ");
    scanf("%c%c", &c, &c);

    // Checking the input and performing the desired operation
    switch(c) {
        case '+':
            printf("The sum of %d and %d is %d\n", a, b, a+b);
            break;
        case '-':
            printf("The difference between %d and %d is %d\n", a, b, a-b);
            break;
        case '*':
            printf("The product of %d and %d is %d\n", a, b, a*b);
            break;
        case '/':
            if (b==0) {
                printf("You can't divide by zero!\n");
                main(); // Re-executing program if input is wrong
            } else {
                printf("The quotient of %d divided by %d is %d\n", a, b, a/b);
            }
            break;
        case '%':
            if (b==0) {
                printf("You can't divide by zero!\n");
                main(); // Re-executing program if input is wrong
            } else {
                printf("The remainder of %d divided by %d is %d\n", a, b, a%b);
            }
            break;
        default:
            printf("%c is not a valid input!\nRe-executing!", c);
            main(); // Re-executing program if input is wrong
    }

}
