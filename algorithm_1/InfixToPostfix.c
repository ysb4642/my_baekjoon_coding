#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define TRUE	1
#define FALSE	0
#define STACK_LEN	100

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

int GetOpPrec(char op)
{
	switch(op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}
	return -1;
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void convToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char *convExp = (char *)malloc(sizeof(char) * expLen + 1);
	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1);
	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isalpha(tok))
			convExp[idx++] = tok;
		else
		{
			switch(tok)
			{
			case '(' :
				SPush(&stack, tok);
				break ;
			case ')' :
				while (1)
				{
					popOp = SPop(&stack);
					if (popOp == '(')
						break ;
					convExp[idx++] = popOp;
				}
				break ;
			case '+' : case '-' :
			case '*' : case '/' :
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);
				SPush(&stack, tok);
				break ;
			}
		}
	}
	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);
	strcpy(exp, convExp);
	free(convExp);
}

int main(void)
{
	char exp[100];

	scanf("%s", exp);
	convToRPNExp(exp);
	printf("%s", exp);
	return (0);
}