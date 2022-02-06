#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define TRUE	1
#define FALSE	0
#define STACK_LEN	100

typedef int Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack *pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack *pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack *pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack *pstack)
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;

	return pstack->stackArr[rIdx];
}

Data SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}
int main(void)
{
	int a, b, m, n, i;
	int num = 0;
	Stack result;

	StackInit(&result);
	scanf("%d %d %d", &a, &b, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &n);
		if (m == 1 && n == 0)
		{
			printf("0\n");
			return (0);
		}
		num += (n * pow(a, m - i - 1));
	}
	while (num != 0)
	{
		SPush(&result, num % b);
		num /= b;
	}

	while (!SIsEmpty(&result))
		printf("%d ", SPop(&result));
	printf("\n");
	return (0);
}