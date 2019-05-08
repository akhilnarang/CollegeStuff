#include <stdio.h>

#define MAX 20

void fifo(int f, int length, int s[MAX]) {
    int i, j, faults = 0, temp;
    int front = 0, rear = 0, frames[MAX];
    for (i = 0; i < f; i++) {
        frames[i] = -1;
    }

    for (i = 0; i < length; i++) {
        temp = 0;
        for (j = 0; j < f; j++) {
            if (frames[j] == s[i]) {
                temp = 1;
                break;
            }
        }
        if (temp) continue;

        frames[rear] = s[i];
        rear = (rear + 1) % f;
        for (j = 0; j < f; j++) {
            if (frames[j] == -1) {
                printf("--\t");
            } else {
                printf("%d\t", frames[j]);
            }
        }
        printf("\n");
        faults++;
    }
    printf("FIFO had %d page faults!\n", faults);
}

void lru(int f, int length, int s[MAX]) {
    int faults = 0, frames[MAX][2], i, j, temp;
    for (i = 0; i < f; i++) {
        frames[i][0] = -1;
        frames[i][1] = 0;
    }

    for (i = 0; i < length; i++) {
        temp = 0;
        for (j = 0; j < f; j++) {
            // If the page is already in one of the frames
            if (frames[j][0] == s[i]) {
                frames[j][1] = 0;  // Reset last referenced time
                temp = 1;
                break;
            }
        }
        if (temp) continue;  // No page fault here, nothing to do!
        temp = 1;
        for (j = 0; j < f; j++) {
            if (frames[j][0] == -1) {
                frames[j][0] = s[j];
                frames[j][1] = 0;
                temp = 0;
                break;
            }
        }
        if (temp) {
            for (j = 1; j < f; j++) {
                if (frames[j][1] > frames[temp][1]) {
                    temp = j;
                }
            }
            frames[temp][0] = s[i];
            frames[temp][1] = 0;
        }

        for (j = 0; j < length; j++) {
            frames[j][1]++;
        }
        for (j = 0; j < f; j++) {
            if (frames[j][0] == -1) {
                printf("--\t");
            } else {
                printf("%d\t", frames[j][0]);
            }
        }
        printf("\n");
        faults++;
    }
    printf("LRU had %d page faults!\n", faults);
}

int main() {
    int ch, frames, i, length, s[MAX];
    printf("Enter the number of frames!\n");
    printf("frames: ");
    scanf("%d", &frames);
    printf("Enter length of reference string!\n");
    printf("length: ");
    scanf("%d", &length);
    for (i = 0; i < length; i++) {
        printf("Enter page %d!\n", i + 1);
        printf("page: ");
        scanf("%d", &s[i]);
    }
    printf("Enter 1 for FIFO\n");
    printf("Enter 2 for LRU\n");
    printf("ch: ");
    scanf("%d", &ch);
    if (ch == 1) {
        fifo(frames, length, s);
    } else if (ch == 2) {
        lru(frames, length, s);
    } else {
        printf("Invalid input!\n");
    }
    return 0;
}