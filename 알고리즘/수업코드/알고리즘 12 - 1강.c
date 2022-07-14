#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct 
{
    int n,m;
    int adj_mat[SIZE][SIZE];
}GraphType;

void init(GraphType* g)
{
    for(int row = 0; row < SIZE; row++)
        for(int col = 0; col < SIZE; col++)
            g->adj_mat[row][col] = 0;
}

void insert_edge(GraphType*g, int start, int end)
{
    if((start >= g->n) || (end >= g->n))
    {
        printf("간선을 추가할  수 없습니다.\n");
        return;
    }
    g->adj_mat[start][end] = 1;
}

void dfs_mat(GraphType*g, int visited[], int v)
{
    visited[v] = TRUE;
    printf("정점[%d]", v+1);
    for(int w = 0; w < g->n; w++)
        if(g->adj_mat[v][w] && !visited[w])
            dfs_mat(g,visited,w);
}

void rev_mat(GraphType* g, int v)
{
    GraphType r;
    init(&r);
    r.n = g->n;
    int visited[SIZE] = {FALSE};

    for(int row = 0; row < g->n; row++)
        for(int col = 0; col < g->n; col++)
            r.adj_mat[col][row] = g->adj_mat[row][col];
    print_adj_mat(&r); printf("\n");
    dfs_mat(&r,visited,v-1);
}
