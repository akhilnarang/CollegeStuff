#include <stdio.h>
#include <stdlib.h>
/**
 * Menu driven C program for a simple arithmetic calculator
 */

int main()
{
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
    // Print menu and accept input
    printf("Choose operation c:\n\t+ for addition,\n\t- for subtraction,\n\t* f");
    printf("or multiplication,\n\t/ for division, and\n\t%% for remainder\n");
    printf("c: ");
    scanf("%c%c", &c, &c);

    // Checking the input and performing the desired operation and displaying result
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
                exit(1); // Exit if you try to divide by 0
            } else {
                printf("The quotient of %d divided by %d is %d\n", a, b, a/b);
            }
            break;
        case '%':
            if (b==0) {
                printf("You can't divide by zero!\n");
                exit(1); // Exit if you try to divide by 0
            } else {
                printf("The remainder of %d divided by %d is %d\n", a, b, a%b);
            }
            break;
        default:
            printf("%c is not a valid input!\nRe-executing!", c);
            exit(1); // Exit on wrong input
    }

}
/* EXECUTION
fpllab@fpllab-OptiPlex-9020:~/Desktop/Akhil$ gcc ./Assignment4_111044_Calculator.c
fpllab@fpllab-OptiPlex-9020:~/Desktop/Akhil$ ./a.out


		BASIC CALCULATOR

Enter 2 numbers a and b!
a: 4
b: 5
Choose operation c:
	+ for addition,
	- for subtraction,
	* for multiplication,
	/ for division, and
	% for remainder
c: %
The remainder of 4 divided by 5 is 4
*/
