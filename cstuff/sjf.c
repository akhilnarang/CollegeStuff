#include <stdio.h>

#define MAX 5

typedef struct node {
    int at;
    int bt;
    int name;
    int wt;
    int tat;
    int rt;
} node;

node process[MAX];
int n = MAX;

void read() {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter data for process %d!\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &process[i].at);
        printf("Burst Time: ");
        scanf("%d", &process[i].bt);
        process[i].name = i + 1;
    }
}

void sort() {
    int i, j;
    for (i = 0; i < n - i - 1; i++) {
        for (j = 0; j < i - 1; j++) {
            if (process[i].at > process[i + 1].at) {
                node t = process[i];
                process[i] = process[i + 1];
                process[i + 1] = t;
            }
        }
    }
}

void sjf() {
    int i, j, min, current, min_index, total_turnaround = 0, total_wait = 0;
    current = process[0].at;
    printf("%d", current);
    while (1) {
        min = 999;
        min_index = -1;
        i = 0;
        while (i < n && process[i].at <= current) {
            if (process[i].rt != 0 && process[i].rt < min) {
                min = process[i].rt;
                min_index = i;
            }
            i++;
        }

        if (i == n && min_index == -1) {
            break;
        } else if (i != n && min_index == -1) {
            printf("<--IDLE-->");
            current = process[i].at;
        } else if (i == n && min_index != -1) {
            j = min_index;
            printf("<--P%d-->", process[i].name);
            current += process[j].rt;
            process[j].rt = 0;
            process[j].tat = current - process[j].at;
            process[j].wt = process[j].tat - process[j].bt;
        } else {
            j = min_index;
            printf("<--P%d-->", process[j].name);
            current++;
            process[j].rt--;
            if (process[j].rt == 0) {
                process[j].tat = current - process[j].at;
                process[j].wt = process[j].tat - process[j].bt;
            }
        }
        printf("%d", current);
    }
}

void display() {
    int i;
    printf("Name\tat\tbt\twt\ttat\n");
    for (i = 0; i < n; i++) {
        node t = process[i];
        printf("%d\t%d\t%d\t%d\t%d\n", t.name, t.at, t.bt, t.wt, t.tat);
    }
}

int main() {
    read();
    sort();
    sjf();
    display();
    return 0;
}
