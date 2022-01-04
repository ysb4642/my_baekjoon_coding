#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE	1
#define FALSE	0
#define STACK_LEN	600000

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
	char str[600000];
	Stack save_l, save_r;
	int n, i;
	char ch, tmp;

	StackInit(&save_l);
	StackInit(&save_r);

	fgets(str, sizeof(str), stdin);
	for (i = 0; i < strlen(str); i++)
		SPush(&save_l, str[i]);
	scanf("%d", &n);
	while (n--)
	{
		char order[10];
		fgets(order, sizeof(order), stdin);
		order[strlen(order) - 1] = '\0';

		//scanf("%c", &tmp);
		if (!strcmp(order, "P"))
		{
			scanf("%c", &ch);
			SPush(&save_l, ch);
		}
		else if (!strcmp(order, "L"))
		{
			if (SIsEmpty(&save_l))
				continue ;
			else
			{
				SPush(&save_r, SPeek(&save_l));
				SPop(&save_l);
			}
		}
		else if (!strcmp(order, "B"))
		{
			if (SIsEmpty(&save_l))
				continue ;
			else
				SPop(&save_l);
		}
		else if (!strcmp(order, "D"))
		{
			if (SIsEmpty(&save_r))
				continue ;
			else
			{
				SPush(&save_l, SPeek(&save_r));
				SPop(&save_r);
			}
		}
	}
	while (!SIsEmpty(&save_l))
	{
		SPush(&save_r, SPeek(&save_l));
		SPop(&save_l);
	}
	while (!SIsEmpty(&save_r))
	{
		printf("%c", SPeek(&save_r));
		SPop(&save_r);
	}
	return (0);
}