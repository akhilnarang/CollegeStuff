#include <stdio.h>

/**
  * Program to accept details of student in a structure and display result
  */
  
main()
{
    // Declaring struct
    struct student {
        char name[30];
        int rollno;
        float pm;
        float mm;
        float bm;
        float im;
    };
    
    int i,n;
    // Prompting user
    printf("\nEnter number of students: ");
    scanf("%d", &n);
    struct student s[n];
    // Looping over all elements of the struct array
    for (i=0;i<n;i++) {
        printf("\nStudent Number %d.\n", i+1);
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
    
    // Printing details of the student
    for (i=0;i<n;i++) {
        printf("\nStudent Number %d.\n", i+1);
        float total=s[i].pm+s[i].mm+s[i].bm+s[i].im;
        float percent=total/4;
        printf("\nName: %s\nRoll Number: %d\nTotal: %.2f/200\nPercent: %.2f\n", s[i].name, s[i].rollno, total, percent);
        if (percent>70) {
            printf("Distinction!\n");
        } else if (percent>60) {
            printf("First class!\n");
        } else if (percent>50) {
            printf("Second class!\n");
        } else if (percent>40) {
            printf("Pass!");
        } else {
            printf("Fail!");
        }
    }
}
