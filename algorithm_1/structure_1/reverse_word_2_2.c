#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STACK_LEN	100002
#define TRUE	1
#define FALSE	0

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

int main(void)
{
	char str[100002];
	Stack stack;
	int len;

	StackInit(&stack);

	fgets(str, 100002, stdin);
	len = strlen(str) - 1;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == '<')
		{
			while (!SIsEmpty(&stack))
				printf("%c", SPop(&stack));
			while (str[i] != '>')
				printf("%c", str[i++]);
			printf("%c", str[i]);
		}
		else if (str[i] == ' ')
		{
			while (!SIsEmpty(&stack))
				printf("%c", SPop(&stack));
			printf("%c", str[i]);
		}
		else
			SPush(&stack, str[i]);
	}

	while (!SIsEmpty(&stack))
		printf("%c", SPop(&stack));
	printf("\n");
	return (0);
}
