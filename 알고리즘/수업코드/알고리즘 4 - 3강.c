#include <stdio.h>
#include <stdlib.h>

void remover(int* A, int r, int n)
{
	for (int i = r + 1; i < n; i++)
	{
		A[i - 1] = A[i];
	}
}

void buildList(int* A, int n)
{
	for (int i = 0; i < n; i++)
	{
		A[i] = i + 1;
	}
	return;
}

int candle(int n, int k)
{
	int* A = (int*)malloc(sizeof(int) * n);
	buildList(A, n);
	return runSimulation(A, n, k);
}

int runSimulation(int* A, int n, int k)
{
	int r = 0;

	while (n > 1)
	{
		r = (r + k) % n;
		remover(A, r, n);
		n = n - 1;
	}
	return A[0];
}

main()
{
	int n = 0;
	n = candle(7, 3);
	printf("배열_ver.2\n마지막으로 남은 촛불은%d번째 입니다.", n);
}