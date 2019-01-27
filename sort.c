/*
 * sort.c
 *
 *  Created on: 19-Nov-2018
 *      Author: Akhil
 */

#include <stdio.h> // Header for standard input/output operations

#define MAX_STUDENTS 5 // Defining size of our array

// Defining a student structure consisting the details we need
typedef struct student {
    int roll;
    char name[25];
} student;

// Function to accept n elements into our student array s
void accept(student s[], int n) {
    int i;
    printf("Enter details of students!\n");
    for (i = 0; i < n; i++) {
        printf("Student %d\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Roll Number: ");
        scanf("%d", &s[i].roll);
    }
}

// Display n elements of our student structure s
void display(student s[], int n) {
    int i;
    printf("Index\tName\tRoll Number\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%d\n", i, s[i].name, s[i].roll);
    }
}

// Sort the elements with roll number using bubble sort
void bubble_sort(student s[], int n) {
    int i, j;
    printf("Sorting the elements by roll number using bubble sort!\n");
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].roll > s[j + 1].roll) {
                s[j].roll += s[j + 1].roll;
                s[j + 1].roll = s[j].roll - s[j + 1].roll;
                s[j].roll -= s[j + 1].roll;
            }
        }
    }
}

// Sort the elements with roll number using selection sort
void selection_sort(student s[], int n) {
    int i, j, pos;
    printf("Sorting the elements by roll number using selection sort!\n");
    for (i = 0; i < n - 2; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (s[j].roll < s[pos].roll) {
                pos = j;
            }
        }
        if (pos != i) {
            s[i].roll += s[pos].roll;
            s[pos].roll = s[i].roll - s[pos].roll;
            s[i].roll -= s[pos].roll;
        }
    }
}

// Sort the elements with roll number using insertion sort
void insertion_sort(student s[], int n) {
    int i, key, j;
    printf("Sorting the elements by roll number using insertion sort!\n");
    for (i = 1; i < n; i++) {
        key = s[i].roll;
        j = i - 1;

        while (j >= 0 && s[j].roll > key) {
            s[j + 1].roll = s[j].roll;
            j--;
        }
        s[j + 1].roll = key;
    }
}

// Search for an element in s using linear search
void linear_search(student s[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (s[i].roll == key) {
            printf("Key %d found at index %d!\n", key, i);
            return; // Break out the moment key is found
        }
    }
    printf("Key %d not found!\n", key);
}

// Search for an element in s using binary search
void binary_search(student s[], int n, int key) {
    // Binary search requires sorted data
    printf("Sorting data incase it is not sorted!\n");
    bubble_sort(s, n);
    display(s, n);
    int l = 0, r = n;
    while (l <= r) {
        int p = (l + r) / 2;
        if (s[p].roll == key) {
            printf("Key %d found at index %d!\n", key, p);
            return; // Break out the moment key is found
        }
        if (s[p].roll > key) {
            r = p - 1;
        } else {
            l = p + 1;
        }
    }
    printf("Key %d not found!\n", key);
}

int main() {
    // Declare our variables for choices, key, size
    int n = MAX_STUDENTS, ch, key;
    student s[n]; // Define an array of student
    accept(s, n);
    display(s, n);
    // Do while loop for user to choose action
    do {
        // Prompt user and accept choice
        printf(
            "Enter 1 for bubble sort, 2 for selection sort, 3 for insertion "
            "sort, 4 for linear search, 5 for binary "
            "search, 0 to exit!\n");
        printf("ch: ");
        scanf("%d", &ch);
        // Check users choice using switch-case
        switch (ch) {
            case 1:
                bubble_sort(s, n);
                printf("Sorted elements are:\n");
                display(s, n);
                break;
            case 2:
                selection_sort(s, n);
                printf("Sorted elements are:\n");
                display(s, n);
                break;
            case 3:
                insertion_sort(s, n);
                printf("Sorted elements are:\n");
                display(s, n);
                break;
            case 4:
                printf("Enter value to search for!\n");
                printf("key: ");
                scanf("%d", &key);
                linear_search(s, n, key);
                break;
            case 5:
                printf("Enter value to search for!\n");
                printf("key: ");
                scanf("%d", &key);
                binary_search(s, n, key);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
      // Exit on 0
    } while (ch != 0);
}

 /* OUTPUT
 Enter details of students!
Student 1
Name: name1
Roll Number: 5
Student 2
Name: name2
Roll Number: 6
Student 3
Name: name3
Roll Number: 1
Student 4
Name: name4
Roll Number: 4
Student 5
Name: name5
Roll Number: 3
Index	Name	Roll Number
0	name1	5
1	name2	6
2	name3	1
3	name4	4
4	name5	3
Enter 1 for bubble sort, 2 for selection sort, 3 for insertion sort, 4 for binary search, 5 for linear search, 0 to exit!
ch: 5
Enter value to search for!
key: 3
Key 3 found at index 4!
Enter 1 for bubble sort, 2 for selection sort, 3 for insertion sort, 4 for binary search, 5 for linear search, 0 to exit!
ch: 3
Sorting the elements by roll number using insertion sort!
Sorted elements are:
Index	Name	Roll Number
0	name1	1
1	name2	3
2	name3	4
3	name4	5
4	name5	6
Enter 1 for bubble sort, 2 for selection sort, 3 for insertion sort, 4 for binary search, 5 for linear search, 0 to exit!
ch: 4
Enter value to search for!
key: 4
Sorting data incase it is not sorted!
Sorting the elements by roll number using bubble sort!
Index	Name	Roll Number
0	name1	1
1	name2	3
2	name3	4
3	name4	5
4	name5	6
Key 4 found at index 2!
Enter 1 for bubble sort, 2 for selection sort, 3 for insertion sort, 4 for binary search, 5 for linear search, 0 to exit!
ch: 0
*/
