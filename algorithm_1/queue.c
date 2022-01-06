#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUE_LEN	10001
#define TRUE	1
#define FALSE	0

typedef struct c_Queue
{
	int front;
	int rear;
	int queArr[QUE_LEN];
} Queue;

void QueueInit(Queue *pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue *pq)
{
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue *pq, int data)
{
	if (NextPosIdx(pq->rear) == pq->front)
		exit(-1);
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

int Dequeue(Queue *pq)
{
	if (QIsEmpty(pq))
		exit(-1);
	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

int Qfront(Queue *pq)
{
	if (QIsEmpty(pq))
		exit(-1);
	return pq->queArr[NextPosIdx(pq->front)];
}

int Qrear(Queue *pq)
{
	if (QIsEmpty(pq))
		exit(-1);
	return pq->queArr[pq->rear];
}

int Qsize(Queue *pq)
{
	return (pq->rear - pq->front);
}

int main(void)
{
	int n, k;
	char command[10];
	Queue que;

	QueueInit(&que);
	scanf ("%d", &n);
	while (n--)
	{
		scanf("%s", command);
		if (!strcmp(command, "push"))
		{
			scanf("%d", &k);
			Enqueue(&que, k);
		}
		else if (!strcmp(command, "pop"))
		{
			if (QIsEmpty(&que))
				printf("-1\n");
			else
				printf("%d\n", Dequeue(&que));
		}
		else if (!strcmp(command, "size"))
			printf("%d\n", Qsize(&que));
		else if (!strcmp(command, "empty"))
			printf("%d\n", QIsEmpty(&que));
		else if (!strcmp(command, "front"))
		{
			if (QIsEmpty(&que))
				printf("-1\n");
			else
				printf("%d\n", Qfront(&que));
		}
		else if (!strcmp(command, "back"))
		{
			if (QIsEmpty(&que))
				printf("-1\n");
			else
				printf("%d\n", Qrear(&que));
		}
	}
	return (0);
}