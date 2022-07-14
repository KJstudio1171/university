#include <stdio.h>

#define INT_MAX 2147483647
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 8
#define INF 10000

int weight[MAX_VERTICES][MAX_VERTICES] = {
	{ 0,INF,INF,INF,INF,INF,INF,INF },
{ 300,0,INF,INF,INF,INF,INF,INF },
{ 1000,800,0,INF,INF,INF,INF,INF },
{ INF,INF,1200,0,INF,INF,INF,INF },
{ INF,INF,INF,1500,0,250,INF,INF },
{ INF,INF,INF,1000,INF,0,900,1400 },
{ INF,INF,INF,INF,INF,INF,0,1000 },
{ 1700,INF,INF,INF,INF,INF,INF,0 } };

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[]) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void shortest_path(int start, int n) {
	int i, u, w;
	for (i = 0; i < n; i++) {
		distance[i] = weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;
	distance[start] = 0;
	for (i = 0; i < n - 1; i++) {
		u = choose(distance, n, found);
		found[u] = TRUE;
		for (w = 0; w < n; w++)
			if (!found[w])
				if (distance[u] + weight[u][w] < distance[w])
					distance[w] = distance[u] + weight[u][w];
	}
	printf("%d \n", start + 1);
	for (i = 0; i < MAX_VERTICES; i++) {
		if (distance[i] == 10000) {
			printf( "distance[%d} INF \n",i+1);
		}
		else {
			printf("distance[%d] %d \n", i + 1, distance[i]);
		}
	}
}

void main() {
	int i = 0;
	for (i = 0; i < MAX_VERTICES; i++) {
		shortest_path(i, MAX_VERTICES);
		printf("\n\n");
	}

	shortest_path(4, MAX_VERTICES);
	printf(" 위에서 보스턴에서 로스엔젤레스 3350\n\n");
}
