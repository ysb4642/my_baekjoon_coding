#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100000];
	char stack[100000];
	int i, j, k, len;

	fgets(str, 100000, stdin);
	len = strlen(str) - 1;

	j = 0;
	k = 0;
	for (i = 0; i < len; i++)
	{
		if (str[i] == '<')
		{
			if (j == 0)
				stack[j++] = str[i];
			else
			
		}
		else if (str[i] == '>')
		{
			while(stack[k] != '>')
				printf("%c", stack[k++]);
			printf("%c", str[i]);
			k = 0;
		}
		else if (str[i] != ' ')
			stack[j++] = str[i];
		else if (str[i] == ' ' || i == len - 1)
		{
			while(--j >= 0)
				printf("%c", stack[j]);
			if (str[i] == ' ')
				printf(" \n");
			else
				printf("\n");
			j = 0;
		}
	}
	return (0);
}