#include <stdio.h>
#include <stdlib.h>

/**
 * Program to copy the contents of one file into another
 * The filenames are taken as command line arguments
 */

void main(int argc, char* argv[]) {
    // Check the arguments
    if (argc != 3) {
        printf("Exactly 2 arguments are required!\n");
        printf("Syntax :-\n\n%s <source file> <destination file>\n\n", argv[0]);
        exit(1);
    }

    // Declaration of some variables and file pointers
    FILE *file1, *file2;
    char c;

    // Opening argv[1] in read mode into file1
    file1 = fopen(argv[1], "r");

    // Check if argv[1] exists, if the file pointer is null it dosen't, exit.
    if (file1 == NULL) {
        printf("Source file %s dosen't exist!\n", argv[1]);
        exit(1);
    }

    printf("Printing data from %s!\n\n", argv[1]);
    // Loop over all the characters in file1 (until EOF) and print to the
    // console
    while ((c = getc(file1)) != EOF) {
        printf("%c", c);
    }
    printf("\n");
    // Closing file1
    fclose(file1);
    printf("Copying data from %s to %s\n", argv[1], argv[2]);
    // Opening argv[1] in read mode into file1
    file1 = fopen(argv[1], "r");
    // Opening argv[2] in write mode into file2
    file2 = fopen(argv[2], "w");
    // Loop over all the characters in file1 (until EOF) and print into file2
    while ((c = getc(file1)) != EOF) {
        fprintf(file2, "%c", c);
    }
    printf("Copied to %s! Printing its contents now!\n", argv[2]);
    // Closing file2
    fclose(file2);
    // Opening argv[2] in read mode into file2
    file2 = fopen(argv[2], "r");
    // Loop over all the characters in file2 (until EOF) and print to the
    // console
    while ((c = getc(file2)) != EOF) {
        printf("%c", c);
    }
    printf("\n");
    // Closing file2
    fclose(file2);
    // Closing file1
    fclose(file1);
}

/* EXECUTION
fpllab@fpllab-OptiPlex-9020:~$ gcc ./arg_filestuff.c
fpllab@fpllab-OptiPlex-9020:~$ ./a.out
Exactly 2 arguments are required!
Syntax :-

./a.out <source file> <destination file>

fpllab@fpllab-OptiPlex-9020:~$ ./a.out testfile testfile1
Source file testfile dosen't exist!
fpllab@fpllab-OptiPlex-9020:~$ ./a.out testfile1 testfile2
Printing data from testfile1!

some data

Copying data from testfile1 to testfile2
Copied to testfile2! Printing its contents now!
some data
*/
