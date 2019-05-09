#include <stdio.h>

#define MAX 10

int i, j, processes, resourceTypes, need[MAX][MAX], allocate[MAX][MAX],
    max[MAX][MAX], available[MAX], total[MAX], resourceInstances[MAX];

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

    printf("Enter total resources!\n");
    for (i = 0; i < resourceTypes; i++) {
        printf("Enter total resources for %d!\n", i + 1);
        printf("total[%d]: ", i);
        scanf("%d", &total[i]);
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

    for (i = 0; i < resourceTypes; i++) {
        int temp = 0;
        for (j = 0; j < processes; j++) {
            temp += allocate[j][i];
        }
        available[i] = total[i] - temp;
    }
}

void safety() {
    int work[resourceTypes];
    int finish[processes];
    int safeSequence[processes];
    int isSafe = 0, count = 0;
    int i, j, found;

    for (i = 0; i < processes; i++) finish[i] = 0;

    for (i = 0; i < resourceTypes; i++) work[i] = available[i];

    while (count < processes) {
        found = 0;
        for (i = 0; i < processes; i++) {
            if (!finish[i]) {
                for (j = 0; j < resourceTypes; j++)
                    if (need[i][j] > work[j]) break;

                if (j == resourceTypes) {
                    for (int k = 0; k < resourceTypes; k++)
                        work[k] += allocate[i][k];
                    finish[i] = 1;
                    found = 1;
                    safeSequence[count++] = i;
                }
            }
        }
    }
    if (!found) {
        printf("The system is in unsafe state!\n");
        return;
    }
    printf("The system is in safe state! Safety sequence is: ");
    for (i = 0; i < processes; i++) {
        printf("%d\t", safeSequence[i]);
    }
}

int main() {
    input();
    safety();
}
