#include <stdio.h>
#include <stdlib.h>

#define M 13

typedef struct 
{
    int key;
    int probeCount;
}Bucket;

typedef struct 
{
    Bucket A[M];
}HashType;

void initHash(HashType* HT)
{
    for(int i = 0; i < M; i++)
    {
        HT->A[i].key = 0;
        HT->A[i].probeCount = 0;
    }
}

int h(int key)
{
    return key % M;
}

int h2(int key)
{
    return 11 - (key%11):
}

int getNextBucketLinear(int v, int i)
{
    return(v + i) % M;
}

int getNextBucketQuadratic(int v, int i)
{
    return (v + i*i)%M;
}

int getNextBuckeyDouble(int v, int i, int key)
{
    return(v + i+h2(key))%M;
}

int isEmpty(HashType* HT, int b)
{
    return HT->A[b].key == 0;
}

int findElement(HashType* HT, int key)
{
    int v = h(key);
    int i = 0;

    while(i < M)
    {
        int b = getNextBucketLinear(v,i);
        if(isEmpty(HT,b))
            return 0;
        else if(HT->A[b].key == key)
            return key;
        else
            i++;
    }
    return 0;
}

int removeElement(HashType* HT, int key)
{
    int v = h(key);
    int i = 0;

    while(i < M)
    {
        int b = getNextBucketLinear(v,i);
        if(isEmpty(HT,b))
            return 0;
        else if(HT->A[b].key == key)
        {
            HT->A[b].key = 0;
            return key;
        }
        else
            i++;
    }
    return 0;
}

void insertItem(HashType* HT, int key)
{
    int v = h(key);
    int i = 0;
    int count = 0;
    while(i < M)
    {
        count++;
        int b = getNextBucketLinear(v,i);
        if(isEmpty(HT,b))
        {
            HT->A[b].key = key;
            HT->A[b].probeCount = count;
            return;
        }
        else
            i++;
    }
}

int main()
{
    return 0;
}
