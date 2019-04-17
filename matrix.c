
#include <stdio.h>

#define max 10

void sparse_to_compact(int sparse[max][max], int compact[max * max + 1][3],
                       int row, int col) {
    int a = 1;
    compact[0][0] = row;  // Converting Sparse to Compact
    compact[0][1] = col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (sparse[i][j] != 0) {
                compact[a][0] = i;
                compact[a][1] = j;
                compact[a][2] = sparse[i][j];
                a++;
            }
        }
    }
    compact[0][2] = a - 1;

    printf("\n Original Sparse Matrix :- \n");
    for (int i = 0; i < row; i++) {
        printf("\n");
        for (int j = 0; j < col; j++) {
            printf("%d\t", sparse[i][j]);
        }
    }

    printf("\n\n Compact matrix :- \n");
    for (int i = 0; i < a; i++) {
        printf("\n ");
        for (int j = 0; j < 3; j++) {
            printf("%d\t", compact[i][j]);
        }
    }
}

void accept(int mat[max][max], int rows, int cols)  // Accepting Sparse Matrix
{
    printf("\n Enter the elements of matrix");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("\n Enter the element [%d][%d] :- ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\n Your entered Sparse Matrix :- \n");
    for (int i = 0; i < rows; i++) {
        printf("\n");
        for (int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
    }
}

void fast_transpose(int mat1[max * max + 1][3], int mat2[max * max + 1][3]) {
    int m = mat1[0][0];
    int n = mat1[0][1];  // Fast Transpose
    int t = mat1[0][2];

    mat2[0][0] = n;
    mat2[0][1] = m;
    mat2[0][2] = t;

    int temp1[t];

    int p, z;

    for (int i = 0; i < t; i++) {
        temp1[i] = 0;
    }

    for (int i = 1; i < t; i++) {
        p = mat1[i][1];  // Storing number of elements for each column
        temp1[p]++;
    }

    int temp2[t];

    temp2[0] = 1;
    for (int i = 1; i <= t; i++) {
        temp2[i] = temp2[i - 1] +
                   temp1[i - 1];  // Storing Location for element et column
    }

    for (int i = 1; i <= t; i++) {
        p = mat1[i][1];
        z = temp2[p];
        mat2[z][0] = mat1[i][1];
        mat2[z][1] = mat1[i][0];
        mat2[z][2] = mat1[i][2];
        temp2[p]++;
    }

    p = mat1[0][2] + 1;

    printf("\n\n Original Compact matrix :- \n");
    for (int i = 0; i < p; i++) {
        printf("\n");
        for (int j = 0; j < 3; j++) {
            printf("%d\t", mat1[i][j]);
        }
    }

    printf("\n\n Fast Transposed Compact matrix :- \n");
    for (int i = 0; i < p; i++) {
        printf(" \n");
        for (int j = 0; j < 3; j++) {
            printf("%d\t", mat2[i][j]);
        }
    }
}

void simple_transpose(int mat1[max * max + 1][3], int mat2[max * max + 1][3]) {
    mat2[0][0] = mat1[0][1];
    mat2[0][1] = mat1[0][0];  // Simple Transpose
    mat2[0][2] = mat1[0][2];

    int q = 1;

    for (int i = 0; i < mat1[0][1]; i++) {
        for (int j = 1; j <= mat1[0][2]; j++) {
            if (i == mat1[j][1]) {
                mat2[q][0] = mat1[j][1];
                mat2[q][1] = mat1[j][0];
                mat2[q][2] = mat1[j][2];
                q++;
            }
        }
    }

    q = mat1[0][2] + 1;

    printf("\n\n Original Compact matrix :- \n");
    for (int i = 0; i < q; i++) {
        printf("\n");
        for (int j = 0; j < 3; j++) {
            printf("%d\t", mat1[i][j]);
        }
    }

    printf("\n\n Simple Transposed Compact matrix :- \n");
    for (int i = 0; i < q; i++) {
        printf(" \n");
        for (int j = 0; j < 3; j++) {
            printf("%d\t", mat2[i][j]);
        }
    }
}

int main() {
    int sparse_matrix[max][max];
    int compact_matrix1[max * max + 1][3];
    int compact_matrix2[max * max + 1][3];  // Declaring required matrices
    int rows, columns;

    int ch, flg;

    printf("\n Enter the number of ROWs in matrix :  ");
    scanf("%d", &rows);
    printf("\n Enter the number of COLUMNs in matrix :  ");
    scanf("%d", &columns);

    accept(sparse_matrix, rows, columns);

    do {
        flg = 1;

        printf("\n\n\n **********  MENU  **********\n\n");
        printf(" 1. Accept a new Sparse Matrix \n");  // Printing Menu for
                                                      // Sparse Operations
        printf(" 2. Convert to Compact form \n");
        printf(" 3. Simple Transpose of Compact \n");
        printf(" 4. Fast Transpose of Compact \n");
        printf(" 5. Exit \n");

        printf("\n Please enter your choice :  ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n Enter the number of ROWs in matrix :  ");
                scanf("%d", &rows);
                printf("\n Enter the number of COLUMNs in matrix :  ");
                scanf("%d", &columns);

                accept(sparse_matrix, rows, columns);
                break;

            case 2:
                sparse_to_compact(sparse_matrix, compact_matrix1, rows,
                                  columns);
                break;

            case 3:
                simple_transpose(compact_matrix1, compact_matrix2);
                break;

            case 4:
                fast_transpose(compact_matrix1, compact_matrix2);
                break;

            case 5:
                flg = 0;
                break;

            default:
                printf("\n\n Invalid Choice! Please try Again! \n\n\n");
                break;
        }
    } while (flg != 0);

    printf("\n\n You Have Exited the Program !");
    return 0;
}

/*

 OUTPUT :-




 Enter the number of ROWs in matrix :  3

 Enter the number of COLUMNs in matrix :  3

 Enter the elements of matrix
 Enter the element [0][0] :- 3

 Enter the element [0][1] :- 6

 Enter the element [0][2] :- 8

 Enter the element [1][0] :- 0

 Enter the element [1][1] :- 6

 Enter the element [1][2] :- 3

 Enter the element [2][0] :- 8

 Enter the element [2][1] :- 9

 Enter the element [2][2] :- 0

 Your entered Sparse Matrix :-

3	6	8
0	6	3
8	9	0


 **********  MENU  **********

 1. Accept a new Sparse Matrix
 2. Convert to Compact form
 3. Simple Transpose of Compact
 4. Fast Transpose of Compact
 5. Exit

 Please enter your choice :  1

 Enter the number of ROWs in matrix :  3

 Enter the number of COLUMNs in matrix :  3

 Enter the elements of matrix
 Enter the element [0][0] :- 3

 Enter the element [0][1] :- 0

 Enter the element [0][2] :- 2

 Enter the element [1][0] :- 0

 Enter the element [1][1] :- 9

 Enter the element [1][2] :- 0

 Enter the element [2][0] :- 0

 Enter the element [2][1] :- 0

 Enter the element [2][2] :- 4

 Your entered Sparse Matrix :-

3	0	2
0	9	0
0	0	4


 **********  MENU  **********

 1. Accept a new Sparse Matrix
 2. Convert to Compact form
 3. Simple Transpose of Compact
 4. Fast Transpose of Compact
 5. Exit

 Please enter your choice :  2

 Original Sparse Matrix :-

3	0	2
0	9	0
0	0	4

 Compact matrix :-

 3	3	4
 0	0	3
 0	2	2
 1	1	9
 2	2	4


 **********  MENU  **********

 1. Accept a new Sparse Matrix
 2. Convert to Compact form
 3. Simple Transpose of Compact
 4. Fast Transpose of Compact
 5. Exit

 Please enter your choice :  3


 Original Compact matrix :-

3	3	4
0	0	3
0	2	2
1	1	9
2	2	4

 Simple Transposed Compact matrix :-

3	3	4
0	0	3
1	1	9
2	0	2
2	2	4


 **********  MENU  **********

 1. Accept a new Sparse Matrix
 2. Convert to Compact form
 3. Simple Transpose of Compact
 4. Fast Transpose of Compact
 5. Exit

 Please enter your choice :  4


 Original Compact matrix :-

3	3	4
0	0	3
0	2	2
1	1	9
2	2	4

 Fast Transposed Compact matrix :-

3	3	4
0	0	3
1	1	9
2	0	2
2	2	4


 **********  MENU  **********

 1. Accept a new Sparse Matrix
 2. Convert to Compact form
 3. Simple Transpose of Compact
 4. Fast Transpose of Compact
 5. Exit

 Please enter your choice : 5


 You Have Exited the Program !




 */
