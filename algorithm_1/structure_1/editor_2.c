#include <stdio.h>
#define STACK_LEN	600001

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
	return pstack->topIndex == -1;
}

void SPush(Stack *pstack, char data)
{
	pstack->topIndex++;
	pstack->stackArr[pstack->topIndex] = data;
}

char SPop(Stack *pstack)
{
	return pstack->stackArr[pstack->topIndex--];
}

int main(void)
{
	Stack left;
	Stack right;
	char ch;
	int n;

	StackInit(&left);
	StackInit(&right);

	while ((ch = getchar()) != '\n')
	{
		SPush(&left, ch);
	}
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		ch = getchar();

		switch (ch)
		{
			case 'P' :
				getchar();
				SPush(&left, getchar());
				break;
			case 'L' :
				if (!SIsEmpty(&left))
					SPush(&right, SPop(&left));
				break ;
			case 'D' :
				if (!SIsEmpty(&right))
					SPush(&left, SPop(&right));
				break ;
			case 'B' :
				if (!SIsEmpty(&left))
					SPop(&left);
				break ;
			default :
				break ;
		}
		getchar();
	}
	while (!SIsEmpty(&left))
		SPush(&right, SPop(&left));
	while (!SIsEmpty(&right))
		printf("%c", SPop(&right));
	return (0);
}