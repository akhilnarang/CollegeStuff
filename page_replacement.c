#include <stdio.h>

#define MAX 20

struct term {
    char bit;
    int count;
};

typedef struct term pterm;
pterm pagetable[MAX];
int buffer[MAX];

void init(int f) {
    int i;
    for (i = 0; i < f; i++) buffer[i] = -1;
    for (i = 0; i < MAX; i++) {
        pagetable[i].bit = 'I';
        pagetable[i].count = 0;
    }
}

void display_buff(int f) {
    int i = 0;
    for (i = 0; i < f; i++) {
        if (buffer[i] == -1)
            printf("--\t");
        else
            printf("%d\t", buffer[i]);
    }
}

void fifo(int f) {
    int pno, j = 0, front = 0, pgfault = 0, temp;

    printf("\nPress -1 any time to terminate!\n\n");
    while (1) {
        printf("\nEnter the page no. :  ");
        scanf("%d", &pno);
        if (pno < 0) {
            printf("Total no. of faults with FIFO = %d \n", pgfault);
            return;
        }

        if (pagetable[pno].bit == 'I') {
            if (j < f) {
                buffer[j] = pno;
                j++;
            } else {
                temp = buffer[front];
                buffer[front] = pno;
                pagetable[temp].bit = 'I';
                front = (front + 1) % f;
            }

            pgfault++;
            pagetable[pno].bit = 'V';
            display_buff(f);
            printf(" F\n");
        } else {
            display_buff(f);
            printf("\n");
        }
    }
}

void lru(int f) {
    int c = 1, min, index, temp, pno, j = 0, pgfault = 0;

    printf("\nPress -1 any time to terminate!\n\n");
    while (1) {
        printf("\nEnter the page no. :  ");
        scanf("%d", &pno);
        if (pno < 0) {
            printf("Total no. of faults with LRU = %d \n", pgfault);
            return;
        }
        pagetable[pno].count = c++;
        if (pagetable[pno].bit == 'I') {
            if (j < f) {
                buffer[j] = pno;
                j++;
            } else {
                min = 999;
                index = -1;
                for (j = 0; j < f; j++) {
                    temp = buffer[j];
                    if (pagetable[temp].count < min) {
                        min = pagetable[temp].count;
                        index = temp;
                    }
                }
            }
            pgfault++;
            pagetable[pno].bit = 'V';
            display_buff(f);
            printf(" F\n");
        } else {
            display_buff(f);
            printf("\n");
        }
    }
}

int main() {
    int nof, ch;
    printf("\n Enter the no. of frames :  ");
    scanf("%d", &nof);

    init(nof);
    printf("\n\n 1. FIFO\n 2. LRU\n Enter your Choice :   ");
    scanf("%d", &ch);
    if (ch == 1) {
        fifo(nof);
    } else if (ch == 2) {
        lru(nof);
    } else
        printf("\n\n Run again and Read Properly! \n\n");

    return 0;
}