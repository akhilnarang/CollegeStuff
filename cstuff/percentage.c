#include <stdio.h>

/**
 * Program to display total marks and percentage and grade
 */

int main() {
    // Variables declaration
    int a, b, c, d, e, total;
    // Prompting user to enter marks
    printf("Enter five subjects marks\n");
    printf("Physics: ");
    scanf("%d", &a);
    printf("Chemistry: ");
    scanf("%d", &b);
    printf("Mathematics: ");
    scanf("%d", &c);
    printf("English: ");
    scanf("%d", &d);
    printf("Computers: ");
    scanf("%d", &e);
    // Adding marks
    total = a + b + c + d + e;
    printf("Total is %d/500!\n", total);
    // Calculating percentage
    double percent = total / 5;
    printf("Percentage is %.2f!\n", percent);
    // Checking and printing grade
    if (percent > 70) {
        printf("Distinction!\n");
    } else if (percent > 60) {
        printf("First class!\n");
    } else if (percent > 50) {
        printf("Second class!\n");
    } else if (percent > 40) {
        printf("Pass!");
    } else {
        printf("Fail!");
    }
}
