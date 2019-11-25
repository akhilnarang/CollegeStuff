#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a; 
    *a = *b; 
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    printf("Pivot is %d\n", pivot);
    printf("i is %d [%d]\n", i, arr[i]);
    printf("j is %d [%d]\n", j, arr[j]);
    while (i <= j) {
        while (arr[++i] < pivot) {
            printf("Incremented i to %d [%d] as less than pivot\n", i, arr[i]);
        }
        while (arr[--j] > pivot) {
            printf("Decremented j to %d [%d] as more than pivot\n", j, arr[j]);
        }
        if (i < j) {
            printf("Swapping positions %d [%d] and %d [%d]\n", i, arr[i], j, arr[j]);
            swap(&arr[i++], &arr[j++]);
        }
    }
    printf("Swapping j = %d [%d] and low = %d [%d]\n", j, arr[j], low, arr[low]);
    swap(&arr[j], &arr[low]);
    return j;
}


void quicksort(int arr[], int low, int high) {
    if (low < high) {
        printf("low %d < high %d\n", low, high);
        int j = partition(arr, low, high);
        printf("Sorting on low [%d], j - 1 [%d]\n", low, j - 1);
        quicksort(arr, low, j - 1);
        printf("Sorting on low + 1 [%d], high [%d]\n", low + 1, high);
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