#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE	1
#define FALSE	0

typedef float Data;

typedef struct _node
{
	Data data;
	struct _node *next;
} Node;

typedef struct _listStack
{
	Node *head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack *pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack *pstack, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data SPop(Stack *pstack)
{
	Data rdata;
	Node *rnode;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free (rnode);

	return rdata;
}

Data SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}

Data EvalRPNExp(char exp[], int arr[])
{
	Stack stack;
	int expLen = strlen(exp);
	int i, j = 0;
	char tok;
	float op1, op2;

	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];

		if (isalpha(tok))
			SPush(&stack, arr[tok - 'A']);
		else
		{
			op2 = SPop(&stack);
			op1 = SPop(&stack);

			switch(tok)
			{
			case '+' :
				SPush(&stack, op1 + op2);
				break ;
			case '-' :
				SPush(&stack, op1 - op2);
				break ;
			case '*' :
				SPush(&stack, op1 * op2);
				break ;
			case '/' :
				SPush(&stack, op1 / op2);
				break ;
			}
		}
	}
	return (SPop(&stack));
}

int main(void)
{
	int n, i;
	float arr[100];
	char exp[100];

	scanf("%d", &n);
	scanf("%s", exp);

	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("%.2f", EvalRPNExp(exp, arr));
	return (0);
}