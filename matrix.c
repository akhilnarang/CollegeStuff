#include <stdio.h>

/**
  * Menu driven program to take in elements of a matrix in a DDA and display sum and difference
  */

main() {

    int r,c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    int a[r][c], b[r][c], i, j, s;
    
    printf("\nEnter elements of a:\n");
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            printf("a[%d][%d]: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("\nEnter elements of b:\n");
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            printf("b[%d][%d]: ", i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    }

    
    printf("\nElements of a are:\n");
    
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            printf("a[%d][%d] - %d\t", i+1, j+1, a[i][j]);
        }
        printf("\n");
    }
    
    printf("\nElements of b are:\n");
    
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            printf("b[%d][%d] - %d\t", i+1, j+1, b[i][j]);
        }
        printf("\n");
    }
    
    do {
        printf("\n\nEnter 1 for addition, 2 for substraction, 0 to exit: ");
        scanf("%d", &s);
        switch (s) {
            case 1:
                printf("\nSum is:\n");
                    for(i=0;i<r;i++) {
                    for(j=0;j<c;j++) {
                        printf("sum[%d][%d] - %d\t", i+1, j+1, a[i][j]+b[i][j]);
                    }
                    printf("\n");
                }
            break;
            case 2:
                printf("\nDifference is:\n");
                for(i=0;i<r;i++) {
                    for(j=0;j<c;j++) {
                        printf("difference[%d][%d] - %d\t", i+1, j+1, a[i][j]-b[i][j]);
                    }
                    printf("\n");
                }
                    break;
            case 0: break;
            default:
                printf("\nWrong input!");
        }  
        printf("\n");
    } while(s!=0);
}
