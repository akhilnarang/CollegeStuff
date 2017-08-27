#include<stdio.h>
#include<string.h>

main () {
    printf("\nEnter 2 strings(max 20 characters each): ");
    char s[20];
    scanf("%s", s);
    char str[20];
    scanf("%s", str);
    printf("\nInputted strings are %s, %s", s, str);
    printf("\nLength of strings are %lu, %lu", strlen(s), strlen(str));
    printf("\ns compared to str: %d", strcmp(s, str));
    strcat(s, str);
    printf("\nConcantenated s and str into s: %s", s);
    strcpy(str, s);
    printf("\nCopied s to str.\nstr: %s", str);
    printf("\n");
}
