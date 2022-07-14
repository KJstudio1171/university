#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char vName;
}Vertex;

typedef struct 
{
    int eNo;
    int weight;
    Vertex v1,v2;
}Edge;

typedef struct 
{
    Vertex v[10];
    Edge e[30];
    int vCount;
    int eCount;
}Graph;

void init(Graph* G)
{
    G->vCount = 0;
    G->eCount = 0;
}

void makeaVertex(Graph* G)
{
    G->v[G->vCount].vName = 97 + G->vCount;
    G->vCount++;
}

void makeVertex(Graph* G)
{
    G->v[G->vCount].vName = 97 + G->vCount;
    G->vCount++;
}

void insertEdge(Graph* G, int w, Vertex v1, Vertex v2)
{
    G->e[G->eCount].eNo = G->eCount;
    G->e[G->eCount].weight = w;
    G->e[G->eCount].v1 = v1;
    G->e[G->eCount].v2 = v2;
    G->eCount++;
}