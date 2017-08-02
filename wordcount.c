#include <stdio.h>

int main() {
    int wc=0, lc=0, cc=0;
    char c;
    printf("Enter some stuff!\n");
    while ((c=getchar()) != EOF) {
        if (c==' ' || c=='\n') {
            wc++;
        }
        if (c=='\n') {
            lc++;
        }
        cc++;
    }
    printf("The given input has %d characters, %d words, and %d lines.\n", cc, wc, lc);
}
