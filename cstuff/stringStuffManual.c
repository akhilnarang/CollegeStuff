#include <stdio.h>   // Header for standard input/output
#include <stdlib.h>  // Header for standard libraries

/**
 * Menu driven program to perform various string operations
 */

// Method to accept a string
void accept(char* s) {
    printf("Enter string: ");
    scanf("%s", s);
}

// Method to display a string
void display(char* s) { puts(s); }

// Method to return the length of a string
int length(char* s) {
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;  // Loop till null character - i.e. end of string
    return i;
}

// Method to copy the contents of one string into another
void copy(char* s) {
    int i;
    char s1[256];
    for (i = 0; s[i] != '\0'; i++) {
        s1[i] = s[i];
    }
    printf("s1: %s\n", s1);
}

// Method to concatenate 2 strings
void concat(char* s1) {
    char s2[256], s3[256];
    int i, l = length(s1);
    printf("Enter second string!\ns2: ");
    scanf("%s", s2);
    for (i = 0; s1[i] != '\0'; i++) {
        s3[i] = s1[i];
    }
    while (s2[i - l] != '\0') {
        s3[i] = s2[i - l];
        i++;
    }
    printf("s3: %s\n", s3);
}

char* reverse(char s[]) {
    int i = length(s);
    char c[i];
    int j = 0;
    while (i-- > 0) {
        c[j++] = s[i];
    }
    c[j] = '\0';
    char* ch = c;
    return ch;
}

int equal(char s[], char c[]) {
    int i, j = 0;
    for (i = 0; s[i] != '\0' || c[i] != '\0'; i++) {
        j = (int)s[i] - (int)c[i];
        if (j) break;
    }
    return j;
}

int palin(char* s) { return equal(s, reverse(s)); }

void substring(char s[], char c[]) {
    int count = 0, i, j, k, n;
    char str[length(c)];
    for (i = 0; i < length(s) - length(c) + 1; i++) {
        for (j = 0; j < length(c); j++) {
            str[j] = s[i + j];
        }
        for (k = 0; c[k] != '\0'; k++) {
            n = (int)c[k] - (int)str[k];
            if (n) break;
        }
        if (n == 0) count++;
    }
    printf("Count: %d\n", count);
}

int main() {
    int ch;
    char s[256], c[256];
    do {
        printf("1 to accept, 2 to display, 3 for length, 4 to copy string, ");
        printf("5 to concatenate, 6 to reverse, 7 to check equality,\n");
        printf("8 to check palindrome, 9 for substring, and 0 to exit!\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                accept(s);
                break;
            case 2:
                display(s);
                break;
            case 3:
                printf("Length of string is %d!\n", length(s));
                break;
            case 4:
                printf("Copying string s (%s) into s1!\n", s);
                copy(s);
                break;
            case 5:
                printf("s1: %s\n", s);
                concat(s);
                break;
            case 6:
                printf("s1: %s\n", s);
                printf("Reverse: %s\n", reverse(s));
                break;
            case 7:
                printf("Enter another string!\nc: ");
                scanf("%s", c);
                int n = equal(s, c);
                if (!n)
                    printf("s and c are equal!\n");
                else
                    printf("s compared to c: %d!\n", n);
                break;
            case 8:
                printf("%s is ", s);
                int r = palin(s);
                if (!r) {
                    printf("a");
                } else {
                    printf("not a");
                }
                printf(" palindrome!\n");
                break;
            case 9:
                printf("Enter substring you want to search for: ");
                scanf("%s", c);
                substring(s, c);
                break;
            case 0:
                printf("Exiting!");
                exit(0);
                break;
            default:
                printf("Invalid input!\n");
        }
    } while (ch != 0);
    return 0;
}
