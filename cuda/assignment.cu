#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

#define MAX 10

int size = MAX * sizeof(int);

__global__ void cudasum(int *a, int *b, int *c) {
  int i = threadIdx.x + blockIdx.x * blockDim.x;
  c[i] = a[i] + b[i];
}

int main() {
  int a[MAX], b[MAX], c[MAX];
  int *da, *db, *dc;
  int i;
  for (i = 0; i < MAX; i++) {
    a[i] = b[i] = i;
  }

  cudaMalloc(&da, size);
  cudaMalloc(&db, size);
  cudaMalloc(&dc, size);
  cudaMemcpy(da, a, size, cudaMemcpyHostToDevice);
  cudaMemcpy(db, b, size, cudaMemcpyHostToDevice);
  cudaMemcpy(dc, c, size, cudaMemcpyHostToDevice);
  cudasum<<<1, 10>>>(da, db, dc);
  cudaMemcpy(c, dc, size, cudaMemcpyDeviceToHost);
  for (i = 0; i < MAX; i++) {
    printf("c[%d] = %d\n", i, c[i]);
  }
  return 0;
}