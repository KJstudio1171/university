#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

typedef struct {
    int V[SIZE];
    int n;
}ArrayList;

void init(ArrayList* L)
{
    L->n = 0;
}

void traverse(ArrayList* L)
{
    for(int i = 0; i < L->n; i++)
        printf("[%d]", L ->V[i]);
    printf("\n");
}

void add(ArrayList* L, int pos, int item)
{
    if(L->n == SIZE)
    {
        printf("풀리스트오류");
        exit(1);
    }

    for(int i = L->n - 1; i >=pos; i--)
    {
        L->V[i+1] = L->V[i];
    L->V[pos] = item;
    L -> n++;
    }
}

int remove(ArrayList*L, int pos)
{
    int item = L->V[pos];
    for(int i = pos + 1; i <= L->n - 1; i ++)
        L-> V[i - 1] = L -> V[i];
    L -> n--;
    return item;
}

void main()
{
    
}