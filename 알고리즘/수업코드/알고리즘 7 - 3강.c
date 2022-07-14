#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15
#define BUCKETS 10
#define DIGITS 2

typedef int element;
typedef struct
{
    element data[MAX_SIZE];
    int front, rear;
}QueueType;

void init_queue(QueueType* q)
{
    q->front = q -> rear = 0;
}

int is_empty(QueueType *q)
{
    return q->front == q->rear;
}

int is_full(QueueType*q)
{
    return (q->rear + 1) % MAX_SIZE == q-> front;
}

void enqueue(QueueType* q, element item)
{
    if(is_full(q)) exit(1);

    q-> rear = (q-> rear +1)%(MAX_SIZE);
    q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
    if(is_empty(q)) exit(1);
    q->front = (q-> front +1) % MAX_SIZE;
    return q-> data[q -> front];
}

void radix_Sort(int list[],int n)
{
    int i, b, d, factor = 1;
    QueueType queues[BUCKETS];

    for(b=0; b<BUCKETS; b++)
        init_queue(&queues[b]);

    for(d=0; d<DIGITS; d++)
    {
        for(i = 0; i < n; i++)
            enqueue(&queues[(list[i]/factor)%10], list[i]);

        for(b=i=0; b< BUCKETS; b++)
            while(!is_empty(&queues[b]))
                list[i++] = dequeue(&queues[b]);

        factor *= 10;
    }
}

void main()
{

}