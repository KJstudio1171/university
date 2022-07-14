#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode
{
    int data;
    struct QueueNode* link;
}QueueNode;

typedef struct
{
    QueueNode* front;
    QueueNode* rear;
}LinkedQueue;

void init(LinkedQueue*queue)
{
    queue ->front = queue -> rear = NULL;
}

void enqueue(LinkedQueue *queue, int data)
{
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp -> data = data;
    temp -> link = NULL;
    if(is_empty(queue))
    {
        queue -> front = temp;
        queue -> rear = temp;
    }
    else
    {
        queue -> rear -> link = temp;
        queue -> rear = temp;
    }
}

int dequeue(LinkedQueue* queue)
{
    QueueNode* temp = queue ->front;
    int data;
    if(is_empty(queue))
    {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }
    else
    {
        data = temp -> data;
        queue -> front = temp -> link;
        if(queue ->front == NULL)
            queue -> rear = NULL;
        free(temp);
        return data;
    }
}

void print_queue(LinkedQueue* queue)
{
    QueueNode* p;
    for(p = queue -> front; p!= NULL; p = p -> link)
        printf("|%d|->", p->data);
    printf("|NULL|\n");
}

void insertion_sort(int list[], int n)
{
    int i,j,key;
    for(i = 1; i < n; i++)
    {
        key = list [i];
        for(j=i-1;j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j];
        list[j + 1] = key;
    }
} 

void inc_insertion_sort(int list[], int first, int last, int gap)
{
    int i,j,key;
    for(i = first + gap; i <= last; i = i + gap)
    {
        key = list[i];
        for(j = i - gap; j >= first && list[j] > key; j = j - gap)
            list[j + gap] = list[j];
        list[j + gap] = key;
    }
}

void shell_sort(int list[],int n)
{
    int i,gap;
    for(gap = n/2; gap > 0; gap = gap/2)
    {
        if(gap%2 == 0)
            gap++;
        for (i = 0; i< gap; i++)
            inc_insertion_sort(list,i,n-1,gap);
    }
}

void main()
{
    LinkedQueue queue;
    init(&queue);
}