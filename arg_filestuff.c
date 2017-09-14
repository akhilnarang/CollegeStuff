#include <stdio.h>
#include <stdlib.h>

/**
 * Program to perform some file operations based on the filenames passed as parameters
 */

void main(int argc, char *argv[])
{

    // Check for number of parameters, exit if extra/less
    if (argc != 4) {
        printf("3 arguments are expected, not %d!\n", argc-1);
        exit(1);
    }

    // Declaration of some variables and file pointers
    FILE *file1, *file2;
    char c;
    // Opening argv[1] in write mode into file1
    file1=fopen(argv[1], "w");
    printf("Writing some data to %s!\n", argv[1]);
    // Writing some data to file1
    fprintf(file1, "%s", argv[3]);
    // Closing file1
    fclose(file1);
    printf("Wrote the data to %s! Printing it now!\n\n", argv[1]);
    // Opening argv[1] in read mode into file1
    file1=fopen(argv[1], "r");
    // Loop over all the characters in file1 (until EOF) and print to the console
    while ((c=getc(file1))!=EOF) {
        printf("%c", c);
    }
    printf("\n");
    // Closing file1
    fclose(file1);
    printf("Copying data to %s\n", argv[2]);
    // Opening argv[1] in read mode into file1
    file1=fopen(argv[1], "r");
    // Opening argv[2] in write mode into file2
    file2=fopen(argv[2], "w");
    // Loop over all the characters in file1 (until EOF) and print into file2
    while ((c=getc(file1))!=EOF) {
        fprintf(file2, "%c", c);
    }
    printf("Copied to %s! Printing its contents now!\n", argv[2]);
    // Closing file2
    fclose(file2);
    // Opening argv[2] in read mode into file2
    file2=fopen(argv[2], "r");
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
