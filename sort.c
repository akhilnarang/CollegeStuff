/*
 * sort.c
 *
 *  Created on: 19-Nov-2018
 *      Author: Akhil
 */

#include <stdio.h>

typedef struct student {
    int roll;
    char name[25];
} student;

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

void display(student s[], int n) {
    int i;
    printf("Index\tName\tRoll Number\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%d\n", i, s[i].name, s[i].roll);
    }
}

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

void insertion_sort(student s[], int n) {
    int i, key, j;
    printf("Sorting the elements by roll number using insertion sort!\n");
    for (i = 1; i < n; i++) {
        key = s[i].roll;
        j = i - 1;

        while (j >= 0 && s[j].roll > key) {
            s[j + 1].roll = s[j].roll;
            j = j - 1;
        }
        s[j + 1].roll = key;
    }
}

void binary_search(student s[], int n, int key) {
    printf("Sorting data incase it is not sorted!\n");
    bubble_sort(s, n);
    display(s, n);
    int l = 0, r = n;
    while (l < r) {
        int p = (l + r) / 2;
        if (s[p].roll == key) {
            printf("Key %d found at index %d!\n", key, p);
            return;
        }
        if (s[p].roll > key) {
            r = p - 1;
        } else {
            l = p + 1;
        }
    }
    printf("Key %d not found!\n", key);
}

void linear_search(student s[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (s[i].roll == key) {
            printf("Key %d found at index %d!\n", key, i);
            return;
        }
    }
    printf("Key %d not found!\n", key);
}

int main() {
    int n, ch, key;
    printf("Enter number of students: ");
    scanf("%d", &n);
    student s[n];
    accept(s, n);
    display(s, n);
    do {
        printf(
            "Enter 1 for bubble sort, 2 for selection sort, 3 for insertion "
            "sort, 4 for binary search, 5 for linear "
            "search, 0 to exit!\n");
        printf("ch: ");
        scanf("%d", &ch);
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
                binary_search(s, n, key);
                break;
            case 5:
                printf("Enter value to search for!\n");
                printf("key: ");
                scanf("%d", &key);
                linear_search(s, n, key);
                break;
        }
    } while (ch != 0);
}
