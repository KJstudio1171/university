#include <stdio.h>
#include <stdlib.h>


typedef struct
{
	int data;
	struct ListNode* link;
}ListNode;

typedef struct
{
	ListNode* head;
}LinkedListType;

void init(LinkedListType* L)
{
	L->head = NULL;
}


void buildList(LinkedListType* L, int n)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = 1;
	L->head = p;
	for (int i = 2; i <= n; i++)
	{
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		node->data = i;
		p->link = node;
		p = p->link;
	}
	p->link = L->head;

}

int runSimulation(LinkedListType* L, int n, int k)
{
	ListNode* p = L->head;
	while (p != p->link)
	{
		for (int i = 1; i < k ; i++)
		{
			p = p->link;
		}
		ListNode* node = p->link;
		p->link = node->link;
		free(node);
		p = p->link;
	}
	return p->data;
}

int candle(int n, int k)
{
	LinkedListType list;
	init(&list);
	buildList(&list, n);
	return runSimulation(&list, n, k);
}

main()
{
	int n = 0;
	n = candle(7, 3);
	printf("원형연결리스트\n마지막으로 남은 촛불은%d번째 입니다.", n);
}