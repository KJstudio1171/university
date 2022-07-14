#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 100

typedef struct
{
	int heap[MAX_ELEMENT];
	int heap_size;
}Heap;

typedef struct 
{
	int stack[MAX_ELEMENT];
	int top;
}Stack;

void init_Heap(Heap* h)
{
	h->heap_size = 0;
}

void init_Stack(Stack* s)
{
	s->top = -1;
}

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

void insertItem(Heap*h, int key)
{
	h->heap_size += 1;
	h->heap[h->heap_size] = key;
	upHeap(h);
}

/*void downHeap(Heap *h) 
{
	int temp = h->heap[1];
	int parent = 1, child = 2;
	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) && (h->heap[child] > h->heap[child + 1]))
			child++;
		if (temp <= h->heap[child])
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
}



int removeMin(Heap *h)
{
	int key = h->heap[1];
	h->heap[1] = h->heap[h->heap_size];
	h->heap_size -= 1;
	downHeap(h);
	return key;
}
*/

void printHeap(Heap* h)
{
	for (int i = 1; i <= h->heap_size; i++)
		printf("[%d]", h->heap[i]);
	printf("\n");
}

/*void heapSort(Heap* h, int list[])
{
	HeapType heap;
	init(&heap);
	for (int i = 1; i <= h->heap_size; i++)
	{
		heap.heap[i] = h->heap[i];
		heap.heap_size++;
	}

	for (int i = 1; i <= h->heap_size; i++)
		list[i] = removeMin(&heap);
}

void printArray(int list[],int n)
{
	for (int i = 1; i <= n; i++)
		printf("[%d]", list[i]);
	printf("\n");
}

void inPlaceHeapSort(Heap *h)
{
	int size = h-> heap_size;
	int key;
	for(int i = 0; i < size; i++)
	{
		key = removeMin(h);
		h->heap[h->heap_size+1] = key;
	}
}*/

int isEmpty(Stack* s)
{
	if( s->top == -1) 
		return 1;
	else 
		return 0;
}

void push(Stack * s,int key)
{
	s->top +=1;
	if(s->top>MAX_ELEMENT)
	{
		printf("OVERFLOW");
		exit(1);
	}
	s->stack[s->top] = key;
}

int pop(Stack* s)
{
	if(s->top==-1)
	{
		printf("ERROR");
		exit(1);
	}
	return s->stack[s->top--];
}

void binaryExpansion(Stack* s,int n)
{
	while(n>=2)
	{
		push(s,n%2);
		n /= 2 ;
	}
	push(s,n);
	return;
}

int findLastNode(Heap* h)
{
	int bit = 0;
	int n = 1 , v;
	Stack stack;
	init_Stack(&stack);
	binaryExpansion(&stack,h->heap_size);
	pop(&stack);
	while(!isEmpty(&stack))
	{
		bit = pop(&stack);
	if(bit == 0)
		n *=2; 
	else
		n = n*2 +1;
	v = h -> heap[n];
	}
	return v;
}

void main()
{
	int element;
	int key;
	Heap heap;
	init_Heap(&heap);
	srand(time(NULL));
	printf("힙원소의 개수를 입력하시오 : ");
	scanf("%d",&element);
	for(int i = 0 ; i < element; i++)
		insertItem(&heap,rand()%100);
	printHeap(&heap);
	key = findLastNode(&heap);
	printf("마지막 노드의 키값은 [%d] 입니다.",key);
	
	/*
	int list[MAX_ELEMENT] = {0};
	srand(time(NULL));
	
	printHeap(&heap);
	getchar();
	inPlaceHeapSort(&heap);
	for(int i = 1; heap.heap[i]>0;i++)
		printf("[%d]",heap.heap[i]);
		*/
	
}