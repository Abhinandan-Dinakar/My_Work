/*
 * Program Name: Three Vector Addition using CUDA
 * Description : This program performs element-wise addition of three vectors using CUDA parallel programming.
 * Author      : Abhinandan Dinakar
 * Date        : 25.02.2022
 * Compiler    : nvcc (NVIDIA CUDA Compiler)
 * 
 * Usage:
 * - This program allocates unified memory for three input vectors and one output vector.
 * - The CUDA kernel is launched with one block and multiple threads to perform addition in parallel.
 * - The first 10 elements of the resulting vector are printed.
 * 
 * Note:
 * - Ensure that the CUDA toolkit is installed and a compatible GPU is available.
 * - Compile using: nvcc filename.cu -o outputfile
 */


#include <stdio.h>
#define SIZE 1024  // Define the size of the vectors

// CUDA kernel function to perform element-wise addition of three vectors
__global__ void VectorAdd(int* a, int* b, int* c, int* d, int n)
{
    int i = threadIdx.x; // Get the thread index within the block

    // Ensure that the thread index is within the valid range
    if (i < n)
        d[i] = a[i] + b[i] + c[i];  // Perform element-wise addition of three vectors
}

int main()
{
    int* a, * b, * c, * d; // Pointers to store vectors in unified memory

    // Allocate unified memory (accessible by both CPU and GPU)
    cudaMallocManaged(&a, SIZE * sizeof(int));
    cudaMallocManaged(&b, SIZE * sizeof(int));
    cudaMallocManaged(&c, SIZE * sizeof(int));
    cudaMallocManaged(&d, SIZE * sizeof(int));

    // Initialize vectors a, b, and c, and set vector d to zero
    for (int i = 0; i < SIZE; ++i)
    {
        a[i] = i;  // Assign values from 0 to SIZE-1
        b[i] = i;  // Assign values from 0 to SIZE-1
        c[i] = i;  // Assign values from 0 to SIZE-1
        d[i] = 0;  // Initialize d to 0
    }

    // Launch the CUDA kernel with 1 block and SIZE threads
    VectorAdd<<<1, SIZE>>>(a, b, c, d, SIZE);

    // Wait for GPU computations to complete before accessing results
    cudaDeviceSynchronize();

    // Print the first 10 elements of the result vector d
    for (int i = 0; i < 10; ++i)
        printf("d[%d] = %d\n", i, d[i]);

    // Free allocated memory
    cudaFree(a);
    cudaFree(b);
    cudaFree(c);
    cudaFree(d);

    return 0;  // Exit the program
}
