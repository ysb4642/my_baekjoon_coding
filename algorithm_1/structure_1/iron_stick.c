#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE	1
#define FALSE	0
#define STACK_LEN	100002

typedef char Data;

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
	char str[100002];
	Stack stk;
	int num = 0, stick = 0;
	int i, len;

	StackInit(&stk);
	
	scanf("%s", str);
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] == '(')
		{
			SPush(&stk, str[i]);
			stick++;
		}
		else
		{
			if (SPeek(&stk) == '(')
			{
				stick--;
				num += stick;
				SPush(&stk, str[i]);
			}
			else
			{
				num++;
				stick--;
			}
		}
	}
	printf("%d", num);
	return (0);
}