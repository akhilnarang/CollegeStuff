#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void sort(int array[], int n, int ascending) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if ((ascending && array[j] > array[j + 1]) ||
                (!ascending && array[j] < array[j + 1])) {
                array[j] += array[j + 1];
                array[j + 1] = array[j] - array[j + 1];
                array[j] -= array[j + 1];
            }
        }
    }
}

void display(int array[], int n, int ascending) {
    int i;
    i = ascending ? 0 : n - 1;
    while ((ascending && i < n) || (!ascending && i >= 0)) {
        printf("array[%d]: %d\n", i, array[i]);
        if (ascending)
            i++;
        else
            i--;
    }
}

int main() {
    int i, j, n, status;
    printf("Enter size of array!\n");
    printf("n: ");
    scanf("%d", &n);
    int array[n];
    for (i = 0; i < n; i++) {
        printf("Enter element %d!\n", i + 1);
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    printf("Before sorting - ascending!\n");
    display(array, n, 1);
    printf("Before sorting - ascending!\n");
    display(array, n, 0);

    printf("\nSorting the array!\n\n");

    pid_t pid = fork();

    if (pid == 0) {
        printf("Sorting in child (ascending)\n");
        sort(array, n, 1);
        printf("Printing in child (descending)\n");
        display(array, n, 0);
        exit(100);
    } else if (pid > 0) {
        printf("Waiting for child to execute!\n");
        wait(&status);
        printf("Child has finished executing! Status: %d!\n",
               WEXITSTATUS(status));
        printf("Sorting in parent (descending)\n");
        sort(array, n, 0);
        printf("Printing in parent (ascending)\n");
        display(array, n, 1);
    } else {
        perror("Fork failed\n");
        _exit(2);
    }
    return 0;
}
