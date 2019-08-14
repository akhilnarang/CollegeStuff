#include <stdio.h>
#include <stdlib.h>

/**
 * Program to accept details of student in a structure and display result
 */

void main() {
    // Declaring structure with name, roll number, marks in various subjects
    struct student {
        char name[30];
        int rollno;
        float pm;
        float mm;
        float bm;
        float im;
    };

    int i, n;
    // Prompting user, accepting number of students
    printf("\nEnter number of students: ");
    scanf("%d", &n);

    if (n < 1) {  // Exit on invalid input
        printf("\nThere must be at least 1 student!\n");
        exit(1);
    }

    // Declare an array of type student of size n
    struct student s[n];

    // Looping over all elements of the struct array
    for (i = 0; i < n; i++) {
        // Prompt the user, and input all the details of a student
        printf("\nStudent Number %d.\n", i + 1);
        printf("Enter name: ");
        scanf("%s", s[i].name);
        printf("Enter roll number: ");
        scanf("%d", &s[i].rollno);
        printf("Enter Physics marks: ");
        scanf("%f", &s[i].pm);
        printf("Enter Mathematics marks: ");
        scanf("%f", &s[i].mm);
        printf("Enter BEE Marks: ");
        scanf("%f", &s[i].bm);
        printf("Enter IEPD Marks: ");
        scanf("%f", &s[i].im);
    }

    // Printing details of the student, calculating and display total marks,
    // percentage, and rank
    for (i = 0; i < n; i++) {
        printf("\nStudent Number %d.\n", i + 1);
        float total = s[i].pm + s[i].mm + s[i].bm + s[i].im;
        float percent = total / 4;
        printf("\nName: %s\nRoll Number: %d\nTotal: %.2f/400\nPercent: %.2f\n",
               s[i].name, s[i].rollno, total, percent);
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
}
/*EXECUTION
fpllab@fpllab-OptiPlex-9020:~/Desktop/Akhil$ gcc ./struct_student.c
fpllab@fpllab-OptiPlex-9020:~/Desktop/Akhil$ ./a.out

Enter number of students: 2

Student Number 1.
Enter name: A
Enter roll number: 1
Enter Physics marks: 55
Enter Mathematics marks: 65
Enter BEE Marks: 75
Enter IEPD Marks: 85

Student Number 2.
Enter name: B
Enter roll number: 2
Enter Physics marks: 65
Enter Mathematics marks: 75
Enter BEE Marks: 85
Enter IEPD Marks: 95

Student Number 1.

Name: A
Roll Number: 1
Total: 280.00/400
Percent: 70.00
First class!

Student Number 2.

Name: B
Roll Number: 2
Total: 320.00/400
Percent: 80.00
Distinction!
*/
