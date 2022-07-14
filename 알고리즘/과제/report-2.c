#include <stdio.h>
#include <stdlib.h>

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
	int N = n;

	while (n > 1)
	{
		int i = 0;
		while (i < k)
		{
			r = (r + 1) % N;
			if (A[r] != 0)
				i = i + 1;
		}
		A[r] = 0;
		n = n - 1;
		while (A[r] == 0)
			r = (r + 1) % N;
	}
	return A[r];
}

main()
{
	int n = 0;
	n = candle(7, 3);
	printf("배열_ver.1\n마지막으로 남은 촛불은%d번째 입니다.", n);
}