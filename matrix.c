#include <stdio.h>

/**
 * Menu driven program to take in elements of a matrix in a DDA 
 */

#define row 3   
#define column 3

void accept(int a[row][column]) {
    int i, j;
    printf("\nEnter elements of a:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("a[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void display(int a[row][column]) {
    int i, j;
    printf("\nElements of a are:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("a[%d][%d] - %d\t", i + 1, j + 1, a[i][j]);
        }
        printf("\n");
    }
}

void compact(int a[row][column], int c[row][3]) {
    int i, j, count = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            if (a[i][j] != 0) {
                count++;
                c[count][0] = i;
                c[count][1] = j;
                c[count][2] = a[i][j];                
            }
        }
    }
    c[0][0] = row;
    c[0][1] = column;
    c[0][2] = count;
    for (i = 0;i <= count;i++) {
        for (j = 0;j < 3;j++) {
            printf("c[%d][%d] - %d\t", i + 1, j + 1, c[i][j]);
        }
        printf("\n");
    }    
}

int main() {
    int a[row][column];
    int c[(row*column)+1][3];

    // Accepting values into array
    accept(a);

    // Display values from array
    display(a);
    
    printf("Computing and displaying compat matrix!\n");
    
    // Make compact matrix
    compact(a, c);
    return 0;
 }
