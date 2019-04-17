#include <stdio.h>

struct process {
    int name;
    int at;
    int bt;
    int wt;
    int tat;
    int rt;
} p[10];

void accept(int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter process name\n");
        scanf("%d", &p[i].name);
        printf("Enter arrival time\n");
        scanf("%d", &p[i].at);
        printf("Enter burst time\n");
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].wt = 0;
        p[i].tat = 0;
    }
}

void display(int n) {
    int i;
    int ft = 0;
    printf("\n Process \t AT \t BT \t WT \t TAT");
    for (i = 0; i < n; i++)
        printf("\n    P%d   \t %d \t %d \t %d \t %d \n", p[i].name, p[i].at,
               p[i].bt, p[i].wt, p[i].tat);
}

void sort(int n) {
    int i, j;
    struct process s;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - j; j++)
            if (p[j].at > p[j + 1].at) {
                s = p[j];
                p[j] = p[j + 1];
                p[j + 1] = s;
            }
}

void sjf(int n) {
    int i, j, min, ct, min_index, total_tat = 0, total_wt = 0;
    ct = p[0].at;
    printf("\n      GANT CHART      \n");
    printf("%d", ct);
    while (1) {
        min = 999;
        min_index = -1;
        i = 0;
        while (i < n && p[i].at <= ct) {
            if (p[i].rt != 0 && p[i].rt < min) {
                min = p[i].rt;
                min_index = i;
            }
            i++;
        }
        if (i == n && min_index == -1)
            break;
        else if (i != n && min_index == -1) {
            printf("<--IDLE-->");
            ct = p[i].at;
        } else if (i == n && min_index != -1) {
            j = min_index;
            printf("<--P%d-->", p[i].name);
            ct += p[j].rt;
            p[j].rt = 0;
            p[j].tat = ct - p[j].at;
            p[j].wt = p[j].tat - p[j].bt;
        } else {
            j = min_index;
            printf("<--P%d-->", p[j].name);
            ct++;
            p[j].rt--;
            if (p[j].rt == 0) {
                p[j].tat = ct - p[j].at;
                p[j].wt = p[j].tat - p[j].bt;
            }
        }
        printf("%d", ct);
    }
}

int main() {
    int n;
    printf("Enter the number of processes you want to display:");
    scanf("%d", &n);
    accept(n);
    sort(n);
    sjf(n);
    display(n);
    printf("\n");
}
