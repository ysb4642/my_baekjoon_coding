#include <stdio.h>
#include <string.h>

int main(void)
{
	int n, top = 0;;
	char str[1001], stack[1001];

	scanf("%d ", &n);
	for (int i = 0; i < n; i++)
	{
		fgets(str, 1001, stdin);
		for (int j = 0; j < strlen(str) - 1; j++)
		{
			if (str[j] != ' ')
				stack[top++] = str[j];
			if (str[j] == ' ' || j == strlen(str) - 2)
			{
				for(int k = top - 1; k >= 0; k--)
					printf("%c", stack[k]);
				printf(" ");
				top = 0;
			}
		}
		printf("\n");
	}
	return (0);
}