#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE	1
#define FALSE	0
#define STACK_LEN	100002

typedef struct _arrayStack
{
	char stackArr[STACK_LEN];
	int topIndex;
} Stack;

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

void SPush(Stack *pstack, char data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

char SPop(Stack *pstack)
{
	int rIdx;

	if (SIsEmpty(pstack))
		exit(-1);

	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;

	return pstack->stackArr[rIdx];
}

char SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))
		exit(-1);

	return pstack->stackArr[pstack->topIndex];
}


void stackprint(Stack *pstack)
{
	while (!SIsEmpty(pstack))
	{
		printf("%c", SPeek(pstack));
		SPop(pstack);
	}
}

int main(void)
{
	char str[100002];
	Stack stk;
	int i, len;

	StackInit(&stk);

	fgets(str, 100000, stdin);
	len = strlen(str) - 1;
	for (i = 0; i < len; i++)
	{
		if (str[i] == '<')
		{
			stackprint(&stk);
			while(1)
			{
				printf("%c", str[i]);
				if (str[i] == '>')
					break ;
				i++;
			}
		}
		else if (str[i] == ' ')
		{
			stackprint(&stk);
			printf(" ");
		}
		else
			SPush(&stk, str[i]);
	}
	stackprint(&stk);
	return (0);
}