#include<stdio.h>
#include<string.h>

/**
 * Program to take 2 strings from the user and print the output of various string functions on them
 */

void main()
{
    // Prompting user, declaring 2 strings, accepting input
    printf("\nEnter 2 strings(max 20 characters each)!\n");
    char s[20];
    printf("String 1: ");
    scanf("%s", s);
    char str[20];
    printf("String 2: ");
    scanf("%s", str);
    // Display input
    printf("\nInputted strings are %s, %s", s, str);
    // Display length using strlen()
    printf("\nLength of strings are %lu, %lu", strlen(s), strlen(str));
    // Display difference using strcmp()
    printf("\ns compared to str: %d", strcmp(s, str));
    // Concatenate and display using strcat()
    strcat(s, str);
    printf("\nConcantenated s and str into s: %s", s);
    // Copy and display using strcpy()
    strcpy(str, s);
    printf("\nCopied s to str.\nstr: %s", str);
    printf("\n");
}

/*EXECUTION
fpllab@fpllab-OptiPlex-9020:~/Desktop/Akhil$ gcc ./stringStuff.c
fpllab@fpllab-OptiPlex-9020:~/Desktop/Akhil$ ./a.out

Enter 2 strings(max 20 characters each)!
String 1: hello
String 2: world

Inputted strings are hello, world
Length of strings are 5, 5
s compared to str: -15
Concantenated s and str into s: helloworld
Copied s to str.
str: helloworld
*/
