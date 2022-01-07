#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE	1
#define FALSE	0

typedef struct _node
{
	int data;
	struct _node *next;
	struct _node *prev;
} Node;

typedef struct _Deque
{
	Node *head;
	Node *tail;
	int cnt;
} Deque;

void DequeInit(Deque *pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
	pdeq->cnt = 0;
}

int DQIsEmpty(Deque *pdeq)
{
	if (pdeq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque *pdeq, int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pdeq->head;

	if (DQIsEmpty(pdeq))
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;
	
	newNode->prev = NULL;
	pdeq->head = newNode;
	pdeq->cnt++;
}

void DQAddLast(Deque *pdeq, int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = pdeq->tail;

	if (DQIsEmpty(pdeq))
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;
	
	newNode->next = NULL;
	pdeq->tail = newNode;
	pdeq->cnt++;
}

int DQRemoveFirst(Deque *pdeq)
{
	Node *rnode = pdeq->head;
	int rdata;
	if (DQIsEmpty(pdeq))
		exit(-1);
	rdata = pdeq->head->data;
	pdeq->head = pdeq->head->next;
	free(rnode);

	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;
	pdeq->cnt--;
	return (rdata);
}

int DQRemoveLast(Deque *pdeq)
{
	Node *rnode = pdeq->tail;
	int rdata;
	if (DQIsEmpty(pdeq))
		exit(-1);
	rdata = pdeq->tail->data;

	pdeq->tail = pdeq->tail->prev;
	free (rnode);

	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;
	pdeq->cnt--;
	return (rdata);
}

int DQGetFirst(Deque *pdeq)
{
	if (DQIsEmpty(pdeq))
		exit(-1);
	return (pdeq->head->data);
}

int DQGetLast(Deque *pdeq)
{
	if (DQIsEmpty(pdeq))
		exit(-1);
	return (pdeq->tail->data);
}

int DQGetSize(Deque *pdeq)
{
	return pdeq->cnt;
}

int main(void)
{
	int n, k;
	char command[15];
	Deque deq;

	DequeInit(&deq);
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", command);
		if (!strcmp(command, "push_front"))
		{
			scanf("%d", &k);
			DQAddFirst(&deq, k);
		}
		else if (!strcmp(command, "push_back"))
		{
			scanf("%d", &k);
			DQAddLast(&deq, k);
		}
		else if (!strcmp(command, "pop_front"))
		{
			if (DQIsEmpty(&deq))
				printf("-1\n");
			else
				printf("%d\n", DQRemoveFirst(&deq));
		}
		else if (!strcmp(command, "pop_back"))
		{
			if (DQIsEmpty(&deq))
				printf("-1\n");
			else
				printf("%d\n", DQRemoveLast(&deq));
		}
		else if (!strcmp(command, "size"))
			printf("%d\n", DQGetSize(&deq));
		else if (!strcmp(command, "empty"))
			printf("%d\n", DQIsEmpty(&deq));
		else if (!strcmp(command, "front"))
		{
			if (DQIsEmpty(&deq))
				printf("-1\n");
			else
				printf("%d\n", DQGetFirst(&deq));
		}
		else if (!strcmp(command, "back"))
		{
			if (DQIsEmpty(&deq))
				printf("-1\n");
			else
				printf("%d\n", DQGetLast(&deq));
		}
	}
	return (0);
}