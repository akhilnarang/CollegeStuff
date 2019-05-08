#include <stdio.h>

#define MAX 10

int i, j, processes, resourceTypes, need[MAX][MAX], allocate[MAX][MAX],
    max[MAX][MAX], available[MAX], resourceInstances[MAX];

void matrixInput(int matrix[MAX][MAX]) {
    for (i = 0; i < processes; i++) {
        printf("Process %d\n", i + 1);
        for (j = 0; j < resourceTypes; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void input() {
    printf("Enter number of processes!\n");
    printf("processes: ");
    scanf("%d", &processes);

    printf("Enter number of resource types!\n");
    printf("resourceTypes: ");
    scanf("%d", &resourceTypes);

    printf("Enter available resources!\n");
    for (i = 0; i < resourceTypes; i++) {
        printf("Enter available resources for %d!\n", i + 1);
        printf("available[%d]: ", i);
        scanf("%d", &available[i]);
    }

    printf("Enter allocated resources for each process!\n");
    matrixInput(allocate);

    printf("Enter maximum resources available for each process!\n");
    matrixInput(max);

    for (i = 0; i < processes; i++) {
        for (j = 0; j < resourceTypes; j++) {
            need[i][j] = max[i][j] - allocate[i][j];
        }
    }
}

void safety() {
    int work[resourceTypes];
    int finish[processes];
    int isSafe = 0, count = 0, cnt = 0;

    for (int i = 0; i < processes; i++) finish[i] = 0;

    for (int i = 0; i < resourceTypes; i++) work[i] = available[i];

    printf("\n\nThe Probable Safety Sequence is :- \n\n");
    printf("\t<<\t ");

    int i, j;
    while (count < (resourceTypes * processes * processes)) {
        for (i = 0; i < processes; i++) {
            if (finish[i] == 0) {
                for (j = 0; j < resourceTypes; j++) {
                    if (need[i][j] > work[j]) break;
                }
                if (j == resourceTypes) {
                    for (int k = 0; k < resourceTypes; k++)
                        work[k] += allocate[i][k];
                    finish[i] = 1;
                    cnt++;
                    printf("P%d\t", i);
                }
            }
        }
        count++;
    }
    if (cnt == processes)
        printf(
            ">>\n Thus SAFE SEQUENCE achieved!  The system is in SAFE "
            "STATE!/n/n");
    else
        printf(
            "...........\n Thus SAFE SEQUENCE not achieved!  The system is in "
            "UNSAFE STATE!\n\n");
}

void snapshot() {
    printf("\tProcess\tAllocated\tMaximum\tNeed\tAvailable\n");
    for (int i = 0; i < processes; i++) {
        printf("P%d\t\t", i);
        for (int j = 0; j < resourceTypes; j++) {
            printf("%d\t\t", allocate[i][j]);
        }
        printf("\t\t");
        for (int j = 0; j < resourceTypes; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\t\t");
        for (int j = 0; j < resourceTypes; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\t\t");
        if (i == 0) {
            for (int j = 0; j < resourceTypes; j++) printf("%d ", available[j]);
        }
    }
}

int main() {
    input();
    safety();
}
