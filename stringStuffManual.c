#include <stdio.h>

/**
 * Menu driven program to perform various string operations
 */

void main()
{
    // Declaring the variables
    char s1[20], s2[20];
    int c, i, j, k;
    printf("Enter values for strings!\n"); // Prompting the user and accepting input
    printf("s1: ");
    scanf("%s", s1);
    printf("s2: ");
    scanf("%s", s2);
    // Printing menu and taking in choice
    printf("Enter:\n0 to exit,\n1 for length,\n2 for compare,\n3 for copy, and\n4 for concatenation");
    printf("\nChoice: ");
    scanf("%d", &c);
    // Looping over the switch-case structure
    while(c!=0) {
        // Taking choice into switch-case structure
        switch (c) {
            case 1: // Determines and prints length of strings
                printf("\nChoice - Length");
                for(i=0;s1[i]!='\0';i++);
                printf("\nLength of s1 is %d", i);
                for(i=0;s2[i]!='\0';i++);
                printf("\nLength of s2 is %d", i);
            break;
                case 2: // Compares and tells us if strings are equal
                printf("\nChoice - Compare");
                for(i=0;s1[1]!='\0'&&s2[i]!='\0';i++) {
                    j=(int)s1[i]-(int)s2[i];
                    if (j==0) continue;
                    break;
                }
                if (j==0) printf("\ns1 and s2 are equal!");
                else printf("\ns1 compared to s2 - %d", j);
            break;
            case 3: // Copies 2nd string into 1st
                printf("\nChoice - Copy");
                printf("\nBefore copying -\n");
                printf("s1: %s\ns2: %s", s1, s2);
                for(i=0;s2[i]!='\0';i++) {
                    s1[i]=s2[i];
                }
                while(s1[i]!='\0') s1[i++]='\0';
                printf("\nAfter copying -\n");
                printf("s1: %s\ns2: %s", s1, s2);
            break;
            case 4: // Concantenates the 2 strings into a 3rd
                printf("\nChoice - Concatenation");
                printf("\ns1: %s\ns2: %s", s1, s2);
                char s3[41];
                i=0,j=0,k=0;
                while(s1[i]!='\0') {
                    s3[k++]=s1[i++];
                }
                while(s2[j]!='\0') {
                    s3[k++]=s2[j++];
                }
                printf("\ns3: %s", s3);
            break;
            default:
                printf("\nInvalid choice selected!");
        }
        // Printing menu and taking in choice
        printf("\n\nEnter:\n1 for length,\n2 for compare,\n3 for copy, and\n4 for concatenation");
        printf("\nChoice: ");
        scanf("%d", &c);
    }
    printf("\n");
}
