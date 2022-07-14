#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct Vertex
{
    int no;
    int weight;
    struct Vertex* next;
}Vertex;

typedef struct 
{
    int vCount;
    Vertex* v[N];
}Graph;

void insertEdge(Graph* G, int w, int v1, int v2)
{
    Vertex* p = (Vertex*)malloc(sizeof(Vertex));
    p-> weight = w;
    p->no = v1+1;
    p->next = G->v[v2];
    G->v[v2] = p;

    Vertex* q = (Vertex*)malloc(sizeof(Vertex));
    q-> weight = w;
    q->no = v2+1;
    q->next = G->v[v1];
    G->v[v1] = q;
}
