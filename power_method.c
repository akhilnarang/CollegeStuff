#include<stdio.h>

/**
 * Program to calculate power of a number calling a function recursively
 */

int power(int n, int p) {
    if (p==1) {
        return 1;
    } else {
        return n*power(n,p-1);
    }
}

void main(){
    int n, p;
    printf("\nEnter a positive integer n: ");
    scanf("%d", &n);
    printf("\nEnter a positive integer p: ");
    scanf("%d", &p);
    if (n<1) {
        printf("\nPlease follow instructions!\n");
    } else {
        printf("\n%d^%d is %d!\n", n, p, power(n,p));
    }
}
