#include <stdio.h>

/**
 * Menu driven program to take in elements of a matrix in a DDA
 */

#define row 10
#define column 10

void accept(int a[row][column], int r, int c) {
    int i, j;
    printf("\nEnter elements of a:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("a[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void display(int a[row][column], int r, int c) {
    int i, j;
    printf("\nElements of a are:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("a[%d][%d] - %d\t", i + 1, j + 1, a[i][j]);
        }
        printf("\n");
    }
}

void compact_display(int comp[(row * column) + 1][3], int count) {
    for (int i = 0; i <= count; i++) {
        printf("c[%d][0] - %d\tc[%d][1] - %d\tc[%d][2] - %d\n", i, comp[i][0],
               i, comp[i][1], i, comp[i][2]);
    }
}

void transpose(int c[(row * column) + 1][3], int count) {
    int t[count][3], q = 0;
    t[0][0] = c[0][1];
    t[0][1] = c[0][0];
    t[0][2] = c[0][2];
    for (int i = 0; i < c[0][1]; i++) {
        for (int j = 1; j <= count; j++) {
            if (c[j][1] == i) {
                q++;
                t[q][0] = c[j][1];
                t[q][1] = c[j][0];
                t[q][2] = c[j][2];
            }
        }
    }
    printf("Displaying transpose!\n");
    compact_display(t, count);
}

void fast_transpose(int c[(row * column) + 1][3], int count) {
    int t[count][3], s[column], r[column], i, j, p;
    t[0][0] = c[0][1];
    t[0][1] = c[0][0];
    t[0][2] = c[0][2];
    for (i = 0; i < c[0][1]; i++) {
        s[i] = 0;
    }
    for (j = 1; j <= count; j++) {
        p = c[j][1];
        s[p]++;
    }
    r[0] = 1;
    for (i = 1; i < c[0][1]; i++) {
        r[i] = r[i - 1] + s[i - 1];
    }
    for (i = 1; i <= count; i++) {
        p = c[i][1];
        t[r[p]][0] = c[j][1];
        t[r[p]][1] = c[j][0];
        t[r[p]][2] = c[j][2];
        r[p]++;
    }
    printf("Displaying transpose!\n");
    compact_display(t, count);
}

void compact(int a[row][column], int r, int c) {
    int comp[(row * column) + 1][3];
    int i, j, count = 0;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (a[i][j] != 0) {
                count++;
                comp[count][0] = i;
                comp[count][1] = j;
                comp[count][2] = a[i][j];
            }
        }
    }
    comp[0][0] = r;
    comp[0][1] = c;
    comp[0][2] = count;
    compact_display(comp, count);
    fast_transpose(comp, count);
}

int main() {
    int a[row][column];
    int r, c;
    printf("Enter rows and columns (max 10 by 10)!\n");
    printf("rows: ");
    scanf("%d", &r);
    printf("columns: ");
    scanf("%d", &c);

    // Accepting values into array
    accept(a, r, c);

    // Display values from array
    display(a, r, c);

    printf("Computing and displaying compat matrix!\n");

    // Make compact matrix
    compact(a, r, c);
    return 0;
}
