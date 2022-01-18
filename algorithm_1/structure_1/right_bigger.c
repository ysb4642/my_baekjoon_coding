#include <stdio.h>
#include <stdlib.h>
#define STACK_LEN	1000000
#define TRUE	1
#define FALSE	0

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
	int n, i;
	int *arr;
	int *ans;
	Stack stk;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);
	ans = (int *)malloc(sizeof(int) * n);
	StackInit(&stk);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		ans[i] = -1;
	}

	for (i = 0; i < n; i++)
	{
		while(!SIsEmpty(&stk) && arr[SPeek(&stk)] < arr[i])
			ans[SPop(&stk)] = arr[i];
		SPush(&stk, i);
	}

	for (i = 0; i < n; i++)
		printf("%d ", ans[i]);

	free(arr);
	free(ans);
	return (0);
}