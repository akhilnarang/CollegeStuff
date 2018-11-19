#include <stdio.h>

/**
 * Program to take in elements of a matrix in a DDA and display the product
 * DOES NOT WORK :D
 */

void main() {
    int ra, ca, rb, cb;
    printf("Enter the number of rows of a: ");
    scanf("%d", &ra);
    printf("Enter the number of columns of a: ");
    scanf("%d", &ca);
    int a[ra][ca];
    printf("Enter the number of rows of b: ");
    scanf("%d", &rb);
    printf("Enter the number of columns of b: ");
    scanf("%d", &cb);
    int b[rb][cb];
    int p[ra][cb];
    if (ca != rb) {
        printf("\nColumns of a should be equal to rows of b!");
    } else {
        int i, j, k;

        printf("\nEnter elements of a:\n");
        for (i = 0; i < ra; i++) {
            for (j = 0; j < ca; j++) {
                printf("a[%d][%d]: ", i + 1, j + 1);
                scanf("%d", &a[i][j]);
            }
        }

        printf("\nEnter elements of b:\n");
        for (i = 0; i < rb; i++) {
            for (j = 0; j < cb; j++) {
                printf("b[%d][%d]: ", i + 1, j + 1);
                scanf("%d", &b[i][j]);
            }
        }

        printf("\nElements of a are:\n");

        for (i = 0; i < ra; i++) {
            for (j = 0; j < ca; j++) {
                printf("a[%d][%d] - %d\t", i + 1, j + 1, a[i][j]);
            }
            printf("\n");
        }

        printf("\nElements of b are:\n");
        for (i = 0; i < rb; i++) {
            for (j = 0; j < cb; j++) {
                printf("b[%d][%d] - %d\t", i + 1, j + 1, b[i][j]);
            }
            printf("\n");
        }

        printf("\nProduct is:\n");
        int t;
        for (i = 0; i < ra; i++) {
            for (j = 0; j < cb; j++) {
                for (k = 0; k < rb; k++) {
                    t += a[k][j] * b[j][k];
                }
                printf("product[%d][%d] - %d\t", i + 1, j + 1, t);
                t = 0;
            }
            printf("\n");
        }
    }
    printf("\n");
}
