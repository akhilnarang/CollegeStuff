#include <stdio.h>

#define MAX 10

int i, j, processes, resourceTypes, need[MAX][MAX], allocate[MAX][MAX],
    max[MAX][MAX], available[MAX][MAX], resourceInstances[MAX];

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

    printf("Enter maximum number of instances of each resource type!\n");
    for (i = 0; i < resourceTypes; i++) {
        printf("Enter maximum number of instances for resource %d!\n", i + 1);
        printf("resourceInstances[%d]: ", i);
        scanf("%d", &resourceInstances[i]);
    }

    printf("Enter allocated resources for each process!\n");
    matrixInput(allocate);

    printf("Enter maximum resources available for each process!\n");
    matrixInput(max);
}

void safety() {
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resourceInstances; j++) {
            need[i][j] = max[i][j] - allocate[i][j];
        }
    }

    for (i = 0; i < resourceTypes; i++) {
        int sum = 0;
        for (j = 0; j < processes; j++) {
            sum += allocate[j][i];
        }
        available[0][i] = resourceInstances[i] - sum;
    }

    for (i = 0; i < processes; i++) {
        for (j = 0; j < resourceTypes; j++) {
            if (available[i][j] > need[i][j]) {
            }
        }
    }
}

int main() {
    input();
    safety();
}