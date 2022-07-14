#include <stdio.h>
#include <stdlib.h>


typedef struct Heap
{
	int heap[100000];
	int heap_size;
}Heap;

typedef struct HeapType
{
    Heap * front;
    Heap * rear;
}HeapType;

void upHeap(Heap* h) 
{
	int i = h->heap_size;
	int key = h->heap[i];

	while ((i != 1) && (key < h->heap[i / 2]))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = key;
}

void downHeap(Heap *h) 
{
  int temp = h->heap[1];
  int parent = 1, child = 2;
  while(child <= h->heap_size)
  {   
      if((child < h->heap_size) && (h->heap[child] > h->heap[child + 1]))
​           child++;
​    if (temp <= h->heap[child])
​      break;
​    h->heap[parent] = h->heap[child];
​    parent = child;
​    child *= 2;
  }

  h->heap[parent] = temp;
}



void heapSort(Heap* h, int list[])
{
  HeapType heap;
  init(&heap);
  for (int i = 1; i <= h->heap_size; i++)

  {
​    heap.heap[i] = h->heap[i];
​    heap.heap_size++;
  }

  for (int i = 1; i <= h->heap_size; i++)
​    list[i] = removeMin(&heap);
}

void inPlaceHeapSort(Heap *h)
{
  int size = h-> heap_size;
  int key;

  for(int i = 0; i < size; i++)
  {
​    key = removeMin(h);
​    h->heap[h->heap_size+1] = key;
  }
}




int partition(int list[], int left, int right)
{
    int pivot, temp, low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    
    do
    {
        do
            low++;
        while(list[low] < pivot);

        do
            high--;
        while(list[high] > pivot);

        if(low < high)
            SWAP(list[low], list[high], temp);
    }while (low < high);

    SWAP(list[left], list[high], temp);
    return high;
}

void quick_sort(int list[], int left, int right)
{
    if(left < right)
    {
        int q = partition(list, left, right);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);
    }
}

int partition_2(int list[], int left, int right, int k)
{
    int pivot, temp, low, high;

    pivot = list[k];
    SWAP(list[k], list[right], temp);

    low = left - 1;
    high = right;
    
    
    do
    {
        do
            low++;
        while(list[low] < pivot);

        do
            high--;
        while(list[high] < pivot);

        if(low < high)
            SWAP(list[low], list[high], temp);
    }while (low < high);

    SWAP(list[left], list[high], temp);
    return low;
}

void quick_sort_2(int list[], int left, int right)
{
    if(left < right)
    {
        int k = rand() % (right - left) + left + 1;
        int q = partition_2(list, left, right, k);
        quick_sort_2(list, left, q-1);
        quick_sort_2(list, q+1, right);
    }
}

void main()
{
    
    int list[MAX_SIZE];
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        list[i] = rand() % 100;
    for(int i = 0; i < MAX_SIZE; i++)
        printf("[%d]", list[i]);
    printf("\n\n"); getch();

    quick_sort(list,0,MAX_SIZE,-1);
}







void merge(int list[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int l;

    while(i <= mid && j <= right)
    {
        if(list[i] <= list[j])
            sorted[k] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if(i>mid)
        for(l = j; l <= right; l++)
            sorted[k++] = list[l];
    else 
        for(l = i; l <= mid; l++)
            sorted[k++] = list[l];
    for(l = left; l <= right; l++)
        list[l] = sorted[l];
}


void merge_sort(int list[], int left, int right)
{
    int mid;
    if(left < right)
    {
        mid = (left + right) / 2;
        merge_sort(list,left,mid);
        merge_sort(list,mid+1,right);
        merge(list,left,mid,right);
    }
}
void main()
{
    int list[MAX_SIZE];
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
    { 
        list[i] = rand()%100;
        for(int j = 0; j < i; j++)
            if(list[i] == list[j])
                i--;
    }

    for(int i = 0; i < MAX_SIZE; i++)
        printf("[%d]", list[i]);
    printf("\n\n"); getch();

    merge_sort(list,0,MAX_SIZE - 1);
}













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
