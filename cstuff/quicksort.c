#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int i, j, pivot;
    pivot = arr[high];
    i = low - 1;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int j = partition(arr, low, high);
        quicksort(arr, low, j - 1);
        quicksort(arr, low + 1, high);
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
}

int main() {
    int i, n;
    printf("Enter size of array!\n");
    printf("n: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Current array is:\n");
    displayArray(arr, n);

    quicksort(arr, 0, n - 1);

    printf("Sorted array is:\n");
    displayArray(arr, n);
}