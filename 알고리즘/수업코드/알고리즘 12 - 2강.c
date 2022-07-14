#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define INF 1000000

int A[SIZE][SIZE];

typedef struct GraphType
{
    int n;
    int weight[SIZE][SIZE];
}GraphType;

void printA(GraphType* g)
{
    int i,j;
    for(i = 0; i < g->n; i++)
    {
        for(j = 0; j < g->n; j++)
        {
            if(A[i][j] == INF)
                printf(" *");
            else printf("%3d", A[i][j]);
        }
        printf("\n");
    }
}

void floyd(GraphType* g)
{
    int i,j,k;
    for(i = 0;i < g->n; i++)
        for(j = 0; j <g->n; j++)
            A[i][j] = g->weight[i][j];
    printA(g);

    for(k=0;k<g->n;k++)
    {
        for(i = 0; i < g->n; i++)
            for(j = 0;j < g->n; j++)
                if(A[i][k]==1 && A[k][j] == 1)
                    A[i][j] = 1;
        printA(g);
    }
}