#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void generate(char* filename, int size) {
    FILE* file = fopen(filename, "w");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", rand());
    }
    fclose(file);
}

void read(FILE* file, int size, int* arr) {
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &arr[i]);
    }
}

int main() {
    int size;
    printf("Enter size of arrays to be generated!\n");
    printf("size: ");
    scanf("%d", &size);

#pragma omp parallel sections
    {
#pragma omp section
        { generate("input1.txt", size); }
#pragma omp section
        { generate("input2.txt", size); }
    }

    FILE* input1 = fopen("input1.txt", "r");
    FILE* input2 = fopen("input2.txt", "r");
    FILE* output = fopen("output.txt", "w");

    int m[size], n[size];
    long int result[size];

#pragma omp parallel sections
    {
#pragma omp section
        { read(input1, size, m); }
#pragma omp section
        { read(input2, size, n); }
    }

    double s = omp_get_wtime();

#pragma omp parallel for
    for (int i = 0; i < size; i++) {
        result[i] = m[i] + n[i];
    }

    for (int i = 0; i < size; i++) {
        fprintf(output, "%ld ", result[i]);
    }

    s = omp_get_wtime() - s;
    printf("Parallel execution time for addition using vector of size %d: %f\n",
           size, s);

    s = omp_get_wtime();

    read(input1, size, m);
    read(input2, size, n);

    for (int i = 0; i < size; i++) {
        result[i] = m[i] + n[i];
    }

    for (int i = 0; i < size; i++) {
        fprintf(output, "%ld ", result[i]);
    }

    s = omp_get_wtime() - s;
    printf("Serial execution time for addition using vector of size %d: %f\n",
           size, s);

    s = omp_get_wtime();

#pragma omp parallel for
    for (int i = 0; i < size; i++) {
        result[i] = m[i] + n[i];
    }

    for (int i = 0; i < size; i++) {
        fprintf(output, "%ld ", result[i]);
    }

    s = omp_get_wtime() - s;
    printf(
        "Parallel execution time for subtraction using vector of size %d: %f\n",
        size, s);

    s = omp_get_wtime();

    read(input1, size, m);
    read(input2, size, n);

    for (int i = 0; i < size; i++) {
        result[i] = m[i] - n[i];
    }

    for (int i = 0; i < size; i++) {
        fprintf(output, "%ld ", result[i]);
    }

    s = omp_get_wtime() - s;
    printf(
        "Serial execution time for subtraction using vector of size %d: %f\n",
        size, s);

    fclose(input1);
    fclose(input2);

    return 0;
}