#include <stdio.h>

#define MAX 5

typedef struct node {
    int at;
    int bt;
    int name;
    int wt;
    int tat;
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

void fcfs() {
    int i, current, total_wait, total_turnaround;
    float average_wait, average_turnaround;
    total_wait = total_turnaround = 0;
    current = process[0].at;
    printf("%d", current);
    for (i = 0; i < n; i++) {
        printf("<--P%d-->", process[i].name);
        current += process[i].bt;
        process[i].tat = current - process[i].at;
        process[i].wt = process[i].tat - process[i].bt;
        total_wait += process[i].wt;
        total_turnaround += process[i].tat;
        printf("%d", current);
        if (i < n - 1 && current < process[i + 1].at) {
            printf("<--IDLE-->");
            current = process[i + 1].at;
            printf("%d", current);
        }
    }
    printf("\n");
    average_wait = (float)total_wait / n;
    average_turnaround = (float)total_turnaround / n;
    printf("Average wait time is: %f!\n", average_wait);
    printf("Average turn around time is: %f!\n", average_turnaround);
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
    fcfs();
    display();
    return 0;
}