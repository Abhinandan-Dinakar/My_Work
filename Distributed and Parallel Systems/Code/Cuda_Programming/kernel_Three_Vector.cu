#include <stdio.h>
#define SIZE 1024

__global__ void VectorAdd(int* a, int* b, int* c, int* d, int n)
{
	int i = threadIdx.x;

	if (i < n)
		d[i] = a[i] + b[i] + c[i];
}


int main()
{
	int* a, * b, * c, * d;

	cudaMallocManaged(&a, SIZE * sizeof(int));
	cudaMallocManaged(&b, SIZE * sizeof(int));
	cudaMallocManaged(&c, SIZE * sizeof(int));
	cudaMallocManaged(&d, SIZE * sizeof(int));

	for (int i = 0; i < SIZE; ++i)
	{
		a[i] = i;
		b[i] = i;
		c[i] = i;
		d[i] = 0;
	}
	VectorAdd << <1, SIZE >> > (a, b, c, d, SIZE);

	cudaDeviceSynchronize();


	for (int i = 0; i < 10; ++i)
		printf("d[%d] = %d\n", i, d[i]);

	cudaFree(a);
	cudaFree(b);
	cudaFree(c);
	cudaFree(d);

	return 0;
}