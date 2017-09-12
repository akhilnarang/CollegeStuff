#include <stdio.h>

/**
 * Program to perform some file operations
 */

void main()
{
    // Declaration of some variables and file pointers
    FILE *file1, *file2;
    char c;
    // Opening file-test-1 in write mode into file1
    file1=fopen("file-test-1", "w");
    printf("Writing some data to file-test-1!\n");
    // Writing some data to file1
    fprintf(file1, "\n%s %d %c %f\n", "Some data", 2, 'c', 1.5);
    // Closing file1
    fclose(file1);
    printf("Wrote the data to file-test-1! Printing it now!\n\n");  
    // Opening file-test-1 in read mode into file1
    file1=fopen("file-test-1", "r");
    // Loop over all the characters in file1 (until EOF) and print to the console
    while ((c=getc(file1))!=EOF) {
        printf("%c", c);
    }
    printf("\n");
    // Closing file1
    fclose(file1);
    printf("Copying data to file-test-2\n");
    // Opening file-test-1 in read mode into file1
    file1=fopen("file-test-1", "r");
    // Opening file-test-2 in write mode into file2
    file2=fopen("file-test-2", "w");
    // Loop over all the characters in file1 (until EOF) and print into file2
    while ((c=getc(file1))!=EOF) {
        fprintf(file2, "%c", c);
    }
    printf("Copied to file-test-2! Printing its contents now!\n");
    // Closing file2
    fclose(file2);
    // Opening file-test-2 in read mode into file2
    file2=fopen("file-test-2", "r");
    // Loop over all the characters in file2 (until EOF) and print to the console    
    while ((c=getc(file2))!=EOF) {
        printf("%c", c);
    }
    printf("\n");
    // Closing file2
    fclose(file2);
    // Closing file1
    fclose(file1);
}
