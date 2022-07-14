#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50
int n = 50;
#define SWAP(x,y,t)( (t) = (x), (x)=(y), (y)=(t) )

int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);
	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main()
{
	int i,random;
	int list[MAX_SIZE];
	srand(time(NULL));
	for (i = 0; i < 50; i++) {
		random = rand() % 10000;
		list[i] = random;
		printf("%d ", list[i]);
	}
	quick_sort(list, 0, n - 1);
	printf("\n");
	for (i = 0; i < 50; i++) {
		printf("%d ", list[i]);
	}
}
