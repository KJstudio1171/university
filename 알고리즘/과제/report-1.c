#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct ListNode
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

void addFirst(LinkedListType* L, int item)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	node->link = L->head;
	L->head = node;
}


void addLast(LinkedListType* L, int item)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* last = L->head;
	while (last->link != NULL)
		last = last->link;
	node->data = item;
	node->link = NULL;
	last->link = node;
}

void add(LinkedListType* L, int pos, int item)
{
	//add함수와 remove함수를 이런식으로 수정하여야 정확한 index에 item삽입이 가능합니다.
	if (pos == 1) {
		addFirst(L, item);
		return;
	}

	if (pos < 0) {
		printf("invalidRankExeption...\n");
		exit(1);
	}

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	for (int i = 0; i < pos - 2; i++)
	{
		before = before->link;
		if (before == NULL) {
			printf("invalidRankExeption...\n");
			exit(1);
		}
	}
	node->data = item;
	node->link = before->link;
	before->link = node;
}

int removeFirst(LinkedListType* L)
{
	ListNode* first = L->head;
	L->head = first->link;
	int data = first->data;
	free(first);
	return data;
}


int removeLast(LinkedListType* L)
{
	ListNode* last = L->head;
	int index = 0;
	while (last->link != NULL)
	{
		last = last->link;
		index++;
	}
	int data = last->data;
	ListNode* node = L->head;
	for (int i = 0; i < index-1; i++)
	{
		node = node->link;
	}
	node->link = NULL;
	free(last);
	return data;
}

int remove(LinkedListType* L, int pos)
{
	if (pos == 1)
		return removeFirst(L);

	if (pos < 0) {
		printf("invalidRankExeption...\n");
		exit(1);
	}
	ListNode* before = L->head;
	for (int i = 0; i < pos - 2; i++)
	{
		before = before->link;
		if (before == NULL) {
			printf("invalidRankExeption...\n");
			exit(1);
		}
	}
	ListNode* node = before->link;
	if (node == NULL) {
		printf("emptyListExeption...\n");
		exit(1);
	}
	int data = node->data;
	before->link = node->link;
	free(node);
	return data;
}


int get(LinkedListType* L, int pos)
{
	if (pos < 0) {
		printf("invalidRankExeption...\n");
		exit(1);
	}
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++) {
		p = p->link;
		if (p == NULL) {
			printf("invalidRankExeption...\n");
			exit(1);
		}
	}
		return p->data;
}

int set(LinkedListType* L, int pos, int item)
{
	if (pos < 0) {
		printf("invalidRankExeption...\n");
		exit(1);
	}
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
	{
		p = p->link;
		if (p == NULL) {
			printf("invalidRankExeption...\n");
			exit(1);
		}
	}
	p->data = item;
}


void printList(LinkedListType* L)
{
	for (ListNode* p = L->head; p != NULL; p = p->link)
		printf("[%d] ->", p->data);
	printf("NULL\n");
}


void main()
{
	LinkedListType list;
	init(&list);
	printf("\naddFirst 10,20\n");
	addFirst(&list, 10); printList(&list);
	addFirst(&list, 20); printList(&list);
	printf("\naddLast 10,20\n");
	addLast(&list, 10); printList(&list);
	addLast(&list, 20); printList(&list);
	printf("\nadd (1,40),(5,0)\n");
	add(&list, 1,40); printList(&list);
	add(&list, 5, 0); printList(&list);
	printf("\nremoveFirst\n");
	int num = removeFirst(&list); printList(&list);
	printf("\nremoveLast\n");
	int num1 = removeLast(&list); printList(&list);
	printf("\nremove 2\n");
	remove(&list, 2); printList(&list);
	
	int pos;
	printf("\n몇 번 노드의 값을 반환할까요?");
	scanf_s("%d", &pos);
	printf("%d번 노드의 값은 %d\n", pos, get(&list, pos));
}